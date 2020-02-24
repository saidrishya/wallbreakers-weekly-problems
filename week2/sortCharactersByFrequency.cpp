class Solution {
public:
    string frequencySort(string s) {
       map<char,int> m;
        for(auto ch : s){
            m[ch]++;
        }
        vector<pair<int,char>> rec;
        for(auto& x:m){
            rec.emplace_back(x.second,x.first);
        }
        sort(rec.begin(),rec.end(),[](const auto& a, const auto& b){
            return a>b;
        });
        string res;
        for(auto& x:rec){
            while(x.first){
                res += x.second;
                x.first--;
            }
        }
        return res;
        
    }
};
