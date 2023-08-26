class Solution {
public:
    // void f(int i,vector<int>&nums,vector<int>&temp,set<vector<int>>&us){
    //     if(i<0){
    //         us.insert(temp);
    //         return;
    //     }
    //     //take
    //     temp.push_back(nums[i]);
    //     f(i-1,nums,temp,us);
    //     temp.pop_back();
    //     //not Take
    //     f(i-1,nums,temp,us);
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // set<vector<int>>us;
        // vector<int>temp;
        // f(nums.size()-1,nums,temp,us);
        // vector<vector<int>>ans(us.begin(),us.end());
        // return ans;
        //using the powerset method of bit manipulation as taught by striver.
        // int n=nums.size();
        // int possibilities=pow(2,n)-1;
        // set<vector<int>>us;
        // for(int i=0;i<=possibilities;i++){
        //     vector<int>temp;
        //     for(int j=0;j<n;j++){
        //         if(i&&(1<<j))temp.push_back(nums[j]);
        //     }
        //     us.insert(temp);
        // }
        // vector<vector<int>>ans(us.begin(),us.end());
        // return ans;
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};