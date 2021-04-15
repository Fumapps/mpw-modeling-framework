#include "RemoveEntityCommandImpl.h"

#include "Entity.h"

namespace commands {

RemoveEntityCommandImpl::RemoveEntityCommandImpl() {
}

void RemoveEntityCommandImpl::execute() {
    auto entity = getEntity();
    EntityReference reference = getEntityToRemove().get();
    entity->removeFromCollection(getFeatureKey(), reference);
}

void RemoveEntityCommandImpl::undo() {

    auto entity = getEntity();
    EntityReference reference = getEntityToRemove().get();
    entity->addToCollection(getFeatureKey(), reference);
}

void RemoveEntityCommandImpl::redo() {
    execute();
}

}

