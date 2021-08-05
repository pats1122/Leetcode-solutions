class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n,true);
        
        for(int i=2; i*i<n; i++){
            if(isPrime[i]==false) continue;
            for(int j=i*i; j<n; j+=i)
                isPrime[j] = false;
        }
        
        int count=0;
        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};