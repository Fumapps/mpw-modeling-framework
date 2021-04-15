/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWMODEL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWMODEL_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "ObjectListView.hpp"
#include "Size.h"
#include "ViewModelRow.h"
#include "ViewModelLogEntry.h"

namespace viewmodel {
class ViewModelCell;
}

namespace viewmodel {

/**
 * Datastructure with Databinding capabilities which contains all relevant information to be displayed on the screen.
 */
class GameViewModel: public std::enable_shared_from_this<GameViewModel> {

private:

	framework::ObservableObjectContainmentListProperty<ViewModelRow> rows;
	/// \brief internal lookup for rows
	std::unordered_set<viewmodel::ViewModelRow*> rowsLookup;

	framework::ObservableObjectContainmentListProperty<ViewModelLogEntry> logEntries;
	/// \brief internal lookup for logEntries
	std::unordered_set<viewmodel::ViewModelLogEntry*> logEntriesLookup;

	framework::ObservablePrimitiveProperty<mpw::Size> size;

	framework::ObservablePrimitiveProperty<bool> playButtonEnabled;

	framework::ObservablePrimitiveProperty<bool> pauseButtonEnabled;

	framework::ObservablePrimitiveProperty<bool> undoButtonEnabled;

	framework::ObservablePrimitiveProperty<bool> redoButtonEnabled;

	framework::ObservablePrimitiveProperty<double> speed;

public:

	GameViewModel();

	virtual framework::ObservableListProperty<viewmodel::ViewModelRow>& rowsProperty() noexcept;
	virtual const framework::ObservableListProperty<viewmodel::ViewModelRow>& rowsProperty() const noexcept;

	virtual framework::ObservableListProperty<viewmodel::ViewModelLogEntry>& logEntriesProperty() noexcept;
	virtual const framework::ObservableListProperty<viewmodel::ViewModelLogEntry>& logEntriesProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<mpw::Size>& sizeProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<mpw::Size>& sizeProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<bool>& playButtonEnabledProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<bool>& playButtonEnabledProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<bool>& pauseButtonEnabledProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<bool>& pauseButtonEnabledProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<bool>& undoButtonEnabledProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<bool>& undoButtonEnabledProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<bool>& redoButtonEnabledProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<bool>& redoButtonEnabledProperty() const noexcept;

	virtual framework::ObservablePrimitiveProperty<double>& speedProperty() noexcept;
	virtual const framework::ObservablePrimitiveProperty<double>& speedProperty() const noexcept;

	virtual framework::ObjectListView<viewmodel::ViewModelRow>& getRows() noexcept;
	virtual const framework::ObjectListView<viewmodel::ViewModelRow>& getRows() const noexcept;

	virtual framework::ObjectListView<viewmodel::ViewModelLogEntry>& getLogEntries() noexcept;
	virtual const framework::ObjectListView<viewmodel::ViewModelLogEntry>& getLogEntries() const noexcept;

	virtual mpw::Size getSize() noexcept;
	virtual mpw::Size getSize() const noexcept;

	virtual bool getPlayButtonEnabled() noexcept;
	virtual bool getPlayButtonEnabled() const noexcept;

	virtual bool getPauseButtonEnabled() noexcept;
	virtual bool getPauseButtonEnabled() const noexcept;

	virtual bool getUndoButtonEnabled() noexcept;
	virtual bool getUndoButtonEnabled() const noexcept;

	virtual bool getRedoButtonEnabled() noexcept;
	virtual bool getRedoButtonEnabled() const noexcept;

	virtual double getSpeed() noexcept;
	virtual double getSpeed() const noexcept;

	virtual void addToRows(
			std::shared_ptr<viewmodel::ViewModelRow> row) noexcept;
	virtual void removeFromRows(
			std::shared_ptr<viewmodel::ViewModelRow> row) noexcept;
	virtual void clearRows() noexcept;

	virtual void addToLogEntries(
			std::shared_ptr<viewmodel::ViewModelLogEntry> logEntry) noexcept;
	virtual void removeFromLogEntries(
			std::shared_ptr<viewmodel::ViewModelLogEntry> logEntry) noexcept;
	virtual void clearLogEntries() noexcept;

	virtual void setSize(mpw::Size size) noexcept;

	virtual void setPlayButtonEnabled(bool playButtonEnabled) noexcept;

	virtual void setPauseButtonEnabled(bool pauseButtonEnabled) noexcept;

	virtual void setUndoButtonEnabled(bool undoButtonEnabled) noexcept;

	virtual void setRedoButtonEnabled(bool redoButtonEnabled) noexcept;

	virtual void setSpeed(double speed) noexcept;

public:

	virtual ~GameViewModel() = 0;

	virtual std::shared_ptr<viewmodel::ViewModelCell> getCellAt(int row,
			int column) = 0;
	virtual std::shared_ptr<const viewmodel::ViewModelCell> getCellAt(int row,
			int column) const = 0;
	virtual void init(mpw::Size size) = 0;

	static constexpr unsigned cFeatureKeyRows = 1;
	static constexpr unsigned cFeatureKeyLogEntries = 2;
	static constexpr unsigned cFeatureKeySize = 3;
	static constexpr unsigned cFeatureKeyPlayButtonEnabled = 4;
	static constexpr unsigned cFeatureKeyPauseButtonEnabled = 5;
	static constexpr unsigned cFeatureKeyUndoButtonEnabled = 6;
	static constexpr unsigned cFeatureKeyRedoButtonEnabled = 7;
	static constexpr unsigned cFeatureKeySpeed = 8;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWMODEL_H

