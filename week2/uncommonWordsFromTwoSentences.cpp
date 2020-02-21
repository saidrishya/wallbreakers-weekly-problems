class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
       int begin=0,i=0;
        unordered_map<string, int> m;
        vector<string> res;
        string s = A + ' ' + B;
        for(i=0; i<s.size(); i++){
            if(s[i]==' '){
                m[s.substr(begin, i-begin)]++;
                begin=i+1;
            }
        }
        if(begin > 0){
            m[s.substr(begin, i-begin)]++;
        }
        
        for(auto j: m){
            if(j.second==1){
                res.push_back(j.first);
            }
        }
return res;
        
    }
};
