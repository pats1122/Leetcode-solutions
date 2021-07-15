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
    ListNode* rotateRight(ListNode* head, int k) {
        //null or 1 node or k=0
        if(head==NULL || head->next ==NULL || k==0) return head;
        
        ListNode *temp1=head, *temp2=head, *t=head;
 
        //counting number of nodes
        int count =0;
        while(t!=NULL){
            t=t->next;
            count++;
        }
        
        //if k is multiple of number of nodes, list remains the same 
        if(k%count==0 ) return head;
        
        //if k is greater than count
        k = k>count ? k%count : k;

        for(int i=1; i<=k; i++){
            temp1 = temp1->next;
        }
        
        while(temp1->next!=NULL){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        //temp2 is at (K+1)th node from last
        ListNode *head1= temp2->next;
        //temp1 is at last node of list
        temp1->next = head;
        temp2->next = NULL;
        
        return head1; 
        
        
    }
};