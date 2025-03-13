#include "Handler.h"

#include <iostream>

namespace {
void NavigationItemsPrint() {
    // std::cout << "Выберите одно из действий: \n";
    // std::cout << "a — прочитать из файла\n";
    // std::cout << "b — записать в файл\n";
    // std::cout << "с — отсортировать базу данных\n";
    // std::cout << "d — добавить в базу данных\n";
    // std::cout << "e — удалить из базы данных\n";
    // std::cout << "f — вывести базу данных\n";
    // std::cout << "q — выход\n\n";

    // std::cout << "Действие: ";
}
}  // namespace

void Handler::InteractiveModeInit() {
    char userAnswer = ' ';

    while (userAnswer != 'q') {
        NavigationItemsPrint();

        std::cin >> userAnswer;

        std::cin.ignore();

        switch (userAnswer) {
            // case 'a':
            //     this->ReadDataBaseFromFile();
            //     break;
            // case 'b':
            //     this->WriteDataBaseToFile();
            //     break;
            // case 'c':
            //     this->SortDataBase();
            //     break;
            // case 'd':
            //     this->AddToDataBase();
            //     break;
            // case 'e':
            //     this->DeleteFromDataBase();
            //     break;
            // case 'f':
            //     this->PrintDataBase();
            //     break;
            // case 'q':
            //     std::cout << "\nMeow!\n";
            //     break;
            default:
                std::cout << "Действие не найдено\n";
                break;
        }

        std::cout << '\n';
    }
}

void Handler::DemoModeInit() {
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
