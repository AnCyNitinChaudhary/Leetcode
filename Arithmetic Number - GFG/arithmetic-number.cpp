//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int a, int b, int c){
        long long int A=a;
        long long int B=b;
        long long int C=c;
        if(C==0&&A==B)return 1;
        if(C==0)return 0;
        if((B-A+C)/C<=0)return 0;
        if((B-A+C)%C==0){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends