/*
 * This file is generated. Do not change it manually.
 */

#include "GamePerformance.h"

#include <stdexcept>

#include "CommandStack.h"

#include "CommandStackImpl.h"

namespace mpw {

GamePerformance::GamePerformance(framework::Semaphore semaphore) {

	this->semaphore = semaphore;
	this->gameCommandStack = std::make_shared<commands::CommandStackImpl>();
	this->mode.set(mpw::Mode::INITIALIZING);
	this->speed.set(4.0);
	this->delayEnabled.set(true);
}

GamePerformance::~GamePerformance() = default;

framework::ObservablePrimitiveProperty<mpw::Mode>& GamePerformance::modeProperty() noexcept {
	return this->mode;
}
const framework::ObservablePrimitiveProperty<mpw::Mode>& GamePerformance::modeProperty() const noexcept {
	return this->mode;
}

framework::ObservablePrimitiveProperty<double>& GamePerformance::speedProperty() noexcept {
	return this->speed;
}
const framework::ObservablePrimitiveProperty<double>& GamePerformance::speedProperty() const noexcept {
	return this->speed;
}

framework::ObservablePrimitiveProperty<bool>& GamePerformance::delayEnabledProperty() noexcept {
	return this->delayEnabled;
}
const framework::ObservablePrimitiveProperty<bool>& GamePerformance::delayEnabledProperty() const noexcept {
	return this->delayEnabled;
}

framework::Semaphore GamePerformance::getSemaphore() noexcept {
	return this->semaphore;
}

framework::Semaphore GamePerformance::getSemaphore() const noexcept {
	return this->semaphore;
}

mpw::Mode GamePerformance::getMode() noexcept {
	return this->mode.get();
}

mpw::Mode GamePerformance::getMode() const noexcept {
	return this->mode.get();
}

double GamePerformance::getSpeed() noexcept {
	return this->speed.get();
}

double GamePerformance::getSpeed() const noexcept {
	return this->speed.get();
}

bool GamePerformance::getDelayEnabled() noexcept {
	return this->delayEnabled.get();
}

bool GamePerformance::getDelayEnabled() const noexcept {
	return this->delayEnabled.get();
}

std::shared_ptr<commands::CommandStack> GamePerformance::getGameCommandStack() noexcept {
	return this->gameCommandStack;
}

std::shared_ptr<const commands::CommandStack> GamePerformance::getGameCommandStack() const noexcept {
	return this->gameCommandStack;
}

void GamePerformance::setMode(mpw::Mode mode) noexcept {
	this->mode.set(mode);
}

void GamePerformance::setSpeed(double speed) noexcept {
	this->speed.set(speed);
}

void GamePerformance::setDelayEnabled(bool delayEnabled) noexcept {
	this->delayEnabled.set(delayEnabled);
}

}
