#include <cctype>
#include <string>
#include <unordered_map>



// Function to get the Soundex code for a given input string 
char getSoundexCode(char c, const std::unordered_map<char, char>& soundexMap)
{
    char upperChar = toupper(c);
    auto it = soundexMap.find(upperChar);
    return it != soundexMap.end() ? it->second : '0';
}



std::string generateSoundex(const std::string& name)
{
    if (name.empty()) return "";



    // Soundex code to mapthe keys and values
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };



    std::string soundex;
    soundex += toupper(name[0]);  // Initilizing the string first letter
    char prevCode = getSoundexCode(soundex[0], soundexMap);  



    for (size_t Char = 1; Char < name.length() && soundex.length() < 4; ++Char) 
    {
        char code = getSoundexCode(name[Char], soundexMap);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }



    soundex.append(4 - soundex.length(), '0');  // Pad with '0's if needed



    return soundex;
}
