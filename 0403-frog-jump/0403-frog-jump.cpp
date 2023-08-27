class Solution {
public:
    // bool f(int i,int prev,vector<int>&stones){
    //     if(i==stones.size()-1)return true;
    //     bool k1=false;
    //     bool k=false;
    //     bool k2=false;
    //     //check for k-1
    //     if((stones[i]+prev-1)==stones[i+1])k1= f(i+1,prev-1,stones);
    //     //check for k
    //     if((stones[i]+prev)==stones[i+1])k=f(i+1,prev,stones);
    //     //check for k+1
    //     if((stones[i]+prev+1)==stones[i+1])k2=f(i+1,prev+1,stones);
    //     return (k1||k||k2);
    // }
    // bool canCross(vector<int>& stones) {
    //     //let f(i,prev,stones) returns whether there is a possible way to jump to the last stone as per the rul or not.
    //     //for now I am considering that the frog has to jump with continuity on stones.
    //     return f(0,1,stones);
    // }
    //the above code can be correct for the problem of continuity of jumps but here the from can jump by skipping an stone whose code is given below
    //  bool f(int i,int prev,vector<int>&stones){
    //     if(i==stones.size()-1)return true;

    //     bool k1=false;
    //     bool k=false;
    //     bool k2=false;
    //     int j=i;
    //     if(prev!=1){
    //     while(((stones[i]+prev-1)>=stones[j+1])&&j<=stones.size()-1){
    //     //check for k-1
    //     if((stones[i]+prev-1)==stones[j+1]){
    //         k1= f(j+1,prev-1,stones);
    //         break;
    //     }
    //     j++;
    //     }
    //  }
    //     if(k1==true)return true;
    //     j=i;
    //      while(((stones[i]+prev)>=stones[j+1])&&j<=stones.size()-1){
    //     //check for k
    //     if((stones[i]+prev)==stones[j+1]){
    //         k=f(j+1,prev,stones);
    //         break;
    //       }
    //       j++;
    //      }
    //      if(k==true)return true;
    //      j=i;
    //       while(((stones[i]+prev+1)>=stones[j+1])&&j<=stones.size()-1){
    //     //check for k+1
    //     if((stones[i]+prev+1)==stones[i+1]){
    //         k2=f(j+1,prev+1,stones);
    //         break;
    //     }
    //     j++;
    //     }
    //     return (k1||k||k2);
    // }
    // bool canCross(vector<int>& stones) {
        //let f(i,prev,stones) returns whether there is a possible way to jump to the last stone as per the rul or not.
        // return f(0,1,stones);
    // }
    //check why the above code is failing for some of the test cases and after that memoize it using a boolean vector.


















    //Nitin_Coder1
    // bool f(int start,int jump,vector<int>&stones){
    //     if(start==stones.size()-1)return true;
    //     // else if(jump<stones[start+1])return false;
    //     // bool temp1=false,temp2=false,temp3=false;
    //     // if(start+jump-1==stones[start+1]){
    //     //     temp1=f(start+1,jump-1,stones);
    //     // }
    //     // if(start+jump==stones[start+1]){
    //     //     temp2=f(start+1,jump,stones);
    //     // }
    //     // if(start+jump+1==stones[start+1]){
    //     //     temp3=f(start+1,jump+1,stones);
    //     // }
    //     // return (temp1||temp2||temp3);

    //     bool ans=false;
    //     for(int ind=start+1;ind<stones.size();ind++){
    //         if(stones[ind]-stones[start]>jump+1)break;
    //         for(int t=-1;t<2;t++){
    //             if(stones[ind]-stones[start]==jump+t){
    //                 ans=f(ind,jump+t,stones)||ans;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    // bool canCross(vector<int>& stones) {
    //     //Let f(0,1,stones) return whether it is possible to reach to the last stone by starting from 0;
    //     if(stones[1]-stones[0]>1)return false;
    //     return f(0,1,stones) ;
    // }

    //Memoization
    //     bool f(int start,int jump,vector<int>&stones,vector<vector<int>>&dp){
    //     if(start==stones.size()-1)return true;
    //     if(dp[start][jump]!=-1)return dp[start][jump];
    //     bool ans=false;
    //     for(int ind=start+1;ind<stones.size();ind++){
    //         if(stones[ind]-stones[start]>jump+1)break;
    //         for(int t=-1;t<2;t++){
    //             if(stones[ind]-stones[start]==jump+t){
    //                 ans=f(ind,jump+t,stones,dp)||ans;
    //             }
    //         }
    //     }
    //     return dp[start][jump]=ans;
    // }
    // bool canCross(vector<int>& stones) {
    //     //Let f(0,1,stones) return whether it is possible to reach to the last stone by starting from 0;
    //     if(stones[1]-stones[0]>1)return false;
    //     if(stones.size()==2)return stones[1]-stones[0]==1;
    //     int n=stones.size();
    //     int col=stones[stones.size()-1]-stones[0];
    //     vector<vector<int>>dp(n,vector<int>(col,-1));
    //     return f(0,1,stones,dp) ;
    // }



    //Tabulation
    //Tabulation is hard to implement for me. So, please try to implement it again.
    bool canCross(vector<int>& stones) {
       unordered_map<int,unordered_set<int>>um;
       um[stones[0]+1]={1};
       for(int i=1;i<stones.size();i++){
           int position=stones[i];
           for(auto it:um[position]){
               um[position+it].insert(it);
               um[position+it+1].insert(it+1);
               um[position+it-1].insert(it-1);
           }
       }
       return um[stones.back()].size()!=0;
    }
};