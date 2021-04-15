/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMAND_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMAND_H

#include <memory>
#include <string>

namespace commands {

/**
 * Defines the basic type for PrimitiveCommand or CompositeCommand which represent behavior which can be executed. It provides the ability to: execute, undo or redo.
 * 
 * Commands are processed in context of an Actor or the Stage.
 */
class Command: public std::enable_shared_from_this<Command> {

public:

	virtual ~Command() = default;

	virtual void execute() = 0;

	virtual void undo() = 0;

	virtual void redo() = 0;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_COMMAND_H

