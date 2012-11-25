#ifndef LINE_H
#define LINE_H

#include <string>
#include <vector>

#include "word.h"
#include "line_template.h"

class Line {
  public:
    Line(std::vector<Word*> words, LineTemplate *lineTemplate);
    std::string getJapanese();
  private:
    std::vector<Word*> words;
    LineTemplate *lineTemplate;
};

#endif // LINE_H
