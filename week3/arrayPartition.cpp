class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sim=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i+=2){
            sim+= min (nums[i], nums[i+1]);
        }
        return sim;
    }
};
