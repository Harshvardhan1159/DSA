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
    private:
    void insertattail(ListNode* &anshead, ListNode* &anstail,int digit){
        ListNode* temp = new ListNode(digit);
        if(anshead==NULL){
            anshead=temp;
            anstail=temp;
        }
        else{
            anstail->next = temp;
            anstail=temp;
        }
    }
    private:
  ListNode * add(ListNode* l1, ListNode* l2){
        int carry = 0;
        int sum ;
        int digit;
         ListNode*anshead=NULL;
          ListNode*anstail=NULL;

        while(l1 && l2){
         sum = carry + l1->val+l2->val;
         digit = sum%10;
         insertattail(anshead,anstail,digit);
         carry = sum/10; 
         l1=l1->next;
         l2=l2->next;
        }
        while(l1){
            sum = carry + l1->val;
         digit = sum%10;
         insertattail(anshead,anstail,digit);
         carry = sum/10; 
         l1=l1->next;
        }
        while(l2){
              sum = carry + l2->val;
         digit = sum%10;
         insertattail(anshead,anstail,digit);
         carry = sum/10; 
         l2=l2->next;
        }
       if(carry!=0){
              sum = carry;
         digit = sum%10;
         insertattail(anshead,anstail,digit);
         carry = sum/10; 
        }
        return anshead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=add(l1,l2);
        return ans;
    }
};