class Solution {
public:
    int compress(vector<char>& chars) {

        // искомое
        int NewLength = 0; // при смещение в циклах будет указывать на потенциальный новый элемент в обновленном chars

        for(int i = 0; i < chars.size() ; ++i){

            const char prev_char = chars[i]; 
            chars[NewLength] = prev_char; // "The compressed string s should not be returned separately, but instead, be stored in the input character array chars. "
            ++NewLength; // инкрементируем, так как учитываем prev_char

            
            // CountRepeat -- количество повторяющихся символов prev_char, которые расположены в диапозоне [i, j] : i <= j
            int CountRepeat = 1; // 1, так как учитываем prev_char
            
            // обновление CountRepeat
            for(; i+1 < chars.size() && prev_char == chars[i+1]; ++i){ // "i+1" ввиду того, что chars[i] обработали выше                 
                ++CountRepeat;                            
            }

            
            // используем тот факт, что |substr| < |substr.size()|, где |*| -- функция, возвращающая длину строки *
            if(CountRepeat > 1){ // "Note that group lengths that are 10 or longer will be split into multiple characters in chars."

                for(const char ch : to_string(CountRepeat)){
                    
                    chars[NewLength] = ch; // "The compressed string s should not be returned separately, but instead, be stored in the input character array chars. "
                    ++NewLength;
                    // equiv: chars[NewLength++] = ch;
                }

            }

        }

        return NewLength;
    }
};
