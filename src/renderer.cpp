#include "renderer.h"

std::string wordToJapaneseKanjiConverter(Word *word) {
  return word->getJapaneseKanji();
};

std::string wordToJapaneseKanaConverter(Word *word) {
  return word->getJapaneseKana();
};

std::string wordToJapaneseRomajiConverter(Word *word) {
  return word->getJapaneseRomaji();
};

std::string wordToEnglishConverter(Word *word) {
  return word->getEnglish();
};

Renderer::Renderer(Poem *poem) {
  this->poem = poem;
}

std::string JapaneseKanjiRenderer::toString() {
  return poem->toString(&wordToJapaneseKanjiConverter);
}

std::string JapaneseKanaRenderer::toString() {
  return poem->toString(&wordToJapaneseKanaConverter);
}

std::string JapaneseRomajiRenderer::toString() {
  return poem->toString(&wordToJapaneseRomajiConverter);
}

std::string EnglishRenderer::toString() {
  return poem->toString(&wordToEnglishConverter);
}
