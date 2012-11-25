#include <cstdio>

#include "poem.h"
#include "poem_generator.h"

Poem* PoemGenerator::getPoem() {
  std::vector<std::string> lines;
  lines.push_back("furuike ya");
  lines.push_back("kawazu tobikomu");
  lines.push_back("mizu no oto");
  printf("[ DEBUG ] generated lines\n");
  Poem *poem = new Poem(lines);
  return poem;
}
