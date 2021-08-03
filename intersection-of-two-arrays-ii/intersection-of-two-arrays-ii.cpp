class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1=nums1.size(), n2=nums2.size();
        int p1=0, p2=0, left, right;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(p1<nums1.size() && p2<nums2.size()){
            left = nums1[p1];
            right = nums2[p2];
            if(left==right){
                res.push_back(left);
                p1++;
                p2++;
                // while(p1<n1 && nums1[p1]==left)p1++;
                // while(p2<n2 && nums2[p2]==right)p2++;
            }
            else if(left>right){
                while(p2<n2 && nums2[p2]==right) p2++;
            }
            else{
                while(p1<n1 && nums1[p1]==left) p1++;
            }
        }
        return res;
    }
};