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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next=head;

        ListNode*grpPrev=&dummy;

        while(true){
            ListNode*kth=grpPrev;
            for(int i=0;i<k;i++){
                kth=kth->next;

                if(kth==NULL){
                    return dummy.next;
                }
            }
            ListNode*grpNext=kth->next;
            ListNode*prev=grpNext;
            ListNode*curr=grpPrev->next;

            while(curr!=grpNext){
                ListNode*temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }

            ListNode*temp=grpPrev->next;
            grpPrev->next=kth;
            grpPrev=temp;

        }
    }
};
