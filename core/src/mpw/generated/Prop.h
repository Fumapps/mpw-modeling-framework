/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_PROP_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_PROP_H

#include <memory>
#include <string>
#include "TileContent.h"

namespace mpw {

/**
 * Base class for props (requisites), which can be placed on the stage.
 * 
 * Examples of the hamster-simulator, are walls or grains.
 */
class Prop: public mpw::TileContent {

private:

	using inherited = TileContent;

public:

	Prop();

	/// \brief returns a shared_ptr of type Prop which shares ownership of *this
	std::shared_ptr<Prop> shared_from_this() {
		return std::dynamic_pointer_cast < Prop
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type Prop which shares ownership of *this
	std::shared_ptr<const Prop> shared_from_this() const {
		return std::dynamic_pointer_cast<const Prop>(
				inherited::shared_from_this());
	}

public:

	virtual ~Prop() = 0;

	using TileContent::cFeatureKeyCurrentTile;
	using TileContent::cFeatureKeyStage;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_PROP_H

