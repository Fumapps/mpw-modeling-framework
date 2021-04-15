/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEPERFORMANCE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEPERFORMANCE_H

#include <memory>
#include <string>
#include "MpwSemaphore.h"
#include "ObservableProperties.h"
#include "Mode.h"

namespace commands {
class CommandStack;
}

namespace mpw {

/**
 * Makes it possible to control the execution of the associated MPW.
 * Supported features are
 * <ul>
 *     <li>undo(All), redo(All)</li>
 *     <li>speed</li>
 *     <li>pause(Async), resume, stop</li>
 *     <li>mode (read-only)</li>
 * </ul>
 * 
 * Internally the GamePerformance contains a CommandStack used 
 * to keep track of game commands.
 */
class GamePerformance: public std::enable_shared_from_this<GamePerformance> {

private:

	framework::Semaphore semaphore;

	framework::ObservablePrimitiveProperty<mpw::Mode> mode;

	/**
	 * The speed of the game performance. Valid values are in the range from
	 * 0.0 to 10.0,
	 * where 0.0 is slow and 10.0 is fast.
	 */
	framework::ObservablePrimitiveProperty<double> speed;

	framework::ObservablePrimitiveProperty<bool> delayEnabled;

	std::shared_ptr<commands::CommandStack> gameCommandStack;

public:

	GamePerformance(framework::Semaphore semaphore);

	virtual framework::ObservablePrimitiveProperty<mpw::Mode>& modeProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<mpw::Mode>& modeProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<double>& speedProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<double>& speedProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<bool>& delayEnabledProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<bool>& delayEnabledProperty() const noexcept;

	virtual framework::Semaphore getSemaphore() noexcept;
	virtual framework::Semaphore getSemaphore() const noexcept;

	virtual mpw::Mode getMode() noexcept;
	virtual mpw::Mode getMode() const noexcept;

	virtual double getSpeed() noexcept;
	virtual double getSpeed() const noexcept;

	virtual bool getDelayEnabled() noexcept;
	virtual bool getDelayEnabled() const noexcept;

	virtual std::shared_ptr<commands::CommandStack> getGameCommandStack() noexcept;
	virtual std::shared_ptr<const commands::CommandStack> getGameCommandStack() const noexcept;

	virtual void setMode(mpw::Mode mode) noexcept;

	virtual void setSpeed(double speed) noexcept;

	virtual void setDelayEnabled(bool delayEnabled) noexcept;

public:

	virtual ~GamePerformance() = 0;

	/**
	 * Start the execution of a game. Before executing start, no commands can be
	 * executed by the actor objects in the game.
	 * This is only possible if the current mode is Mode.INITIALIZING
	 * The game will be started in running mode.
	 */
	virtual void startGame() = 0;
	/**
	 * Start the execution of a game. Before executing start, no commands can be
	 * executed by the actor objects in the game.
	 * This is only possible if the current mode is Mode.INITIALIZING
	 * The game will be started in pause mode.
	 */
	virtual void startGamePaused() = 0;
	/**
	 * Pauses the game when it is running.
	 * If the game is not running (paused previously, not started or stopped), an exception
	 * is thrown.
	 * This is executed asynchronously, but this method waits until the started thread
	 * has performed a paused state.
	 */
	virtual void pauseGame() = 0;
	/**
	 * Resumes the game.
	 * It is only possible to execute this in paused mode.
	 */
	virtual void resumeGame() = 0;
	/**
	 * Stop the execution of the game. The game is finished and needs to be reset / hardReset
	 * or closed.
	 * If the game is already stopped, this does nothing
	 */
	virtual void stopGame() = 0;
	/**
	 * Hard-resets the game command stack. It clears executed commands and undone commands, however, it does NOT
	 * undo all commands. If this behaviour is desired, it is necessary to call undoAll first.
	 * This also sets the mode to initializing.
	 */
	virtual void hardReset() = 0;
	/**
	 * Abort or stop the execution of the game. The game is finished and needs to be reset / hardReset
	 * or closed.
	 * If the game is running, paused or aborted, the game is aborted.
	 * if the game is initializing or stopped, it is stopped.
	 */
	virtual void abortOrStopGame() = 0;
	/**
	 * Called by the facade to validate the execution of a game command.
	 */
	virtual void preExecuteGameCommand() = 0;
	/**
	 * Called by the facade to validate the execution of an editor command.
	 */
	virtual void preExecuteEditorCommand() = 0;
	/**
	 * Called by the facade to delay the control flow for game commands.
	 */
	virtual void delayControlFlow() = 0;

	static constexpr unsigned cFeatureKeySemaphore = 1;
	static constexpr unsigned cFeatureKeyMode = 2;
	static constexpr unsigned cFeatureKeySpeed = 3;
	static constexpr unsigned cFeatureKeyDelayEnabled = 4;
	static constexpr unsigned cFeatureKeyGameCommandStack = 5;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEPERFORMANCE_H

