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
        if(head==NULL) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }

        if(fast==NULL || fast->next==NULL) return NULL;

        
        fast = head;
        cout<<endl;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }

        // cout<<slow->val<<" slow "<<fast->val<<" fast"<<endl;

        return slow;
    }
};