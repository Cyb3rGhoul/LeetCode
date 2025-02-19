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

#include <deque>
class Solution {
public:
    int pairSum(ListNode* head) {
        deque<int> q;
        while(head!=NULL){
            q.push_back(head->val);
            head = head->next;
        }
        int maxi = INT_MIN;
        while(!q.empty()){
            maxi = max(maxi,q.front()+q.back());
            q.pop_front();
            if(!q.empty()) q.pop_back();
        }
        return maxi;
    }
};