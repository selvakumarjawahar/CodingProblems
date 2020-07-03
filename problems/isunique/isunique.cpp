#include"isunique.h"

#include<vector>


//#define naive

#ifdef naive

/*
Naive Implementation where the complexity is O(n^2)
*/

static bool isexits(const std::vector<char> &str, char chr) {
	for (auto& elem : str) {
		if (chr == elem)
			return true;
}
	return false;
}
bool isunique(std::string str)

{
	std::vector<char> strset;
	for (auto& elem : str) {
		if (strset.empty())
			strset.push_back(elem);
		else
		{
			if (isexits(strset, elem))
				return false;
			strset.push_back(elem);
		}
	}
	return true;
}
#else

/*
Optimized Implementation where the complexity is O(n)
Assumption is the string has ascci chars and the char size is 256
*/
bool isunique(std::string str)
{
	std::vector<int> bitmap(256, 0);
	for (auto& elem : str) {
		if (bitmap[elem])
			return false;
		bitmap[elem] = 1;
	}
	return true;
}
#endif // naive

