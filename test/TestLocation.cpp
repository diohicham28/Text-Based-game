/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include<vector>

#include "gtest/gtest.h"
#include "../include/Location.h"
#include "../include/Item.h"
#include "../include/World.h"

TEST(TestLocation, objectCode) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Location* location1 = dynamic_cast<Location*>(w.findPanel(3011));
  Location* location2 = dynamic_cast<Location*>(w.findPanel(3012));

  EXPECT_EQ(3011, location1->getObjectCode());
  EXPECT_NE(3012, location1->getObjectCode());
  EXPECT_EQ(3012, location2->getObjectCode());
}

TEST(TestLocation, getNeighbors) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Location* location11 = dynamic_cast<Location*>(w.findPanel(3011));
  Location* location12 = dynamic_cast<Location*>(w.findPanel(3012));
  Location* location13 = dynamic_cast<Location*>(w.findPanel(3013));
  Location* location21 = dynamic_cast<Location*>(w.findPanel(3021));
  Location* location01 = dynamic_cast<Location*>(w.findPanel(3001));
  Location* location10 = dynamic_cast<Location*>(w.findPanel(3010));

  // NORTH
  Location* northNeighbor = location11->getNeighbor(Location::NORTH);
  EXPECT_EQ(location12->getObjectCode(), northNeighbor->getObjectCode());
  EXPECT_NE(location13->getObjectCode(), northNeighbor->getObjectCode());

  // EAST
  Location* eastNeighbor = location11->getNeighbor(Location::EAST);
  EXPECT_EQ(location21->getObjectCode(), eastNeighbor->getObjectCode());
  EXPECT_NE(location12->getObjectCode(), eastNeighbor->getObjectCode());

  // SOUTH
  Location* southNeighbor = location11->getNeighbor(Location::SOUTH);
  EXPECT_EQ(location10->getObjectCode(), southNeighbor->getObjectCode());
  EXPECT_NE(location01->getObjectCode(), southNeighbor->getObjectCode());

  // WEST
  Location* westNeighbor = location11->getNeighbor(Location::WEST);
  EXPECT_EQ(location01->getObjectCode(), westNeighbor->getObjectCode());
  EXPECT_NE(location11->getObjectCode(), westNeighbor->getObjectCode());
}

TEST(TestLocation, locationContainer) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Location* location11 = dynamic_cast<Location*>(w.findPanel(3011));
  Item* expectedItem1 = dynamic_cast<Item*>(w.findPanel(1001));
  Item* expectedItem2 = dynamic_cast<Item*>(w.findPanel(1002));
  Item* actualItem1 = location11->container.itemsList[0];

  EXPECT_EQ(expectedItem1->getObjectCode(), actualItem1->getObjectCode());
  EXPECT_NE(expectedItem2->getObjectCode(), actualItem1->getObjectCode());
}
















