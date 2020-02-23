class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> s;
        stringstream ss(str);        
        string tmp;
        while(getline(ss,tmp,' ')){
           s.push_back(tmp);         
        }
        unordered_map<char,string> m;
        unordered_map<string, char> im;

        if(pattern.size()!=s.size()) return false;
        for(int i=0; i<pattern.size(); i++){
            char val=pattern[i];
            string token=s[i];
            if(m.find(val) == m.end() && im.find(token) == im.end()){
                m[val]=token;
                im[token]=val;
            }
            else if(m.find(val)!=m.end() && im.find(token)!=im.end()){
                string token1=m.at(val);
                char val1= im.at(token);
                if( token!=token1 || val1!=val) return false;
            }
             else return false;
        }      
        
return true; 
    }
};
