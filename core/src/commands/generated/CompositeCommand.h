/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMPOSITECOMMAND_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMPOSITECOMMAND_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "SimpleListProperties.h"
#include "ObjectListView.hpp"
#include "Command.h"

namespace commands {

/**
 * A more complex type of commands which makes use of multiple sub-commands. Usually the sub-commands are PrimitiveCommands.
 * 
 * Example Hamster-Simulation: Game commands: Move, PickGrain, PutGrain or TurnLeft. Editor commands: InitTerritory or InitHamster.
 */
class CompositeCommand: public virtual commands::Command {

private:

	framework::SimpleObjectContainmentListProperty<commands::Command> subCommands;
	/// \brief internal lookup for subCommands
	std::unordered_set<commands::Command*> subCommandsLookup;

public:

	CompositeCommand();

	virtual framework::ObjectListView<commands::Command>& getSubCommands() noexcept;
	virtual const framework::ObjectListView<commands::Command>& getSubCommands() const noexcept;

	virtual void addToSubCommands(
			std::shared_ptr<commands::Command> subCommand) noexcept;
	virtual void removeFromSubCommands(
			std::shared_ptr<commands::Command> subCommand) noexcept;
	virtual void clearSubCommands() noexcept;

public:

	virtual ~CompositeCommand() = 0;

	static constexpr unsigned cFeatureKeySubCommands = 1;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMPOSITECOMMAND_H

