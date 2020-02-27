class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        if(g.size()==0 || s.size()==0) return 0;
        
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int c=0,i=0,j=0;
        while(i<g.size() && j<s.size()){
            if(s[j] >= g[i]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
        
    }
};

