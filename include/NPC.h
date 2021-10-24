/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef NPC_H
#define NPC_H

#include <string>
#include <Character.h>

class NPC : public Character {
 public:
  NPC();
  NPC(int);
  virtual ~NPC();

  Item* triggerItem;
  std::string eventBeginMessage;
  std::string eventEndMessage;
  bool solved;

  void event();

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
};
#endif // NPC_H
