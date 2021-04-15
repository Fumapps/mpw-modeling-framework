#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMANDSTACKIMPL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMANDSTACKIMPL_H

#include "CommandStack.h"
#include "Command.h"

namespace commands {

class CommandStackImpl : public CommandStack {
private:
    using inherited = CommandStack;

public:

    CommandStackImpl();

    void execute(std::shared_ptr<commands::Command> command) override;

    void undo() override;

    void redo() override;

    void undoAll() override;

    void redoAll() override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMANDSTACKIMPL_H
