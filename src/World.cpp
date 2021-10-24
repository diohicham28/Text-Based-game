/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include "../include/World.h"
#include "../include/Item.h"
#include "../include/Player.h"
#include "../include/NPC.h"
#include "../include/Location.h"

World::World() {
  //ctor
}

World::~World() {
  for (GamePanel* g : panelsList) {
    delete g;
  }
}

void World::createPanel(int objectCode, DeSerializer* d) {
  int classCode = objectCode / 100;
  ClassCode code = static_cast<ClassCode>(classCode);
  GamePanel* ptr;

  switch (code) {
  case ITEM:
    ptr = new Item(objectCode);
    break;
  case PLAYER:
    ptr = new Player(objectCode);
    player = dynamic_cast<Player*>(ptr);
    break;
  case NPCC:
    ptr = new NPC(objectCode);
    break;
  //case ENEMY: ptr = new Enemy(objectCode);
  //break;
  case LOCATION:
    ptr = new Location(objectCode);
    map.addLocation(dynamic_cast<Location*>(ptr));
    break;
  }

  panelsList.push_back(ptr);
  ptr->load(d, this);
}

GamePanel* World::findPanel(int code) {
  for (GamePanel* g : panelsList) {
    if (g->getObjectCode() == code) {
      return g;
    }
  }
  return nullptr; // Add Exception for Panel Not Found
}

void World::loadWorld(DeSerializer* d) {
  int numberOfPanels = d->countPanels();
  d->openFile();
  for (int i = 0; i < numberOfPanels; i++) {
    d->line();
    int code = d->loadInt("objectCode");
    this->createPanel(code, d);
  }
  d->closeFile();
  map.buildMap();
}

void World::saveWorld(Serializer* s) {
  s->openFile();
  for (GamePanel* g : panelsList) {
    g->save(s);
  }
  s->closeFile();
}
