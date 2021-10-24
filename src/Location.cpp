/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <vector>
#include "../include/Location.h"

Location::Location() {
  Xcoord = 0;
  Ycoord = 0;
  beenHereBefore = 0;
}

Location::Location(int code) {
  objectCode = code;
  Xcoord = 0;
  Ycoord = 0;
  beenHereBefore = 0;
}

Location::~Location() {
  //dtor
}

int Location::getX() {
  return Xcoord;
}

int Location::getY() {
  return Ycoord;
}

bool Location::hasBeenHere() {
  return beenHereBefore;
}

void Location::setBeenHere(bool b) {
  beenHereBefore = b;
}

bool Location::isLocked() {
  return locked;
}

std::string Location::getLockedMessage() {
  return lockedMessage;
}

void Location::setNeighbors(std::vector<Location*> v) {
  neighbors.clear();
  for (int i = 0; i < 4; i++) {
    neighbors.push_back(v[i]);
  }
}

Location* Location::getNeighbor(CompassCode direction) {
  int i = static_cast<int>(direction);
  return neighbors[i];
}

void Location::save(Serializer* s) {
  this->GamePanel::save(s);
  s->saveInt("Xcoord", Xcoord);
  s->saveInt("Ycoord", Ycoord);
  s->saveBool("beenHereBefore", beenHereBefore);
  container.save(s);
  s->savePointer("itemToEnter", itemToEnter);
  s->saveBool("locked", locked);
  s->savePointer("npc", npc);
  s->saveString("lockedMessage", lockedMessage);
}

void Location::load(DeSerializer* d, World* w) {
  this->GamePanel::load(d, w);
  Xcoord = d->loadInt("Xcoord");
  Ycoord = d->loadInt("Ycoord");
  beenHereBefore = d->loadBool("beenHereBefore");
  container.load(d, w);
  itemToEnter = dynamic_cast<Item*>(d->loadPointer("itemToEnter", w));
  locked = d->loadBool("locked");
  npc = dynamic_cast<NPC*>(d->loadPointer("npc", w));
  lockedMessage = d->loadString("lockedMessage");
}
