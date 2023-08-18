class Solution {
public:
// int f(int n){
//     if(n<=1)return 1;
//     int onestep=0;
//     int twostep=0;
//     onestep=f(n-1);
//     if(n>1)twostep=f(n-2);
//     return onestep+twostep;
// }


// int f1(int n,vector<int>&dp){
//     if(n<=1)return 1;
//     if(dp[n]!=-1)return dp[n];
//     int onestep=0;
//     int twostep=0;
//     onestep=f1(n-1,dp);
//     if(n>1)twostep=f1(n-2,dp);
//     return dp[n]=onestep+twostep;
// }




















// //Using recursion
// //Lets imagine f(n) means the number of distinct steps required to reach at nth stair.
//     int f(int n){
//         if(n==0||n==1)return 1;
//         //ways of climbing 1 stair
//         int climb1=f(n-1);
//         //ways of climbing 2 star
//         int climb2=0;
//         if(n>1)climb2=f(n-2);
//         return climb1+climb2;
//     }
//Recursive approach will give TLE after 20 testcases.
//Below is the code usig memoization.

    // int f(int n,vector<int>&dp){
    //     if(n==0||n==1)return 1;
    //     if(dp[n-1]!=-1)return dp[n-1];
    //     //ways of climbing 1 stair
    //     int climb1=f(n-1,dp);
    //     //ways of climbing 2 star
    //     int climb2=0;
    //     if(n>1)climb2=f(n-2,dp);
    //     return dp[n-1]=(climb1+climb2);
    // }
    // int climbStairs(int n) {
    //     vector<int>dp(n,-1);
    //     return f(n,dp);
    // }
    //The above code is working successfully, there is the wish to solve by using tabulation dp and hence i am doing it below.
    //    int climbStairs(int n) {
    //     vector<int>dp(n+1);
    //     dp[0]=1;
    //     dp[1]=1;
    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }
    //The above code is beating 100% in terms of time complexity 
    //This is the time to space optimize it as it is giving the feeling of fibonaci
    //   int climbStairs(int n) {
    //       if(n==1)return 1;
    //     int left=1;
    //     int right=1;
    //     int current;
    //     for(int i=2;i<=n;i++){
    //         current=left+right;
    //         left=right;
    //         right=current;
    //     }
    //     return current;
    // }
    //The above space optimized code is really powerfull and seems to be great in terms of both time and space complexity.






















    //Solving the same problem again by all the methods.
    //Recursive-
    // return f(n);
    //Using Memoization
    // vector<int>dp(n+1,-1 );
    // return f1(n,dp);


    //Tabulation
    // vector<int>dp(n+1,0);
    // dp[0]=1;
    // dp[1]=1;
    // for(int i=2;i<=n;i++){
    //   dp[i]=dp[i-1]+dp[i-2];
    // }
    // return dp[n];

    //Space optimization-
    // int a=1;
    // int b=1;
    // int c;
    // for(int i=2;i<=n;i++){
    //   c=a+b;
    //   a=b;
    //   b=c;
    // }
    // return b;
// }







    int f(int i,int n,vector<int>&dp){
        if(i>=n)return 1;
        if(dp[i]!=-1)return dp[i];
        int onestep=f(i+1,n,dp);
        int twostep=0;
        if(i+2<=n)twostep=f(i+2,n,dp);
        return dp[i]=onestep+twostep;
    }
      int climbStairs(int n){
    //Solving this problem again just for practice.
    //Recursive
    // return f(0,n);
    //Giving TLE
    vector<int>dp(n,-1);
    return f(0,n,dp);

      }
};