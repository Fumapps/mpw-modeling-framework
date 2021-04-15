/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_DUMMYUSERINPUTINTERFACE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_DUMMYUSERINPUTINTERFACE_H

#include "UserInputInterface.h"

namespace mpw {

class DummyUserInputInterface: public UserInputInterface {
public:

	int readInteger(std::string message) override {
		throw std::runtime_error("not implemented");
	}

	std::string readString(std::string message) override {
		throw std::runtime_error("not implemented");
	}

	void confirmAlert(const std::exception &t) override {
		throw std::runtime_error("not implemented");
	}

	void abort() override {
		throw std::runtime_error("not implemented");
	}

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_DUMMYUSERINPUTINTERFACE_H

