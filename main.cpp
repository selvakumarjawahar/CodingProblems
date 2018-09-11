#include<iostream>

#include"factorial.h"


using namespace std;


int main(int argc,char* argv[])
{
    auto fact = GenerateFactorialSequence(10);
    for(auto& elem : fact)
        std::cout << elem << ' ';
	std::cout << '\n';
    return 0;
}