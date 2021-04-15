/*
 * This file is generated. Do not change it manually.
 */

#include "MiniProgrammingWorld.h"

#include <stdexcept>

#include "CommandStack.h"
#include "GamePerformance.h"
#include "GameLog.h"
#include "UserInputInterface.h"

#include "CommandStackImpl.h"
#include "GamePerformanceImpl.h"

#include "DummyUserInputInterface.h"

namespace mpw {

MiniProgrammingWorld::MiniProgrammingWorld() {

	this->editorCommandStack = std::make_shared<commands::CommandStackImpl>();
	this->performance = std::make_shared<mpw::GamePerformanceImpl>();
	this->gameLog = std::make_shared<mpw::GameLog>();
	this->userInputInterface = std::make_shared<mpw::DummyUserInputInterface>();
}

MiniProgrammingWorld::~MiniProgrammingWorld() = default;

std::shared_ptr<commands::CommandStack> MiniProgrammingWorld::getEditorCommandStack() noexcept {
	return this->editorCommandStack;
}

std::shared_ptr<const commands::CommandStack> MiniProgrammingWorld::getEditorCommandStack() const noexcept {
	return this->editorCommandStack;
}

std::shared_ptr<mpw::GamePerformance> MiniProgrammingWorld::getPerformance() noexcept {
	return this->performance;
}

std::shared_ptr<const mpw::GamePerformance> MiniProgrammingWorld::getPerformance() const noexcept {
	return this->performance;
}

std::shared_ptr<mpw::GameLog> MiniProgrammingWorld::getGameLog() noexcept {
	return this->gameLog;
}

std::shared_ptr<const mpw::GameLog> MiniProgrammingWorld::getGameLog() const noexcept {
	return this->gameLog;
}

std::shared_ptr<mpw::UserInputInterface> MiniProgrammingWorld::getUserInputInterface() noexcept {
	return this->userInputInterface;
}

std::shared_ptr<const mpw::UserInputInterface> MiniProgrammingWorld::getUserInputInterface() const noexcept {
	return this->userInputInterface;
}

void MiniProgrammingWorld::setUserInputInterface(
		std::shared_ptr<mpw::UserInputInterface> userInputInterface) noexcept {
	auto previousUserInputInterface = this->getUserInputInterface();
	if (previousUserInputInterface != userInputInterface) {
		this->userInputInterface = userInputInterface;
	}
}

}
