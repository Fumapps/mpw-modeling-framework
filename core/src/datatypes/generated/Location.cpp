#include "Location.h"

#include <utility>

namespace mpw {

Location::Location(int column, int row) : column(column), row(row) {
}

bool operator==(const Location &lhs, const Location &rhs) {
	if (lhs.column != rhs.column) {
		return false;
	}
	if (lhs.row != rhs.row) {
		return false;
	}
	return true;
}

bool operator!=(const Location &lhs, const Location &rhs) {
	return !(lhs == rhs);
}

std::size_t hash_value(const Location &obj) {
	std::size_t prime = 31;
	std::size_t result = 1;
	result = prime * result + std::hash<int>()(obj.column);
	result = prime * result + std::hash<int>()(obj.row);
	return result;
}

}

