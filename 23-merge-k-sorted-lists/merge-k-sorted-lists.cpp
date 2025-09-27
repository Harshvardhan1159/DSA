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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = lists.size();
        for(int i=0;i<n;i++){
            ListNode* head = lists[i];
            while(head!=NULL){
                pq.push(head->val);
                head=head->next;
            }
        }
        ListNode* tail=NULL;
        ListNode* head=NULL;
        while(!pq.empty()){
            ListNode* x = new ListNode(pq.top());
            pq.pop();
           if(head==NULL){
            head=x;
            tail=x;
           }else{
            tail->next=x;
            tail=x;
           }
        }
        return head;
    }
};