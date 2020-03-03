class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        if(n<k) k=k-n;
        if(n==0 || n==1 || k==0) return;
        queue<int> q;
       for(int i=n-1; i>=0; i--){
           q.push(nums[i]);
       }
        for(int i=0; i<k; i++){
            int k=q.front();
            q.pop();
            q.push(k);            
        }
        
        for(int i=n-1; i>=0; i--){
            nums[i] = q.front();
            q.pop();
        }
    }
};
