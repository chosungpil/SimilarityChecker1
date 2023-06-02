#include "pch.h"
#include "../Project6/SimilarityChecker.cpp"
TEST(SimilarityCheckerTest, PerfectMatch) {
	SimilarityChecker similarityChecker;
	EXPECT_EQ(60, similarityChecker.checkLengthSimilarity("ASD", "DSA"));
}
TEST(SimilarityCheckerTest, SecondParamTwoTimesLongerThanFirstParam) {
	SimilarityChecker similarityChecker;
	EXPECT_EQ(0, similarityChecker.checkLengthSimilarity("A", "DS"));
}
TEST(SimilarityCheckerTest, FirstParamTwoTimesLongerThanSecondParam) {
	SimilarityChecker similarityChecker;
	EXPECT_EQ(0, similarityChecker.checkLengthSimilarity("AA", "D"));
}
TEST(SimilarityCheckerTest, PartialPointWithLongFirstParam) {
	SimilarityChecker similarityChecker;
	EXPECT_EQ(40, similarityChecker.checkLengthSimilarity("AAABB", "BAA"));
}
TEST(SimilarityCheckerTest, PartialPointWithLongSecondParam) {
	SimilarityChecker similarityChecker;
	EXPECT_EQ(40, similarityChecker.checkLengthSimilarity("BAA", "AAABB"));
}