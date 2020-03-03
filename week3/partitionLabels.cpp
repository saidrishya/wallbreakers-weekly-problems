class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
       vector<int> a(26, -1);
        string temp = "";
        
       for(int i = 0 ; i < S.length(); i++)
       {
           //Assuming string is all in lowercase
           a[S[i] - 'a'] = i;
       }
        
        for(int i = 0; i < S.length(); i++)
        {
            int last = a[S[i] - 'a'];
            int j=i;
            for(j = i; j <= last; j++)
            {
              
                if(a[S[j] - 'a'] > last)
                {
                    last = a[S[j] - 'a'];
                }
            }
            res.push_back(j-i);
            i = last;
        }
return res;
    }
};
