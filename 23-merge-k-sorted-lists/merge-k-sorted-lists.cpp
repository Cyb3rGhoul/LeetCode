class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            if (node->next) {
                pq.push(node->next);
            }

            temp->next = node;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};
