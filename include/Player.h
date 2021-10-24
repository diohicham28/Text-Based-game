/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <Character.h>


class Player : public Character {
 public:
  Player();
  Player(int);
  virtual ~Player();

  void healthUp();
  void healthDown();

  /**
  * Saves a panel to the ofstream in Serializer.
  * @param s The Serializer that handles the saving.
  */
  virtual void save(Serializer*);

  /**
  * Loads a panel from the ifstream in DeSerializer.
  * @param d The Deserializer that handles the loading.
  */
  virtual void load(DeSerializer*, World*);

 private:
  int health;
};
#endif // PLAYER_H
