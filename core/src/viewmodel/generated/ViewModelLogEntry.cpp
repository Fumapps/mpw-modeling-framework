/*
 * This file is generated. Do not change it manually.
 */

#include "ViewModelLogEntry.h"

#include <stdexcept>

namespace viewmodel {

ViewModelLogEntry::ViewModelLogEntry() {

}

framework::ObservablePrimitiveProperty<std::string>& ViewModelLogEntry::messageProperty() noexcept {
	return this->message;
}
const framework::ObservablePrimitiveProperty<std::string>& ViewModelLogEntry::messageProperty() const noexcept {
	return this->message;
}

framework::ObservablePrimitiveProperty<viewmodel::Color>& ViewModelLogEntry::colorProperty() noexcept {
	return this->color;
}
const framework::ObservablePrimitiveProperty<viewmodel::Color>& ViewModelLogEntry::colorProperty() const noexcept {
	return this->color;
}

const std::string& ViewModelLogEntry::getMessage() noexcept {
	return this->message.get();
}

const std::string& ViewModelLogEntry::getMessage() const noexcept {
	return this->message.get();
}

viewmodel::Color ViewModelLogEntry::getColor() noexcept {
	return this->color.get();
}

viewmodel::Color ViewModelLogEntry::getColor() const noexcept {
	return this->color.get();
}

void ViewModelLogEntry::setMessage(std::string message) noexcept {
	this->message.set(message);
}

void ViewModelLogEntry::setColor(viewmodel::Color color) noexcept {
	this->color.set(color);
}

}
