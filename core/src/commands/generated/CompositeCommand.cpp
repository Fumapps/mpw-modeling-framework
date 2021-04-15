/*
 * This file is generated. Do not change it manually.
 */

#include "CompositeCommand.h"

#include <stdexcept>

namespace commands {

CompositeCommand::CompositeCommand() {

}

CompositeCommand::~CompositeCommand() = default;

framework::ObjectListView<commands::Command>& CompositeCommand::getSubCommands() noexcept {
	return this->subCommands;
}

const framework::ObjectListView<commands::Command>& CompositeCommand::getSubCommands() const noexcept {
	return this->subCommands;
}

void CompositeCommand::addToSubCommands(
		std::shared_ptr<commands::Command> subCommand) noexcept {
	if (this->subCommandsLookup.find(subCommand.get())
			== this->subCommandsLookup.end()) {
		this->subCommands.push_back(subCommand);
		this->subCommandsLookup.insert(subCommand.get());
	}
}
void CompositeCommand::removeFromSubCommands(
		std::shared_ptr<commands::Command> subCommand) noexcept {
	if (this->subCommandsLookup.find(subCommand.get())
			!= this->subCommandsLookup.end()) {
		this->subCommands.remove(subCommand);
		this->subCommandsLookup.erase(subCommand.get());
	}
}

void CompositeCommand::clearSubCommands() noexcept {
	while (!this->subCommands.empty()) {
		removeFromSubCommands(this->subCommands.front());
	}
}

}
