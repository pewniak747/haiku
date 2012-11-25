#ifndef POEM_GENERATOR_H
#define POEM_GENERATOR_H

class PoemGenerator {
  public:
    PoemGenerator();
    Poem* getPoem();
  private:
    void loadWordRepository();
    std::vector<std::string> wordRepository;
};

#endif // POEM_GENERATOR_H
