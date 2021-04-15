
#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMPOSITECOMMANDBASE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMPOSITECOMMANDBASE_H

#include <memory>
#include <string>

#include "Any.h"
#include "CompositeCommand.h"
#include "SetPropertyCommandImpl.h"
#include "Entity.h"

namespace commands {
class CompositeCommandBase : public CompositeCommand {
public:

    void undo() override;

    void redo() override;

protected:

    void executeSetProperty(std::shared_ptr<basetypes::Entity> entity, unsigned featureKey, Any oldValue, Any newValue);

    void executeSetProperty(std::shared_ptr<basetypes::Entity> entity, unsigned featureKey,
                            std::shared_ptr<basetypes::Entity> oldValue, std::shared_ptr<basetypes::Entity> newValue);

    /// \brief special variant to set a value, which can be used for value-types
    /// \note \param oldValue and \param newValue are created as copied raw pointers of unmanaged memory on the heap
    template<typename T>
    void executeSetValueProperty(std::shared_ptr<basetypes::Entity> entity, unsigned featureKey, T oldValue, T newValue) {
        auto& command = internalExecuteSetProperty(entity, featureKey, new T(oldValue), new T(newValue));
        command.handleLifeCycleOfValues([](ValueReference reference) {
            delete reinterpret_cast<T*>(reference);
        });
    }

    template<typename T>
    void executeSetEnumProperty(std::shared_ptr<basetypes::Entity> entity, unsigned featureKey, T oldValue, T newValue) {
        internalExecuteSetProperty(entity, featureKey, static_cast<int>(oldValue), static_cast<int>(newValue));
    }

    void executeSetStringProperty(std::shared_ptr<basetypes::Entity> entity, unsigned featureKey,
                                  const std::string& oldValue, const std::string& newValue) {
        internalExecuteSetProperty(entity, featureKey, oldValue, newValue);
    }

    void executeAddReference(std::shared_ptr<basetypes::Entity> entity, unsigned featureKey,
                             std::shared_ptr<basetypes::Entity> entityToAdd);

    void executeRemoveReference(std::shared_ptr<basetypes::Entity> entity, unsigned featureKey,
                                std::shared_ptr<basetypes::Entity> entityToRemove);

private:

    SetPropertyCommandImpl& internalExecuteSetProperty(std::shared_ptr<basetypes::Entity> entity,
                                                       unsigned featureKey, Any oldValue, Any newValue);
};
}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMPOSITECOMMANDBASE_H

