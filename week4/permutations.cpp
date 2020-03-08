class Solution {
public:
      vector<vector<int>> res;
    
    void dfs(vector<int> nums, vector<int> &curr, vector<int> &visit){
        if(curr.size() == nums.size()) {
             res.push_back(curr);
            return;
        }
         for(int i = 0; i < nums.size(); ++i){
            if(!visit[i]){
                curr.push_back(nums[i]); visit[i] = 1;
                dfs(nums, curr, visit);
                curr.pop_back(); visit[i] = 0;
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return res;
         vector<int> visit(nums.size(), 0), curr;
        dfs(nums, curr, visit);
        return res;
    }
};
