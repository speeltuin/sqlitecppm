#include <cstdlib>
#include <ctime>
#include <iostream>

import speech;

int main()
{
    std::srand(std::time(nullptr));
    if (std::rand() % 2) {
        std::cout << get_phrase_en() << std::endl;
    } else {
        std::cout << get_phrase_es() << std::endl;
    }
}
