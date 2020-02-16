class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.size()==0 || S.size()==0) return 0;
        int res=0;
        unordered_map<char, int> m;
        for(auto i : J){
            m[i]++;
        }
        for(auto i: S){
            if(m.find(i) != m.end()) res++;
        }
        return res;
        
    
    }
};
