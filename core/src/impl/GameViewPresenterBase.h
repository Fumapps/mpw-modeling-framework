#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GameViewPresenterBase_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GameViewPresenterBase_H

#include "GameViewModel.h"
#include "GameViewPresenter.h"
#include "ViewModelCell.h"

#include "MiniProgrammingWorld.h"
#include "Tile.h"
#include "LogEntry.h"

#include <unordered_map>

#include "Direction.h"

namespace viewmodel {

/**
 * Base class for concrete presenters, which contains common presenter
 * logic based on the MPW View-Model.
 */
class GameViewPresenterBase : public GameViewPresenter {
private:
    using inherited = GameViewPresenter;

public:

    explicit GameViewPresenterBase(std::shared_ptr<mpw::MiniProgrammingWorld> miniProgrammingWorld);

    void playClicked() override;
    void pauseClicked() override;
    void undoClicked() override;
    void redoClicked() override;
    void speedChanged(double speedValue) override;

    void close() override;

    void bind() override;

protected:

    // needs to be implemented by derived presenter classes, since here
    // no concrete Stage is available.
    virtual const framework::ObservablePrimitiveProperty<mpw::Size>& getStageSizeFromConcreteStage() = 0;

    // needs to be implemented by derived presenter classes, since here
    // no concrete Stage is available.
    virtual const framework::ObservableListProperty<mpw::Tile>& getTilesPropertyFromConcreteStage() = 0;

    virtual Color getColorForLogEntry(const mpw::LogEntry& entry) const;

    virtual void onBind();
    virtual void onSetTileNodeAtForCell(ViewModelCell& cell, const mpw::Tile& tile) = 0;

    static int getRotationForDirection(mpw::Direction direction);

private:

    void bindSize();
    void bindTiles();
    void bindGameLog();
    void bindButtons();

    void addTileNode(const mpw::Tile& tile);
    void removeTileNode(const mpw::Tile& tile);

    void setTileNodeAt(const mpw::Location& location, const mpw::Tile& tile);

    void addLogEntry(const mpw::LogEntry& entry);
    void removeLogEntry(const mpw::LogEntry& entry);
    void updateButtonEnables();

    const std::shared_ptr<mpw::MiniProgrammingWorld> miniProgrammingWorld;

    std::unordered_map<const mpw::Tile*, unsigned int> addedContentListenerIds;
    std::unordered_map<const mpw::Tile*, unsigned int> removedContentListenerIds;
    std::unordered_map<const mpw::LogEntry*, viewmodel::ViewModelLogEntry*> gameLogMapping;
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GameViewPresenterBase_H
