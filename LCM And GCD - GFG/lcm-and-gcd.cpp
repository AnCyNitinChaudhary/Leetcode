//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long gcd(long long A,long long B){
        if(B==0)return A;
        return gcd(B,A%B);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        // long long mx=max(A,B);
        // long long mn=min(A,B);
        // long long lcm,gcd;
        // if(mx%mn==0)lcm=mx;
        // else{
        //     mx++;
        //     while(true){
        //         if(mx%A==0&&mx%B==0){
        //             lcm=mx;
        //             break;
        //         }
        //         mx++;
        //     }
        // }
        // if(mx%mn==0)gcd=mn;
        // else{
        //     mn--;
        //     while(true){
        //         if(A%mn==0&&B%mn==0){
        //             gcd=mn;
        //             break;
        //         }
        //         mn--;
        //     }
        // }
        
        // vector<long long>ans={lcm,gcd};
        // return ans;
        //The above brute force aproach is giving TLE to me.
        //A very beautiful approach learned from gfg article
        long long g=gcd(A,B);
        long long l=(A*B)/g;
        vector<long long>ans={l,g};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends