#include "Soundex.h"
#include <unordered_map>
#include <cctype>
#include <string>

std::string Soundex::generateSoundex(const std::string& name) {
    if (name.empty()) return "0000";

    std::string result(1, std::toupper(name[0])); 
    char prevCode = getMappedSoundexCode(name[0]);
    size_t length = 1;

    for (size_t i = 1; i < name.length() && length < 4; ++i) {
        char currentCode = getMappedSoundexCode(name[i]);
        if (SoundexCodeCheck(currentCode, prevCode)) {
            result += currentCode;
            prevCode = currentCode;
            length++;
        }
    }

    return result.append(4 - result.length(), '0'); 
}

char Soundex::getMappedSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap {
        {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'}, {'Y', '0'}, {'H', '0'}, {'W', '0'},
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    auto it = soundexMap.find(toupper(c));
    return (it != soundexMap.end()) ? it->second : '0';
}

bool Soundex::SoundexCodeCheck(char code, char prevCode) {
    return code != '0' && code != prevCode;
}
