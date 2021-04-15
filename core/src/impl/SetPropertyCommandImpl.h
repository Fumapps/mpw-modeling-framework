#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SETPROPERTYCOMMANDIMPL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SETPROPERTYCOMMANDIMPL_H

#include <functional>

#include "SetPropertyCommand.h"

namespace commands {

class SetPropertyCommandImpl : public SetPropertyCommand {
public:

    SetPropertyCommandImpl();

    void execute() override;

    void undo() override;

    void redo() override;

    /// \brief injected lambda which deletes the raw values, which shall be owned by handleLifeCycleOfValues() semantics
    using deleter = std::function<void(ValueReference)>;

    /// \brief Used for value-types to make unique-pointers owning the raw references of the given values
    void handleLifeCycleOfValues(deleter deletionFunction);

private:

    std::unique_ptr<void, deleter> oldValueUniquePtr;
    std::unique_ptr<void, deleter> newValueUniquePtr;
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SETPROPERTYCOMMANDIMPL_H
