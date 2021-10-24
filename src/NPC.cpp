/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include "NPC.h"

NPC::NPC() {
  //ctor
}

NPC::NPC(int code) {
  objectCode = code;
}

NPC::~NPC() {
  //dtor
}

void NPC::event() {
  // event
}

void NPC::save(Serializer* s) {
  this->Character::save(s);
  s->savePointer("triggerItem", triggerItem);
  s->saveString("eventBeginMessage", eventBeginMessage);
  s->saveString("eventEndMessage", eventEndMessage);
  s->saveBool("solved", solved);
}

void NPC::load(DeSerializer* d, World* w) {
  this->Character::load(d, w);
  triggerItem = dynamic_cast<Item*>(d->loadPointer("triggerItem", w));
  eventBeginMessage = d->loadString("eventBeginMessage");
  eventEndMessage = d->loadString("eventEndMessage");
  solved = d->loadBool("solved");
}
