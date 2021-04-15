/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELCELL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELCELL_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "ObjectListView.hpp"
#include "Location.h"
#include "ViewModelCellLayer.h"

namespace viewmodel {

/**
 * Relates to a tile in the logical MiniProgrammingWorld and therefore represents a concrete location on the game map.
 * It contains a ordered collection of ViewModelCellLayers, which represent the graphical images to be rendered.
 */
class ViewModelCell: public std::enable_shared_from_this<ViewModelCell> {

private:

	framework::ObservableObjectContainmentListProperty<ViewModelCellLayer> layers;
	/// \brief internal lookup for layers
	std::unordered_set<viewmodel::ViewModelCellLayer*> layersLookup;

	framework::ObservablePrimitiveProperty<mpw::Location> location;

public:

	ViewModelCell();

	virtual framework::ObservableListProperty<viewmodel::ViewModelCellLayer>& layersProperty() noexcept;
	virtual const framework::ObservableListProperty<
			viewmodel::ViewModelCellLayer>& layersProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<mpw::Location>& locationProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<mpw::Location>& locationProperty() const noexcept;

	virtual framework::ObjectListView<viewmodel::ViewModelCellLayer>& getLayers() noexcept;
	virtual const framework::ObjectListView<viewmodel::ViewModelCellLayer>& getLayers() const noexcept;

	virtual mpw::Location getLocation() noexcept;
	virtual mpw::Location getLocation() const noexcept;

	virtual void addToLayers(
			std::shared_ptr<viewmodel::ViewModelCellLayer> layer) noexcept;
	virtual void removeFromLayers(
			std::shared_ptr<viewmodel::ViewModelCellLayer> layer) noexcept;
	virtual void clearLayers() noexcept;

	virtual void setLocation(mpw::Location location) noexcept;

public:

	virtual ~ViewModelCell() = default;

	static constexpr unsigned cFeatureKeyLayers = 1;
	static constexpr unsigned cFeatureKeyLocation = 2;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELCELL_H

