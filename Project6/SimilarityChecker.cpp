#include <iostream>
#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int checkLengthSimilarity(string firstParam, string secondParam)
	{
		if( true == isTwoTimesLong(firstParam, secondParam))
		{
			return 0;
		}
		if(firstParam.size() > secondParam.size())
		{
			double point = static_cast<double>(firstParam.size() - secondParam.size()) / static_cast<double>(secondParam.size());
			return point * 60;
		}
		if (secondParam.size() > firstParam.size())
		{
			double point = static_cast<double>(secondParam.size() - firstParam.size()) / static_cast<double>(firstParam.size());
			return point * 60;
		}
		return 60;
	}
private:
	bool isTwoTimesLong(string firstParam, string secondParam)
	{
		if (secondParam.size() >= (firstParam.size() * 2))
		{
			return true;
		}
		if (firstParam.size() >= (secondParam.size() * 2))
		{
			return true;
		}
		return false;
	}
};