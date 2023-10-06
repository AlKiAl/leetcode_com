constexpr int SIZE_ALPHABET = 26;

class Solution {

private:

    // https://github.com/SkosMartren/leetcode_com/blob/main/README.md#setting-the-size-of-an-array-in-a-private-section
    //constexpr int SIZE_ALPHABET = 26; // 'Solution::SIZE_ALPHABET' cannot be declared with 'constexpr' specifier // почему так?
    int LengthSubstr = 0;
public:

    int lengthOfLongestSubstringKDistinct(string_view s, int k) { // "0 <= k <= 50"

        if(k <= 0){ return LengthSubstr; }


        array<int, SIZE_ALPHABET> CharToCount; CharToCount.fill(0);        

        for (int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow <= s.size() - 1; ++RightBorderWindow) { // move Right ptr

            if (++CharToCount[s[RightBorderWindow] - 'a'] == 1) { // новая буква (CharToCount[RightBorderWindow]) в sliding window
                --k;
            } // RightBorderWindow указывет на последний символ sliding window 
              
            while (LeftBorderWindow < RightBorderWindow && k < 0) { // move Left ptr

                if (--CharToCount[s[LeftBorderWindow] - 'a'] == 0) {
                    ++k;
                }
                ++LeftBorderWindow;
            } // LeftBorderWindow указывет на первый символ sliding window

            LengthSubstr = max(LengthSubstr, RightBorderWindow - LeftBorderWindow + 1);
            assert(LeftBorderWindow <= RightBorderWindow);
        }

        return LengthSubstr;
    }

};