/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<vector>
#include "../include/Location.h"

class Map {
 public:
  /**
  * Default constructor
  */
  Map();
  /**
  * Default destructor
  */
  virtual ~Map();
  /**
    *
    * @param location push back the different locations
    */
  void addLocation(Location* location);
  /**
    * build the map
    */
  void buildMap();
  /**
  * display the map
  */
  void displayMap();

 private:
  std::vector<Location*> locationList;
  std::vector<Location*> locationMatrix;
  int Xmin;
  int Ymin;
  int Xmax;
  int Ymax;

  int index(int, int);
  void findBoundaries();
  bool areCoordsUnique();
  bool isMapConnected();
  void connectionHelper(Location*);
};

#endif // MAP_H
