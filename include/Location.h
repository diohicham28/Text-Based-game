/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef LOCATION_H
#define LOCATION_H

#include<string>
#include<vector>
#include "./GamePanel.h"
#include "./Container.h"
#include "./Item.h"
#include "./NPC.h"

class Location : public GamePanel {
 public:
  enum CompassCode {NORTH, EAST, SOUTH, WEST};
  Container container;
  NPC* npc;
  bool playerHere;

  /**
  * Default constructor
  * set the coordinates to 0
  *
  */
  Location();
  Location(int);

  /**
  * Default destructor
  */
  virtual ~Location();

  /**
  * @return Xcoord
    */
  int getX();

  /**
  * @return Ycoord
  */
  int getY();

  /**
  * @return hasBeenBefore
  */
  bool hasBeenHere();

  /**
  * @param b set b to hasBeenBefore
  */
  void setBeenHere(bool b);

  bool isLocked();

  std::string getLockedMessage();

  /**
  * @param v vector<Location*> set the different locations
  */
  void setNeighbors(std::vector<Location*>v );

  Location* getNeighbor(CompassCode);

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

 private:
  std::vector<Location*> neighbors;
  int Xcoord;
  int Ycoord;
  bool beenHereBefore;
  Item* itemToEnter;
  bool locked;
  std::string lockedMessage;
};

#endif // LOCATION_H
