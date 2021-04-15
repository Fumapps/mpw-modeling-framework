/*
 * This file is generated. Do not change it manually.
 */

#include "Stage.h"

#include <stdexcept>

namespace mpw {

Stage::Stage() {

}

Stage::~Stage() = default;

framework::ObservableListProperty<mpw::Tile>& Stage::tilesProperty() noexcept {
	return this->tiles;
}
const framework::ObservableListProperty<mpw::Tile>& Stage::tilesProperty() const noexcept {
	return this->tiles;
}

framework::ObservableListProperty<mpw::TileContent>& Stage::tileContentsProperty() noexcept {
	return this->tileContents;
}
const framework::ObservableListProperty<mpw::TileContent>& Stage::tileContentsProperty() const noexcept {
	return this->tileContents;
}

framework::ObservablePrimitiveProperty<mpw::Size>& Stage::stageSizeProperty() noexcept {
	return this->stageSize;
}
const framework::ObservablePrimitiveProperty<mpw::Size>& Stage::stageSizeProperty() const noexcept {
	return this->stageSize;
}

framework::ObjectListView<mpw::Tile>& Stage::getTiles() noexcept {
	return this->tiles;
}

const framework::ObjectListView<mpw::Tile>& Stage::getTiles() const noexcept {
	return this->tiles;
}

framework::ObjectListView<mpw::TileContent>& Stage::getTileContents() noexcept {
	return this->tileContents;
}

const framework::ObjectListView<mpw::TileContent>& Stage::getTileContents() const noexcept {
	return this->tileContents;
}

mpw::Size Stage::getStageSize() noexcept {
	return this->stageSize.get();
}

mpw::Size Stage::getStageSize() const noexcept {
	return this->stageSize.get();
}

void Stage::addToTiles(std::shared_ptr<mpw::Tile> tile) noexcept {
	if (this->tilesLookup.find(tile.get()) == this->tilesLookup.end()) {
		this->tiles.add(tile);
		this->tilesLookup.insert(tile.get());
		if (tile != nullptr) {
			auto thisPtr = this->shared_from_this();
			tile->setStage(thisPtr);
		}
	}
}
void Stage::removeFromTiles(std::shared_ptr<mpw::Tile> tile) noexcept {
	if (this->tilesLookup.find(tile.get()) != this->tilesLookup.end()) {
		this->tiles.remove(tile);
		this->tilesLookup.erase(tile.get());
		if (tile != nullptr && tile->getStage().get() == this) {
			tile->setStage(nullptr);
		}
	}
}

void Stage::clearTiles() noexcept {
	while (!this->tiles.empty()) {
		removeFromTiles(this->tiles.front());
	}
}

void Stage::addToTileContents(
		std::shared_ptr<mpw::TileContent> tileContent) noexcept {
	if (this->tileContentsLookup.find(tileContent.get())
			== this->tileContentsLookup.end()) {
		this->tileContents.add(tileContent);
		this->tileContentsLookup.insert(tileContent.get());
		if (tileContent != nullptr) {
			auto thisPtr = this->shared_from_this();
			tileContent->setStage(thisPtr);
		}
	}
}
void Stage::removeFromTileContents(
		std::shared_ptr<mpw::TileContent> tileContent) noexcept {
	if (this->tileContentsLookup.find(tileContent.get())
			!= this->tileContentsLookup.end()) {
		this->tileContents.remove(tileContent);
		this->tileContentsLookup.erase(tileContent.get());
		if (tileContent != nullptr && tileContent->getStage().get() == this) {
			tileContent->setStage(nullptr);
		}
	}
}

void Stage::clearTileContents() noexcept {
	while (!this->tileContents.empty()) {
		removeFromTileContents(this->tileContents.front());
	}
}

void Stage::setStageSize(mpw::Size stageSize) noexcept {
	auto previousStageSize = this->getStageSize();
	if (previousStageSize != stageSize) {
		this->stageSize.set(stageSize);
	}
}

void Stage::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	case cFeatureKeyStageSize: {

		auto reference = std::get < ValueReference > (value);
		auto valuePtr = reinterpret_cast<Size*>(reference);
		setStageSize(*valuePtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void Stage::addToCollection(unsigned featureKey, EntityReference reference) {
	switch (featureKey) {
	case cFeatureKeyTiles: {

		auto typedElement =
				dynamic_cast<Tile*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		addToTiles(sharedPtr);

		return;
	}
	case cFeatureKeyTileContents: {

		auto typedElement =
				dynamic_cast<TileContent*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		addToTileContents(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void Stage::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	case cFeatureKeyTiles: {

		auto typedElement =
				dynamic_cast<Tile*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		removeFromTiles(sharedPtr);

		return;
	}
	case cFeatureKeyTileContents: {

		auto typedElement =
				dynamic_cast<TileContent*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		removeFromTileContents(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

}
