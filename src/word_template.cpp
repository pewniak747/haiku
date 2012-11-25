#include <string>

#include "word_template.h"

WordTemplate::WordTemplate(std::string type) {
  this->type = type;
}

std::string WordTemplate::getType() {
  return this->type;
}
