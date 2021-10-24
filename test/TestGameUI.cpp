/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include<vector>
#include "gtest/gtest.h"
#include "../include/GameUI.h"

TEST(TestGameUI, separateWords) {
  GameUI gameui;
  std::string command0 = "";
  std::string command1 = "take key";
  std::string command2 = "Take Key";

  std::vector<std::string> expected;
  EXPECT_EQ(expected, gameui.separateWords(command0));
  expected.push_back("take");
  expected.push_back("key");
  EXPECT_EQ(expected, gameui.separateWords(command1));
  EXPECT_EQ(expected, gameui.separateWords(command2));
}

TEST(TestGameUI, removeWords) {
  GameUI gameui;
  gameui.initializeVerbs();

  std::vector<std::string> before1 {"take", "the", "key"};
  std::vector<std::string> before2 {"move", "east"};
  std::vector<std::string> before3 {"move", "at", "the", "to", "up", "key"};
  // std::vector<std::string> before4 {"at", "the", "to", "up", "key"};
  // removeWords does not work on before4, need to fix

  std::vector<std::string> after1 {"take", "key"};
  std::vector<std::string> after2 {"move", "east"};
  std::vector<std::string> after3 {"move", "key"};

  EXPECT_EQ(after1, gameui.removeWords(before1));
  EXPECT_EQ(after2, gameui.removeWords(before2));
  EXPECT_EQ(after3, gameui.removeWords(before3));
}

TEST(TestGameUI, identifyVerb) {
  GameUI gameui;
  gameui.initializeVerbs();

  std::vector<std::string> lookWords {
    "look", "see", "check", "view", "examine"
  };

  std::vector<std::string> moveWords {
    "move", "travel", "go", "walk", "run"
  };

  std::vector<std::string> takeWords {
    "take", "pick", "collect", "grab", "equip", "gather"
  };

  std::vector<std::string> dropWords {
    "drop", "discard", "leave", "dump"
  };

  std::vector<std::string> otherWords {
    "dragon", "hello", "", "1"
  };

  for (std::string word : lookWords)
    EXPECT_EQ(GameUI::LOOK, gameui.identifyVerb(word));

  for (std::string word : moveWords)
    EXPECT_EQ(GameUI::MOVE, gameui.identifyVerb(word));

  for (std::string word : takeWords)
    EXPECT_EQ(GameUI::TAKE, gameui.identifyVerb(word));

  for (std::string word : dropWords)
    EXPECT_EQ(GameUI::DROP, gameui.identifyVerb(word));

  for (std::string word : otherWords)
    EXPECT_EQ(GameUI::OTHER, gameui.identifyVerb(word));
}

