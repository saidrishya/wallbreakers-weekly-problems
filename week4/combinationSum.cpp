class Solution {
public:
    void dfs(vector<int> candidates, int index, int target, vector<int>& curr, 
               vector<vector<int>>& res)
    {
        if(target == 0){
            res.push_back(curr);
            return;
        }

        for(int i=index; i<candidates.size() && candidates[i] <= target; i++){
            
                curr.push_back(candidates[i]);
                dfs(candidates, i, target-candidates[i],curr,res);
                curr.pop_back();
            
        }
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates , 0 , target , curr, res);
        return res;
    }
};
