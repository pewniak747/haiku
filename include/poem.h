#ifndef POEM_H
#define POEM_H

#include <string>
#include <vector>

#include "line.h"

class Poem {
  public:
    Poem(std::vector<Line*> lines);
    std::string toString();
  private:
    std::vector<Line*> lines;
};

#endif // POEM_H
