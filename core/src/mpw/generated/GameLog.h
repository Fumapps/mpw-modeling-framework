/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMELOG_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMELOG_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "ObjectListView.hpp"
#include "Entity.h"
#include "LogEntry.h"

namespace mpw {

/**
 * Represents a collection of log entries, which are used
 * to provide information about the game's performance.
 * 
 * It consists of LogEntry objects, which contain a message
 * and a reference to the initiating Actor. On the screen,
 * log entries are rendered to provide tracability for the
 * client.
 */
class GameLog: public virtual basetypes::Entity {

private:

	framework::ObservableObjectContainmentListProperty<LogEntry> logEntries;
	/// \brief internal lookup for logEntries
	std::unordered_set<mpw::LogEntry*> logEntriesLookup;

public:

	GameLog();

	/// \brief returns a shared_ptr of type GameLog which shares ownership of *this
	std::shared_ptr<GameLog> shared_from_this() {
		return std::dynamic_pointer_cast < GameLog
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type GameLog which shares ownership of *this
	std::shared_ptr<const GameLog> shared_from_this() const {
		return std::dynamic_pointer_cast<const GameLog>(
				basetypes::Entity::shared_from_this());
	}

	virtual framework::ObservableListProperty<mpw::LogEntry>& logEntriesProperty() noexcept;
	virtual const framework::ObservableListProperty<mpw::LogEntry>& logEntriesProperty() const noexcept;

	virtual framework::ObjectListView<mpw::LogEntry>& getLogEntries() noexcept;
	virtual const framework::ObjectListView<mpw::LogEntry>& getLogEntries() const noexcept;

	virtual void addToLogEntries(
			std::shared_ptr<mpw::LogEntry> logEntry) noexcept;
	virtual void removeFromLogEntries(
			std::shared_ptr<mpw::LogEntry> logEntry) noexcept;
	virtual void clearLogEntries() noexcept;

public:

	virtual ~GameLog() = default;

	static constexpr unsigned cFeatureKeyLogEntries = 1;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMELOG_H

