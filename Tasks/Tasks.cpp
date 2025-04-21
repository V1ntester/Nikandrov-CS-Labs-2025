#include "Tasks.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <string>
#include <vector>
#include "Box.h"
#include "Inventory.h"

namespace {
const size_t kWordsForInputCount = 3;

const size_t kStartVectorLenght = 10;

const int kDistributionStart = -100;
const int kDistributionEnd = 100;

const size_t kElementIndexForDeleteInVector = 4;

const size_t kInventoryArrayLength = 6;

const std::string kFirstInventoryName = "Отвёртка";
const size_t kFirstInventoryCost = 99;
const size_t kFirstInventoryOnHand = 0;
const std::string kSecondInventoryName = "Молоток";
const size_t kSecondInventoryCost = 430;
const size_t kSecondInventoryOnHand = 10;
const std::string kThirdInventoryName = "Гайки";
const size_t kThirdInventoryCost = 70;
const size_t kThirdInventoryOnHand = 100;
const std::string kFourthInventoryName = "Профиль";
const size_t kFourthInventoryCost = 540;
const size_t kFourthInventoryOnHand = 0;
const std::string kFifthInventoryName = "Уголок";
const size_t kFifthInventoryCost = 230;
const size_t kFifthInventoryOnHand = 9;
const std::string kSixthInventoryName = "Доска";
const size_t kSixthInventoryCost = 350;
const size_t kSixthInventoryOnHand = 17;

const size_t kStartListLength = 6;

const size_t kElementIndexForDeleteInList = 4;

const double kFirstBoxA = 1.0;
const double kFirstBoxB = 2.0;
const double kFirstBoxC = 63.0;
const double kSecondBoxA = 14.0;
const double kSecondBoxB = 57.0;
const double kSecondBoxC = 19.0;
const double kThirdBoxA = 7.0;
const double kThirdBoxB = 32.0;
const double kThirdBoxC = 20.0;
const double kFourthBoxA = 5.0;
const double kFourthBoxB = 13.0;
const double kFourthBoxC = 23.0;
const double kFifthBoxA = 10.0;
const double kFifthBoxB = 19.0;
const double kFifthBoxC = 45.0;
const double kSixthBoxA = 19.0;
const double kSixthBoxB = 9.0;
const double kSixthBoxC = 59.0;

const char kFirstPairKeyMap = 'a';
const int kFirstPairValueMap = 61;
const char kSecondPairKeyMap = 'b';
const int kSecondPairValueMap = 62;
const char kThirdPairKeyMap = 'c';
const int kThirdPairValueMap = 63;
const char kFourthPairKeyMap = 'd';
const int kFourthPairValueMap = 64;
const char kFifthPairKeyMap = 'e';
const int kFifthPairValueMap = 65;

const std::string kFirstPairKeyShop = "Бананы";
const size_t kFirstPairValueFirstShop = 400;
const size_t kFirstPairValueSecondShop = 750;
const std::string kSecondPairKeyShop = "Яблоки";
const size_t kSecondPairValueFirstShop = 300;
const size_t kSecondPairValueSecondShop = 150;
const std::string kThirdPairKeyShop = "Груши";
const size_t kThirdPairValueSecondShop = 300;

void Print(Inventory* array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        std::cout << array[i] << '\n';
    }
}

template<typename TypeName>
void Print(std::list<TypeName>& list) {
    std::cout << '[';

    if (!list.empty()) {
        auto iter = list.begin();
        std::cout << *iter;

        for (iter = std::next(iter, 1); iter != list.cend(); ++iter) {
            std::cout << ", " << *iter;
        }
    }

    std::cout << "]\n";
}

template<>
void Print(std::list<Box>& list) {
    std::cout << "[\n";

    if (!list.empty()) {
        auto iter = list.begin();
        std::cout << *iter;

        for (iter = std::next(iter, 1); iter != list.cend(); ++iter) {
            std::cout << "---\n" << *iter;
        }
    }

    std::cout << "]\n";
}

template<typename TypeName>
void Print(const std::vector<TypeName>& vector) {
    size_t length = vector.size();

    std::cout << '[';

    if (!vector.empty()) {
        std::cout << vector[0];

        for (size_t i = 1; i < length; i++) {
            std::cout << ", " << vector[i];
        }
    }

    std::cout << "]\n";
}

template<>
void Print(const std::vector<Inventory>& vector) {
    size_t length = vector.size();

    std::cout << "[\n";

    for (size_t i = 0; i < length; i++) {
        std::cout << vector[i] << '\n';
    }

    std::cout << "]\n";
}

void Print(const std::map<char, int>& map) {
    std::cout << "{\n";

    if (!map.empty()) {
        for (const auto& [key, value] : map) {
            std::cout << '\'' << key << "\': " << value << '\n';
        }
    }

    std::cout << "}\n";
}

void Print(const std::map<std::string, size_t>& map) {
    std::cout << "{\n";

    if (!map.empty()) {
        for (const auto& [key, value] : map) {
            std::cout << '\"' << key << "\": " << value << '\n';
        }
    }

    std::cout << "}\n";
}

}  // namespace

void FirstTask::Init() {
    std::string word;
    std::string buffer;

    std::cout << "Введите слова: ";

    for (size_t i = 0; i < kWordsForInputCount; i++) {
        std::cin >> buffer;

        word += buffer[buffer.length() - 1];
    }

    std::cout << "Итоговое слово: " << word << '\n';
}

void SecondTask::Init() {
    std::string word;

    std::cout << "Введите слово: ";
    std::cin >> word;

    size_t wordLength = word.length();

    for (size_t i = 0; i < wordLength / 2; i++) {
        if (word[i] != word[wordLength - i - 1]) {
            std::cout << "Это не палиндром\n";

            return;
        }
    }

    std::cout << "Это палиндром\n";
}

void ThirdTask::Init() {
    std::string text;

    std::ifstream inputStream("Input.txt");
    std::ofstream outputStream("Output.txt");

    std::string buffer;

    while (getline(inputStream, buffer, '\n')) {
        outputStream << buffer << "\n\n";
    }

    inputStream.close();
    outputStream.close();

    std::cout << "Выполнено\n";
}

void FourthTask::Init() {
    std::vector<double> firstVector;

    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::uniform_real_distribution<double> distribution(kDistributionStart, kDistributionEnd);

    for (size_t i = 0; i < kStartVectorLenght; i++) {
        firstVector.push_back(distribution(randomEngine));
    }

    Print(firstVector);

    std::vector<double> secondVector;

    for (size_t i = 0; i < kStartVectorLenght; i++) {
        if (firstVector[i] < 0) {
            secondVector.push_back(firstVector[i]);
        }
    }

    Print(secondVector);

    firstVector.erase(std::next(firstVector.cbegin(), kElementIndexForDeleteInVector));

    Print(firstVector);
}

void FifthTask::Init() {
    Inventory inventoryArray[kInventoryArrayLength] = {Inventory(kFifthInventoryName, kFirstInventoryCost, kFirstInventoryOnHand),
                                                       Inventory(kSecondInventoryName, kSecondInventoryCost, kSecondInventoryOnHand),
                                                       Inventory(kThirdInventoryName, kThirdInventoryCost, kThirdInventoryOnHand),
                                                       Inventory(kFourthInventoryName, kFourthInventoryCost, kFourthInventoryOnHand),
                                                       Inventory(kFifthInventoryName, kFifthInventoryCost, kFifthInventoryOnHand),
                                                       Inventory(kSixthInventoryName, kSixthInventoryCost, kSixthInventoryOnHand)};

    Print(inventoryArray, kInventoryArrayLength);

    std::vector<Inventory> inventoryVector;

    for (Inventory inventory : inventoryArray) {
        if (inventory.GetOnHand() == 0) {
            inventoryVector.push_back(inventory);
        }
    }

    std::cout << '\n';

    Print(inventoryVector);
}

void SixthTask::Init() {
    std::list<double> firstList;

    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::uniform_real_distribution<double> distribution(kDistributionStart, kDistributionEnd);

    for (size_t i = 0; i < kStartListLength; i++) {
        firstList.push_back(distribution(randomEngine));
    }

    Print(firstList);

    std::list<double> secondList;

    for (double element : firstList) {
        if (element < 0) {
            secondList.push_back(element);
        }
    }

    Print(secondList);

    firstList.erase(std::next(firstList.cbegin(), kElementIndexForDeleteInList));

    Print(firstList);
}

void SeventhTask::Init() {
    std::list<Box> boxList{Box(kFirstBoxA, kFirstBoxB, kFirstBoxC), Box(kSecondBoxA, kSecondBoxB, kSecondBoxC),
                           Box(kThirdBoxA, kThirdBoxB, kThirdBoxC), Box(kFourthBoxA, kFourthBoxB, kFourthBoxC),
                           Box(kFifthBoxA, kFifthBoxB, kFifthBoxC), Box(kSixthBoxA, kSixthBoxB, kSixthBoxC)};

    Print(boxList);

    Box largestBox = *boxList.cbegin();

    for (auto iter = std::next(boxList.begin(), 1); iter != boxList.cend(); ++iter) {
        if (largestBox < *iter) {
            largestBox = *iter;
        }
    }

    std::cout << "\nLargest box:\n" << largestBox << '\n';
}

void EighthTask::Init() {
    std::map<char, int> map{
        {kFirstPairKeyMap,  kFirstPairValueMap },
        {kSecondPairKeyMap, kSecondPairValueMap},
        {kThirdPairKeyMap,  kThirdPairValueMap },
        {kFourthPairKeyMap, kFourthPairValueMap},
        {kFifthPairKeyMap,  kFifthPairValueMap }
    };

    Print(map);

    map.erase(kSecondPairKeyMap);

    std::cout << '\n';
    Print(map);
}

void NinethTask::Init() {
    std::map<std::string, size_t> firstShop{
        {kFirstPairKeyShop,  kFirstPairValueFirstShop },
        {kSecondPairKeyShop, kSecondPairValueFirstShop},
    };
    std::map<std::string, size_t> secondShop{
        {kFirstPairKeyShop,  kFirstPairValueSecondShop },
        {kSecondPairKeyShop, kSecondPairValueSecondShop},
        {kThirdPairKeyShop,  kThirdPairValueSecondShop },
    };

    std::map<std::string, size_t> nomenclature{
        {kFirstPairKeyShop,  0},
        {kSecondPairKeyShop, 0},
        {kThirdPairKeyShop,  0},
    };

    for (const auto& [key, value] : firstShop) {
        nomenclature[key] += value;
    }

    for (const auto& [key, value] : secondShop) {
        nomenclature[key] += value;
    }

    Print(nomenclature);
}
