class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp(nums2.size()),res;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i])s.pop();
            tmp[i]=s.empty()?-1:s.top();
            s.push(nums2[i]);
        }
        for(int i:nums1){
            auto j=find(nums2.begin(),nums2.end(),i);
            if(j==nums2.end())res.push_back(0);
            else res.push_back(tmp[j-nums2.begin()]);
        }
        return res;
    }
};
