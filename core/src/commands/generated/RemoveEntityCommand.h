/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_REMOVEENTITYCOMMAND_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_REMOVEENTITYCOMMAND_H

#include <memory>
#include <string>
#include "PrimitiveCommand.h"

namespace basetypes {
class Entity;
}

namespace commands {

/**
 * A primitive command which removes an entity from a collection property.
 */
class RemoveEntityCommand: public commands::PrimitiveCommand {

private:

	using inherited = PrimitiveCommand;

	std::shared_ptr<basetypes::Entity> entityToRemove;

public:

	RemoveEntityCommand();

	/// \brief returns a shared_ptr of type RemoveEntityCommand which shares ownership of *this
	std::shared_ptr<RemoveEntityCommand> shared_from_this() {
		return std::dynamic_pointer_cast < RemoveEntityCommand
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type RemoveEntityCommand which shares ownership of *this
	std::shared_ptr<const RemoveEntityCommand> shared_from_this() const {
		return std::dynamic_pointer_cast<const RemoveEntityCommand>(
				inherited::shared_from_this());
	}

	virtual std::shared_ptr<basetypes::Entity> getEntityToRemove() noexcept;
	virtual std::shared_ptr<const basetypes::Entity> getEntityToRemove() const noexcept;

	virtual void setEntityToRemove(
			std::shared_ptr<basetypes::Entity> entityToRemove) noexcept;

public:

	virtual ~RemoveEntityCommand() = 0;

	static constexpr unsigned cFeatureKeyEntityToRemove = 4;
	using PrimitiveCommand::cFeatureKeyEntity;
	using PrimitiveCommand::cFeatureKeyPropertyName;
	using PrimitiveCommand::cFeatureKeyFeatureKey;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_REMOVEENTITYCOMMAND_H

