/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <vector>
#include "../include/Map.h"

Map::Map() {}

Map::~Map() {}

void Map::addLocation(Location* location) {
  locationList.push_back(location);
}

void Map::findBoundaries() {
  Xmin = 100; // Left X Boundary
  Ymin = 100; // Bottom Y Boundary
  Xmax = -100; // Right X Boundary
  Ymax = -100; // Top Y Boundary
  for (Location* loc : locationList) {
    int currentX = loc->getX();
    int currentY = loc->getY();

    if (currentX < Xmin)
      Xmin = currentX;

    if (currentY < Ymin)
      Ymin = currentY;

    if (currentX > Xmax)
      Xmax = currentX;

    if (currentY > Ymax)
      Ymax = currentY;
  }
}

bool Map::areCoordsUnique() {
  // Given here is the brute force method
  // However, if you sort first, you only have to compare partners
  int size = locationList.size();
  for (int i = 0; i < size - 1; i++) {
    int x1 = locationList[i]->getX();
    int y1 = locationList[i]->getY();

    for (int j = i + 1; i < size; j++) {
      int x2 = locationList[j]->getX();
      int y2 = locationList[j]->getY();

      if (x1 == x2 && y1 == y2) {
        return false;
      }
    }
  }
  return true;
}

bool Map::isMapConnected() {
  // First, keep a record of which Locations the player has been to,
  // then set every location to unvisited.
  std::vector<Location*> beenHereRecord;
  for (Location* loc : locationList) {
    if (loc->hasBeenHere()) {
      beenHereRecord.push_back(loc);
      loc->setBeenHere(false);
    }
  }

  // Visit the first location
  locationList[0]->setBeenHere(true);

  // From first location, recursively visit each neighbor
  this->connectionHelper(locationList[0]);

  // If any location hasn't been visited, it is not connected
  for (Location* loc : locationList) {
    if (!loc->hasBeenHere()) {
      return false; // Add Exception here for unconnected Map
    }
  }

  // Reset to original values
  for (Location* loc : locationList) {
    loc->setBeenHere(false);
  }
  for (Location* loc : beenHereRecord) {
    loc->setBeenHere(true);
  }

  return true;
}

void Map::connectionHelper(Location* loc) {
  for (int i = 0; i < 4; i++) {
    Location::CompassCode direction = static_cast<Location::CompassCode>(i);
    Location* neighbor = loc->getNeighbor(direction);
    if (neighbor != nullptr) {
      if (!neighbor->hasBeenHere()) {
        neighbor->setBeenHere(true);
        this->connectionHelper(neighbor);
      }
    }
  }
}

int Map::index(int x, int y) {
  int deltaX = Xmax - Xmin + 1;

  if (x >= Xmin && y >= Ymin && x <= Xmax && y <= Ymax) {
    return (Ymax - y) * deltaX + (x - Xmin);
  }
  return 0; //Add Exception for out-of-bounds
}

void Map::buildMap() {
  this->findBoundaries();
  int deltaX = Xmax - Xmin + 1;
  int deltaY = Ymax - Ymin + 1;
  int matrixSize = deltaX * deltaY;

  // Creating a vector the size of the grid
  for (int i = 0; i < matrixSize; i++) {
    locationMatrix.push_back(nullptr);
  }

  // Assigning each real Location a spot in the matrix
  for (Location* loc : locationList) {
    int i = this->index(loc->getX(), loc->getY());
    locationMatrix[i] = loc;
  }

  //Assigning Neighbors to each Location
  for (Location* loc : locationList) {
    std::vector<Location*> temp;
    int x = loc->getX();
    int y = loc->getY();

    // North Neighbor
    if (y < Ymax) {
      int i = this->index(x, y + 1);
      temp.push_back(locationMatrix[i]);
    } else {
      temp.push_back(nullptr);
    }

    // East Neighbor
    if (x < Xmax) {
      int i = this->index(x + 1, y);
      temp.push_back(locationMatrix[i]);
    } else {
      temp.push_back(nullptr);
    }

    // South Neighbor
    if (y > Ymin) {
      int i = this->index(x, y - 1);
      temp.push_back(locationMatrix[i]);
    } else {
      temp.push_back(nullptr);
    }

    // West Neighbor
    if (x > Xmin) {
      int i = this->index(x - 1, y);
      temp.push_back(locationMatrix[i]);
    } else {
      temp.push_back(nullptr);
    }

    loc->setNeighbors(temp);
  }

  for (Location* loc: locationList) {
    loc->npc->setCurrentLocation(loc);
  }
}

void Map::displayMap() {
  std::cout << std::endl;
  for (int y = Ymax; y >= Ymin; y--) {
    for (int x = Xmin; x <= Xmax; x++) {
      int i = this->index(x, y);
      if (locationMatrix[i] == nullptr) {
        std::cout << "   ";
      } else {
        std::cout << "[ ]";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
