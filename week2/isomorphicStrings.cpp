class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int m[256];
      memset(m,-1,sizeof(m));
    bool vis[256]={false};
        for(int i=0; i<s.size(); i++){
            if(m[s[i]] == -1){
                if(vis[t[i]] == true) return false;
                m[s[i]] = t[i];
                vis[t[i]] = true;
            }
            if(m[s[i]] != t[i]) return false;
        }
        return true;
        
        
        
        
    }
};
