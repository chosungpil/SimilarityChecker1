#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int checkLengthSimilarity(string firstParam, string secondParam)
	{
		if( true == isTwoTimesLong(firstParam.size(), secondParam.size()))
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
	bool isSecondParamTwoTimesBigger(int firstNumber, int secondNumber)
	{
		if (secondNumber >= (firstNumber * 2))
			return true;
		return false;
	}
	bool isFirstParamTwoTimesBigger(int firstNumber, int secondNumber)
	{
		if (firstNumber >= (secondNumber * 2))
			return true;
		return false;
	}
	bool isTwoTimesLong(int firstParamSize, int secondParamSize)
	{
		if (true == isSecondParamTwoTimesBigger(firstParamSize, secondParamSize))
		{
			return true;
		}
		if (true == isFirstParamTwoTimesBigger(firstParamSize, secondParamSize))
		{
			return true;
		}
		return false;
	}
};