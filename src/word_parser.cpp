#include <cstdio>

#include "word_parser.h"

WordParser::WordParser(std::string fileName) {
  this->xmlFileName = fileName;
}

void WordParser::parse() {
  parsedElements.push_back(new Word("古池", "ふるいけ", "furuike", "old pond", "noun:place"));
  parsedElements.push_back(new Word("蛙", "かわず", "kawazu", "frog", "noun:animal"));
  parsedElements.push_back(new Word("飛び込む", "とびこむ", "tobikomu", "leap in", "verb"));
  parsedElements.push_back(new Word("水", "みず", "mizu", "water", "noun:element"));
  parsedElements.push_back(new Word("音", "おと", "oto", "sound", "noun:element"));
}

void WordParser::loadToRepository(WordRepository *repository) {
  for(unsigned i = 0; i < parsedElements.size(); i++) {
    repository->add(parsedElements[i]);
  }
  printf("[ DEBUG ] loaded word repository\n");
}
