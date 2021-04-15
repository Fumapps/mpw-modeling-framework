/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_MINIPROGRAMMINGWORLD_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_MINIPROGRAMMINGWORLD_H

#include <memory>
#include <string>

namespace commands {
class CommandStack;
}
namespace mpw {
class GamePerformance;
}
namespace mpw {
class GameLog;
}
namespace mpw {
class UserInputInterface;
}

namespace mpw {

/**
 * Represents the root meta-class for a MPW (Mini Programming World).
 * 
 * It typically is derived by game classes like a HamsterGame, which is used
 * to realize a concrete MPW. MiniProgrammingWorld contains a Stage object,
 * which is set by a concrete derived class in context of a concrete MPW.
 * 
 * Further, it defines command stacks, a game log and a performance class, which
 * controls the mode of the game.
 */
class MiniProgrammingWorld: public std::enable_shared_from_this<
		MiniProgrammingWorld> {

private:

	std::shared_ptr<commands::CommandStack> editorCommandStack;

	std::shared_ptr<mpw::GamePerformance> performance;

	std::shared_ptr<mpw::GameLog> gameLog;

	std::shared_ptr<mpw::UserInputInterface> userInputInterface;

public:

	MiniProgrammingWorld();

	virtual std::shared_ptr<commands::CommandStack> getEditorCommandStack() noexcept;
	virtual std::shared_ptr<const commands::CommandStack> getEditorCommandStack() const noexcept;

	virtual std::shared_ptr<mpw::GamePerformance> getPerformance() noexcept;
	virtual std::shared_ptr<const mpw::GamePerformance> getPerformance() const noexcept;

	virtual std::shared_ptr<mpw::GameLog> getGameLog() noexcept;
	virtual std::shared_ptr<const mpw::GameLog> getGameLog() const noexcept;

	virtual std::shared_ptr<mpw::UserInputInterface> getUserInputInterface() noexcept;
	virtual std::shared_ptr<const mpw::UserInputInterface> getUserInputInterface() const noexcept;

	virtual void setUserInputInterface(
			std::shared_ptr<mpw::UserInputInterface> userInputInterface) noexcept;

public:

	virtual ~MiniProgrammingWorld() = 0;

	static constexpr unsigned cFeatureKeyEditorCommandStack = 1;
	static constexpr unsigned cFeatureKeyPerformance = 2;
	static constexpr unsigned cFeatureKeyGameLog = 3;
	static constexpr unsigned cFeatureKeyUserInputInterface = 4;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_MINIPROGRAMMINGWORLD_H

