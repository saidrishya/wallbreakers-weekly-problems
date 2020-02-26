class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <=1 ) return intervals;
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        int j=0;
        for(int i=0; i+1<intervals.size(); i++){
            if(res[j][1] >= intervals[i+1][0]){
                res[j][1] = max(intervals[i+1][1], res[j][1]);
            }
            else {
                res.push_back(intervals[i+1]);
                j++;
            }
        }
        return res;
    }
};



