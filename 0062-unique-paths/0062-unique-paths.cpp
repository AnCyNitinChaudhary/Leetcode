class Solution {
public:
    // int f(int i,int j){
    //     if(i==0&&j==0)return 1;
    //     if(i<0||j<0)return 0;
    //     int up=f(i-1,j);
    //     int left=f(i,j-1);
    //     return (up+left);
    // }
    // int uniquePaths(int m, int n) {
    //     //Let f(m,n) means - I will give you all the unique paths from (0,0) to (m,n) with the required constrainsts.
    //     return f(m-1,n-1);
    // }
    //The above code will give the TLE to me after running 40 testcases.
    //Hence there is a big need to do memoization which is done below by me.
    // int f(int i,int j,vector<vector<int>> &dp){
    //     if(i==0&&j==0)return 1;
    //     if(i<0||j<0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int up=f(i-1,j,dp);
    //     int left=f(i,j-1,dp);
    //     return dp[i][j]=(up+left);
    // }
    // int uniquePaths(int m, int n) {
    //     //Let f(m,n) means - I will give you all the unique paths from (0,0) to (m,n) with the required constrainsts.
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return f(m-1,n-1,dp);
    // }
    //The above code is working successfully, Now there is a interent to tabulize it do do stack space optimization which is done by me below-
    //  int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     dp[0][0]=1;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0&&j==0)dp[0][0]=1;
    //             else{
    //                 int up=0;
    //                 int left=0;
    //                 if(i>0) up=dp[i-1][j];
    //                 if(j>0) left=dp[i][j-1];
    //                 dp[i][j]=up+left;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }
    //The above code is running successfully.
    //For writing the above code of tabulation, I have taken the help from the striver L8 video and hence solve it again and at the same time do the space optimization for this below.


    //Solving this question again by understanding from strivers playlist-


    // int f(int i,int j){
    //     if(i==0&&j==0)return 1;
    //     if(i<0||j<0)return 0;
    //     int up=f(i-1,j);
    //     int left=f(i,j-1);
    //     return up+left;
    // }



// int f1(int i,int j,vector<vector<int>>&dp){
//         if(i==0&&j==0)return 1;
//         if(i<0||j<0)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int up=f1(i-1,j,dp);
//         int left=f1(i,j-1,dp);
//         return dp[i][j]=up+left;
//     }
    
    int uniquePaths(int m, int n) {
        //Recursive
        //    return f(m-1,n-1);
        //Memoization
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f1(m-1,n-1,dp);
        //Tabulation
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0&&j==0)dp[i][j]=1;
        //         else{
        //             int up=0;
        //             int left=0;
        //             if(i>0)up=dp[i-1][j];
        //             if(j>0)left=dp[i][j-1];
        //             dp[i][j]=up+left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
        //Space Optimization
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0)curr[j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0)up=prev[j];
                    if(j>0)left=curr[j-1];
                    curr[j]=up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};