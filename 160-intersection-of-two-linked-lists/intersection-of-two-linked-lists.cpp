
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* temp = headA;
        ListNode* temp1 = headB;
        while(temp!=nullptr){
            temp=temp->next;
            lenA++;
        }
        cout<<lenA<<endl;
        while(temp1!=nullptr){
            temp1=temp1->next;
            lenB++;
        }
        if(lenA>lenB){
            temp = headA;
            while(lenA!=lenB){
                temp = temp->next;
                lenA--;
            }
            while(temp && temp!=headB){
                temp = temp->next;
                headB = headB->next;
            }
        }
        else{
            temp = headB;
            while(lenA!=lenB){
                temp = temp->next;
                lenB--;
            }
            while(temp && temp!=headA){
                temp = temp->next;
                headA = headA->next;
            }
        }
        return temp;
    }
};