#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
constexpr int PARTIAL_POINT_MULTIPLIER = 60;
constexpr int MAX_POINT_FOR_LENGTH_CHECKER = 60;
constexpr int MAX_POINT_FOR_ALPHA_CHECKER = 40;
constexpr int MAX_ALPHA_NUM = 26;
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
		assertionForLowerCase(firstParam, secondParam);
		if(firstParam.size() != secondParam.size())
		{
			if (false == isSameCharExist(firstParam, secondParam))
			{
				return 0;
			}
		}
		else if (firstParam.size() == secondParam.size())
		{
			return 40;
		}
		int sameCount = getSameCount(firstParam, secondParam);
		int totalCount = getTotalCount(firstParam, secondParam);
		cout << sameCount << endl;
		cout << totalCount << endl;
		return (sameCount / totalCount) * 40;

	}
private:
	int getSameCount(string firstParam, string secondParam)
	{
		int sameCount = 0;
		bool alphaCountArrayForFirstParam[MAX_ALPHA_NUM]{ false };
		for (char firstParamChar : firstParam)
		{
			if (false == alphaCountArrayForFirstParam[firstParamChar - 'A'])
			{
				if (string::npos != secondParam.find(firstParamChar))
				{
					sameCount++;
					alphaCountArrayForFirstParam[firstParamChar - 'A'] = true;
				}
			}
		}
		return sameCount;
	}
	int getTotalCount(string firstParam, string secondParam)
	{
		bool alphaCountArray[MAX_ALPHA_NUM]{ false };
		for (char firstParamChar : firstParam)
		{
			alphaCountArray[firstParamChar - 'A'] = true;
		}
		for (char secondParamChar : secondParam)
		{
			alphaCountArray[secondParamChar - 'A'] = true;
		}
		int totalCount = 0;
		for (auto isExist : alphaCountArray)
		{
			if (isExist)
			{
				totalCount++;
			}
		}
		return totalCount;
	}
	void assertionForLowerCase(string firstParam, string secondParam)
	{
		for (char firstParamChar : firstParam)
		{
			if (firstParamChar < 'A' || firstParamChar > 'Z')
			{
				throw std::invalid_argument("Upper case only");
			}
		}
	}
	bool isSameCharExist(string firstParam, string secondParam)
	{
		bool hasSameChar = false;
		for (char firstParamChar : firstParam)
		{
			if (string::npos != secondParam.find(firstParamChar))
			{
				hasSameChar = true;
			}
		}
		return hasSameChar;
	}
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
	
	bool alphaCountArrayForSecondParam[MAX_ALPHA_NUM]{ false };
};