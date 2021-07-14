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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        ListNode *h1 = l1, *h2 = l2;
        while(h1!=NULL && h2!=NULL){
            ListNode *newN = new ListNode();
            temp->next = newN;
            temp = newN;
            if(h1->val < h2->val){
                newN->val = h1->val;
                h1=h1->next;
            }
            else{
                newN->val = h2->val;
                h2 = h2->next;
            }
        }
        while(h1!=NULL){
            ListNode *newN = new ListNode(h1->val);
            h1 = h1->next;
            temp->next = newN;
            temp = newN;
        }
        while(h2!=NULL){
            ListNode *newN = new ListNode(h2->val);
            h2 = h2->next;
            temp->next = newN;
            temp = newN;
        }
        return dummy->next;
    }
};