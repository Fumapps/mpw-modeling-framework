/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_TILECONTENT_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_TILECONTENT_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "Entity.h"

namespace mpw {
class Tile;
}
namespace mpw {
class Stage;
}

namespace mpw {

/**
 * Base class for entities, which can be placed as contents on a tile.
 * 
 * It has two sub types: Actor and Prop.
 */
class TileContent: public virtual basetypes::Entity {

private:

	framework::ObservableObjectReferenceProperty<Tile> currentTile;

	framework::ObservableObjectReferenceProperty<Stage> stage;

public:

	TileContent();

	/// \brief returns a shared_ptr of type TileContent which shares ownership of *this
	std::shared_ptr<TileContent> shared_from_this() {
		return std::dynamic_pointer_cast < TileContent
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type TileContent which shares ownership of *this
	std::shared_ptr<const TileContent> shared_from_this() const {
		return std::dynamic_pointer_cast<const TileContent>(
				basetypes::Entity::shared_from_this());
	}

	virtual framework::ObservableObjectProperty<mpw::Tile>& currentTileProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Tile>& currentTileProperty() const noexcept;

	virtual framework::ObservableObjectProperty<mpw::Stage>& stageProperty() noexcept;
	virtual const framework::ObservableObjectProperty<mpw::Stage>& stageProperty() const noexcept;

	virtual std::shared_ptr<mpw::Tile> getCurrentTile() noexcept;
	virtual std::shared_ptr<const mpw::Tile> getCurrentTile() const noexcept;

	virtual std::shared_ptr<mpw::Stage> getStage() noexcept;
	virtual std::shared_ptr<const mpw::Stage> getStage() const noexcept;

	virtual void setCurrentTile(std::shared_ptr<mpw::Tile> currentTile) noexcept;

	virtual void setStage(std::shared_ptr<mpw::Stage> stage) noexcept;

public:

	virtual ~TileContent() = 0;

	static constexpr unsigned cFeatureKeyCurrentTile = 1;
	static constexpr unsigned cFeatureKeyStage = 2;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_TILECONTENT_H

