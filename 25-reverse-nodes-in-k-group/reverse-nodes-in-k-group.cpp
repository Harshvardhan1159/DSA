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
    // Function to reverse a linked list
    ListNode* reverseLinkedList(ListNode *head) {
        ListNode* temp = head;  
        ListNode* prev = NULL;  

        while(temp != NULL) {  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }

        return prev;  
    }

    // Function to get the Kth node from a given node
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1; 
        while(temp != NULL && k > 0) {
            k--; 
            temp = temp->next; 
        }
        return temp; 
    }

    // Main function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; 
        ListNode* prevLast = NULL; 
        
        while(temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k); 
            if(kThNode == NULL) {
                if(prevLast) {
                    prevLast->next = temp; 
                }
                break; 
            }
            
            ListNode* nextNode = kThNode->next; 
            kThNode->next = NULL; 

            ListNode* newHead = reverseLinkedList(temp); 
            
            if(temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead; 
            }

            prevLast = temp; 
            temp = nextNode; 
        }

        return head; 
    }
};
