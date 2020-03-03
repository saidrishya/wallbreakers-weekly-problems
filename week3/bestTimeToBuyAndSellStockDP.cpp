class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size() , maxi=0, mini=INT_MAX;
        if(n==0) return maxi;
        for(int i=0; i<n; i++){
            mini = min(prices[i] , mini);
            maxi = max(maxi , prices[i]-mini);
        }
        
        return maxi;
        
    }
};
