class Solution {
public:
    bool backspaceCompare(string S, string T) {
         stack<char> st1, st2;
         for(auto i: S){
             if(st1.empty() && i=='#') 
                 continue;
             else{
                 if(i!= '#')
                     st1.push(i);
                 else {
                     st1.pop();
                 }
             }
         }
        
        for(auto i: T){
             if(st2.empty() && i=='#') 
                 continue;
             else{
                 if(i!= '#')
                     st2.push(i);
                 else {
                     st2.pop();
                 }
             }
         }
        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top()) return false;
            st1.pop(); st2.pop();
        }
        
        return (!st1.empty() || !st2.empty()) ? false : true;
        
    }
};
