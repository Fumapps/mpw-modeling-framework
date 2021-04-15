/*
 * This file is generated. Do not change it manually.
 */

#include "GameViewModel.h"

#include <stdexcept>

#include "ViewModelCell.h"

namespace viewmodel {

GameViewModel::GameViewModel() {

}

GameViewModel::~GameViewModel() = default;

framework::ObservableListProperty<viewmodel::ViewModelRow>& GameViewModel::rowsProperty() noexcept {
	return this->rows;
}
const framework::ObservableListProperty<viewmodel::ViewModelRow>& GameViewModel::rowsProperty() const noexcept {
	return this->rows;
}

framework::ObservableListProperty<viewmodel::ViewModelLogEntry>& GameViewModel::logEntriesProperty() noexcept {
	return this->logEntries;
}
const framework::ObservableListProperty<viewmodel::ViewModelLogEntry>& GameViewModel::logEntriesProperty() const noexcept {
	return this->logEntries;
}

framework::ObservablePrimitiveProperty<mpw::Size>& GameViewModel::sizeProperty() noexcept {
	return this->size;
}
const framework::ObservablePrimitiveProperty<mpw::Size>& GameViewModel::sizeProperty() const noexcept {
	return this->size;
}

framework::ObservablePrimitiveProperty<bool>& GameViewModel::playButtonEnabledProperty() noexcept {
	return this->playButtonEnabled;
}
const framework::ObservablePrimitiveProperty<bool>& GameViewModel::playButtonEnabledProperty() const noexcept {
	return this->playButtonEnabled;
}

framework::ObservablePrimitiveProperty<bool>& GameViewModel::pauseButtonEnabledProperty() noexcept {
	return this->pauseButtonEnabled;
}
const framework::ObservablePrimitiveProperty<bool>& GameViewModel::pauseButtonEnabledProperty() const noexcept {
	return this->pauseButtonEnabled;
}

framework::ObservablePrimitiveProperty<bool>& GameViewModel::undoButtonEnabledProperty() noexcept {
	return this->undoButtonEnabled;
}
const framework::ObservablePrimitiveProperty<bool>& GameViewModel::undoButtonEnabledProperty() const noexcept {
	return this->undoButtonEnabled;
}

framework::ObservablePrimitiveProperty<bool>& GameViewModel::redoButtonEnabledProperty() noexcept {
	return this->redoButtonEnabled;
}
const framework::ObservablePrimitiveProperty<bool>& GameViewModel::redoButtonEnabledProperty() const noexcept {
	return this->redoButtonEnabled;
}

framework::ObservablePrimitiveProperty<double>& GameViewModel::speedProperty() noexcept {
	return this->speed;
}
const framework::ObservablePrimitiveProperty<double>& GameViewModel::speedProperty() const noexcept {
	return this->speed;
}

framework::ObjectListView<viewmodel::ViewModelRow>& GameViewModel::getRows() noexcept {
	return this->rows;
}

const framework::ObjectListView<viewmodel::ViewModelRow>& GameViewModel::getRows() const noexcept {
	return this->rows;
}

framework::ObjectListView<viewmodel::ViewModelLogEntry>& GameViewModel::getLogEntries() noexcept {
	return this->logEntries;
}

const framework::ObjectListView<viewmodel::ViewModelLogEntry>& GameViewModel::getLogEntries() const noexcept {
	return this->logEntries;
}

mpw::Size GameViewModel::getSize() noexcept {
	return this->size.get();
}

mpw::Size GameViewModel::getSize() const noexcept {
	return this->size.get();
}

bool GameViewModel::getPlayButtonEnabled() noexcept {
	return this->playButtonEnabled.get();
}

bool GameViewModel::getPlayButtonEnabled() const noexcept {
	return this->playButtonEnabled.get();
}

bool GameViewModel::getPauseButtonEnabled() noexcept {
	return this->pauseButtonEnabled.get();
}

bool GameViewModel::getPauseButtonEnabled() const noexcept {
	return this->pauseButtonEnabled.get();
}

bool GameViewModel::getUndoButtonEnabled() noexcept {
	return this->undoButtonEnabled.get();
}

bool GameViewModel::getUndoButtonEnabled() const noexcept {
	return this->undoButtonEnabled.get();
}

bool GameViewModel::getRedoButtonEnabled() noexcept {
	return this->redoButtonEnabled.get();
}

bool GameViewModel::getRedoButtonEnabled() const noexcept {
	return this->redoButtonEnabled.get();
}

double GameViewModel::getSpeed() noexcept {
	return this->speed.get();
}

double GameViewModel::getSpeed() const noexcept {
	return this->speed.get();
}

void GameViewModel::addToRows(
		std::shared_ptr<viewmodel::ViewModelRow> row) noexcept {
	if (this->rowsLookup.find(row.get()) == this->rowsLookup.end()) {
		this->rows.add(row);
		this->rowsLookup.insert(row.get());
	}
}
void GameViewModel::removeFromRows(
		std::shared_ptr<viewmodel::ViewModelRow> row) noexcept {
	if (this->rowsLookup.find(row.get()) != this->rowsLookup.end()) {
		this->rows.remove(row);
		this->rowsLookup.erase(row.get());
	}
}

void GameViewModel::clearRows() noexcept {
	while (!this->rows.empty()) {
		removeFromRows(this->rows.front());
	}
}

void GameViewModel::addToLogEntries(
		std::shared_ptr<viewmodel::ViewModelLogEntry> logEntry) noexcept {
	if (this->logEntriesLookup.find(logEntry.get())
			== this->logEntriesLookup.end()) {
		this->logEntries.add(logEntry);
		this->logEntriesLookup.insert(logEntry.get());
	}
}
void GameViewModel::removeFromLogEntries(
		std::shared_ptr<viewmodel::ViewModelLogEntry> logEntry) noexcept {
	if (this->logEntriesLookup.find(logEntry.get())
			!= this->logEntriesLookup.end()) {
		this->logEntries.remove(logEntry);
		this->logEntriesLookup.erase(logEntry.get());
	}
}

void GameViewModel::clearLogEntries() noexcept {
	while (!this->logEntries.empty()) {
		removeFromLogEntries(this->logEntries.front());
	}
}

void GameViewModel::setSize(mpw::Size size) noexcept {
	auto previousSize = this->getSize();
	if (previousSize != size) {
		this->size.set(size);
	}
}

void GameViewModel::setPlayButtonEnabled(bool playButtonEnabled) noexcept {
	this->playButtonEnabled.set(playButtonEnabled);
}

void GameViewModel::setPauseButtonEnabled(bool pauseButtonEnabled) noexcept {
	this->pauseButtonEnabled.set(pauseButtonEnabled);
}

void GameViewModel::setUndoButtonEnabled(bool undoButtonEnabled) noexcept {
	this->undoButtonEnabled.set(undoButtonEnabled);
}

void GameViewModel::setRedoButtonEnabled(bool redoButtonEnabled) noexcept {
	this->redoButtonEnabled.set(redoButtonEnabled);
}

void GameViewModel::setSpeed(double speed) noexcept {
	this->speed.set(speed);
}

}
