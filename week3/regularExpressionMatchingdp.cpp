class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size()+1][p.size()+1];
        memset(dp, false, sizeof(dp));
        dp[s.size()][p.size()]=true;
        for (int i=s.length();i>=0;i--) { 
            for (int j=p.length()-1;j>=0;j--) {
                bool firstMatch = i < s.length() && (s[i] == p[j] || p[j] == '.');
                if (j+1 < p.length() && p[j+1] == '*') {
                    dp[i][j] = firstMatch && dp[i+1][j] || dp[i][j+2];
                } else {
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
        
        
    }
};
