#ifndef POEM_H
#define POEM_H

#include <string>
#include <vector>

class Poem {
  public:
    Poem(std::vector<std::string> lines);
    std::string toString();
  private:
    std::vector<std::string> lines;
};

#endif // POEM_H
