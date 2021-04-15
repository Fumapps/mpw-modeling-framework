/*
 * This file is generated. Do not change it manually.
 */

#include "Tile.h"

#include <stdexcept>

#include "Stage.h"

namespace mpw {

Tile::Tile() {

}

framework::ObservableListProperty<mpw::TileContent>& Tile::contentsProperty() noexcept {
	return this->contents;
}
const framework::ObservableListProperty<mpw::TileContent>& Tile::contentsProperty() const noexcept {
	return this->contents;
}

framework::ObservablePrimitiveProperty<mpw::Location>& Tile::locationProperty() noexcept {
	return this->location;
}
const framework::ObservablePrimitiveProperty<mpw::Location>& Tile::locationProperty() const noexcept {
	return this->location;
}

framework::ObservableObjectProperty<mpw::Tile>& Tile::southProperty() noexcept {
	return this->south;
}
const framework::ObservableObjectProperty<mpw::Tile>& Tile::southProperty() const noexcept {
	return this->south;
}

framework::ObservableObjectProperty<mpw::Tile>& Tile::northProperty() noexcept {
	return this->north;
}
const framework::ObservableObjectProperty<mpw::Tile>& Tile::northProperty() const noexcept {
	return this->north;
}

framework::ObservableObjectProperty<mpw::Tile>& Tile::eastProperty() noexcept {
	return this->east;
}
const framework::ObservableObjectProperty<mpw::Tile>& Tile::eastProperty() const noexcept {
	return this->east;
}

framework::ObservableObjectProperty<mpw::Tile>& Tile::westProperty() noexcept {
	return this->west;
}
const framework::ObservableObjectProperty<mpw::Tile>& Tile::westProperty() const noexcept {
	return this->west;
}

framework::ObservableObjectProperty<mpw::Stage>& Tile::stageProperty() noexcept {
	return this->stage;
}
const framework::ObservableObjectProperty<mpw::Stage>& Tile::stageProperty() const noexcept {
	return this->stage;
}

framework::ObjectListView<mpw::TileContent>& Tile::getContents() noexcept {
	return this->contents;
}

const framework::ObjectListView<mpw::TileContent>& Tile::getContents() const noexcept {
	return this->contents;
}

mpw::Location Tile::getLocation() noexcept {
	return this->location.get();
}

mpw::Location Tile::getLocation() const noexcept {
	return this->location.get();
}

std::shared_ptr<mpw::Tile> Tile::getSouth() noexcept {
	return this->south.get();
}

std::shared_ptr<const mpw::Tile> Tile::getSouth() const noexcept {
	return this->south.get();
}

std::shared_ptr<mpw::Tile> Tile::getNorth() noexcept {
	return this->north.get();
}

std::shared_ptr<const mpw::Tile> Tile::getNorth() const noexcept {
	return this->north.get();
}

std::shared_ptr<mpw::Tile> Tile::getEast() noexcept {
	return this->east.get();
}

std::shared_ptr<const mpw::Tile> Tile::getEast() const noexcept {
	return this->east.get();
}

std::shared_ptr<mpw::Tile> Tile::getWest() noexcept {
	return this->west.get();
}

std::shared_ptr<const mpw::Tile> Tile::getWest() const noexcept {
	return this->west.get();
}

std::shared_ptr<mpw::Stage> Tile::getStage() noexcept {
	return this->stage.get();
}

std::shared_ptr<const mpw::Stage> Tile::getStage() const noexcept {
	return this->stage.get();
}

void Tile::addToContents(std::shared_ptr<mpw::TileContent> content) noexcept {
	if (this->contentsLookup.find(content.get())
			== this->contentsLookup.end()) {
		this->contents.add(content);
		this->contentsLookup.insert(content.get());
		if (content != nullptr) {
			auto thisPtr = this->shared_from_this();
			content->setCurrentTile(thisPtr);
		}
	}
}
void Tile::removeFromContents(
		std::shared_ptr<mpw::TileContent> content) noexcept {
	if (this->contentsLookup.find(content.get())
			!= this->contentsLookup.end()) {
		this->contents.remove(content);
		this->contentsLookup.erase(content.get());
		if (content != nullptr && content->getCurrentTile().get() == this) {
			content->setCurrentTile(nullptr);
		}
	}
}

void Tile::clearContents() noexcept {
	while (!this->contents.empty()) {
		removeFromContents(this->contents.front());
	}
}

void Tile::setLocation(mpw::Location location) noexcept {
	auto previousLocation = this->getLocation();
	if (previousLocation != location) {
		this->location.set(location);
	}
}

void Tile::setSouth(std::shared_ptr<mpw::Tile> south) noexcept {
	auto previousSouth = this->getSouth();
	if (previousSouth != south) {
		this->south.set(south);
		if (previousSouth != nullptr
				&& previousSouth->getNorth().get() == this) {
			previousSouth->setNorth(nullptr);
		}
		if (south != nullptr) {
			auto thisPtr = this->shared_from_this();
			south->setNorth(thisPtr);
		}
	}
}

void Tile::setNorth(std::shared_ptr<mpw::Tile> north) noexcept {
	auto previousNorth = this->getNorth();
	if (previousNorth != north) {
		this->north.set(north);
		if (previousNorth != nullptr
				&& previousNorth->getSouth().get() == this) {
			previousNorth->setSouth(nullptr);
		}
		if (north != nullptr) {
			auto thisPtr = this->shared_from_this();
			north->setSouth(thisPtr);
		}
	}
}

void Tile::setEast(std::shared_ptr<mpw::Tile> east) noexcept {
	auto previousEast = this->getEast();
	if (previousEast != east) {
		this->east.set(east);
		if (previousEast != nullptr && previousEast->getWest().get() == this) {
			previousEast->setWest(nullptr);
		}
		if (east != nullptr) {
			auto thisPtr = this->shared_from_this();
			east->setWest(thisPtr);
		}
	}
}

void Tile::setWest(std::shared_ptr<mpw::Tile> west) noexcept {
	auto previousWest = this->getWest();
	if (previousWest != west) {
		this->west.set(west);
		if (previousWest != nullptr && previousWest->getEast().get() == this) {
			previousWest->setEast(nullptr);
		}
		if (west != nullptr) {
			auto thisPtr = this->shared_from_this();
			west->setEast(thisPtr);
		}
	}
}

void Tile::setStage(std::shared_ptr<mpw::Stage> stage) noexcept {
	auto previousStage = this->getStage();
	if (previousStage != stage) {
		this->stage.set(stage);
		if (previousStage != nullptr) {
			auto thisPtr = this->shared_from_this();
			previousStage->removeFromTiles(thisPtr);
		}
		if (stage != nullptr) {
			auto thisPtr = this->shared_from_this();
			stage->addToTiles(thisPtr);
		}
	}
}

void Tile::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	case cFeatureKeyLocation: {

		auto reference = std::get < ValueReference > (value);
		auto valuePtr = reinterpret_cast<Location*>(reference);
		setLocation(*valuePtr);

		return;
	}
	case cFeatureKeySouth: {

		auto reference = std::get < EntityReference > (value);
		auto typedElement =
				dynamic_cast<Tile*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr =
				typedElement != nullptr ? typedElement->shared_from_this() :
						nullptr;
		setSouth(sharedPtr);

		return;
	}
	case cFeatureKeyNorth: {

		auto reference = std::get < EntityReference > (value);
		auto typedElement =
				dynamic_cast<Tile*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr =
				typedElement != nullptr ? typedElement->shared_from_this() :
						nullptr;
		setNorth(sharedPtr);

		return;
	}
	case cFeatureKeyEast: {

		auto reference = std::get < EntityReference > (value);
		auto typedElement =
				dynamic_cast<Tile*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr =
				typedElement != nullptr ? typedElement->shared_from_this() :
						nullptr;
		setEast(sharedPtr);

		return;
	}
	case cFeatureKeyWest: {

		auto reference = std::get < EntityReference > (value);
		auto typedElement =
				dynamic_cast<Tile*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr =
				typedElement != nullptr ? typedElement->shared_from_this() :
						nullptr;
		setWest(sharedPtr);

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

void Tile::addToCollection(unsigned featureKey, EntityReference reference) {
	switch (featureKey) {
	case cFeatureKeyContents: {

		auto typedElement =
				dynamic_cast<TileContent*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		addToContents(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void Tile::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	case cFeatureKeyContents: {

		auto typedElement =
				dynamic_cast<TileContent*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		removeFromContents(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

}
