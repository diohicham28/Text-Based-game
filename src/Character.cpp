/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <vector>
#include "Character.h"
#include "Location.h"

Character::Character() {
  //ctor
}

Character::Character(int code) {
  objectCode = code;
}

Character::~Character() {
  //dtor
}

Location* Character::getCurrentLocation() {
  return currentLocation;
}

void Character::setCurrentLocation(Location* loc) {
  currentLocation = loc;
}

void Character::dropItem(Item* item) {
  Container* ground = &this->currentLocation->container;
  this->container.transfer(ground, item);
}

void Character::takeItem(Item* item) {
  Container* ground = &(this->currentLocation->container);
  ground->transfer(&(this->container), item);
}

std::vector<Item*> Character::getBag() {
  return container.getItemsList();
}

void Character::save(Serializer* s) {
  this->GamePanel::save(s);
  container.save(s);
}

void Character::load(DeSerializer* d, World* w) {
  this->GamePanel::load(d, w);
  container.load(d, w);
}
