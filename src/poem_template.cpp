#include "poem_template.h"

PoemTemplate::PoemTemplate(std::vector<LineTemplate*> lineTemplates) {
  this->lineTemplates = lineTemplates;
}

LineTemplate* PoemTemplate::getLine(unsigned i) {
  return this->lineTemplates[i];
}

unsigned PoemTemplate::linesCount() {
  return lineTemplates.size();
}
