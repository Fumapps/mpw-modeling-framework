#include "Size.h"

#include <utility>

namespace mpw {

Size::Size(int columnCount, int rowCount) : columnCount(columnCount), rowCount(
		rowCount) {
}

bool operator==(const Size &lhs, const Size &rhs) {
	if (lhs.columnCount != rhs.columnCount) {
		return false;
	}
	if (lhs.rowCount != rhs.rowCount) {
		return false;
	}
	return true;
}

bool operator!=(const Size &lhs, const Size &rhs) {
	return !(lhs == rhs);
}

std::size_t hash_value(const Size &obj) {
	std::size_t prime = 31;
	std::size_t result = 1;
	result = prime * result + std::hash<int>()(obj.columnCount);
	result = prime * result + std::hash<int>()(obj.rowCount);
	return result;
}

}

