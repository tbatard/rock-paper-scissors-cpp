#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockRockPaperScissors.h"
#include <RockPaperScissorsApp.h>
#include <fstream>

class RockPaperScissorsAppTest : public ::testing::Test {
protected:
  void SetUp() override {
    rockPaperScissorsApp = new RockPaperScissorsApp(&rockPaperScissors);
  }

  MockRockPaperScissors rockPaperScissors;
  RockPaperScissorsApp *rockPaperScissorsApp{};
};

TEST_F(RockPaperScissorsAppTest, start_callsDisplayMethod3Times) {
  std::ifstream mockedInput;
  EXPECT_CALL(rockPaperScissors, getDisplayChoice).Times(testing::Exactly(5));
  EXPECT_CALL(rockPaperScissors, getRandomChoice).Times(testing::Exactly(1));

  rockPaperScissorsApp->start(mockedInput);
}

TEST_F(RockPaperScissorsAppTest, displayChoices) {
  EXPECT_CALL(rockPaperScissors, getDisplayChoice).Times(testing::Exactly(3));

  testing::internal::CaptureStdout();

  rockPaperScissorsApp->displayChoices();

  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_STREQ("1: Rock\n2: Paper\n3: Scissors\n", output.data());
}

TEST_F(RockPaperScissorsAppTest, mapInputToChoice_whenInputIs1) {
  EXPECT_EQ(rockPaperScissorsApp->mapInputToChoice(1), ROCK);
}

TEST_F(RockPaperScissorsAppTest, mapInputToChoice_whenInputIs2) {
  EXPECT_EQ(rockPaperScissorsApp->mapInputToChoice(2), PAPER);
}

TEST_F(RockPaperScissorsAppTest, mapInputToChoice_whenInputIs3) {
  EXPECT_EQ(rockPaperScissorsApp->mapInputToChoice(3), SCISSORS);
}