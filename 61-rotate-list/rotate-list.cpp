class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Compute the length of the list
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Make it a circular list
        tail->next = head;

        // Step 3: Find the new tail: (length - k % length - 1)th node
        k %= length;
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // Step 4: Set the new head and break the loop
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
