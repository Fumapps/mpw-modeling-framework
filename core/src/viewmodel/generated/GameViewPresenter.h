/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWPRESENTER_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWPRESENTER_H

#include <memory>
#include <string>
#include "MpwSemaphore.h"
#include "GameViewInput.h"

namespace viewmodel {
class GameViewModel;
}

namespace viewmodel {

/**
 * Base class for a presenter of a game view.
 * It implements the GameViewInput interface to accept user inputs.
 * By calling bind(), it starts observing a concrete MiniProgrammingWorld and updates the GameViewModel accordingly.
 */
class GameViewPresenter: public virtual viewmodel::GameViewInput {

private:

	/**
	 * The view-model, which represents the visible information to be rendered on a screen.
	 */
	std::shared_ptr<viewmodel::GameViewModel> viewModel;

	/**
	 * Used to synchronize access from a different thread to the view-model.
	 */
	framework::Semaphore semaphore;

public:

	GameViewPresenter(framework::Semaphore semaphore);

	virtual std::shared_ptr<viewmodel::GameViewModel> getViewModel() noexcept;
	virtual std::shared_ptr<const viewmodel::GameViewModel> getViewModel() const noexcept;

	virtual framework::Semaphore getSemaphore() noexcept;
	virtual framework::Semaphore getSemaphore() const noexcept;

public:

	virtual ~GameViewPresenter() = 0;

	/**
	 * Binds the view-model to the concrete MiniProgrammingWorld, which has to be given at construction time.
	 */
	virtual void bind() = 0;

	static constexpr unsigned cFeatureKeyViewModel = 1;
	static constexpr unsigned cFeatureKeySemaphore = 2;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWPRESENTER_H

