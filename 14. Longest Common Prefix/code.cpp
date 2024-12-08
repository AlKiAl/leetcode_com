class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) {return "";}

        for (int i = 0; i < strs.front().size(); i++) {

            char CurCh = strs.front()[i];

            for (int j = 1; j < strs.size(); j++) {
                if (
                i == strs[j].size() /*strs.front().size() -- макисмальная длина ответа*/
                || 
                strs[j][i] != CurCh /*нарушение условия на префикс*/
                )
                    {return strs.front().substr(0, i);}
            }
        }
      
        return strs.front();
    }
};
