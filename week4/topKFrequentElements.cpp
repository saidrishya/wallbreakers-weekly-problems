class Solution {
public:
    
    struct Node{
        int count, val;
        
    bool operator <(Node a) const  {  return count < a.count; }
    bool operator >(Node a) const  {  return count > a.count; }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<Node> pq;
      unordered_map<int, int> m;
        for(auto i: nums){
            m[i]++;
        }
        
        for(auto i: m){
            pq.push({i.first, i.second});
        }
        
        vector<int> res;
        for(int i=0; i<k; i++){
           Node item = pq.top();
            pq.pop();
            res.push_back(item.val);
        }
        return res;
    }
};
