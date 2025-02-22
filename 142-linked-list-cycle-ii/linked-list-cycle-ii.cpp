/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
    while(head!=NULL){
        if(mp.find(head)!=mp.end())return head;
        mp[head]++;
        head=head->next;
        

    }
    return NULL;
    }
};