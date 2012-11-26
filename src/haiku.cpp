#include <cstdio>

#include "poem_generator.h"
#include "renderer.h"

int main() {
  PoemGenerator *poemGenerator = new PoemGenerator();
  Poem *poem = poemGenerator->getPoem();
  Renderer *renderer = new JapaneseRenderer(poem);
  std::string generatedPoem = renderer->toString();
  printf("%s", generatedPoem.c_str());
}
