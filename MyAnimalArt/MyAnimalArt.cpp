#include "MyAnimalArt.h"

#include <iostream>
#include <random>

using AnimalArtPrintFunctionPointer = void (*)();

namespace {
void PrintCat() {
  std::cout << "    /\\_____/\\\n";
  std::cout << "   /  o   o  \\\n";
  std::cout << "  ( ==  ^  == )\n";
  std::cout << "   )         (\n";
  std::cout << "   (           )\n";
  std::cout << "  ( (  )   (  ) )\n";
  std::cout << "(__(__)___(__)__)\n";
}

void PrintCow() {
  std::cout << "           __n__n__\n";
  std::cout << "    .------`-\\00/-'\n";
  std::cout << "   /  ##  ## (oo)\n";
  std::cout << "  / \\## __   ./\n";
  std::cout << "     |||   |||\n";
}

void PrintDog() {
  std::cout << "              /\\___/\\\n";
  std::cout << "              `)9 9('\n";
  std::cout << "              {_:Y:.}_\n";
  std::cout << "--------------( )U-'( )----------\n";
  std::cout << "              ```   '''\n";
}

const int kAnimalCount = 3;
const AnimalArtPrintFunctionPointer
    kAnimalArtPrintFunctionPointers[kAnimalCount]{PrintCat, PrintCow, PrintDog};

int GenerateRandom(int start, int end) {
  std::random_device r{};
  std::default_random_engine randomEngine(r());
  std::uniform_int_distribution distribution(start, end);

  return distribution(randomEngine);
}
}  // namespace

namespace MyAnimalArt {
void PrintRandomAnimalArt() {
  kAnimalArtPrintFunctionPointers[GenerateRandom(0, kAnimalCount - 1)]();
}
}  // namespace MyAnimalArt
