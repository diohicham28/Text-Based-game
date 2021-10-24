/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

class DeSerializer;
class Serializer;
class Item;
class World;

class Container {
 public:
  std::vector<Item*> itemsList;

  Container();

  virtual ~Container();

  /**
  * Adds an item to the itemsList.
  * @param item A pointer to the item being added.
  */
  void addItem(Item* item);

  /**
  * Removes a specific item from the itemsList.
  * @param item The item pointer that is being removed.
  */
  void removeItem(Item* item);

  /**
  * Transfers an item from one Container to another.
  * @param transferTo The container that is gaining the item.
  * @param item The item that is being transferred.
  */
  void transfer(Container* transferTo, Item* item);

  /**
  * Gets the itemsList, a vector of Item pointers.
  * @return itemsList, a vector of all the items a container has.
  */
  std::vector<Item*> getItemsList();

  /**
  * Sets the itemsList so that it is a copy of another Item vector.
  * @param v The vector of items that is being reproduced.
  */
  void setItemsList(std::vector<Item*> v);

  /**
  * Saves the container as a list of objectCodes, representing items.
  * @param s The Serializer that is doing the saving.
  */
  void save(Serializer* s);

  /**
  * Loads a list of objectCodes, which act as pointers to items.
  * @param d The DeSerializer that is doing the loading.
  * @param w The world that is being loaded.
  */
  void load(DeSerializer* d, World* w);
};

#endif // CONTAINER_H
