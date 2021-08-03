//merge sort
class Solution {
public:
    void merge(vector<int> &nums, int start, int end, int mid ){
        int n1 = mid-start+1;
        int n2 = end-mid;
        vector<int> num1 (n1);
        vector<int> num2 (n2);
        
        for(int i=0; i<n1; i++)
            num1[i] = nums[start+i];
        for(int i=0; i<n2; i++)
            num2[i] = nums[i+mid+1];
        
        int p1=0,p2=0,p=start;
        while(p1<n1 && p2<n2){
            if(num1[p1]<=num2[p2]){
                nums[p] = num1[p1];
                p++;
                p1++;
            }
            else{
                nums[p] = num2[p2];
                p++;
                p2++;
            }
        }
        while(p1<n1){
            nums[p] = num1[p1];
            p++; p1++;
        }
        while(p2<n2){
            nums[p] = num2[p2];
            p++; p2++;
        }
    }
    void mergeSort(vector<int> &nums, int start, int end){
        if(start<end){
            int mid = start+(end-start)/2;
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            merge(nums,start,end, mid);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        //merge sort
        mergeSort(nums,0, nums.size()-1);
        return nums;
    }
};