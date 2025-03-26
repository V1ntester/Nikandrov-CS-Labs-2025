#include "Handler.h"

#include <cstring>
#include <iostream>
#include "DataBase.h"

namespace {
const size_t kBufferSize = 256;

const char kPlanetNameDemonstration[] = "TestPlanet";
const int kDiameterDemonstration = 1000;
const bool kLifeExistsDemonstration = false;
const size_t kSatellitesCountDemonstration = 3;

const size_t kIndexDemonstration = 0;

void NavigationItemsPrint() {
    std::cout << "Выберите одно из действий: \n";
    std::cout << "a — прочитать из файла\n";
    std::cout << "b — записать в файл\n";
    std::cout << "с — отсортировать базу данных\n";
    std::cout << "d — добавить в базу данных\n";
    std::cout << "e — удалить из базы данных\n";
    std::cout << "f — вывести базу данных\n";
    std::cout << "q — выход\n\n";

    std::cout << "Действие: ";
}
}  // namespace

void Handler::InteractiveModeInit() {
    char userAnswer = ' ';

    while (userAnswer != 'q') {
        NavigationItemsPrint();

        std::cin >> userAnswer;

        std::cin.ignore();

        switch (userAnswer) {
            case 'a':
                this->ReadDataBaseFromFile();
                break;
            case 'b':
                this->WriteDataBaseToFile();
                break;
            case 'c':
                this->SortDataBase();
                break;
            case 'd':
                this->AddToDataBase();
                break;
            case 'e':
                this->DeleteFromDataBase();
                break;
            case 'f':
                this->PrintDataBase();
                break;
            case 'q':
                std::cout << "\nMeow!\n";
                break;
            default:
                std::cout << "Действие не найдено\n\n";
                break;
        }

        std::cout << '\n';
    }
}

void Handler::DemoModeInit() {
}

void Handler::ReadDataBaseFromFile() {
    this->dataBase.ReadFromFile();
    std::cout << "Чтение выполнено\n";
}

void Handler::WriteDataBaseToFile() {
    this->dataBase.WriteToFile();
    std::cout << "Запись выполнена\n";
}

void Handler::SortDataBase() {
    this->dataBase.Sort();
    std::cout << "Сортировка выполнена\n";
}

void Handler::AddToDataBase() {
    char planetName[kBufferSize]{'\0'};
    int diameter = 0;
    bool lifeExists = false;
    size_t satellitesCount = 0;

    if (isInteractive) {
        std::cout << "Введите название планеты: ";
        std::cin >> planetName;

        std::cout << "Введите диаметр планеты: ";
        std::cin >> diameter;

        std::cout << "Введите наличие жизни: ";
        std::cin >> lifeExists;

        std::cout << "Введите кол-во спутников: ";
        std::cin >> satellitesCount;
    } else {
        strncpy(planetName, kPlanetNameDemonstration, strlen(kPlanetNameDemonstration) + 1);
        diameter = kDiameterDemonstration;
        lifeExists = kLifeExistsDemonstration;
        satellitesCount = kSatellitesCountDemonstration;
    }

    this->dataBase.Add(planetName, diameter, lifeExists, satellitesCount);
    
    std::cout << "Объект добавлен\n";
}

void Handler::DeleteFromDataBase() {
    size_t index = 0;

    if (isInteractive) {
        std::cout << "Введите индекс элемента: ";
        std::cin >> index;
    } else {
        index = kIndexDemonstration;
    }

    dataBase.Delete(index);
    std::cout << "Объект удалён\n";
}

void Handler::PrintDataBase() {
    this->dataBase.Print();
}

Handler::Handler(DataBase& dataBase, bool isInteractive) : isInteractive(isInteractive), dataBase(dataBase) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
