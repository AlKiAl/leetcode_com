/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
Time complexity : O(n+m)
Space complexity : O(n+m)
*/	
class Solution {

public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

	    //---------------------УСЛОВИЕ ВЫХОДА ИЗ РЕКУРСИИ--------------------------------------
	    if(list1 == nullptr){return list2;} // list2 отсортирован, оставшиеся его элементы приписываются к ответу
	
	    if(list2 == nullptr) {return list1;} // list1 отсортирован, оставшиеся его элементы приписываются к ответу
		//-----------------------------------------------------------
        if(list1->val < list2->val){

            list1->next = mergeTwoLists(list1->next, list2);
            return list1;

        }else{

            list2->next = mergeTwoLists(list1, list2->next);
            return list2;  

        }
     
    }

};
