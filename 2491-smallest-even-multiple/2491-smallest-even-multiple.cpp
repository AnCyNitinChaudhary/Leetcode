class Solution {
public:
    int smallestEvenMultiple(int n) {
        int g=__gcd(2,n);
        int ans=(2*n)/g;
        return ans;
    }
};