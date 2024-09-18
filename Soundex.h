#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string> 

class Soundex {
public:
    static std::string generateSoundex(const std::string& name); 

private:
    static char getMappedSoundexCode(char c);
    static bool SoundexCodeCheck(char code, char prevCode);
};

#endif // SOUNDEX_HPP
