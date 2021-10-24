/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <string>
#include <vector>
#include "./Serializer.h"
#include "./DeSerializer.h"

class World;
/**
* GamePanel class , a panel reference for the different names and code
*/
class GamePanel {
 public:
  /**
  * Default constructor
  */
  GamePanel();
  /**
  * Parameterized Constructor
  * @param take object the integer code number
  */
  GamePanel(int i);
  /**
  * Default destructor
  */
  virtual ~GamePanel();
  /**
  * @return return object code
  */
  int getObjectCode();
  /**
  * @return return name
  */
  std::string getName();
  /**
  * @param s set the name
  */
  void setName(std::string s);
  /**
  * @return getOtherNames vector of strings
  */
  std::vector<std::string> getOtherNames();
  /**
  * @param  v set the vector of strings
  */
  void setOtherNames(std::vector<std::string> v);
  /**
  * @return lookMessage
  */
  std::string getLookMessage();

  /**
  * @param s set the LookMessage
  */
  void setLookMessage(std::string s );
  /**
  * @return true if the names and other names matches
  */
  bool nameMatch(std::string s);

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
  int objectCode;
  std::string name;
  std::vector<std::string> otherNames;
  std::string lookMessage;
};

#endif // GAMEPANEL_H
