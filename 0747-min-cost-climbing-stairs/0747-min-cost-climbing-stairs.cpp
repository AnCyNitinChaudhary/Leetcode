class Solution {
public:
    // int f(int n,vector<int>&cost,int index){
    //     if(n==index)return 0;
    //     //Now two possibilities to reach at n
    //     //reached from n-1
    //     int c1=f(n-1,cost,index)+cost[n-1];
    //     //reached from n-2
    //     int c2=0;
    //     if(n>1)c2=f(n-2,cost,index)+cost[n-2];
    //     return min(c1,c2);
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     //let f(n,cost,i) denotes the minimum cost to reach the top of the floor starting with index i
    //     int cost1=f(n,cost,0);
    //     return cost1;
    //     //int cost2=f(n,cost,1);
    //     //return min(cost1,cost2);
    // }
    //The above code will cause TLE after 258 test cases hence the below code for memoization will be needed.
    //   int f(int n,vector<int>&cost,vector<int>&dp){
    //     if(n==0||n==1)return 0;
    //     //Now two possibilities to reach at n
    //     //reached from n-1
    //     if(dp[n]!=-1)return dp[n];
    //     int c1=f(n-1,cost,dp)+cost[n-1];
    //     //reached from n-2
    //     int c2=0;
    //     if(n>1)c2=f(n-2,cost,dp)+cost[n-2];
    //     return dp[n]=min(c1,c2);
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //        vector<int> dp(n+1,-1);
    //     //let f(n,cost,i) denotes the minimum cost to reach the top of the floor starting with index i
    //     int cost1=f(n,cost,dp);
    //     return cost1;
    //     //int cost2=f(n,cost,1);
    //     //return min(cost1,cost2);
    // }

    //The above  code is working successfully, there is a wish to tabulize it and hence doing the same below.
   //     int minCostClimbingStairs(vector<int>& cost) {
   //      int n=cost.size();
   //      vector<int> dp(n);
   //      //dp[i] means that ith stair ko cross krne ki minimum cost
   //      dp[0]=cost[0];
   //      dp[1]=cost[1];
   //      for(int i=2;i<n;i++){
   //         dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
   //      }
   //     for(int i=0;i<n;i++)cout<<dp[i]<<" ";
   //     return min(dp[n-1],dp[n-2]);
   //  }
   //The above tabulation is working successfully and hence there is a big need to space optimize it.
        int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1)return cost[0];
        if(n==2)return min(cost[0],cost[1]);
        if(n==3){
           return min(cost[1],cost[0]+cost[2]);
        }
        int left=cost[0];
        int right=cost[1];
        int current;
        int answer;
        for(int i=2;i<n;i++){
           if(i==n-1){
              int temp=cost[i]+min(left,right);
              answer= min(current,temp);
              break;
           }
           current=cost[i]+min(left,right);
           left=right;
           right=current;
        }
        return answer;
    }
    //The space optimized code is not very much better to handle all the cases inside the loop while it is not creating any issue but still this code should be improved by understanding from others solutions.
};