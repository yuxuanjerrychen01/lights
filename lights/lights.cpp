// lights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

/* 8 switches, 8 lights
 * The default lights pattern is
 * 1,3,5,7,0,2,4,6,0(off),7(off)
 */

int main()
{
    // light sequence construction
    static int SIZE = 8;
    std::vector<std::string> vec;
    vec.push_back("01000000");
    vec.push_back("01010000");
    vec.push_back("01010100");
    vec.push_back("01010101");
    vec.push_back("11010101");
    vec.push_back("11110101");
    vec.push_back("11111101");
    vec.push_back("11111111");
    vec.push_back("01111111");
    vec.push_back("01111110");

    std::cout << "Testing lights program." << std::endl;
    std::cout << "When you are ready, press any letter and hit enter." << std::endl;
    std::string temp1;
    std::cin >> temp1;
    std::cout << " " << std::endl;

    std::cout << "Below are the light sequences." << std::endl;
    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << std::endl; }
    std::cout << " " << std::endl;

    std::cout << "When you are ready for the game, press any letter and hit enter." << std::endl;
    std::string temp2;
    std::cin >> temp2;
    std::cout << " " << std::endl;
    system("cls");
    //std::cout << "test clean" << std::endl;

    std::cout << "Begin turning on the switches. Note that there are 8 switches in total." << std::endl;
    std::cout << "Use bit strings to represent open and closed switches." << std::endl;
    std::cout << "Current switch condition: " << std::endl;
    std::cout << "00000000" << std::endl;

    int count = 0;
    while (true) {
        if (count == vec.size()) {
            std::cout << " " << std::endl;
            std::cout << "You have won the game!" << std::endl;
            return 0;
        }

        std::string str;
        std::cin >> str;
        if (str == "q") {
            std::cout << " " << std::endl;
            std::cout << "Come back and try again next time!" << std::endl;
            return 0;
        }

        if (str == vec[count]) {
            count++;
            continue;
        }

        if (str != vec[count]) {
            count = 0;
            system("cls");
            if (str.length() != SIZE) {
                std::cout << "Incorrect input. Please use 0/1 to represent switch off/on. There are 8 switches." << std::endl;
            }
            std::cout << "The lights have been turned off. Try again." << std::endl;
            std::cout << "If you wish to quit, enter \"q\"." << std::endl;
            std::cout << " " << std::endl;
            std::cout << "00000000" << std::endl;
            continue;
        }
    }
    return 0;
}

