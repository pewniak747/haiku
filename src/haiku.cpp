#include <cstdio>

#include "poem.h"
#include "poem_generator.h"

int main() {
  PoemGenerator *poemGenerator = new PoemGenerator();
  Poem *poem = poemGenerator->getPoem();
  std::string generatedPoem = poem->toString();
  printf("%s", generatedPoem.c_str());
}
