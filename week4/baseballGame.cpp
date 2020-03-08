class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum=0;
        for(auto i: ops){
           if(i == "C")
           {
               st.pop();
           }
           else if(i == "D"){
               st.push(2*st.top());
           }
           else if(i == "+"){
               int top = st.top();
               st.pop();
               int newround = top + st.top();
               st.push(top);
               st.push(newround);
           }
           else {
               int k = stoi(i);
               st.push(k);
           }
        }
        
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
