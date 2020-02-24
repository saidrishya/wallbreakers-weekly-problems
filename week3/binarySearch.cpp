class Solution {
public:
    int search(vector<int>& nums, int target) {
       // if(nums.size()==1 && nums[0]==target) return 0;
        int l=0,h=nums.size()-1,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            if(target>nums[mid]) l=mid+1;
            else h=mid-1;
        }
return ans;
    }
};
