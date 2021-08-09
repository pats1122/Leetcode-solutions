class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),i,maxArea=0;
        stack<int> stk;
        stk.push(-1);
        
        //keeping stack to get right limit and left limit
        //keep heights in increasing order in stack
        //if curr height is less thn stk.top(), we pop it
        //and calculate maxArea possible due to stk.top()
        //by using left limit - element below top element
        //and right limit is current i
        //push current i
        for(i=0; i<n; i++){
            while(stk.top()!=-1 && heights[i]<heights[stk.top()]){
                int t = stk.top();
                stk.pop();
                maxArea = max(maxArea, (i-stk.top()-1)*heights[t]);
            }
            stk.push(i);
        }
        
        //calculate area for remaining elemnts present in stack 
        while(stk.top() != -1){
            int t = stk.top();
            stk.pop();
            maxArea = max(maxArea, (n-stk.top()-1)*heights[t]);
        }
        return maxArea;
    }
};