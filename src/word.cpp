#include <string>

#include "word.h"

Word::Word(std::string japanese, std::string type) {
  this->japanese = japanese;
  this->type = type;
}

std::string Word::getJapanese() {
  return this->japanese;
}
