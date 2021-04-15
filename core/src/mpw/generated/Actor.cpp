/*
 * This file is generated. Do not change it manually.
 */

#include "Actor.h"

#include <stdexcept>

namespace mpw {

Actor::Actor() {

}

Actor::~Actor() = default;

framework::ObservablePrimitiveProperty<mpw::Direction>& Actor::directionProperty() noexcept {
	return this->direction;
}
const framework::ObservablePrimitiveProperty<mpw::Direction>& Actor::directionProperty() const noexcept {
	return this->direction;
}

mpw::Direction Actor::getDirection() noexcept {
	return this->direction.get();
}

mpw::Direction Actor::getDirection() const noexcept {
	return this->direction.get();
}

void Actor::setDirection(mpw::Direction direction) noexcept {
	this->direction.set(direction);
}

void Actor::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	case cFeatureKeyDirection: {

		int raw = std::get<int>(value);
		auto enumValue = static_cast<Direction>(raw);
		setDirection(enumValue);

		return;
	}
	}

	inherited::setProperty(featureKey, value);
}

void Actor::addToCollection(unsigned featureKey, EntityReference reference) {
	switch (featureKey) {
	}

	inherited::addToCollection(featureKey, reference);
}

void Actor::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	inherited::removeFromCollection(featureKey, reference);
}

}
