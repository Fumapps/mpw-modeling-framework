#include "gtest/gtest.h"

#include "MpwFrameworkCore.h"

#include <unordered_set>

using namespace mpw;

/// \note use 'NO-LINT' comment at tests to suppress a warning caused by TEST_F
class LocationTest : public testing::Test {
};

TEST_F(LocationTest, givenLocation0x0_whenCheckEqualsTo0x0_thenIsTrue) { /* NOLINT */
    auto sut = Location::from(0, 0);
    bool actual = sut == Location::from(0, 0);
    EXPECT_TRUE(actual);
}

TEST_F(LocationTest, givenLocation1x1_whenCheckEqualsTo2x1_thenIsFalse) { /* NOLINT */
    auto sut = Location::from(1, 1);
    bool actual = sut == Location::from(2, 1);
    EXPECT_FALSE(actual);
}

TEST_F(LocationTest, givenLocation3x5_whenPutIntoHashSet_andCheckIfSetContains3x5_thenCheckIsTrue) { /* NOLINT */
    std::unordered_set<Location> hashSet;
    hashSet.insert(Location::from(3, 5));
    bool actual = hashSet.find(Location::from(3, 5)) != hashSet.end();
    EXPECT_TRUE(actual);
}

TEST_F(LocationTest, givenLocation3x5_whenPutIntoHashSet_andCheckIfSetContains3x3_thenCheckIsFalse) { /* NOLINT */
    std::unordered_set<Location> hashSet;
    hashSet.insert(Location::from(3, 5));
    bool actual = hashSet.find(Location::from(3, 3)) != hashSet.end();
    EXPECT_FALSE(actual);
}
