class Solution {
public:
    int distributeCandies(vector<int>& candies) {
       unordered_map<int,int> m;
       for(auto i: candies) m[i]++;
       return min(candies.size()/2, m.size() );
    }
};
