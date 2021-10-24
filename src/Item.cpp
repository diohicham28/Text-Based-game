/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include "../include/Item.h"

Item::Item() {
  reusable = false;
}

Item::Item(int code) {
  objectCode = code;
  reusable = false;
}

Item::~Item() {
  //dtor
}

bool Item::isReusable() {
  return reusable;
}

void Item::setReusable(bool b) {
  reusable = b;
}

void Item::save(Serializer* s) {
  this->GamePanel::save(s);
  s->saveBool("reusable", reusable);
}

void Item::load(DeSerializer* d, World* w) {
  this->GamePanel::load(d, w);
  reusable = d->loadBool("reusable");
}
