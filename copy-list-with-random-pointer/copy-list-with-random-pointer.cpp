/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copy(Node *head, unordered_map<Node*, Node*> &um){
        if(head==NULL) return NULL;
        Node *newN = new Node(head->val);
        um[head] = newN;
        
        Node *temp = head;
        while(temp != NULL){
            if(um.find(temp->next)==um.end())
                um[temp]->next  = copy(temp->next,um);
            else
                um[temp]->next = um[temp->next];
            
            if(um.find(temp->random)==um.end())
                um[temp]->random  = copy(temp->random,um);
            else
                um[temp]->random = um[temp->random];
            
            temp = temp->next;
        }
        return um[head];
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*, Node*> um;
        return copy(head,um);
    }
};