class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(nums.size() == k){ // k is in the range [1, The number of unique nums[i]]            
            //ranges::sort(nums); //  You may return the answer in any order.
            return nums;
        }   

        unordered_map<int, int> NumToCount; 
        //NumToCount.reserve(nums.size() - 1); // медленно работает, сам. докуменатцию!

        for(int num : nums){
            ++NumToCount[num];
        } 

         vector<pair<int, int>> CountToNum; CountToNum.reserve(nums.size() - 1);

         for(auto [num, cnt] : NumToCount){

            CountToNum.push_back({cnt, num});

         }        

        nth_element(
            CountToNum.begin(),
            CountToNum.begin() + k,
            CountToNum.end(), 
            [](const auto F, const auto S){
                return F.first > S.first;
            }
        );

        vector<int> TopK; TopK.reserve(k);

        for(int i = 0; i < k; ++i){
            TopK.push_back(CountToNum[i].second);
        }

        return TopK;
    }
};
