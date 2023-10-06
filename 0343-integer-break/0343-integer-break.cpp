class Solution {
public:
    int integerBreak(int n) {
        //2*2*2<3*3 hence we shuld use more and more 3
        if(n==2)return 1;
        if(n==3)return 2;
        int product=1;
        while(n>4){
            product*=3;
            n-=3;
        }
        product*=n;
        return product;
    }
};