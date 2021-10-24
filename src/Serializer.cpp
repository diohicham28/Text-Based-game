/**
 * @author {Aaron Ackerman}
 * @date {March, 2020}
 */

#include <string>
#include <vector>
#include "../include/Serializer.h"
#include "../include/GamePanel.h"

Serializer::Serializer() {}

Serializer::Serializer(std::string const file) : fileName{file} {}

Serializer::~Serializer() {}

void Serializer::openFile() {
  saveFile.open(fileName);
}

void Serializer::closeFile() {
  saveFile.close();
}

void Serializer::line() {
  if (saveFile.is_open()) {
    saveFile << "##########################" << std::endl;
  }
}

void Serializer::saveBool(std::string name, bool value) {
  if (saveFile.is_open()) {
    saveFile << name << ": " << value << std::endl;
  }
}

void Serializer::saveInt(std::string name, int value) {
  if (saveFile.is_open()) {
    saveFile << name << ": " << value << std::endl;
  }
}

void Serializer::saveString(std::string name, std::string value) {
  if (saveFile.is_open()) {
    saveFile << name << ": " << value << std::endl;
  }
}

void Serializer::savePointer(std::string name, GamePanel* g) {
  if (saveFile.is_open()) {
    if (g == nullptr) {
      saveFile << name << ": " << "0" << std::endl;
    } else {
      saveFile << name << ": " << g->getObjectCode() << std::endl;
    }
  }
}

void Serializer::saveIntVector(std::string name, std::vector<int> values) {
  if (saveFile.is_open()) {
    saveFile << name << ": ";
    for (int i : values) {
      saveFile << i << " ";
    }
    saveFile << std::endl;
  }
}

void Serializer::saveStringVector(std::string name,
                                  std::vector<std::string> values) {
  if (saveFile.is_open()) {
    saveFile << name << ": ";
    for (std::string i : values) {
      saveFile << i << "/";
    }
    saveFile << std::endl;
  }
}

void Serializer::savePointerVector(std::string name,
                                   std::vector<GamePanel*> v) {
  if (saveFile.is_open()) {
    saveFile << name << ": ";
    for (GamePanel* g : v) {
      if (g == nullptr) {
        saveFile << "0" << " ";
      } else {
        saveFile << g->getObjectCode() << " ";
      }
    }
    saveFile << std::endl;
  }
}
