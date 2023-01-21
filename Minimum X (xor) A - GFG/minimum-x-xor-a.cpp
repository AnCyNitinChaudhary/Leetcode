//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //This is the hardest question which i have understood and tried to solve which uses 
  // two new concepts of bitmasking and shift and or operators.
  //I still need to revise it again.
    int minVal(int a, int b) {
        int setBitInA=setBit(a);
        int setBitInB=setBit(b);
        if(setBitInA==setBitInB)return a;
        int ans=0;
        for(int i=0;i<31;i++){
            int mask=1<<i;
            int set=a&mask;
            if(set==0&&setBitInA<setBitInB){
                ans=ans|mask;
                setBitInB--;
            }
            else if(set!=0&&setBitInA>setBitInB)setBitInA--;
            else{
                ans|=set;
            }
        }
        return ans;
        // code here
    }
    int setBit(int n){
        int count=0;
        while(n){
            if(n&1!=0)count++;
            n/=2;
        }
         return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends