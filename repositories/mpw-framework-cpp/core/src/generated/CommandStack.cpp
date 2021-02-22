/*
 * This file is generated. Do not change it manually.
 */

#include "CommandStack.h"

#include <stdexcept>

namespace commands {

CommandStack::CommandStack() {

}

CommandStack::~CommandStack() = default;

const framework::ObservableListProperty<commands::Command>& CommandStack::executedCommandsProperty() noexcept {
	return this->executedCommands;
}

const framework::ObservableListProperty<commands::Command>& CommandStack::undoneCommandsProperty() noexcept {
	return this->undoneCommands;
}

framework::ObjectListView<Command>& CommandStack::getExecutedCommands() noexcept {
	return this->executedCommands;
}

framework::ObjectListView<Command>& CommandStack::getUndoneCommands() noexcept {
	return this->undoneCommands;
}

void CommandStack::addToExecutedCommands(
		std::shared_ptr<commands::Command> executedCommand) noexcept {
	if (this->executedCommandsLookup.find(executedCommand.get())
			== this->executedCommandsLookup.end()) {
		this->executedCommands.add(executedCommand);
		this->executedCommandsLookup.insert(executedCommand.get());
	}
}
void CommandStack::removeFromExecutedCommands(
		std::shared_ptr<commands::Command> executedCommand) noexcept {
	if (this->executedCommandsLookup.find(executedCommand.get())
			!= this->executedCommandsLookup.end()) {
		this->executedCommands.remove(executedCommand);
		this->executedCommandsLookup.erase(executedCommand.get());
	}
}

void CommandStack::clearExecutedCommands() noexcept {
	while (!this->executedCommands.empty()) {
		removeFromExecutedCommands(this->executedCommands.front());
	}
}

void CommandStack::addToUndoneCommands(
		std::shared_ptr<commands::Command> undoneCommand) noexcept {
	if (this->undoneCommandsLookup.find(undoneCommand.get())
			== this->undoneCommandsLookup.end()) {
		this->undoneCommands.add(undoneCommand);
		this->undoneCommandsLookup.insert(undoneCommand.get());
	}
}
void CommandStack::removeFromUndoneCommands(
		std::shared_ptr<commands::Command> undoneCommand) noexcept {
	if (this->undoneCommandsLookup.find(undoneCommand.get())
			!= this->undoneCommandsLookup.end()) {
		this->undoneCommands.remove(undoneCommand);
		this->undoneCommandsLookup.erase(undoneCommand.get());
	}
}

void CommandStack::clearUndoneCommands() noexcept {
	while (!this->undoneCommands.empty()) {
		removeFromUndoneCommands(this->undoneCommands.front());
	}
}

// TODO Source Operation void CommandStack::execute(std::shared_ptr<commands::Command> command) {}
// TODO Source Operation void CommandStack::undo() {}
// TODO Source Operation void CommandStack::redo() {}
// TODO Source Operation void CommandStack::undoAll() {}
// TODO Source Operation void CommandStack::redoAll() {}

}