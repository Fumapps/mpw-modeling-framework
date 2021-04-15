/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELCELLLAYER_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELCELLLAYER_H

#include <memory>
#include <string>
#include "ObservableProperties.h"

namespace viewmodel {

/**
 * Represents a graphical layer on a cell, which uses a symbolic / logical imageName to refer to a concrete graphic, like a Hamster image.
 * With rotation and visible, it further provides information for the rendering layer how the image shall be rendered.
 */
class ViewModelCellLayer: public std::enable_shared_from_this<ViewModelCellLayer> {

private:

	framework::ObservablePrimitiveProperty<std::string> imageName;

	framework::ObservablePrimitiveProperty<int> rotation;

	framework::ObservablePrimitiveProperty<bool> visible;

public:

	ViewModelCellLayer();

	virtual framework::ObservablePrimitiveProperty<std::string>& imageNameProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<std::string>& imageNameProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<int>& rotationProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<int>& rotationProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<bool>& visibleProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<bool>& visibleProperty() const noexcept;

	virtual const std::string& getImageName() noexcept;
	virtual const std::string& getImageName() const noexcept;

	virtual int getRotation() noexcept;
	virtual int getRotation() const noexcept;

	virtual bool getVisible() noexcept;
	virtual bool getVisible() const noexcept;

	virtual void setImageName(std::string imageName) noexcept;

	virtual void setRotation(int rotation) noexcept;

	virtual void setVisible(bool visible) noexcept;

public:

	virtual ~ViewModelCellLayer() = default;

	static constexpr unsigned cFeatureKeyImageName = 1;
	static constexpr unsigned cFeatureKeyRotation = 2;
	static constexpr unsigned cFeatureKeyVisible = 3;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_VIEWMODELCELLLAYER_H

