/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include<string>
#include<fstream>
#include<vector>
class GamePanel;


class Serializer {
 public:
  Serializer();
  Serializer(std::string);
  virtual ~Serializer();

  void openFile();
  void line();
  void saveBool(std::string, bool);
  void saveInt(std::string, int);
  void saveString(std::string, std::string);
  void savePointer(std::string, GamePanel*);
  void saveIntVector(std::string, std::vector<int>);
  void saveStringVector(std::string, std::vector<std::string>);
  void savePointerVector(std::string, std::vector<GamePanel*>);
  void closeFile();

 private:
  std::string fileName;
  std::ofstream saveFile;
};


#endif // SERIALIZER_H
