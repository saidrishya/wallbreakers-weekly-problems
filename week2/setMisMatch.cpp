class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size() , sum=0, s;
        map<int, int> m;
        for(auto i: nums){
            sum+=i;
            m[i]++;
        }
        int k;
        for(auto i: m){
            if(i.second > 1){
                k=i.first;
                break;
            }
        }
        
        s= (n*(n+1))/2;
        
return {k , s-sum+k};
    }
};
