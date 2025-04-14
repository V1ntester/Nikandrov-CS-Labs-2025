#include "Tasks.h"

#include <cstddef>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>

namespace {
    const size_t kWordsForInputCount = 3;

    const size_t kStartValuesCount = 10;

    const int kDistributionStart = -100;
    const int kDistributionEnd = 100;

    const size_t kElementIndexForDelete = 4;

    void PrintVector(const std::vector<int> vector) {
        size_t length = vector.size();

        std::cout << '[';

        for (size_t i = 0; i < length - 1; i++) {
            std::cout << vector[i] << ", ";
        }

        std::cout << vector[length-1];

        std::cout << "]\n";
    }
}

void FirstTask::Init() {
    std::string word;
    std::string buffer;

    std::cout << "Введите слова: ";

    for (size_t i = 0; i < kWordsForInputCount; i++) {
        std::cin >> buffer;

        word.append(buffer);
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
        outputStream << buffer << '\n';
    }

    inputStream.close();
    outputStream.close();
}

void FourthTask::Init() {
    std::vector<int> firstVector;
    
    std::random_device randomDevice;
    std::default_random_engine randomEngine(static_cast<int>(randomDevice()));
    std::uniform_int_distribution distribution(kDistributionStart, kDistributionEnd);

    for (size_t i = 0; i < kStartValuesCount; i++) {
        firstVector.push_back(distribution(randomEngine));
    }

    PrintVector(firstVector);

    std::vector<int> secondVector;

    for (size_t i = 0; i < kStartValuesCount; i++) {
        if (firstVector[i] < 0) {
            secondVector.push_back(firstVector[i]);
        }
    }

    PrintVector(secondVector);

    firstVector.erase(firstVector.cbegin() + kElementIndexForDelete);

    PrintVector(firstVector);
}
