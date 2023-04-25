//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    // int f(int i,int n){
    //     if(i==n)return 0;
    //     //double the number m
    //     int d=INT_MAX;
    //     if(i*2<=n)d=f(i*2,n)+1;
    //     //add one to the number
    //     int a=f(i+1,n)+1;
    //     return min(d,a);
    // }
    // int minOperation(int n)
    // {
    //     //code here.
    //     //Let f(0,n) return the minimum number of operations  required to reach n from 0.
    //     if(n==0)return 0;
    //     return f(1,n)+1;
    // }
    //The above code will give TLE after 10 test cases and hence there is a need to do memoization in the above code which is done by me below
    int f(int i,int n,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        //double the number m
        int d=INT_MAX;
        if(i*2<=n)d=f(i*2,n,dp)+1;
        //add one to the number
        int a=f(i+1,n,dp)+1;
        return dp[i]=min(d,a);
    }
    int minOperation(int n)
    {
        //code here.
        //Let f(0,n,dp) return the minimum number of operations  required to reach n from 0.
        if(n==0)return 0;
        vector<int>dp(n,-1);
        return f(1,n,dp)+1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends