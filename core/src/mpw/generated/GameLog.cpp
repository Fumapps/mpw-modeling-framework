/*
 * This file is generated. Do not change it manually.
 */

#include "GameLog.h"

#include <stdexcept>

namespace mpw {

GameLog::GameLog() {

}

framework::ObservableListProperty<mpw::LogEntry>& GameLog::logEntriesProperty() noexcept {
	return this->logEntries;
}
const framework::ObservableListProperty<mpw::LogEntry>& GameLog::logEntriesProperty() const noexcept {
	return this->logEntries;
}

framework::ObjectListView<mpw::LogEntry>& GameLog::getLogEntries() noexcept {
	return this->logEntries;
}

const framework::ObjectListView<mpw::LogEntry>& GameLog::getLogEntries() const noexcept {
	return this->logEntries;
}

void GameLog::addToLogEntries(std::shared_ptr<mpw::LogEntry> logEntry) noexcept {
	if (this->logEntriesLookup.find(logEntry.get())
			== this->logEntriesLookup.end()) {
		this->logEntries.add(logEntry);
		this->logEntriesLookup.insert(logEntry.get());
	}
}
void GameLog::removeFromLogEntries(
		std::shared_ptr<mpw::LogEntry> logEntry) noexcept {
	if (this->logEntriesLookup.find(logEntry.get())
			!= this->logEntriesLookup.end()) {
		this->logEntries.remove(logEntry);
		this->logEntriesLookup.erase(logEntry.get());
	}
}

void GameLog::clearLogEntries() noexcept {
	while (!this->logEntries.empty()) {
		removeFromLogEntries(this->logEntries.front());
	}
}

void GameLog::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void GameLog::addToCollection(unsigned featureKey, EntityReference reference) {
	switch (featureKey) {
	case cFeatureKeyLogEntries: {

		auto typedElement =
				dynamic_cast<LogEntry*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		addToLogEntries(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

void GameLog::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	case cFeatureKeyLogEntries: {

		auto typedElement =
				dynamic_cast<LogEntry*>(reinterpret_cast<basetypes::Entity*>(reference));
		auto sharedPtr = typedElement->shared_from_this();
		removeFromLogEntries(sharedPtr);

		return;
	}
	}

	throw std::runtime_error(
			"property with key " + std::to_string(featureKey)
					+ " is not supported");
}

}
