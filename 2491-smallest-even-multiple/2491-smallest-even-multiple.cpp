//First Appraoch
// class Solution {
// public:
//     int smallestEvenMultiple(int n) {
//         int g=__gcd(2,n);
//         int ans=(2*n)/g;
//         return ans;
//     }
// };

//Second Approach
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0)return n;
        return n*2;
    }
};