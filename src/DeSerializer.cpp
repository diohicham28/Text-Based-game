/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <string>
#include <vector>
#include "../include/DeSerializer.h"
#include "../include/GamePanel.h"
#include "../include/World.h"

DeSerializer::DeSerializer() {}

DeSerializer::DeSerializer(std::string file) : fileName{file} {}

DeSerializer::~DeSerializer() {}

void DeSerializer::openFile() {
  saveFile.open(fileName);
}

void DeSerializer::closeFile() {
  saveFile.close();
}

int DeSerializer::countPanels() {
  int count = 0;
  saveFile.open(fileName);
  std::string line;

  if (saveFile.is_open()) {
    while (std::getline(saveFile, line)) {
      if (line[0] == '#')
        count++;
    }
  }
  saveFile.close();
  return count;
}

void DeSerializer::line() {
  std::string line;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
  }
}

bool DeSerializer::loadBool(std::string name) {
  std::string line;
  int nameEnd = name.size() + 2;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
    line = line.substr(nameEnd, line.size() - 1);
    if (line == "0")
      return false;
    if (line == "1")
      return true;
  }
}

int DeSerializer::loadInt(std::string name) {
  std::string line;
  int nameEnd = name.size() + 2;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
    line = line.substr(nameEnd, line.size() - 1);
    return std::stoi(line);
  }
}

std::string DeSerializer::loadString(std::string name) {
  std::string line;
  int nameEnd = name.size() + 2;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
    line = line.substr(nameEnd, line.size() - 1);
    return line;
  }
}

GamePanel* DeSerializer::loadPointer(std::string name, World* w) {
  std::string line;
  int nameEnd = name.size() + 2;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
    line = line.substr(nameEnd, line.size() - 1);
    int code = std::stoi(line);
    return w->findPanel(code);
  }
}

std::vector<int> DeSerializer::loadIntVector(std::string name) {
  std::string line;
  int nameEnd = name.size() + 2;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
    line = line.substr(nameEnd, line.size() - 1);

    int limit = line.size();
    std::vector<int> list;
    std::string temp = "";
    for (int i = 0; i < limit; i++) {
      if (line[i] != ' ') {
        temp += line[i];
      } else {
        list.push_back(std::stoi(temp));
        temp = "";
      }
    }
    if (temp != "")
      list.push_back(std::stoi(temp));
    return list;
  }
}

std::vector<std::string> DeSerializer::loadStringVector(std::string name) {
  std::string line;
  int nameEnd = name.size() + 2;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
    line = line.substr(nameEnd, line.size() - 1);

    int limit = line.size();
    std::vector<std::string> list;
    std::string temp = "";
    for (int i = 0; i < limit; i++) {
      if (line[i] != '/') {
        temp += line[i];
      } else {
        list.push_back(temp);
        temp = "";
      }
    }
    if (temp != "")
      list.push_back(temp);
    return list;
  }
}

std::vector<GamePanel*> DeSerializer::loadPointerVector(std::string name,
    World* w) {
  std::string line;
  int nameEnd = name.size() + 2;
  if (saveFile.is_open()) {
    std::getline(saveFile, line);
    line = line.substr(nameEnd, line.size() - 1);

    int limit = line.size();
    std::vector<GamePanel*> list;
    std::string temp = "";
    for (int i = 0; i < limit; i++) {
      if (line[i] != ' ') {
        temp += line[i];
      } else {
        int code = std::stoi(temp);
        list.push_back(w->findPanel(code));
        temp = "";
      }
    }
    if (temp != "") {
      int code = std::stoi(temp);
      list.push_back(w->findPanel(code));
    }
    return list;
  }
}









