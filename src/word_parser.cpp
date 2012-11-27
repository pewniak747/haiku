#include <cstdio>

#include "word_parser.h"

WordParser::WordParser(std::string fileName) {
  this->xmlFileName = fileName;
}

void WordParser::parse() {

}

void WordParser::loadToRepository(WordRepository *repository) {
  repository->add(new Word("古池", "ふるいけ", "furuike", "old pond", "noun:place"));
  repository->add(new Word("蛙", "かわず", "kawazu", "frog", "noun:animal"));
  repository->add(new Word("飛び込む", "とびこむ", "tobikomu", "leap in", "verb"));
  repository->add(new Word("水", "みず", "mizu", "water", "noun:element"));
  repository->add(new Word("音", "おと", "oto", "sound", "noun:element"));
  printf("[ DEBUG ] loaded word repository\n");
}
