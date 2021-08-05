class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        sort(primes.begin(), primes.end());
        
        priority_queue<long long, vector<long long>, greater<long long>>minq(primes.begin(), primes.end());
        minq.push(1);
        
        for(int i=1; i<n; i++){
            int top = minq.top();
            minq.pop();
            bool flag = false;
            for(int j=0; j<primes.size(); j++){
                if(flag) break;
                if(top%primes[j]==0){
                    for(int k=0; k<=j; k++){
                        minq.push((long)primes[k]*top);
                    }
                    flag = true;
                }    
            }
        }
        
        return minq.top();
    }
};