/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_PRIMITIVECOMMAND_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_PRIMITIVECOMMAND_H

#include <memory>
#include <string>
#include "Command.h"

namespace basetypes {
class Entity;
}

namespace commands {

/**
 * Defines a primitive command which can set, add or removes values regarding to a property of an Entity.
 */
class PrimitiveCommand: public virtual commands::Command {

private:

	std::shared_ptr<basetypes::Entity> entity;

	std::string propertyName;

	int featureKey;

public:

	PrimitiveCommand();

	virtual std::shared_ptr<basetypes::Entity> getEntity() noexcept;
	virtual std::shared_ptr<const basetypes::Entity> getEntity() const noexcept;

	virtual const std::string& getPropertyName() noexcept;
	virtual const std::string& getPropertyName() const noexcept;

	virtual int getFeatureKey() noexcept;
	virtual int getFeatureKey() const noexcept;

	virtual void setEntity(std::shared_ptr<basetypes::Entity> entity) noexcept;

	virtual void setPropertyName(std::string propertyName) noexcept;

	virtual void setFeatureKey(int featureKey) noexcept;

public:

	virtual ~PrimitiveCommand() = 0;

	static constexpr unsigned cFeatureKeyEntity = 1;
	static constexpr unsigned cFeatureKeyPropertyName = 2;
	static constexpr unsigned cFeatureKeyFeatureKey = 3;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_PRIMITIVECOMMAND_H

