#ifndef LINE_TEMPLATE_H
#define LINE_TEMPLATE_H

#include <string>
#include <vector>

#include "word_template.h"

class LineTemplate {
  public:
    LineTemplate(std::vector<WordTemplate*> wordTemplates, std::string japanese, std::string romaji, std::string english, unsigned syllabes);
    WordTemplate* getWord(unsigned i);
    std::string getJapaneseTemplate();
    std::string getRomajiTemplate();
    std::string getEnglishTemplate();
    unsigned getSyllabes();
    unsigned wordsCount();
  private:
    std::vector<WordTemplate*> wordTemplates;
    std::string japanese;
    std::string romaji;
    std::string english;
    unsigned syllabes;
};

#endif // LINE_TEMPLATE_H
