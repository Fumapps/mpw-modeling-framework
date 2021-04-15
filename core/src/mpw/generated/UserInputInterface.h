/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_USERINPUTINTERFACE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_USERINPUTINTERFACE_H

#include <memory>
#include <string>
#include <exception>

namespace mpw {

/**
 * Interface to interact with a UI or mock object for reading values from the user.
 * Warning: subclasses of this interface must support multithreading. <code>readInteger</code>,
 * <code>readString</code> and <code>confirmAlert</code> may be invoked from different threads before
 * the previous invocation returned. It is guaranteed that in this case, <code>abort</code> is called
 * before the next invocation.
 */
class UserInputInterface: public std::enable_shared_from_this<UserInputInterface> {

public:

	virtual ~UserInputInterface() = default;

	/**
	 * Read an integer value from a user. This blocks until there is
	 * an integer to return or it is aborted.
	 * This must be thread safe
	 * @param message The message used in the prompt for the number.
	 * @return The integer value read or an empty optional, if aborted.
	 */
	virtual int readInteger(std::string message) = 0;

	/**
	 * Read a string value from a user. This blocks until there is a
	 * String to return or it is aborted
	 * This must be thread safe
	 * @param message The message used in the prompt for the string.
	 * @return The string value read or an empty optional, if aborted.
	 */
	virtual std::string readString(std::string message) = 0;

	/**
	 * Inform a user about an abnormal execution aborting.
	 * This blocks until it returns or is aborted
	 * This must be thread safe
	 * @param t The throwable which lead to aborting the program.
	 */
	virtual void confirmAlert(const std::exception &t) = 0;

	/**
	 * Aborts readInteger, readString or confirmAlert. This is used due to multi ui systems,
	 * where every dialog could return first. Because only one dialog is able to return a
	 * value, all other dialogs can be aborted.<br>
	 * This must be thread-safe.
	 * May be called multiple times, even if no input is pending
	 */
	virtual void abort() = 0;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_USERINPUTINTERFACE_H

