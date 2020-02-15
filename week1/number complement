class Solution {
public:
    int findComplement(int num) {
        int res=0;
        long int mul=1;
        while(num){
            if(num%2==0)
                res+= mul;
            mul*=2;
            num/=2;
        }
        return res;
    }
};
