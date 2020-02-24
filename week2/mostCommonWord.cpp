class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> ump;
        int n = paragraph.size();
        int i = 0;
        int maxCount = 0;
        string res;
        while (i < n)
        {
            if (isalpha(paragraph[i]))
            {
                string tmp;
                while (i < n && isalpha(paragraph[i]))
                {
                    tmp.push_back(tolower(paragraph[i++]));
                }
                if(++ump[tmp] > maxCount && (!isBanned(banned, tmp)))
                {
                    maxCount = ump[tmp];
                    res = tmp; 
                    
                }
            }
            ++i;
        }
        
        return res;
        
    }
    
    bool isBanned(vector<string>& banned, string str)
    {
        for (auto s:banned)
            if (str == s)
                return true;
        
        return false;
    }
};
