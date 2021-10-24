#ifndef WORLD_H
#define WORLD_H

#include<vector>
/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include "./Serializer.h"
#include "./DeSerializer.h"
#include "./Map.h"
#include "./Player.h"

class GamePanel;

class World {
 public:
  enum ClassCode {ITEM = 10, PLAYER = 21, NPCC = 22, ENEMY = 23, LOCATION = 30};
  std::vector<GamePanel*> panelsList;
  Map map;
  Player* player;

  World();
  virtual ~World();

  void createPanel(int, DeSerializer*);
  GamePanel* findPanel(int);

  void loadWorld(DeSerializer*);
  void saveWorld(Serializer*);
};
#endif // WORLD_H
