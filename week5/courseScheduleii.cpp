class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& pre) {
        vector<int> ans, alt;
        vector<int> inDegree(nc,0);
        vector<vector<int>> adj(nc, vector<int>());    
        for (auto i: pre) {
            adj[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0; i<nc; i++) {
            if (inDegree[i] == 0) 
                q.push(i);
        }
        while (!q.empty()) {
            int temp = q.front(); q.pop();
            nc--;
            ans.push_back(temp);
            for (auto j: adj[temp])
                if (--inDegree[j] == 0)
                    q.push(j);
        }
        
        return nc==0?ans:alt;             
    }
};
