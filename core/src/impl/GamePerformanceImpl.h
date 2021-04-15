#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEPERFORMANCEIMPL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEPERFORMANCEIMPL_H

#include "GamePerformance.h"
#include "MpwSemaphore.h"

namespace mpw {

class GamePerformanceImpl : public GamePerformance {
private:
    using inherited = GamePerformance;

public:

    GamePerformanceImpl();

    void startGame() override;

    void startGamePaused() override;

    void pauseGame() override;

    void resumeGame() override;

    void stopGame() override;

    void hardReset() override;

    void abortOrStopGame() override;

    void preExecuteGameCommand() override;

    void preExecuteEditorCommand() override;

    void delayControlFlow() override;

private:

    void startGameInMode(Mode mode);

    void clearCommandStack();

    void acquireSemaphore();

    void unblockForMode(Mode mode);

    void stopControlFlowIfPaused();

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEPERFORMANCEIMPL_H
