#include "poem_template.h"

PoemTemplate::PoemTemplate(std::vector<LineTemplate*> lineTemplates) {
  this->lineTemplates = lineTemplates;
}

unsigned PoemTemplate::linesCount() {
  return lineTemplates.size();
}
