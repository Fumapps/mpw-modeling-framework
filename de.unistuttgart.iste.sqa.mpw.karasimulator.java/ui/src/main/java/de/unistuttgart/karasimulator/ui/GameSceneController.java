package de.unistuttgart.karasimulator.ui;

import de.unistuttgart.kara.mpw.LogEntry;
import de.unistuttgart.kara.viewmodel.GameViewInput;
import de.unistuttgart.kara.viewmodel.GameViewModel;
import de.unistuttgart.kara.viewmodel.ViewModelLogEntry;
import javafx.application.Platform;
import javafx.beans.property.ReadOnlyListProperty;
import javafx.collections.ListChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Parent;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;

public class GameSceneController {

    class CellFormat extends ListCell<ViewModelLogEntry> {
        @Override
        protected void updateItem(final ViewModelLogEntry logEntry, final boolean empty) {
            Platform.runLater(() -> {
                super.updateItem(logEntry, empty);
                if (empty || logEntry == null) {
                    setText(null);
                } else {
                    setText(logEntry.getMessage());
                    setTextFill(ViewModelColorConverter.toJavaFxColor(logEntry.getColor()));
                }
            });
        }
    }

    @FXML private BorderPane root;
    @FXML private ToolBar toolbar;
    @FXML private Button play;
    @FXML private Button pause;
    @FXML private Button undo;
    @FXML private Button redo;
    @FXML private Slider speed;
    @FXML private KaraWorldGrid karaGrid;
    @FXML private SplitPane splitPane;
    @FXML private ListView<ViewModelLogEntry> log;

    private GameViewInput gameViewInput;

    @FXML
    private void initialize() {
    }

    @FXML
    void pauseGame(final ActionEvent event) {
        new Thread(gameViewInput::pauseClicked).start();
    }

    @FXML
    void undo(final ActionEvent event) {
        new Thread(gameViewInput::undoClicked).start();
    }

    @FXML
    void redo(final ActionEvent event) {
        new Thread(gameViewInput::redoClicked).start();
    }

    @FXML
    void startGame(final ActionEvent event) {
        new Thread(gameViewInput::playClicked).start();
    }

    @SuppressWarnings("unchecked")
    public void connectToGame(final GameViewInput gameViewInput, final GameViewModel gameViewModel) {
        this.gameViewInput = gameViewInput;
        this.karaGrid.bindToViewModel(gameViewModel);

        /*this.play.disableProperty().bind(gameViewInput.modeProperty().isNotEqualTo(Mode.PAUSED));
        this.pause.disableProperty().bind(gameViewInput.modeProperty().isNotEqualTo(Mode.RUNNING));
        this.undo.disableProperty().bind(this.gameViewInput.canUndoProperty().not());
        this.redo.disableProperty().bind(this.gameViewInput.canRedoProperty().not());
        this.speed.valueProperty().bindBidirectional(this.gameViewInput.speedProperty());*/
        this.log.setCellFactory(list -> new CellFormat());
        this.log.itemsProperty().bind(gameViewModel.logEntriesProperty());
        this.log.getItems().addListener((ListChangeListener<ViewModelLogEntry>) changeListener -> {
            changeListener.next();
            final int size = log.getItems().size();
            if (size > 1) {
                JavaFXUtil.blockingExecuteOnFXThread(() -> {
                    final Parent virtualFlow = (Parent) log.getChildrenUnmodifiable().get(0);
                    final Parent group = (Parent) virtualFlow.getChildrenUnmodifiable().get(1);
                    final Parent cell = (Parent) group.getChildrenUnmodifiable().get(0);
                    final ListCell<LogEntry> listCell = (ListCell<LogEntry>) cell;
                    final int visibleCells = (int) (log.getHeight() / listCell.getHeight());
                    log.scrollTo(Math.max(0, size - visibleCells));
                });
            }
        });
    }

}

