#include"isunique.h"

#include<vector>

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