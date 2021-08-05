class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        if(a->val <= b->val){
            a->next = merge(a->next, b);
            return a;
        }
        else {
            b->next = merge(a, b->next);
            return b;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        
        for(int i=1; i<n; i++){
            lists[0] = merge(lists[0], lists[i]);
        }
        return lists[0];
    }
};