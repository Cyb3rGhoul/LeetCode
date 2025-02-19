class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* nextNode = curr->next;  // Store next node
            curr->next = prev;  // Reverse the link
            prev = curr;  // Move prev forward
            curr = nextNode;  // Move curr forward
        }
        
        return prev;  // New head of the reversed list
    }
};
