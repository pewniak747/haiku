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

std::string lineToJapaneseTemplate(LineTemplate *line) {
  return line->getJapaneseTemplate();
}

Renderer::Renderer(Poem *poem) {
  this->poem = poem;
}

std::string JapaneseKanjiRenderer::toString() {
  return poem->toString(&wordToJapaneseKanjiConverter, &lineToJapaneseTemplate);
}

std::string JapaneseKanaRenderer::toString() {
  return poem->toString(&wordToJapaneseKanaConverter, &lineToJapaneseTemplate);
}

std::string JapaneseRomajiRenderer::toString() {
  return poem->toString(&wordToJapaneseRomajiConverter, &lineToJapaneseTemplate);
}

std::string EnglishRenderer::toString() {
  return poem->toString(&wordToEnglishConverter, &lineToJapaneseTemplate);
}
