//recursive
class Solution {
public:
    double power(double x, long int n){
        if(n==0) return 1;
        double temp = power(x,n/2);
        temp = temp*temp;
        if(n%2==0) return temp;
        else
            return x*temp;
    }
    double myPow(double x, int n) {
        long int p = n;
        if(p<0) p = -1*p;
        double ans = power(x,n);
        if(n<0) return 1/ans;
        return ans;
    }
};