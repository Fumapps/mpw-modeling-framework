#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_REMOVEENTITYCOMMANDIMPL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_REMOVEENTITYCOMMANDIMPL_H

#include "RemoveEntityCommand.h"

namespace commands {

class RemoveEntityCommandImpl : public RemoveEntityCommand {
public:

    RemoveEntityCommandImpl();

    void execute() override;

    void undo() override;

    void redo() override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_REMOVEENTITYCOMMANDIMPL_H
