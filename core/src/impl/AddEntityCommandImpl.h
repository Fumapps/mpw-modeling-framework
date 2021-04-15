#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ADDENTITYCOMMANDIMPL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ADDENTITYCOMMANDIMPL_H

#include "AddEntityCommand.h"

namespace commands {

class AddEntityCommandImpl : public AddEntityCommand {
public:

    AddEntityCommandImpl();

    void execute() override;

    void undo() override;

    void redo() override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ADDENTITYCOMMANDIMPL_H
