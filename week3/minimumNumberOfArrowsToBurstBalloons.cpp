class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        
         if(intervals.size()==0) return 0;
         sort(intervals.begin(), intervals.end());
         int arrow=1;
        int end = intervals[0][1];
        
       
        for(int i=1; i<intervals.size(); i++){
           if(intervals[i][0] > end ){ //not merging{
               arrow++;
               end = intervals[i][1];
            }
            else{
                end = min(end, intervals[i][1]);
            }
        }
        
        return arrow;
       
    }
};
