/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include "Player.h"
#include "Location.h"

Player::Player() {
  //ctor
}

Player::Player(int code) {
  objectCode = code;
}

Player::~Player() {
  //dtor
}

void Player::healthUp() {
  health++;
}

void Player::healthDown() {
  health--;
}

void Player::save(Serializer* s) {
  this->Character::save(s);
  s->savePointer("currentLocation", currentLocation);
  s->saveInt("health", health);
}

void Player::load(DeSerializer* d, World* w) {
  this->Character::load(d, w);
  currentLocation = dynamic_cast<Location*>
                    (d->loadPointer("currentLocation", w));
  health = d->loadInt("health");
}
