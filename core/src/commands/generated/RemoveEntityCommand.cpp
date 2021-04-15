/*
 * This file is generated. Do not change it manually.
 */

#include "RemoveEntityCommand.h"

#include <stdexcept>

#include "Entity.h"

namespace commands {

RemoveEntityCommand::RemoveEntityCommand() {

}

RemoveEntityCommand::~RemoveEntityCommand() = default;

std::shared_ptr<basetypes::Entity> RemoveEntityCommand::getEntityToRemove() noexcept {
	return this->entityToRemove;
}

std::shared_ptr<const basetypes::Entity> RemoveEntityCommand::getEntityToRemove() const noexcept {
	return this->entityToRemove;
}

void RemoveEntityCommand::setEntityToRemove(
		std::shared_ptr<basetypes::Entity> entityToRemove) noexcept {
	auto previousEntityToRemove = this->getEntityToRemove();
	if (previousEntityToRemove != entityToRemove) {
		this->entityToRemove = entityToRemove;
	}
}

}
