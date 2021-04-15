#include "CommandStackImpl.h"

#include <stdexcept>

namespace commands {

CommandStackImpl::CommandStackImpl() {
}

void CommandStackImpl::execute(std::shared_ptr<commands::Command> command) {
    addToExecutedCommands(command);
    command->execute();
}

void CommandStackImpl::undo() {
    auto& stack = getExecutedCommands();
    if (stack.empty()) {
        throw std::runtime_error("cannot undo with empty stack");
    }

    auto command = stack.back();
    removeFromExecutedCommands(command);
    command->undo();
    addToUndoneCommands(command);
}

void CommandStackImpl::redo() {
    if (getUndoneCommands().empty()) {
        throw std::runtime_error("cannot redo with no undone commands");
    }
    auto& undoStack = getUndoneCommands();
    auto undoneCommand = undoStack.back();
    removeFromUndoneCommands(undoneCommand);
    undoneCommand->redo();
    addToExecutedCommands(undoneCommand);
}

void CommandStackImpl::undoAll() {
    while (!getExecutedCommands().empty()) {
        undo();
    }
}

void CommandStackImpl::redoAll() {
    while (!getUndoneCommands().empty()) {
        redo();
    }
}

}

