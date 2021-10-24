/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <string>
#include <vector>
#include "../include/GamePanel.h"
#include "../include/World.h"

GamePanel::GamePanel() {
  objectCode = 1;
  name = "Dragon";
}

GamePanel::GamePanel(int i) {
  objectCode = i;
}

GamePanel::~GamePanel() {
  //dtor
}

int GamePanel::getObjectCode() {
  return objectCode;
}

std::string GamePanel::getName() {
  return name;
}

void GamePanel::setName(std::string s) {
  name = s;
}

std::vector<std::string> GamePanel::getOtherNames() {
  return otherNames;
}

void GamePanel::setOtherNames(std::vector<std::string> v) {
  otherNames.clear();
  for (std::string s : v) {
    otherNames.push_back(s);
  }
}

std::string GamePanel::getLookMessage() {
  return lookMessage;
}

void GamePanel::setLookMessage(std::string s) {
  lookMessage = s;
}

bool GamePanel::nameMatch(std::string s) {
  if (s == name)
    return true;

  for (std::string n : otherNames)
    if (s == n)
      return true;

  return false;
}

void GamePanel::save(Serializer* s) {
  s->line();
  s->saveInt("objectCode", objectCode);
  s->saveString("name", name);
  s->saveStringVector("otherNames", otherNames);
  s->saveString("lookMessage", lookMessage);
}

void GamePanel::load(DeSerializer* d, World*) {
  // Line is loaded by LoadGame
  // objectCode is loaded by LoadGame, because it is needed for createPanel
  name = d->loadString("name");
  this->setOtherNames(d->loadStringVector("otherNames"));
  lookMessage = d->loadString("lookMessage");
}
