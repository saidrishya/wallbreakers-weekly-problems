class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector <int> freq(n,0);
        unordered_map <int, vector<int>> m;
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(auto w : m)
        {
            for(auto ww : w.second) freq[ww]++;
        }
        for(auto w : freq) cout << w << endl;
        stack <int> s;
        for(int i = 0; i < freq.size(); ++i)
        {
            if(freq[i] == 0) s.push(i);
        }
        vector <int> res;
        while(not s.empty())
        {
            res.push_back(s.top());
            s.pop();
            for(auto w : m[res[res.size()-1]])
            {
                freq[w]--;
                if(not freq[w]) s.push(w);
            }
        }
        return (res.size() == n);
    }
};
