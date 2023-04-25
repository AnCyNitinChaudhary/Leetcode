//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // long long f(int n){
    //     if(n==0)return 1;
        
    //     long long one=0;
    //     long long two=0;
    //     long long three=0;
    //     //one jump
    //     one=f(n-1);
    //     //two jump
    //     if(n>1)two=f(n-2);
    //     if(n>2)three=f(n-3);
    //     return (one+two+three);
    // }
    // //Function to count the number of ways in which frog can reach the top.
    // long long countWays(int n)
    // {
    //     //Let f(n) returns the total number of ways possible to reach at n from 0 
    //     return f(n);
    //     // your code here
        
    // }
    //The above code is giving TLE to me and hence I will be in need to  do the memoization in the above code which is done below by me and I believe that this will work successfully here.
      long long f(int n,vector<int>&dp){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        long long one=0;
        long long two=0;
        long long three=0;
        //one jump
        one=f(n-1,dp);
        //two jump
        if(n>1)two=f(n-2,dp);
        if(n>2)three=f(n-3,dp);
        return dp[n]=(one+two+three)% 1000000007;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        //Let f(n) returns the total number of ways possible to reach at n from 0 
        vector<int>dp(n+1,-1);
        return f(n,dp);
        // your code here
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends