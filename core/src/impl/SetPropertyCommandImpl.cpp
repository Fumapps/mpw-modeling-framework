#include "SetPropertyCommandImpl.h"

#include "Entity.h"

namespace commands {

SetPropertyCommandImpl::SetPropertyCommandImpl() {
}

void SetPropertyCommandImpl::execute() {
    auto entity = getEntity();
    entity->setProperty(getFeatureKey(), getNewValue());
}

void SetPropertyCommandImpl::undo() {
    auto entity = getEntity();
    entity->setProperty(getFeatureKey(), getOldValue());
}

void SetPropertyCommandImpl::redo() {
    execute();
}

void SetPropertyCommandImpl::handleLifeCycleOfValues(deleter deletionFunction) {
    ValueReference oldValue = std::get<ValueReference>(getOldValue());
    ValueReference newValue = std::get<ValueReference>(getNewValue());
    oldValueUniquePtr = std::unique_ptr<void, deleter>(oldValue, deletionFunction);
    newValueUniquePtr = std::unique_ptr<void, deleter>(newValue, deletionFunction);
}

}

