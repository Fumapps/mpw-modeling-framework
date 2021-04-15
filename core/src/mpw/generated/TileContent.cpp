/*
 * This file is generated. Do not change it manually.
 */

#include "TileContent.h"

#include <stdexcept>

#include "Tile.h"
#include "Stage.h"

namespace mpw {

TileContent::TileContent() {

}

TileContent::~TileContent() = default;

framework::ObservableObjectProperty<mpw::Tile>& TileContent::currentTileProperty() noexcept {
	return this->currentTile;
}
const framework::ObservableObjectProperty<mpw::Tile>& TileContent::currentTileProperty() const noexcept {
	return this->currentTile;
}

framework::ObservableObjectProperty<mpw::Stage>& TileContent::stageProperty() noexcept {
	return this->stage;
}
const framework::ObservableObjectProperty<mpw::Stage>& TileContent::stageProperty() const noexcept {
	return this->stage;
}

std::shared_ptr<mpw::Tile> TileContent::getCurrentTile() noexcept {
	return this->currentTile.get();
}

std::shared_ptr<const mpw::Tile> TileContent::getCurrentTile() const noexcept {
	return this->currentTile.get();
}

std::shared_ptr<mpw::Stage> TileContent::getStage() noexcept {
	return this->stage.get();
}

std::shared_ptr<const mpw::Stage> TileContent::getStage() const noexcept {
	return this->stage.get();
}

void TileContent::setCurrentTile(
		std::shared_ptr<mpw::Tile> currentTile) noexcept {
	auto previousCurrentTile = this->getCurrentTile();
	if (previousCurrentTile != currentTile) {
		this->currentTile.set(currentTile);
		if (previousCurrentTile != nullptr) {
			auto thisPtr = this->shared_from_this();
			previousCurrentTile->removeFromContents(thisPtr);
		}
		if (currentTile != nullptr) {
			auto thisPtr = this->shared_from_this();
			currentTile->addToContents(thisPtr);
		}
	}
}

void TileContent::setStage(std::shared_ptr<mpw::Stage> stage) noexcept {
	auto previousStage = this->getStage();
	if (previousStage != stage) {
		this->stage.set(stage);
		if (previousStage != nullptr) {
			auto thisPtr = this->shared_from_this();
			previousStage->removeFromTileContents(thisPtr);
		}
		if (stage != nullptr) {
			auto thisPtr = this->shared_from_this();
			stage->addToTileContents(thisPtr);
		}
	}
}

void TileContent::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	case cFeatureKeyCurrentTile: {

		auto reference = std::get < EntityReference > (value);
		auto typedElement =
				dynamic_cast<Tile*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr =
				typedElement != nullptr ? typedElement->shared_from_this() :
						nullptr;
		setCurrentTile(sharedPtr);

		return;
	}
	case cFeatureKeyStage: {

		auto reference = std::get < EntityReference > (value);
		auto typedElement =
				dynamic_cast<Stage*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr =
				typedElement != nullptr ? typedElement->shared_from_this() :
						nullptr;
		setStage(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void TileContent::addToCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void TileContent::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

}
