class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<=j && s[i]==s[j]){
            i++;
            j--;
        }
        if(i>j) return true;
        return false;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i=0, j=n-1;
        
        while(i<=j && s[i]==s[j]){
            i++;
            j--;
        }
        
        if(i>j) return true;
        
        return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
    }
};