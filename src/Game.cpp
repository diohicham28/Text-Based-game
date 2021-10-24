/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <string>
#include "../include/Game.h"

Game::Game() {
  gameui = new GameUI(this);
}

Game::~Game() {
  delete gameui;
}

void Game::play() {
  std::string command = "";
  while (command != "q") {
    command = gameui->getCommand();
    gameui->executeCommand(command);
  }
}

void Game::loadGame(std::string file) {
  DeSerializer* deserial = new DeSerializer(file);
  world.loadWorld(deserial);
  delete deserial;
}

void Game::saveGame(std::string file) {
  Serializer* serial = new Serializer(file);
  world.saveWorld(serial);
  delete serial;
}

GamePanel* Game::findPanel(int code) {
  return world.findPanel(code);
}


