#include "CompositeCommandBase.h"

#include "AddEntityCommandImpl.h"
#include "RemoveEntityCommandImpl.h"

using namespace basetypes;

namespace commands {
void CompositeCommandBase::undo() {
    auto& subCommands = getSubCommands();
    for (auto iter = subCommands.rbegin(); iter != subCommands.rend(); ++iter) {
        auto& subCommand = *iter;
        subCommand.undo();
    }
}

void CompositeCommandBase::redo() {
    for (auto& subCommand : getSubCommands()) {
        subCommand.redo();
    }
}

void CompositeCommandBase::executeSetProperty(std::shared_ptr<Entity> entity, unsigned featureKey, Any oldValue,
                                              Any newValue) {
    internalExecuteSetProperty(entity, featureKey, oldValue, newValue);
}

void CompositeCommandBase::executeSetProperty(std::shared_ptr<Entity> entity, unsigned featureKey,
                                              std::shared_ptr<Entity> oldValue, std::shared_ptr<Entity> newValue) {
    internalExecuteSetProperty(entity, featureKey, oldValue.get(), newValue.get());
}

SetPropertyCommandImpl& CompositeCommandBase::internalExecuteSetProperty(std::shared_ptr<Entity> entity, unsigned featureKey,
                                                                         Any oldValue, Any newValue) {
    auto command = std::make_shared<SetPropertyCommandImpl>();
    command->setEntity(entity);
    command->setOldValue(oldValue);
    command->setNewValue(newValue);
    command->setFeatureKey(featureKey);

    addToSubCommands(command);
    command->execute();
    return *command;
}

void CompositeCommandBase::executeAddReference(std::shared_ptr<Entity> entity, unsigned featureKey,
                                               std::shared_ptr<Entity> entityToAdd) {
    auto command = std::make_shared<AddEntityCommandImpl>();
    command->setEntity(entity);
    command->setEntityToAdd(entityToAdd);
    command->setFeatureKey(featureKey);

    addToSubCommands(command);
    command->execute();
}

void CompositeCommandBase::executeRemoveReference(std::shared_ptr<Entity> entity, unsigned featureKey,
                                                  std::shared_ptr<Entity> entityToRemove) {
    auto command = std::make_shared<RemoveEntityCommandImpl>();
    command->setEntity(entity);
    command->setEntityToRemove(entityToRemove);
    command->setFeatureKey(featureKey);

    addToSubCommands(command);
    command->execute();
}

}
