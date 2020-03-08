class Solution {
void generate(int depth, vector<int>& path, 
              vector<vector<int>>& ans, vector<int>& nums){
    
        ans.push_back(path);
        for(int i = depth; i < nums.size(); ++i){
            path.push_back(nums[i]);
            generate(i + 1, path, ans, nums);
            path.pop_back();
        }
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        generate(0, path, ans, nums);
        return ans;
    }
    
};
