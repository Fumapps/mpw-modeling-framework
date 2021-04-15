/*
 * This file is generated. Do not change it manually.
 */

#include "SetPropertyCommand.h"

#include <stdexcept>

namespace commands {

SetPropertyCommand::SetPropertyCommand() {

}

SetPropertyCommand::~SetPropertyCommand() = default;

Any SetPropertyCommand::getOldValue() noexcept {
	return this->oldValue;
}

Any SetPropertyCommand::getOldValue() const noexcept {
	return this->oldValue;
}

Any SetPropertyCommand::getNewValue() noexcept {
	return this->newValue;
}

Any SetPropertyCommand::getNewValue() const noexcept {
	return this->newValue;
}

void SetPropertyCommand::setOldValue(Any oldValue) noexcept {
	this->oldValue = oldValue;
}

void SetPropertyCommand::setNewValue(Any newValue) noexcept {
	this->newValue = newValue;
}

}
