/**
 * @author {Aaron Ackerman, Hicham Dioury, Neville Leung}
 * @date {March, 2020}
 */


#include "../include/Game.h"

#include<fstream>
#include<string>
#include<iostream>


using namespace std;

int main() {

  Game game;
  game.loadGame("./include/save1.txt");
  game.world.map.displayMap();
  game.play();
  game.saveGame("./include/save2.txt");

  return 0;
}
