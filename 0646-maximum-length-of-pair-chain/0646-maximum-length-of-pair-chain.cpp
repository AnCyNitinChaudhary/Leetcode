class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort(pairs.begin(),pairs.end());
        // int ans=1;
        // int curr=1;
        // for(int i=1;i<pairs.size();i++){
        //     if(pairs[i][0]>pairs[i-1][1])curr++;
        //     // else if(pairs[i][0]==pairs[i-1][1])
        //     else curr=1;
        //     ans=max(ans,curr);
        // }
        // return ans;
        sort(pairs.begin(), pairs.end(),[](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int curr = INT_MIN, ans = 0;

        for (const auto& pair : pairs) {
            if (pair[0] > curr) {
                ans++;
                curr = pair[1];
            }
        }
        return ans;
    }
};