bool isBipartite(vector<vector<int>>& g) {
        int N = g.size();
        vector<int> color(N, 0);
        function<bool(int, int)> dfs = [&](int cur, int c) {
            if(color[cur] != 0) return color[cur] == c;
            color[cur] = c;
            for(auto nxt : g[cur]) if(!dfs(nxt, -c)) return false;
            return true;
        };

        for(int i = 0; i < N; i++) if(color[i] == 0 && !dfs(i, 1)) return false;
        return true;
    }
