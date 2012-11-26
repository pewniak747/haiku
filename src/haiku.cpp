#include <cstdio>

#include "poem_generator.h"
#include "renderer.h"

int main() {
  PoemGenerator *poemGenerator = new PoemGenerator();
  Poem *poem = poemGenerator->getPoem();
  std::string generatedKanjiPoem, generatedKanaPoem, generatedRomajiPoem, generatedEnglishPoem;
  generatedKanjiPoem = (new JapaneseKanjiRenderer(poem))->toString();

  printf("KANJI:\n");
  printf("%s", generatedKanjiPoem.c_str());
  printf("\n");
  printf("KANA:\n");
  printf("%s", generatedKanaPoem.c_str());
  printf("\n");
  printf("ROMAJI:\n");
  printf("%s", generatedRomajiPoem.c_str());
  printf("\n");
  printf("ENGLISH:\n");
  printf("%s", generatedEnglishPoem.c_str());
  printf("\n");
}
