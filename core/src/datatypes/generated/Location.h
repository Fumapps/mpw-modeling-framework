
#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_LOCATION_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_LOCATION_H

#include <cstddef>
#include <functional>

namespace mpw {

struct Location final {

private:

	int column = 0;
	int row = 0;

public:

	Location() = default;

	Location(int column, int row);

	inline int getColumn() const {
		return this->column;
	}
	inline void setColumn(int column) {
		this->column = column;
	}
	inline int getRow() const {
		return this->row;
	}
	inline void setRow(int row) {
		this->row = row;
	}

	friend bool operator==(const Location &lhs, const Location &rhs);

	friend bool operator!=(const Location &lhs, const Location &rhs);

	friend std::size_t hash_value(const Location &obj);

	inline static Location from(int column, int row) {
		return Location(column, row);
	}
};

}

namespace std {
template<> struct hash<mpw::Location> {
	std::size_t operator()(const mpw::Location &object) const noexcept {
		return hash_value(object);
	}
};
}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_LOCATION_H

