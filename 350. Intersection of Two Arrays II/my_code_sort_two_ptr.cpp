/*
Time complexity: O(n+m)
Space complexity: O(n*log(n) + m*log(m))
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());


        vector<int> intersection; intersection.reserve(min(nums1.size(), nums2.size()));

        int Ptr_1 = 0;
        int Ptr_2 = 0;

        /*
        чтобы прийти к решению надо учесть события: 
        nums1[i] < nums2[j] --> сдвигаем указатель на nums1
        nums1[i] = nums2[j] --> сдвигаем оба указателя на проверку следующего элемента
        nums1[i] > nums2[j] --> сдвигаем указатель на nums2
        */        
        
        while(Ptr_1 < nums1.size() && Ptr_2 < nums2.size()){ // как только один из указателей указывает за последний элемент вектора, это означает, что просмотрели все элемменты вектора --> пересечений быть не может

            if(nums1[Ptr_1] == nums2[Ptr_2]){

                intersection.push_back(nums1[Ptr_1]);
                ++Ptr_1;
                ++Ptr_2;
                
            }else{
                
               (nums1[Ptr_1] < nums2[Ptr_2]) ? ++Ptr_1 : ++Ptr_2; // equiv
               /* так будет ошибочно, ввиду того, что можно сдвинуть Ptr_1 за границу массива, а потом обратиться к nums1[Ptr_1] -- что приведет к ошибке!
               Ptr_1 += (nums1[Ptr_1] < nums2[Ptr_2]);
               Ptr_2 += (nums1[Ptr_1] > nums2[Ptr_2]);
               */

            }

        }

        intersection.shrink_to_fit();
        return intersection;
    }
};
