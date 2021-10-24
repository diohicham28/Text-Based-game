/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <GamePanel.h>
#include "./Container.h"
#include "./Item.h"
class Location;

class Character : public GamePanel {
 public:
  Container container;
  Location* currentLocation;

  Character();

  /**
  * Constructs a Character with the specific objectCode.
  * @param code The objectCode that the Character is initialized with.
  */
  Character(int code);

  virtual ~Character();

  /**
  * Gets a pointer to the current location of a character.
  * @return The current location of the character.
  */
  Location* getCurrentLocation();

  /**
  * Moves a character, changing their current location.
  * @param loc A pointer to the new location.
  */
  void setCurrentLocation(Location* loc);

  /**
  * Removes an item from bag, adds it to Location's items.
  * @param item Pointer to item that is being dropped.
  */
  void dropItem(Item* item);

  /**
  * Takes an item from the current Location, adding to bag.
  * @param item Pointer of item that is being taken.
  */
  void takeItem(Item* item);

  /**
  * Returns the item vector of character's container.
  * @return A vector of items that the character has.
  */
  std::vector<Item*> getBag();

  /**
  * Saves a panel to the ofstream in Serializer.
  * @param s The Serializer that handles the saving.
  */
  virtual void save(Serializer* s);

  /**
  * Loads a panel from the ifstream in DeSerializer.
  * @param d The Deserializer that handles the loading.
  * @param w The world that is being loaded.
  */
  virtual void load(DeSerializer* d, World* w);
};

#endif // CHARACTER_H
