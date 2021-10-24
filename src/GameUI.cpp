/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <iostream>
#include <string>
#include <vector>
#include "../include/GameUI.h"
#include "./Game.h"

GameUI::GameUI() {}

GameUI::GameUI(Game* g) : game{g} {
  initializeVerbs();
}

GameUI::~GameUI() {}

void GameUI::initializeVerbs() {

  std::vector<std::string> lookWords {
    "look", "see", "check", "view", "examine"
  };

  std::vector<std::string> moveWords {
    "move", "travel", "go", "walk", "run",
  };

  std::vector<std::string> takeWords {
    "take", "pick", "collect", "grab", "equip", "gather"
  };

  std::vector<std::string> dropWords {
    "drop", "discard", "leave", "dump"
  };

  std::vector<std::string> useWords {
    "use", "give"
    };

  verbs.push_back(lookWords);
  verbs.push_back(moveWords);
  verbs.push_back(takeWords);
  verbs.push_back(dropWords);
  verbs.push_back(useWords);

  // IGNORE
  ignore.push_back("the");
  ignore.push_back("at");
  ignore.push_back("to");
  ignore.push_back("up");
}

std::string GameUI::getCommand() {
  std::string line;
  std::cout << ">>  ";

  std::getline(std::cin, line);
  std::cin.ignore();
  std::cout << std::endl;
  return line;
}

std::vector<std::string> GameUI::separateWords(std::string command) {
  int size = command.size();

  std::vector<std::string> words;
  std::string temp = "";
  for (int i = 0; i < size; i++) {
    if (command[i] == ' ') {
      if (temp != "") {
        words.push_back(temp);
        temp = "";
      }
    } else {
      temp += std::tolower(command[i]);
    }
  }
  if (temp != "") {
    words.push_back(temp);
  }

  return words;
}

std::vector<std::string> GameUI::removeWords(std::vector<std::string> words) {
  int numberOfWords = words.size();

  for (int i = 0; i < numberOfWords; i++) {
    for (std::string ignoreWord : ignore) {
      if (words[i] == ignoreWord) {
        words.erase(words.begin() + i);
        i--;
        numberOfWords--;
      }
    }
  }
  return words;
}

std::vector<std::string> GameUI::recombine(std::vector<std::string> words) {
  int size = words.size();

  if (size == 0 || size == 1 || size == 2) {
    return words;
  }

  std::vector<std::string> newWords;
  newWords.push_back(words[0]);

  std::string noun = "";
  for (int i = 1; i < size; i++) {
    noun += words[i];
  }

  newWords.push_back(noun);
  return newWords;
}

GameUI::InputCode GameUI::identifyVerb(std::string verb) {
  int size = verbs.size();
  for (int i = 0; i < size; i++) {
    for (std::string acceptedVerb : verbs[i]) {
      if (verb == acceptedVerb) {
        return static_cast<GameUI::InputCode>(i);
      }
    }
  }
  return GameUI::OTHER;
}

GamePanel* GameUI::identifyNoun(std::string noun, World* w) {
  // Search the player
  if (w->player->nameMatch(noun)) {
    return w->player;
  }

  // Search the player's items
  for (Item* item : w->player->getBag()) {
    if (item->nameMatch(noun)) {
      return item;
    }
  }

  // Search the current location of the player
  Location* currentLocation = w->player->getCurrentLocation();
  if (currentLocation->nameMatch(noun)) {
    return currentLocation;
  }

  // Search the current location's NPC
  if (currentLocation->npc->nameMatch(noun)) {
    return currentLocation->npc;
  }

  // Search the items of the current location

}

int GameUI::travel(std::string noun) {
  std::vector<std::string> directions {"north", "east", "south", "west"};
  bool recognized = false;
  Location::CompassCode direction;
  for (int i = 0; i < 4; i++) {
    if (noun == directions[i]) {
      recognized = true;
      direction = static_cast<Location::CompassCode>(i);
    }
  }

  if (!recognized) {
    unrecognizedCommand();
    return 0;
  }

  Location* current = game->world.player->currentLocation;
  Location* moveTo = current->getNeighbor(direction);

  if (moveTo == nullptr) {
    std::cout << "Nothing that way but ocean." << std::endl;
    return 0;
  }

  if (moveTo->isLocked()) {
    std::cout << moveTo->getLockedMessage() <<std::endl;
    return 0;
  }

  game->world.player->setCurrentLocation(moveTo);
  std::cout << moveTo->getLookMessage() << std::endl;
  return 1;
}

void GameUI::unrecognizedCommand() {
  std::cout << "I don't know what that means." << std::endl;
}

void GameUI::executeCommand(std::string command) {
  std::vector<std::string> commandWords = separateWords(command);

  for (std::string word : commandWords) {
    std::cout << "*" << word;
  }
  std::cout <<std::endl;

  commandWords = removeWords(commandWords);
  commandWords = recombine(commandWords);

  for (std::string word : commandWords) {
    std::cout << "*" << word;
  }
  std::cout <<std::endl;

  GameUI::InputCode verb = identifyVerb(commandWords[0]);

  switch (verb) {
  case GameUI::LOOK:
    break;

  case GameUI::MOVE:
    travel(commandWords[1]);
    break;

  case GameUI::TAKE:
    break;

  case GameUI::DROP:
    break;

  case GameUI::USE:
    break;

  case GameUI::OTHER:
    break;

  default:
    break;
  }
}





