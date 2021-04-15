#include "GameViewModelImpl.h"

#include "CollectionHelpers.hpp"

#include "ViewModelRow.h"

namespace viewmodel {

GameViewModelImpl::GameViewModelImpl() = default;

std::shared_ptr<viewmodel::ViewModelCell> GameViewModelImpl::getCellAt(
        int rowIndex, int columnIndex) {
    auto row = collectionhelpers::get_at(getRows(), rowIndex);
    auto cell = collectionhelpers::get_at(row->get()->getCells(), columnIndex);
    return cell.value();
}

std::shared_ptr<const viewmodel::ViewModelCell> GameViewModelImpl::getCellAt(
        int rowIndex, int columnIndex) const {
    auto row = collectionhelpers::get_at(getRows(), rowIndex);
    auto cell = collectionhelpers::get_at(row->get()->getCells(), columnIndex);
    return cell.value();
}

void GameViewModelImpl::init(mpw::Size size) {
    setSize(size);
    clearRows();
    for (int rowIndex = 0; rowIndex < size.getRowCount(); rowIndex++) {
        auto row = std::make_shared<ViewModelRow>();
        addToRows(row);
        for (int columnIndex = 0; columnIndex < size.getColumnCount(); columnIndex++) {
            auto cell = std::make_shared<ViewModelCell>();
            cell->setLocation(mpw::Location::from(columnIndex, rowIndex));
            row->addToCells(cell);
        }
    }
}

}

