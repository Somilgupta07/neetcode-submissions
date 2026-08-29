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
    void reorderList(ListNode* head) {
        // first find the halves
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        // reverse the second half
        ListNode*second=slow->next;
        slow->next=nullptr;
        ListNode*prev=nullptr;
        while(second!=nullptr){
            ListNode*next=second->next;
            second->next=prev;
            prev=second;
            second=next;
        }

        ListNode*first=head;
        ListNode*secondHalf=prev;
        while(secondHalf!=nullptr){
            ListNode*temp1=first->next;
            ListNode*temp2=secondHalf->next;
            first->next=secondHalf;
            secondHalf->next=temp1;
            first=temp1;
            secondHalf=temp2;
        }


    }
};
