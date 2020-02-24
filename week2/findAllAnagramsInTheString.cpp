class Solution {
public:
  vector<int> findAnagrams(string& s, string& p) {
    vector<int> res;

    int PGroups = 0, SGroups = 0;
    vector<int> pSet(26, 0); 
    vector<int> sSet(26, 0);

    for(char c : p) {
      if(pSet[c-'a'] == 0) PGroups++;
      pSet[c-'a']++;
    }

    int i = 0, j = 0;

    while(i < s.size()){

      if(i >= p.size()){
        int c = s[j]-'a';
        if(sSet[c] == pSet[c]) SGroups--;
        --sSet[c];
        j++; //move j forward
      }

      int c = s[i]-'a';
      if(++sSet[c] == pSet[c]) SGroups++;

      if(SGroups == PGroups) res.push_back(j);
      i++; //move i forward        
    }

    return res;
  }
};
