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
    int sizeNode(ListNode* head){
        ListNode* temp = head;
        int ctn = 0;
        while(temp!=NULL){
            ctn++;
            temp=temp->next;
        }
        return ctn;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int l = sizeNode(head);
        if(l==1) return NULL;
        int mid = l/2;
        ListNode* p = head;
        ListNode* n = head;
        ListNode* t = head;
        int i = 0;
        while(i<mid-1){
            p = p->next;
            i++;
        }
        t = p->next;
        n = t->next;
        p->next = n;
        t->next = NULL;
        return head;
    }
};