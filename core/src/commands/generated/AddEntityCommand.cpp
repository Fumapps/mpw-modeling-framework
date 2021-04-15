/*
 * This file is generated. Do not change it manually.
 */

#include "AddEntityCommand.h"

#include <stdexcept>

#include "Entity.h"

namespace commands {

AddEntityCommand::AddEntityCommand() {

}

AddEntityCommand::~AddEntityCommand() = default;

std::shared_ptr<basetypes::Entity> AddEntityCommand::getEntityToAdd() noexcept {
	return this->entityToAdd;
}

std::shared_ptr<const basetypes::Entity> AddEntityCommand::getEntityToAdd() const noexcept {
	return this->entityToAdd;
}

void AddEntityCommand::setEntityToAdd(
		std::shared_ptr<basetypes::Entity> entityToAdd) noexcept {
	auto previousEntityToAdd = this->getEntityToAdd();
	if (previousEntityToAdd != entityToAdd) {
		this->entityToAdd = entityToAdd;
	}
}

}
