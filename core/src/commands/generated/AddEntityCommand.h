/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ADDENTITYCOMMAND_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ADDENTITYCOMMAND_H

#include <memory>
#include <string>
#include "PrimitiveCommand.h"

namespace basetypes {
class Entity;
}

namespace commands {

/**
 * A primitive command which adds an entity to a collection property.
 */
class AddEntityCommand: public commands::PrimitiveCommand {

private:

	using inherited = PrimitiveCommand;

	std::shared_ptr<basetypes::Entity> entityToAdd;

public:

	AddEntityCommand();

	/// \brief returns a shared_ptr of type AddEntityCommand which shares ownership of *this
	std::shared_ptr<AddEntityCommand> shared_from_this() {
		return std::dynamic_pointer_cast < AddEntityCommand
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type AddEntityCommand which shares ownership of *this
	std::shared_ptr<const AddEntityCommand> shared_from_this() const {
		return std::dynamic_pointer_cast<const AddEntityCommand>(
				inherited::shared_from_this());
	}

	virtual std::shared_ptr<basetypes::Entity> getEntityToAdd() noexcept;
	virtual std::shared_ptr<const basetypes::Entity> getEntityToAdd() const noexcept;

	virtual void setEntityToAdd(
			std::shared_ptr<basetypes::Entity> entityToAdd) noexcept;

public:

	virtual ~AddEntityCommand() = 0;

	static constexpr unsigned cFeatureKeyEntityToAdd = 4;
	using PrimitiveCommand::cFeatureKeyEntity;
	using PrimitiveCommand::cFeatureKeyPropertyName;
	using PrimitiveCommand::cFeatureKeyFeatureKey;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ADDENTITYCOMMAND_H

