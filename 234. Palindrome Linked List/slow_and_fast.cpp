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

class Solution {

public:
        bool isPalindrome(ListNode* head) {

        // ------------------------Быстрые и медленные указатели для поиска серидины-----------------------------------
        auto slow = head;
        auto fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // -----------------------------------------------------------


        // -----------------------REVERSE------------------------------------
        
        ListNode* HeadMid = (fast == NULL) ? slow : slow->next;
        ListNode* HeadEnd = NULL;

        while (HeadMid != NULL){
            auto temp = HeadMid->next;
            HeadMid->next = HeadEnd;
            HeadEnd = HeadMid;
            HeadMid = temp;
        }
        // -----------------------------------------------------------


        // ---------------------CHECK-PALINDROME--------------------------------------

        while (HeadEnd != NULL){

            if (head->val != HeadEnd->val){return false;}

            head = head->next;
            HeadEnd = HeadEnd->next;
        }
        // -----------------------------------------------------------

        return true;

    }
};

/*
class Solution {

public:
        bool isPalindrome(ListNode* head) {

        // ------------------------Быстрые и медленные указатели-----------------------------------
        auto slow = head;
        auto fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // -----------------------------------------------------------

        // -----------------------REVERSE------------------------------------
        auto begin = (fast == NULL) ? slow : slow->next;
        ListNode* prev = NULL;
        auto curr = begin;
        while (curr != NULL){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // -----------------------------------------------------------



        // ---------------------CHECK-PALINDROME--------------------------------------
        begin = prev;
        while (begin != NULL){

            if (head->val != begin->val){return false;}

            head = head->next;
            begin = begin->next;
        }
        // -----------------------------------------------------------

        return true;

    }
};
*/
