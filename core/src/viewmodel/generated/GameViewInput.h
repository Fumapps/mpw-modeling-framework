/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWINPUT_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWINPUT_H

#include <memory>
#include <string>

namespace viewmodel {

/**
 * Interface, which defines the view inputs of a MPW simulator.
 * It defines the input methods to play, pause, undo and redo which usually are called by button click event handlers.
 * Also, the input speedChanged is used to change the speed, e.g. controlled by a slider control.
 * 
 * A dedicated input is close(), which indicates that the user wants to close the simulator, e.g. by clicking the "X" on a graphical simulator window.
 */
class GameViewInput: public std::enable_shared_from_this<GameViewInput> {

public:

	virtual ~GameViewInput() = default;

	/**
	 * Input event for clicking the play button.
	 */
	virtual void playClicked() = 0;

	/**
	 * Input event for clicking the pause button.
	 */
	virtual void pauseClicked() = 0;

	/**
	 * Input event for clicking the undo button.
	 */
	virtual void undoClicked() = 0;

	/**
	 * Input event for clicking the redo button.
	 */
	virtual void redoClicked() = 0;

	/**
	 * Input event for for changing the speed of the simulation.
	 */
	virtual void speedChanged(double speedValue) = 0;

	/**
	 * Input event for closing the simulator.
	 */
	virtual void close() = 0;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWINPUT_H

