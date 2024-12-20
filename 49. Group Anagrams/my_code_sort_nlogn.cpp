/*
Time complexity: O(n*str.size()*[str.size() * log(str.size())])
Space complexity: O(n)    
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> SortStrToAnagrams;
        //SortStrToAnagrams.reserve(strs.size()); // "Average case linear in the size of the container, worst case quadratic." <-- https://en.cppreference.com/w/cpp/container/unordered_map/reserve
        
        for(string& str : strs){
            
            string CopyStr = str;
            sort(str.begin(), str.end());
            SortStrToAnagrams[str].push_back(move(CopyStr));
        }

        vector<vector<string>> ans;ans.reserve(SortStrToAnagrams.size());
        for(auto [Key, VectorAnagrams] : SortStrToAnagrams){
            ans.push_back(move(VectorAnagrams));
        }

        return ans;

    }
};
