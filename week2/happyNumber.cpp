class Solution {
public:
    bool isHappy(int n) {
        set<int> m;
        while(true){
            n=squares(n);
            if(n==1) return true;
            if(m.find(n)!=m.end()) return false;
            m.insert(n);
        }
    }
private:
    int squares(int n){
        int s=0;
        while(n){
            int r=n%10;
            s=s+ r*r;
            n/=10;
        }
return s;
    }
};
