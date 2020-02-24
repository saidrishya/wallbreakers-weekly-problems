class Solution {
public:
    int firstUniqChar(string s) {
        multiset<char, greater<int > > f;
        for(int i=0; i<s.size(); i++)
        {
            f.insert(s[i]);
        }
        for(int i=0;i<s.size(); i++)
        {
            if(f.count(s[i]) == 1) return i;
        }
return -1;
    }
};
