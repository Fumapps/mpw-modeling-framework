/*
 * This file is generated. Do not change it manually.
 */

#include "LogEntry.h"

#include <stdexcept>

#include "Actor.h"

namespace mpw {

LogEntry::LogEntry() {

}

framework::ObservablePrimitiveProperty<std::string>& LogEntry::messageProperty() noexcept {
	return this->message;
}
const framework::ObservablePrimitiveProperty<std::string>& LogEntry::messageProperty() const noexcept {
	return this->message;
}

framework::ObservableObjectProperty<mpw::Actor>& LogEntry::actorProperty() noexcept {
	return this->actor;
}
const framework::ObservableObjectProperty<mpw::Actor>& LogEntry::actorProperty() const noexcept {
	return this->actor;
}

const std::string& LogEntry::getMessage() noexcept {
	return this->message.get();
}

const std::string& LogEntry::getMessage() const noexcept {
	return this->message.get();
}

std::shared_ptr<mpw::Actor> LogEntry::getActor() noexcept {
	return this->actor.get();
}

std::shared_ptr<const mpw::Actor> LogEntry::getActor() const noexcept {
	return this->actor.get();
}

void LogEntry::setMessage(std::string message) noexcept {
	this->message.set(message);
}

void LogEntry::setActor(std::shared_ptr<mpw::Actor> actor) noexcept {
	auto previousActor = this->getActor();
	if (previousActor != actor) {
		this->actor.set(actor);
	}
}

void LogEntry::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	case cFeatureKeyMessage: {

		auto typedValue = std::get < std::string > (value);
		setMessage(typedValue);

		return;
	}
	case cFeatureKeyActor: {

		auto reference = std::get < EntityReference > (value);
		auto typedElement =
				dynamic_cast<Actor*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr =
				typedElement != nullptr ? typedElement->shared_from_this() :
						nullptr;
		setActor(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void LogEntry::addToCollection(unsigned featureKey, EntityReference reference) {
	switch (featureKey) {
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void LogEntry::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

}
