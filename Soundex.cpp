#include <cctype>
#include <string>
#include <unordered_map>
 
char getSoundexCode(char c, const std::unordered_map<char, char>& soundexMap) {
   char upperChar = toupper(c);
   auto it = soundexMap.find(upperChar);
   return it != soundexMap.end() ? it->second : '0';
}
 
std::string generateSoundex(const std::string& name) {
   if (name.empty()) return "";
 
   static const std::unordered_map<char, char> soundexMap = {
       {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
       {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
       {'D', '3'}, {'T', '3'},
       {'L', '4'},
       {'M', '5'}, {'N', '5'},
       {'R', '6'}
   };
 
   std::string soundex(1, toupper(name[0]));  // Start with the first letter
   char prevCode = getSoundexCode(soundex[0], soundexMap);
 
   for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
       char code = getSoundexCode(name[i], soundexMap);
       if (code != '0' && code != prevCode) {
           soundex += code;
           prevCode = code;
       }
   }
 
   soundex.append(4 - soundex.length(), '0');  // Pad with '0's if needed
  
   return soundex;
}
