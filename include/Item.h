#ifndef ITEM_H
#define ITEM_H

#include<string>
/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include "./GamePanel.h"

class Item : public GamePanel {
 public:
  /**
  * Default constructor
  */
  Item();
  /**
  * Parameterized Constructor
  * @param code item takes the code number
  */
  Item(int code);
  /**
  * Default destructor
  */
  virtual ~Item();
  /**
  * @return reusable
  */
  bool isReusable();
  /**
  * @param b set reusable
  */
  void setReusable(bool b);

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

 protected:
  bool reusable;
};

#endif // Item_H
