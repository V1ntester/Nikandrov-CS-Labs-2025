#include "Handler.h"

#include <cstring>
#include <iostream>
#include "Collections/Set.h"
#include "Collections/Vector.h"

namespace {
const size_t kStringLength = 6;
}

void Handler::InteractiveModeInit() {
    Set<char*> set;

    char* firstString = new char[kStringLength];
    char* secondString = new char[kStringLength];

    strncpy(firstString, "aaacc", kStringLength);
    strncpy(secondString, "aaaaa", kStringLength);

    set.Add(firstString);
    set.Add(secondString);

    delete[] secondString;

    Set<char*> setClone(set);

    std::cout << set << '\n';
    std::cout << setClone << '\n';
    std::cout << setClone.isElement(firstString) << '\n';

    
    delete[] firstString;
}

void Handler::DemoModeInit() {
    Vector<const char*> vector("Hello!");

    vector.Add("Привет!");
    vector.Add("Привет!");
    vector.Add("Привет!");
    vector.Add("Привет!");
    vector.Add("Привет!");
    
    std::cout << "Вектор v: " << vector << '\n';

    vector.Add("Привет!");
    vector.Add("Привет!");
    vector.Add("Привет!");

    std::cout << "Вектор v: " << vector << '\n';

    Vector<const char*> vector1 = vector;

    std::cout << "Вектор v1: " << vector1 << '\n';

    for (size_t i = 0; i < vector1.GetLength(); i++) {
        vector1.Delete(0);
    }

    std::cout << "Вектор v1: " << vector1 << '\n';

    Set<const char*> set("Yes");
    Set<const char*> set1;
    Set<const char*> set2;

    set.Add("Привет!");
    set.Add("No");

    const char* string = "Hello!";

    set.Add(string);

    std::cout << "Множество s: " << set << '\n';

    set1.Add("Cat");
    set1.Add("No");
    set1.Add("Привет");

    std::cout << "Множество s1: " << set1 << '\n';

    set2 = set1 - set;

    std::cout << "Множество s2=s1-s: " << set2 << "\n\n";
    std::cout << "Множество s1: " << set1 << '\n';
    std::cout << "Множество s: " << set << '\n';

    set2 = set1 + set;

    std::cout << "Множество s2=s1+s: " << set2 << "\n\n";
    std::cout << "Множество s1: " << set1 << '\n';
    std::cout << "Множество s: " << set << '\n';

    set2 = set1 * set;

    std::cout << "Множество s2=s1*s: " << set2 << "\n\n";
    std::cout << "Множество s1: " << set1 << '\n';
    std::cout << "Множество s: " << set << '\n';

    Set<const char*> set3 = set2;

    std::cout << "Множество s3=s2: " << set3 << "\n\n";

    if(set3 == set2) {
        std::cout << "Множество s3=s2\n";
    } else {
        std::cout << "Множество s3!=s2\n";
    }

    if(set3 == set1) {
        std::cout << "Множество s3=s1\n";
    } else {
        std::cout << "Множество s3!=s1\n";
    }

    if(set1 == set3) {
        std::cout << "Множество s1=s3\n";
    } else {
        std::cout << "Множество s1!=s3\n";
    }
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
