#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int checkLengthSimilarity(string a, string b)
	{
		if(b.size() >= (a.size() * 2))
		{
			return 0;
		}
		if (a.size() >= (b.size() * 2))
		{
			return 0;
		}
		return 60;
	}
};