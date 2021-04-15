#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWMODELIMPL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWMODELIMPL_H

#include "ViewModelCell.h"
#include "GameViewModel.h"

namespace viewmodel {

class GameViewModelImpl : public GameViewModel {
private:
    using inherited = GameViewModel;

public:

    GameViewModelImpl();

    void init(mpw::Size size) override;

    std::shared_ptr<viewmodel::ViewModelCell> getCellAt(int row, int column) override;

    std::shared_ptr<const viewmodel::ViewModelCell> getCellAt(int row, int column) const override;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_GAMEVIEWMODELIMPL_H
