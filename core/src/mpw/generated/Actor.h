/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ACTOR_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ACTOR_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "TileContent.h"
#include "Direction.h"

namespace mpw {

/**
 * Represents the base class of actors in a mini programming world.
 * 
 * Usually there is only one instance per mini world, like a hamster.
 * An actor is enriched by game commands, which will be called on a dedicated actor facade to control the game.
 */
class Actor: public mpw::TileContent {

private:

	using inherited = TileContent;

	/**
	 * The looking direction of the actor.
	 */
	framework::ObservablePrimitiveProperty<mpw::Direction> direction;

public:

	Actor();

	/// \brief returns a shared_ptr of type Actor which shares ownership of *this
	std::shared_ptr<Actor> shared_from_this() {
		return std::dynamic_pointer_cast < Actor
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type Actor which shares ownership of *this
	std::shared_ptr<const Actor> shared_from_this() const {
		return std::dynamic_pointer_cast<const Actor>(
				inherited::shared_from_this());
	}

	virtual framework::ObservablePrimitiveProperty<mpw::Direction>& directionProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<mpw::Direction>& directionProperty() const noexcept;

	virtual mpw::Direction getDirection() noexcept;
	virtual mpw::Direction getDirection() const noexcept;

	virtual void setDirection(mpw::Direction direction) noexcept;

public:

	virtual ~Actor() = 0;

	static constexpr unsigned cFeatureKeyDirection = 3;
	using TileContent::cFeatureKeyCurrentTile;
	using TileContent::cFeatureKeyStage;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ACTOR_H

