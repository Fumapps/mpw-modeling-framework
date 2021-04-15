#include "gtest/gtest.h"

#include "Tile.h"
#include "testdoubles/ActorFake.h"
#include "testdoubles/PropFake.h"
#include "testdoubles/StageFake.h"

#include <memory>

#include "CompositeCommandBase.h"
#include "SetPropertyCommandImpl.h"
#include "AddEntityCommandImpl.h"
#include "RemoveEntityCommandImpl.h"

using namespace mpw;

/*
 * Note: this file will later be removed and replaced by "real" Undo / Property Tests.
 */

TEST(SetterTest, testSettingWestOfTile) {
    auto east = std::make_shared<Tile>();
    auto west = std::make_shared<Tile>();

    east->setWest(west);

    EXPECT_EQ(west, east->getWest());
    EXPECT_EQ(east, west->getEast());
}

TEST(ReflectionTest, testSettingLocationByReflection) {
    auto tile = std::make_shared<Tile>();

    {
        auto location = Location::from(1, 2);
        tile->setProperty(Tile::cFeatureKeyLocation, &location);
    }

    EXPECT_EQ(Location::from(1, 2), tile->getLocation());
}

class CompositeCommandDummy : public commands::CompositeCommandBase {

public:
    void execute() override {}
};

TEST(AddRemoveTest, testAddRemove) {
    auto actor = std::make_shared<ActorFake>();
    auto stage = std::make_shared<StageFake>();
    auto pStage = stage->shared_from_this();

    stage->addToTileContents(actor);
    EXPECT_EQ(1, stage->getTileContents().size());

    stage->removeFromTileContents(actor);
    EXPECT_EQ(0, stage->getTileContents().size());

    auto dummyParentCommand = std::make_shared<CompositeCommandDummy>();
    auto dummySubCommand = std::make_shared<CompositeCommandDummy>();

    dummyParentCommand->addToSubCommands(dummySubCommand);
    EXPECT_EQ(1, dummyParentCommand->getSubCommands().size());

    dummyParentCommand->removeFromSubCommands(dummySubCommand);
    EXPECT_EQ(0, dummyParentCommand->getSubCommands().size());
}

class CompositeCommandDummyTest : public testing::Test, public commands::CompositeCommandBase {
public:
    void execute() override { }

    Command& at(size_t i) {
        auto& list = getSubCommands();
        auto iter = list.begin();
        std::advance(iter, i);
        return *iter;
    }
};

TEST_F(CompositeCommandDummyTest, testPrimitiveCommands) {
    auto actor = std::make_shared<ActorFake>();
    actor->setDirection(Direction::SOUTH);
    auto stage = std::make_shared<StageFake>();
    auto tile = std::make_shared<Tile>();

    executeSetProperty(actor, Actor::cFeatureKeyDirection, (int)actor->getDirection(), (int)Direction::WEST);
    executeSetValueProperty(tile, Tile::cFeatureKeyLocation, tile->getLocation(), Location::from(1, 2));
    executeAddReference(stage, Stage::cFeatureKeyTiles, tile);

    EXPECT_EQ(Direction::WEST, actor->getDirection());
    EXPECT_EQ(Location::from(1, 2), tile->getLocation());
    EXPECT_EQ(stage->getTiles().front(), tile);

    executeSetProperty(actor, Actor::cFeatureKeyDirection, (int)actor->getDirection(), (int)Direction::NORTH);
    executeSetValueProperty(tile, Tile::cFeatureKeyLocation, tile->getLocation(), Location::from(3, 5));
    executeRemoveReference(stage, Stage::cFeatureKeyTiles, tile);

    EXPECT_EQ(Direction::NORTH, actor->getDirection());
    EXPECT_EQ(Location::from(3, 5), tile->getLocation());
    EXPECT_TRUE(stage->getTiles().empty());

    at(5).undo();
    at(4).undo();
    at(3).undo();

    EXPECT_EQ(Direction::WEST, actor->getDirection());
    EXPECT_EQ(Location::from(1, 2), tile->getLocation());
    EXPECT_EQ(stage->getTiles().front(), tile);

    at(3).redo();
    at(4).redo();
    at(5).redo();

    EXPECT_EQ(Direction::NORTH, actor->getDirection());
    EXPECT_EQ(Location::from(3, 5), tile->getLocation());
    EXPECT_TRUE(stage->getTiles().empty());

    this->undo();

    EXPECT_EQ(Direction::SOUTH, actor->getDirection());
    EXPECT_EQ(Location::from(0, 0), tile->getLocation());
    EXPECT_TRUE(stage->getTiles().empty());

    this->redo();

    EXPECT_EQ(Direction::NORTH, actor->getDirection());
    EXPECT_EQ(Location::from(3, 5), tile->getLocation());
    EXPECT_TRUE(stage->getTiles().empty());
}

TEST(PropertyTest, testProperties) {
    auto prop = std::make_shared<PropFake>();
    auto tile1 = std::make_shared<Tile>();
    auto tile2 = std::make_shared<Tile>();
    prop->setCurrentTile(tile1);
    prop->setCurrentTile(tile2);
    EXPECT_TRUE(tile1->getContents().empty());
    EXPECT_EQ(prop.get(), tile2->getContents().front().get());
    EXPECT_EQ(tile2.get(), prop->getCurrentTile().get());
}

