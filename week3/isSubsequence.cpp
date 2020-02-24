class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=s.size()-1;
        for(int i=t.size()-1; i>=0; i--){
            if(s[j] == t[i]){
                s.pop_back();
                j=s.size()-1;    
            }
            if(s.size()==0) return true;
        }
        return s.size()==0;
    }
};
