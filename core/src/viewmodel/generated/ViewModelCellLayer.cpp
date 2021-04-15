/*
 * This file is generated. Do not change it manually.
 */

#include "ViewModelCellLayer.h"

#include <stdexcept>

namespace viewmodel {

ViewModelCellLayer::ViewModelCellLayer() {

}

framework::ObservablePrimitiveProperty<std::string>& ViewModelCellLayer::imageNameProperty() noexcept {
	return this->imageName;
}
const framework::ObservablePrimitiveProperty<std::string>& ViewModelCellLayer::imageNameProperty() const noexcept {
	return this->imageName;
}

framework::ObservablePrimitiveProperty<int>& ViewModelCellLayer::rotationProperty() noexcept {
	return this->rotation;
}
const framework::ObservablePrimitiveProperty<int>& ViewModelCellLayer::rotationProperty() const noexcept {
	return this->rotation;
}

framework::ObservablePrimitiveProperty<bool>& ViewModelCellLayer::visibleProperty() noexcept {
	return this->visible;
}
const framework::ObservablePrimitiveProperty<bool>& ViewModelCellLayer::visibleProperty() const noexcept {
	return this->visible;
}

const std::string& ViewModelCellLayer::getImageName() noexcept {
	return this->imageName.get();
}

const std::string& ViewModelCellLayer::getImageName() const noexcept {
	return this->imageName.get();
}

int ViewModelCellLayer::getRotation() noexcept {
	return this->rotation.get();
}

int ViewModelCellLayer::getRotation() const noexcept {
	return this->rotation.get();
}

bool ViewModelCellLayer::getVisible() noexcept {
	return this->visible.get();
}

bool ViewModelCellLayer::getVisible() const noexcept {
	return this->visible.get();
}

void ViewModelCellLayer::setImageName(std::string imageName) noexcept {
	this->imageName.set(imageName);
}

void ViewModelCellLayer::setRotation(int rotation) noexcept {
	this->rotation.set(rotation);
}

void ViewModelCellLayer::setVisible(bool visible) noexcept {
	this->visible.set(visible);
}

}
