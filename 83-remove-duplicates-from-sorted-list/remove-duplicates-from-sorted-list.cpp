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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* pre = head;
        ListNode* nex = head->next;
        ListNode* dis = head;
        while(nex!=NULL){
            if(pre->val==nex->val){
                dis = nex;
                nex = nex->next;
                pre->next = nex;
                dis->next = NULL; 
            }else{
                pre = nex;
                nex = nex->next;
            }
        }
        return head;
    }
};