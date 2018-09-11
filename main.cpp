#include<iostream>

#include"factorial.h"


using namespace std;


int main(char argv[], int argc)
{
    auto fact = GenerateFactorial(5);
    for(auto& elem : fact)
        std::cout << elem << ' ';
    return 0;
}