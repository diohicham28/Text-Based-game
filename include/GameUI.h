/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef GAMEUI_H
#define GAMEUI_H

#include<string>
#include<vector>

#include "./World.h"
#include "./DeSerializer.h"
class Game;

/**
* Implements a user interface
*/
class GameUI {
 public:
  enum InputCode { LOOK, MOVE, TAKE, DROP, USE, OTHER };
  Game* game;

  /**
  *   Default constructor
  */
  GameUI();

  GameUI(Game* g);

  /**
  * Default destructor
  */
  virtual ~GameUI();

  int travel(std::string noun);
  void unrecognizedCommand();

  std::string getCommand();
  void initializeVerbs();
  std::vector<std::string> separateWords(std::string);
  std::vector<std::string> removeWords(std::vector<std::string>);
  std::vector<std::string> recombine(std::vector<std::string>);
  InputCode identifyVerb(std::string);
  GamePanel* identifyNoun(std::string, World*);
  void executeCommand(std::string command);

  std::vector<std::vector<std::string>> verbs;
  std::vector<std::string> ignore;
};
#endif // GAME_H
