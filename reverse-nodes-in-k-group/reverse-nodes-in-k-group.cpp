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
        if(head==NULL || k==1) return head;
        
        ListNode *temp = head;
        int count=0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *curr=dummy, *prev=dummy, *nex = dummy;
        
        while(count>=k){
            curr =  prev->next;
            nex = curr->next;
            
            //runs k-1 times
            for(int i=1; i<k; i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev=curr;
            count -= k;
        }
        return dummy->next;
    }
};