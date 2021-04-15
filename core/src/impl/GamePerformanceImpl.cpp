#include "GamePerformanceImpl.h"

#include "CommandStack.h"
#include "FrameworkAssert.h"

#include <thread>
#include <stdexcept>
#include <cassert>
#include <GameAbortedException.h>

using namespace framework;

namespace mpw {

GamePerformanceImpl::GamePerformanceImpl()
        : inherited(framework::Semaphore()) {
}

void GamePerformanceImpl::startGame() {
    startGameInMode(Mode::RUNNING);
}

void GamePerformanceImpl::startGamePaused() {
    startGameInMode(Mode::RUNNING);
    pauseGame();
}

void GamePerformanceImpl::startGameInMode(Mode mode) {
    checkState(getMode() == Mode::INITIALIZING,
               "start game is only possible during initialization");

    clearCommandStack();
    this->setMode(mode);
}

void GamePerformanceImpl::preExecuteGameCommand() {
    stopControlFlowIfPaused();
    if (this->getMode() == Mode::ABORTED) {
        this->setMode(Mode::STOPPED);
        throw GameAbortedException("Stopped execution of command due to abort");
    } else if (this->getMode() != Mode::RUNNING) {
        throw std::runtime_error("The game needs to be running to execute game commands");
    }
    checkState(getMode() != Mode::STOPPED);
}

void GamePerformanceImpl::preExecuteEditorCommand() {
    if (this->getMode() != Mode::INITIALIZING) {
        throw std::runtime_error("The game needs to be initializing to execute editor commands");
    }
}

void GamePerformanceImpl::stopControlFlowIfPaused() {
    // obtain lock by RAII pattern
    SemaphoreLock semaphoreLock = getSemaphore().lock();
}

void GamePerformanceImpl::delayControlFlow() {
    if (getDelayEnabled()) {
        double speed = getSpeed();
        long delayTimeInMillis = static_cast<long>((11.0 - speed) / 5.0 * 400.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(delayTimeInMillis));
    }
}

void GamePerformanceImpl::pauseGame() {
    checkState(getMode() == Mode::RUNNING, "Cannot pause: game is not running");
    setMode(Mode::PAUSED);
    acquireSemaphore();
}

void GamePerformanceImpl::acquireSemaphore() {
    if (!getSemaphore().isLocked()) {
        getSemaphore().acquire();
    }
}

void GamePerformanceImpl::resumeGame() {
    checkState(getMode() == Mode::PAUSED, "Cannot resume: game is not paused");
    assert(getSemaphore().isLocked());

    getGameCommandStack()->redoAll();
    unblockForMode(Mode::RUNNING);
}

void GamePerformanceImpl::hardReset() {
    clearCommandStack();
    this->stopGame();
    setMode(Mode::INITIALIZING);
}

void GamePerformanceImpl::clearCommandStack() {
    auto gameCommandStack = getGameCommandStack();
    gameCommandStack->clearExecutedCommands();
    gameCommandStack->clearUndoneCommands();
}

void GamePerformanceImpl::abortOrStopGame() {
    Mode mode = getMode();
    if ((mode == Mode::STOPPED) || (mode == Mode::INITIALIZING)) {
        stopGame();
    } else {
        unblockForMode(Mode::ABORTED);
    }
}

void GamePerformanceImpl::stopGame() {
    unblockForMode(Mode::STOPPED);
}

void GamePerformanceImpl::unblockForMode(Mode mode) {
    setMode(mode);
    if (getSemaphore().isLocked()) {
        getSemaphore().release();
    }
}

}

