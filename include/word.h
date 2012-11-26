#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
  public:
    Word(std::string japanese, std::string type);
    std::string getJapanese();
  private:
    std::string japanese;
    std::string type;
};

#endif // WORD_H
