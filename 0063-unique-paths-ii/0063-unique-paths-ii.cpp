class Solution {
//     int f(int i,int j,vector<vector<int>>&og){
//         if(i>=0&&j>=0&&og[i][j]==1)return 0;
//         if(i==0&&j==0)return 1;
//         if(i<0||j<0)return 0;
        
//         //The stuff
//         int up=f(i-1,j,og);
//         int left=f(i,j-1,og);
//         return up+left;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         //Let f(i,j,obstacleGrid) tells the number of unique paths possible.
//         if(obstacleGrid.size()==obstacleGrid[0].size()&&obstacleGrid.size()==1){
//             //cout<<"Entered";
//             if(obstacleGrid[0][0]==0)return 1;
//             else return 0;
//         }
//         return f(obstacleGrid.size()-1,obstacleGrid[0].size()-1,obstacleGrid);
//     }
//The above code is giving TLE and hence I will be in need to memoize it which is done by me below-
    // int f(int i,int j,vector<vector<int>>&og,vector<vector<int>> & dp){
    //     if(i>=0&&j>=0&&og[i][j]==1)return 0;
    //     if(i==0&&j==0)return 1;
    //     if(i<0||j<0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     //The stuff
    //     int up=f(i-1,j,og,dp);
    //     int left=f(i,j-1,og,dp);
    //     return dp[i][j]=up+left;
    // }
public:
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Let f(i,j,obstacleGrid) tells the number of unique paths possible.
        // int row=obstacleGrid.size();
        // int col=obstacleGrid[0].size();
        // if(row==col&&row==1){
        //     //cout<<"Entered";
        //     if(obstacleGrid[0][0]==0)return 1;
        //     else return 0;
        // }
        // vector<vector<int>>dp(row,vector<int>(col,-1));
        // return f(row-1,col-1,obstacleGrid,dp);
    // }
    //Finally I will learn to do it with tabulation when I will solve this again with pratham.
    //Soving dp questions is really cool to me and hence dp is going to become one of the favourite topic of algorithms of my life.
    //Solving this again on codestudio and pasting the code written by me on code studio
//     int f(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
//     if(i==0&&j==0&&mat[0][0]!=1)return 1;
//     if(i==0&&j==0&&mat[0][0]==1)return 0;
//     if(i<0||j<0)return 0;
//     if(mat[i][j]==1)return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int up=f(i-1,j,mat,dp);
//     int left=f(i,j-1,mat,dp);
//     return dp[i][j]=up+left;
// }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        if(n==1&&m==1&&mat[0][0]==1)return 0;
        if(n==1&&m==1&&mat[0][0]==0)return 1;
        // return f(n-1,m-1,mat);
        //Memoization
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,mat,dp);

        //Tabulation
        // vector<vector<int>>dp(n,vector<int>(m,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(i==0&&j==0&&mat[0][0]!=1)dp[i][j]=1;
        //         else if(i==0&&j==0&&mat[0][0]==1)dp[i][j]=0;
        //         else if(mat[i][j]==1)dp[i][j]=0;
        //         else{
        //             int up=0;
        //             if(i>0)up=dp[i-1][j];
        //             int left=0;
        //             if(j>0)left=dp[i][j-1];
        //             dp[i][j]=up+left;
        //         }
        //     }
        // }
        // return dp[n-1][m-1];
        //Space Optimization
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0&&j==0&&mat[0][0]!=1)temp[j]=1;
                else if(i==0&&j==0&&mat[0][0]==1)temp[j]=0;
                else if(mat[i][j]==1)temp[j]=0;
                else{
                    int up=0;
                    if(i>0)up=prev[j];
                    int left=0;
                    if(j>0)left=temp[j-1];
                    temp[j]=up+left;
                }
            }
            prev=temp;
        }
        return prev[m-1];
    }
};