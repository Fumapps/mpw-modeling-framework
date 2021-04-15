/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SETPROPERTYCOMMAND_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SETPROPERTYCOMMAND_H

#include <memory>
#include <string>
#include "Any.h"
#include "PrimitiveCommand.h"

namespace commands {

/**
 * A primitive command which sets a generic value (Object) to a property.
 */
class SetPropertyCommand: public commands::PrimitiveCommand {

private:

	using inherited = PrimitiveCommand;

	Any oldValue;

	Any newValue;

public:

	SetPropertyCommand();

	/// \brief returns a shared_ptr of type SetPropertyCommand which shares ownership of *this
	std::shared_ptr<SetPropertyCommand> shared_from_this() {
		return std::dynamic_pointer_cast < SetPropertyCommand
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type SetPropertyCommand which shares ownership of *this
	std::shared_ptr<const SetPropertyCommand> shared_from_this() const {
		return std::dynamic_pointer_cast<const SetPropertyCommand>(
				inherited::shared_from_this());
	}

	virtual Any getOldValue() noexcept;
	virtual Any getOldValue() const noexcept;

	virtual Any getNewValue() noexcept;
	virtual Any getNewValue() const noexcept;

	virtual void setOldValue(Any oldValue) noexcept;

	virtual void setNewValue(Any newValue) noexcept;

public:

	virtual ~SetPropertyCommand() = 0;

	static constexpr unsigned cFeatureKeyOldValue = 4;
	static constexpr unsigned cFeatureKeyNewValue = 5;
	using PrimitiveCommand::cFeatureKeyEntity;
	using PrimitiveCommand::cFeatureKeyPropertyName;
	using PrimitiveCommand::cFeatureKeyFeatureKey;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SETPROPERTYCOMMAND_H

