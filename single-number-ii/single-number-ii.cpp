class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0, count=0, mask=1, n=nums.size();
        
        for(int i=0; i<32; i++){
            count=0;
            mask = 1<<i;
            for(int j=0; j<n; j++){
                if((nums[j]&mask) != 0)
                    count++;
            }
            if(count%3 == 1)
                res = res | mask;
        }
        return res;
    }
};