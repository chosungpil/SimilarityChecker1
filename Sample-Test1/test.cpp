#include "pch.h"
#include "../Project6/SimilarityChecker.cpp"
class SimilarityChecker_Fixture : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
};
TEST_F(SimilarityChecker_Fixture, PerfectMatch) {
	EXPECT_EQ(60, similarityChecker.checkLengthSimilarity("ASD", "DSA"));
}
TEST_F(SimilarityChecker_Fixture, SecondParamTwoTimesLongerThanFirstParam) {
	EXPECT_EQ(0, similarityChecker.checkLengthSimilarity("A", "DS"));
}
TEST_F(SimilarityChecker_Fixture, FirstParamTwoTimesLongerThanSecondParam) {
	EXPECT_EQ(0, similarityChecker.checkLengthSimilarity("AA", "D"));
}
TEST_F(SimilarityChecker_Fixture, PartialPointWithLongFirstParam) {
	EXPECT_EQ(40, similarityChecker.checkLengthSimilarity("AAABB", "BAA"));
}
TEST_F(SimilarityChecker_Fixture, PartialPointWithLongSecondParam) {
	EXPECT_EQ(40, similarityChecker.checkLengthSimilarity("BAA", "AAABB"));
}