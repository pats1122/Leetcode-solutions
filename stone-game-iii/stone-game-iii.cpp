class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int temp1, temp2, temp3;
        vector<int> dpAlice(n+3,0);
        vector<int> dpBob(n+3,0);
        
        for(int i=n-1; i>=0; i--){
            temp1 = temp2 = temp3 = stoneValue[i];
            
            if(i+1<n){
                temp2 += stoneValue[i+1];
                temp3 += stoneValue[i+1];
            }
            
            if(i+2<n)
                temp3 += stoneValue[i+2];
            
            dpAlice[i] = max(temp1+dpBob[i+1], max(temp2+dpBob[i+2], temp3+dpBob[i+3]));
            dpBob[i] = min(-temp1+dpAlice[i+1], min(-temp2+dpAlice[i+2], -temp3+dpAlice[i+3]));
        }
        
        if(dpAlice[0]>0) return "Alice";
        else if(dpAlice[0]==0) return "Tie";
        else return "Bob";
    }
};