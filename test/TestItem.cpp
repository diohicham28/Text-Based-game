/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "../include/Item.h"
#include "../include/World.h"

TEST(TestItem, objectCode) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Item* item1 = dynamic_cast<Item*>(w.findPanel(1001));
  Item* item2 = dynamic_cast<Item*>(w.findPanel(1002));

  EXPECT_EQ(1001, item1->getObjectCode());
  EXPECT_NE(1002, item1->getObjectCode());
  EXPECT_EQ(1002, item2->getObjectCode());
}

TEST(TestItem, name) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Item* item1 = dynamic_cast<Item*>(w.findPanel(1001));
  Item* item2 = dynamic_cast<Item*>(w.findPanel(1002));

  EXPECT_EQ("Potion", item1->getName());
  EXPECT_EQ("Sword", item2->getName());
  item1->setName("Coin");
  item2->setName("Feather");
  EXPECT_EQ("Coin", item1->getName());
  EXPECT_EQ("Feather", item2->getName());
}

TEST(TestItem, getOtherNames) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Item* item1 = dynamic_cast<Item*>(w.findPanel(1002));

  std::vector<std::string> expected;
  expected.push_back("Dagger");
  expected.push_back("Blade");
  expected.push_back("Saber");

  EXPECT_EQ(3, item1->getOtherNames().size());
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(expected[i], item1->getOtherNames()[i]);
  }
}

TEST(TestItem, setOtherNames) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Item* item1 = dynamic_cast<Item*>(w.findPanel(1002));

  std::vector<std::string> newNames;
  newNames.push_back("Apple");
  newNames.push_back("Banana");
  item1->setOtherNames(newNames);

  EXPECT_EQ(2, item1->getOtherNames().size());
  for (int i = 0; i < 2; i++) {
    EXPECT_EQ(newNames[i], item1->getOtherNames()[i]);
  }
}

TEST(TestItem, lookMessage) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Item* item1 = dynamic_cast<Item*>(w.findPanel(1001));
  Item* item2 = dynamic_cast<Item*>(w.findPanel(1002));

  EXPECT_EQ("A potion with a curious red colour.",
            item1->getLookMessage());
  EXPECT_EQ("A simple steel sword favored by knights.",
            item2->getLookMessage());
  item1->setLookMessage("Coin");
  item2->setLookMessage("Feather");
  EXPECT_EQ("Coin", item1->getLookMessage());
  EXPECT_EQ("Feather", item2->getLookMessage());
}

TEST(TestItem, reusable) {
  DeSerializer* d = new DeSerializer("./test/testSave.txt");
  World w;
  w.loadWorld(d);
  delete d;

  Item* item1 = dynamic_cast<Item*>(w.findPanel(1001));
  Item* item2 = dynamic_cast<Item*>(w.findPanel(1002));

  EXPECT_EQ(false, item1->isReusable());
  EXPECT_EQ(true, item2->isReusable());
  item1->setReusable(true);
  item2->setReusable(false);
  EXPECT_EQ(true, item1->isReusable());
  EXPECT_EQ(false, item2->isReusable());
}
