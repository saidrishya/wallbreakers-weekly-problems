class Solution {
public:
     int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums.empty()?0:nums[0];
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
    
    int helper(vector<int>& nums, int l, int r){
        if(r - l == 1)
            return nums[l];
        vector<int> dp(r, 0);
        dp[l] = nums[l];
        dp[l+1] = max(nums[l], nums[l+1]);
        for(int i = l + 2; i < r; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp.back();
    }
};
