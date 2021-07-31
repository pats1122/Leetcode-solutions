class Solution {
public:
    int getSum(int a, int b) {
        int sum =0, carry=0,res=0 ;
        for(int i=0; i<32; i++){
            sum = ((a>>i)&1) + ((b>>i)&1)+carry;
            res = res|((sum%2)<<i);
            carry = sum/2;
        }
        return res;
    }
};