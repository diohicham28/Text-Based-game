/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef DESERIALIZER_H
#define DESERIALIZER_H

#include<string>
#include<fstream>
#include<iostream>
#include<vector>
class GamePanel;
class World;

class DeSerializer {
 public:
  DeSerializer();

  /**
  * A constructor that takes in the file name as a string.
  * @param file The path name of the save file.
  */
  DeSerializer(std::string file);

  virtual ~DeSerializer();

  /**
    * Uses ifstream saveFile to open file with path fileName.
    */
  void openFile();

  /**
    * Gets the "new object line" that precedes an object in the save.
    */
  void line();

  /**
    * Opens file, counts the number of objects in save file, then closes.
    * @return The number of GamePanels stored in the save file.
    */
  int countPanels();

  /**
  * Loads a single boolean from a line in the save file.
  * @param name The name of the integer in the save (e.g. objectCode)
  * @return The value of the stored boolean, 0 = false, 1 = true.
  */
  bool loadBool(std::string name);

  /**
    * Loads a single integer from a line in the save file.
    * @param name The name of the integer in the save (e.g. objectCode)
    * @return The value of the stored integer.
    */
  int loadInt(std::string name);

  /**
    * Loads a single string from a line in the save file.
    * @param name The name of the string in the save (e.g. lookMessage)
    * @return The value of the stored string.
    */
  std::string loadString(std::string name);

  /**
  * Loads a pointer (stored as an objectCode) from a line in the save file.
  * Uses the world to search for an object with a matching objectCode.
  * @param name The name of the string in the save (e.g. lookMessage)
  * @param w The world that is being loaded.
  * @return The value of the stored string.
  */
  GamePanel* loadPointer(std::string name, World* w);

  /**
    * Loads a vector of integers from a line in the save file.
    * @param name The name of the integer vector in the save file.
    * @return A vector of integers that can be deep copied.
    */
  std::vector<int> loadIntVector(std::string name);

  /**
    * Loads a vector of strings from a line in the save file.
    * @param name The name of the string vector in the save file.
    * @return A vector of strings that can be deep copied.
    */
  std::vector<std::string> loadStringVector(std::string name);

  /**
  * Loads a vector of pointers (a series of objectCodes) from the save file.
  * @param name The name of the pointer vector in the save file.
  * @param w The world that is being loaded.
  * @return A vector of strings that can be deep copied.
  */
  std::vector<GamePanel*> loadPointerVector(std::string name, World* w);

  /**
    * Closes the file opened by ifstream saveFile.
    */
  void closeFile();

 private:
  std::string fileName;
  std::ifstream saveFile;
};

#endif // DESERIALIZER_H
