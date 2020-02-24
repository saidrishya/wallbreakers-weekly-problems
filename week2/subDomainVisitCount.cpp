class Solution {
public:
    vector<string> subdomainVisits(vector<string>& d) {
        unordered_map<string, int> m;
        for(int i=0; i<d.size(); i++){
            int n=d[i].size(),x;
            for(int j=0; j<n; j++){
                if(d[i][j] == ' '){
                    string c = d[i].substr(0,j);
                    x = stoi(c);
                    string t = d[i].substr(j+1);
                    m[t] +=x;
                }
                if(d[i][j] == '.'){
                    string t = d[i].substr(j+1);
                    m[t]+=x;
                }
            }
        }
        
        vector<string> res;
        for(auto i: m){
            string z = to_string(i.second);
            string s = z + ' ' + i.first;
            res.push_back(s);
        }
        
        return res;
        
        }
    
};
