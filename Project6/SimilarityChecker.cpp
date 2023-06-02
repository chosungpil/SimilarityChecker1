#include <iostream>
#include <cstdlib>
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

		if(firstParam.size() != secondParam.size())
		{
			return calculatePartialPoint(firstParam.size(), secondParam.size());
		}

		return 60;
	}
private:
	int calculatePartialPoint(int firstNumber, int secondNumber)
	{
		int absNum = abs((firstNumber - secondNumber));
		int divisor = firstNumber;
		if (firstNumber > secondNumber)
			divisor = secondNumber;
		auto point = absNum / static_cast<double>(divisor);
		return point * 60;
	}

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