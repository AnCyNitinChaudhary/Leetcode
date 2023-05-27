//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
//     int f(int N,int i,vector<int>&dp){
//     if(N==1)return 1;
//     if(dp[N-1]!=-1)return dp[i];
//     else if(i!=0&&N%i==0) dp[N-1]=i+f(N,i-1,dp);
//     else if(i!=0)return f(N,i-1,dp);
//     int temp=f(N-1,N-1,dp);
// }
// int F(int N,int i){
//     if(i==1)return 1;
//     if(i!=0&&N%i==0)return i+F(N,i-1);
//     else return F(N,i-1);
// }
public:
    long long sumOfDivisors(int N)
    {
        //vector<int>dp(N+1,-1);
        //Let f(N,i,dp) stores the required sums till N in dp;
        // Write Your Code here
        // int last=f(N,N,dp);
         long long answer=0;
        // for(int i=0;i<N;i++){
        //     answer+=dp[i];
        // }
        // return answer;
        //Let F(N i) evaluates the required function value
        // for(int i=1;i<=N;i++)answer+=(F(sqrt(i),i)+i);
        // return answer-1;
        //Again giving TLE even after using sqrt
        for(int i=1;i<=N;i++)answer+=(i*(N/i));
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends