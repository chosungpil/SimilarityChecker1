#include "pch.h"
#include "../Project6/SimilarityChecker.cpp"
class SimilarityChecker_Fixture : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
};
TEST_F(SimilarityChecker_Fixture, LengthPerfectMatch) {
	EXPECT_EQ(60, similarityChecker.checkLengthSimilarity("ASD", "DSA"));
}
TEST_F(SimilarityChecker_Fixture, LengthSecondParamTwoTimesLongerThanFirstParam) {
	EXPECT_EQ(0, similarityChecker.checkLengthSimilarity("A", "DS"));
}
TEST_F(SimilarityChecker_Fixture, LengthFirstParamTwoTimesLongerThanSecondParam) {
	EXPECT_EQ(0, similarityChecker.checkLengthSimilarity("AA", "D"));
}
TEST_F(SimilarityChecker_Fixture, LengthPartialPointWithLongFirstParam) {
	EXPECT_EQ(20, similarityChecker.checkLengthSimilarity("AAABB", "BAA"));
}
TEST_F(SimilarityChecker_Fixture, LengthPartialPointWithLongSecondParam) {
	EXPECT_EQ(20, similarityChecker.checkLengthSimilarity("BAA", "AAABB"));
}
TEST_F(SimilarityChecker_Fixture, AlphaPerfectMatch) {
	EXPECT_EQ(40, similarityChecker.checkAlphaSimilarity("ASD", "DSA"));
}
TEST_F(SimilarityChecker_Fixture, AlphaNeverMatch) {
	EXPECT_EQ(0, similarityChecker.checkAlphaSimilarity("A", "BB"));
}
TEST_F(SimilarityChecker_Fixture, AlphaLowerCase) {
	EXPECT_THROW(similarityChecker.checkAlphaSimilarity("a", "Bb"), std::invalid_argument);
}
TEST_F(SimilarityChecker_Fixture, AlphaPartialMatch) {
	EXPECT_EQ(40, similarityChecker.checkAlphaSimilarity("AAABB", "BA"));
}