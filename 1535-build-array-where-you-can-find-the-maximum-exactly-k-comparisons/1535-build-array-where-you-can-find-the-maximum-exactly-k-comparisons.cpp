class Solution {
public:
    //Again understand this question from- https://www.youtube.com/watch?v=f0WoMyaUJrE this link and solve again.
    int dp[51][51][101];
    int n,m,k;
    const int mod = 1e9+7;
    int solve(int ind,int ln,int prevGrt) {
        if(ind == n){
            if(ln==k) return 1;
            else return 0;
        }
        if(dp[ind][ln][prevGrt] != -1) return dp[ind][ln][prevGrt];

        int ans = 0;
        for(int i=1;i<=m;i++){
            if(i > prevGrt){
                ans += solve(ind+1,ln+1,i);
            } else {
                ans += solve(ind+1,ln,prevGrt);
            }
            ans = ans % mod;
        }
        return dp[ind][ln][prevGrt] = ans;
    }
    int numOfArrays(int nn, int mm, int kk) {
        memset(dp,-1,sizeof(dp));
        n=nn;
        m=mm;
        k=kk;
        return solve(0,0,0);

    }
};