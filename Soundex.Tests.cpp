#include "Soundex.h"
#include <gtest/gtest.h>

TEST(GetMappedSoundexCodeTest, MappedSoundex) {
    EXPECT_EQ(Soundex::generateSoundex("Smith"), "S530");
    EXPECT_EQ(Soundex::generateSoundex("Johnson"), "J525");
    EXPECT_EQ(Soundex::generateSoundex("Robert"), "R163");
}

TEST(HandlesEmptyInputTest, EmptyInput) {
    EXPECT_EQ(Soundex::generateSoundex(""), "0000");
}

TEST(HandlesAdjacentLettersWithSameCodeTest, AdjacentSameCode) {
    EXPECT_EQ(Soundex::generateSoundex("Bbb"), "B100");
    EXPECT_EQ(Soundex::generateSoundex("Dddd"), "D300");
}

TEST(HandlesLongNamesTest, LongNames) {
    EXPECT_EQ(Soundex::generateSoundex("Washington"), "W252");
    EXPECT_EQ(Soundex::generateSoundex("Robert"), "R163");
}

TEST(HandlesSpecialCharactersTest, SpecialCharacters) {
    EXPECT_EQ(Soundex::generateSoundex("O'Connor"), "O256");
    EXPECT_EQ(Soundex::generateSoundex("Smith-Jones"), "S530");
}

TEST(HandlesVowelsAndNonMappedCharactersTest, VowelsAndNonMapped) {
    EXPECT_EQ(Soundex::generateSoundex("Aeiou"), "A000");
    EXPECT_EQ(Soundex::generateSoundex("Hwy"), "H000");
}

