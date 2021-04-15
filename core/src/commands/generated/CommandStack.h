/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMANDSTACK_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMANDSTACK_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "ObjectListView.hpp"
#include "Command.h"

namespace commands {

/**
 * Tracks the executed Commands which allow to undo and redo their behavior.
 */
class CommandStack: public std::enable_shared_from_this<CommandStack> {

private:

	framework::ObservableObjectContainmentListProperty<Command> executedCommands;
	/// \brief internal lookup for executedCommands
	std::unordered_set<commands::Command*> executedCommandsLookup;

	framework::ObservableObjectContainmentListProperty<Command> undoneCommands;
	/// \brief internal lookup for undoneCommands
	std::unordered_set<commands::Command*> undoneCommandsLookup;

public:

	CommandStack();

	virtual framework::ObservableListProperty<commands::Command>& executedCommandsProperty() noexcept;
	virtual const framework::ObservableListProperty<commands::Command>& executedCommandsProperty() const noexcept;

	virtual framework::ObservableListProperty<commands::Command>& undoneCommandsProperty() noexcept;
	virtual const framework::ObservableListProperty<commands::Command>& undoneCommandsProperty() const noexcept;

	virtual framework::ObjectListView<commands::Command>& getExecutedCommands() noexcept;
	virtual const framework::ObjectListView<commands::Command>& getExecutedCommands() const noexcept;

	virtual framework::ObjectListView<commands::Command>& getUndoneCommands() noexcept;
	virtual const framework::ObjectListView<commands::Command>& getUndoneCommands() const noexcept;

	virtual void addToExecutedCommands(
			std::shared_ptr<commands::Command> executedCommand) noexcept;
	virtual void removeFromExecutedCommands(
			std::shared_ptr<commands::Command> executedCommand) noexcept;
	virtual void clearExecutedCommands() noexcept;

	virtual void addToUndoneCommands(
			std::shared_ptr<commands::Command> undoneCommand) noexcept;
	virtual void removeFromUndoneCommands(
			std::shared_ptr<commands::Command> undoneCommand) noexcept;
	virtual void clearUndoneCommands() noexcept;

public:

	virtual ~CommandStack() = 0;

	virtual void execute(std::shared_ptr<commands::Command> command) = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
	virtual void undoAll() = 0;
	virtual void redoAll() = 0;

	static constexpr unsigned cFeatureKeyExecutedCommands = 1;
	static constexpr unsigned cFeatureKeyUndoneCommands = 2;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMANDSTACK_H

