class Solution {

public:
    int maxSubArray(const vector<int>& nums) {

        // "nums.front()" существует ввиду "1 <= nums.length <= 10^5"
        int CurrentMaxAffixSum = nums.front();
        int TotalMaxAffixSum = nums.front();

        for (size_t i = 1; i < nums.size(); i++) {
            CurrentMaxAffixSum = max(CurrentMaxAffixSum + nums[i], nums[i]);
            TotalMaxAffixSum = max(TotalMaxAffixSum, CurrentMaxAffixSum);
        }

        return TotalMaxAffixSum;

    }
};

/*
Заметим, что CurrentMaxAffixSum зависит от i.
    При i = 0 есть всего один аффикс, его и записываем
    при i = 1 есть два возможных аффикса: [0,1] и [1] -- один из них, максимальный, и окажется в CurrentMaxAffixSum
    ...
    Положим, CurrentMaxAffixSum верно работает для любого i = n - 1 : n \in |N. Докажем, что оно верно работате и для i = n:
    
    
*/
