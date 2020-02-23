class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<string, int> count;
        for(auto s : A)
        {
            string even = "", odd = "";
            for(int i = 0; i < s.size(); i++)
            {
                if(i % 2 == 0)
                    even += s[i];
                else odd += s[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            string key = even + odd;
            count[key]++;
        }
        return count.size();
    }
};
