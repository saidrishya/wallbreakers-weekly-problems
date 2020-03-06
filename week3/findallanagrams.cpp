class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()==0) return res;
        int count[26] = {0};
        int exp[26] = {0};
        for(auto i: p){
            count[i-'a']++;
        }
        
        int window = p.size()-1, start=0;
        for(int i=0; i<s.size(); i++){
            exp[s[i] - 'a']++;
            if(i<window)
                continue;
            if(isEqual(exp,count)) res.push_back(start);
            exp[s[start++] - 'a']--;
        }
        return res;
    }
    
    bool isEqual(int exp[], int count[]){
        for(int i=0; i<26; i++){
            if(exp[i] != count[i]) return false;
        }
        return true;
    }
};
