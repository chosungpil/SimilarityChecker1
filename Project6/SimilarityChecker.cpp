#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
constexpr int PARTIAL_POINT_MULTIPLIER = 60;
constexpr int MAX_POINT_FOR_LENGTH_CHECKER = 60;
constexpr int MAX_POINT_FOR_ALPHA_CHECKER = 40;
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

		return MAX_POINT_FOR_LENGTH_CHECKER;
	}
	int checkAlphaSimilarity(string firstParam, string secondParam)
	{
		if(firstParam.size() != secondParam.size())
		{
			bool hasSameChar = false;
			for(char firstParamChar : firstParam)
			{
				bool isFirstCharExist = false;
				
				for (char secondParamChar : secondParam)
				{
					if( firstParamChar == secondParamChar)
					{
						isFirstCharExist = true;
						break;
					}
				}
				if(true == isFirstCharExist)
				{
					hasSameChar = true;
				}
			}
			if (false == hasSameChar)
			{
				return 0;
			}
		}
		return 40;
	}
private:
	int calculatePartialPoint(int firstNumber, int secondNumber)
	{
		int absNum = abs((firstNumber - secondNumber));
		int divisor = firstNumber;
		if (firstNumber > secondNumber)
			divisor = secondNumber;
		auto point = absNum / static_cast<double>(divisor);
		return (1-point) * PARTIAL_POINT_MULTIPLIER;
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