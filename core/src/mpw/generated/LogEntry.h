/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_LOGENTRY_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_LOGENTRY_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "Entity.h"

namespace mpw {
class Actor;
}

namespace mpw {

/**
 * A log entry object represents a log message of the
 * MPW and is typically displayed in the log
 * view at the right side of a simulator window.
 */
class LogEntry: public virtual basetypes::Entity {

private:

	framework::ObservablePrimitiveProperty<std::string> message;

	framework::ObservableObjectReferenceProperty<Actor> actor;

public:

	LogEntry();

	/// \brief returns a shared_ptr of type LogEntry which shares ownership of *this
	std::shared_ptr<LogEntry> shared_from_this() {
		return std::dynamic_pointer_cast < LogEntry
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type LogEntry which shares ownership of *this
	std::shared_ptr<const LogEntry> shared_from_this() const {
		return std::dynamic_pointer_cast<const LogEntry>(
				basetypes::Entity::shared_from_this());
	}

	virtual framework::ObservablePrimitiveProperty<std::string>& messageProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<std::string>& messageProperty() const noexcept;

	virtual framework::ObservableObjectProperty<mpw::Actor>& actorProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Actor>& actorProperty() const noexcept;

	virtual const std::string& getMessage() noexcept;
	virtual const std::string& getMessage() const noexcept;

	virtual std::shared_ptr<mpw::Actor> getActor() noexcept;
	virtual std::shared_ptr<const mpw::Actor> getActor() const noexcept;

	virtual void setMessage(std::string message) noexcept;

	virtual void setActor(std::shared_ptr<mpw::Actor> actor) noexcept;

public:

	virtual ~LogEntry() = default;

	static constexpr unsigned cFeatureKeyMessage = 1;
	static constexpr unsigned cFeatureKeyActor = 2;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_LOGENTRY_H

