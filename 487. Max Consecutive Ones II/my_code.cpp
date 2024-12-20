/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums, int CountUpdZero = 1) { // CountUpdZero = 1 <-- "you can flip at most one 0."      
        
        int Ans = 0;

        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){ // сдвиг правого указателя

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}

            while(CountUpdZero < 0){ // сдвиг левого указателя
                //if(nums[LeftBorderWindow++] == 0){++CountUpdZero;} // equiv
                if(nums[LeftBorderWindow] == 0){++CountUpdZero;}
                LeftBorderWindow++;
            }

            // if(CountUpdZero != 0){ assert(LeftBorderWindow < RightBorderWindow); } // error: nums = [1,1,1,0,0,0,1,1,1,1,0] k = 2
            assert(LeftBorderWindow <= RightBorderWindow); // LeftBorderWindow == RightBorderWindow по меньшей мере в самом начале, когда указывают на первый элемент
            
            // В отрезке [LeftBorderWindow, RightBorderWindow] содержится максимум CountUpdZero нулей
            Ans = max(Ans, RightBorderWindow - LeftBorderWindow  + 1);
        }

        return Ans;
    }
};
