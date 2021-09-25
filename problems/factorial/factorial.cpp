#include "factorial.h"
size_t GenerateFactorial(int num) {
	size_t factorial = 1;
	for (int i = 1; i <= num; ++i)
	{
		factorial *= i;
	}
	return factorial;
}

std::vector<int> GenerateFactorialSequence(int sequence_size)
{
    std::vector<int> result;
	result.push_back(1); // 0!
	for (int i = 1; i < sequence_size; i++)
	{
		result.push_back(GenerateFactorial(i));
	}
    return result;
}

