/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <vector>
#include "Container.h"
#include "./World.h"
#include "./Item.h"
#include "./Serializer.h"
#include "./DeSerializer.h"

Container::Container() {
  //ctor
}

Container::~Container() {
  // Note: World creates and destroys all GamePanels, including Items
}

void Container::addItem(Item* item) {
  itemsList.push_back(item);
}

void Container::removeItem(Item* item) {
  int size = itemsList.size();

  for (int i = 0; i < size; i++) {
    if (itemsList[i] == item) {
      itemsList.erase(itemsList.begin() + i);
      break;
    }
  }
}

void Container::transfer(Container* transferTo, Item* item) {
  transferTo->addItem(item);
  this->removeItem(item);
}

std::vector<Item*> Container::getItemsList() {
  return itemsList;
}

void Container::setItemsList(std::vector<Item*> v) {
  itemsList.clear();
  for (Item* i : v) {
    itemsList.push_back(i);
  }
}

void Container::save(Serializer* s) {
  std::vector<GamePanel*> temp;
  for (Item* i : itemsList) {
    temp.push_back(i);
  }
  s->savePointerVector("container", temp);
}

void Container::load(DeSerializer* d, World* w) {
  std::vector<GamePanel*> panelTemp;
  panelTemp = d->loadPointerVector("container", w);
  std::vector<Item*> itemTemp;
  for (GamePanel* g : panelTemp) {
    itemTemp.push_back(dynamic_cast<Item*>(g));
  }
  this->setItemsList(itemTemp);
}
