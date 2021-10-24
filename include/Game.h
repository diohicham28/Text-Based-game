/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef GAME_H
#define GAME_H

#include<string>
#include "./GameUI.h"
#include "./Serializer.h"
#include "./DeSerializer.h"
#include "./World.h"

class Game {
 public:
  World world;
  GameUI* gameui;

  Game();
  virtual ~Game();

  void play();

  /**
  * Populates world from objects in file.
  * @param file The save file path name.
  */
  void loadGame(std::string file);

  /**
  * Saves the objects of the world to a save file.
  * @param file The save file path name.
  */
  void saveGame(std::string file);

  /**
  * GamePanel find the specific object based on the code
  * @param code the specific id of the code
  */
  GamePanel* findPanel(int code);



 private:
  std::string defaultSave;
};

#endif // GAME_H
