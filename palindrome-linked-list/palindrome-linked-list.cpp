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
    ListNode* reverse(ListNode *head){
        ListNode *prev=NULL, *curr;
        while(head){
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }
    bool isPalindrome(ListNode* head) {
        //NULL or one node
        if(head==NULL || head->next==NULL) return true;
        
        //take slow pointer to middle of ll in odd list
        //left middle in case of even list
        ListNode *fast=head, *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //reverse linked list from slow->next to end
        slow->next = reverse(slow->next);

        ListNode *p1 = head, *p2 = slow->next;
        while(p2!=NULL){
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};