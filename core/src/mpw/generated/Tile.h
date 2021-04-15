/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_TILE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_TILE_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "ObjectListView.hpp"
#include "Entity.h"
#include "Location.h"
#include "TileContent.h"

namespace mpw {
class Stage;
}

namespace mpw {

/**
 * Represents a field on the stage, where actors or props can be placed on.
 * 
 * It is connected to other tiles by its west, north, east and south references
 * to build up a mesh. Further, it defines a location, which defines the
 * column and row position of the tile.
 * 
 * It can reference up to many TileContent objects, which is the base class for actors
 * and props.
 */
class Tile: public virtual basetypes::Entity {

private:

	framework::ObservableObjectReferenceListProperty<TileContent> contents;
	/// \brief internal lookup for contents
	std::unordered_set<mpw::TileContent*> contentsLookup;

	framework::ObservablePrimitiveProperty<mpw::Location> location;

	framework::ObservableObjectReferenceProperty<Tile> south;

	framework::ObservableObjectReferenceProperty<Tile> north;

	framework::ObservableObjectReferenceProperty<Tile> east;

	framework::ObservableObjectReferenceProperty<Tile> west;

	framework::ObservableObjectReferenceProperty<Stage> stage;

public:

	Tile();

	/// \brief returns a shared_ptr of type Tile which shares ownership of *this
	std::shared_ptr<Tile> shared_from_this() {
		return std::dynamic_pointer_cast < Tile
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type Tile which shares ownership of *this
	std::shared_ptr<const Tile> shared_from_this() const {
		return std::dynamic_pointer_cast<const Tile>(
				basetypes::Entity::shared_from_this());
	}

	virtual framework::ObservableListProperty<mpw::TileContent>& contentsProperty() noexcept;
	virtual const framework::ObservableListProperty<mpw::TileContent>& contentsProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<mpw::Location>& locationProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<mpw::Location>& locationProperty() const noexcept;

	virtual framework::ObservableObjectProperty<mpw::Tile>& southProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Tile>& southProperty() const noexcept;

	virtual framework::ObservableObjectProperty<mpw::Tile>& northProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Tile>& northProperty() const noexcept;

	virtual framework::ObservableObjectProperty<mpw::Tile>& eastProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Tile>& eastProperty() const noexcept;

	virtual framework::ObservableObjectProperty<mpw::Tile>& westProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Tile>& westProperty() const noexcept;

	virtual framework::ObservableObjectProperty<mpw::Stage>& stageProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Stage>& stageProperty() const noexcept;

	virtual framework::ObjectListView<mpw::TileContent>& getContents() noexcept;
	virtual const framework::ObjectListView<mpw::TileContent>& getContents() const noexcept;

	virtual mpw::Location getLocation() noexcept;
	virtual mpw::Location getLocation() const noexcept;

	virtual std::shared_ptr<mpw::Tile> getSouth() noexcept;
	virtual std::shared_ptr<const mpw::Tile> getSouth() const noexcept;

	virtual std::shared_ptr<mpw::Tile> getNorth() noexcept;
	virtual std::shared_ptr<const mpw::Tile> getNorth() const noexcept;

	virtual std::shared_ptr<mpw::Tile> getEast() noexcept;
	virtual std::shared_ptr<const mpw::Tile> getEast() const noexcept;

	virtual std::shared_ptr<mpw::Tile> getWest() noexcept;
	virtual std::shared_ptr<const mpw::Tile> getWest() const noexcept;

	virtual std::shared_ptr<mpw::Stage> getStage() noexcept;
	virtual std::shared_ptr<const mpw::Stage> getStage() const noexcept;

	virtual void addToContents(
			std::shared_ptr<mpw::TileContent> content) noexcept;
	virtual void removeFromContents(
			std::shared_ptr<mpw::TileContent> content) noexcept;
	virtual void clearContents() noexcept;

	virtual void setLocation(mpw::Location location) noexcept;

	virtual void setSouth(std::shared_ptr<mpw::Tile> south) noexcept;

	virtual void setNorth(std::shared_ptr<mpw::Tile> north) noexcept;

	virtual void setEast(std::shared_ptr<mpw::Tile> east) noexcept;

	virtual void setWest(std::shared_ptr<mpw::Tile> west) noexcept;

	virtual void setStage(std::shared_ptr<mpw::Stage> stage) noexcept;

public:

	virtual ~Tile() = default;

	static constexpr unsigned cFeatureKeyContents = 1;
	static constexpr unsigned cFeatureKeyLocation = 2;
	static constexpr unsigned cFeatureKeySouth = 3;
	static constexpr unsigned cFeatureKeyNorth = 4;
	static constexpr unsigned cFeatureKeyEast = 5;
	static constexpr unsigned cFeatureKeyWest = 6;
	static constexpr unsigned cFeatureKeyStage = 7;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_TILE_H

