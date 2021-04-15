
#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SIZE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SIZE_H

#include <cstddef>
#include <functional>

namespace mpw {

struct Size final {

private:

	int columnCount = 0;
	int rowCount = 0;

public:

	Size() = default;

	Size(int columnCount, int rowCount);

	inline int getColumnCount() const {
		return this->columnCount;
	}
	inline void setColumnCount(int columnCount) {
		this->columnCount = columnCount;
	}
	inline int getRowCount() const {
		return this->rowCount;
	}
	inline void setRowCount(int rowCount) {
		this->rowCount = rowCount;
	}

	friend bool operator==(const Size &lhs, const Size &rhs);

	friend bool operator!=(const Size &lhs, const Size &rhs);

	friend std::size_t hash_value(const Size &obj);

	inline static Size from(int columnCount, int rowCount) {
		return Size(columnCount, rowCount);
	}
};

}

namespace std {
template<> struct hash<mpw::Size> {
	std::size_t operator()(const mpw::Size &object) const noexcept {
		return hash_value(object);
	}
};
}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_SIZE_H

