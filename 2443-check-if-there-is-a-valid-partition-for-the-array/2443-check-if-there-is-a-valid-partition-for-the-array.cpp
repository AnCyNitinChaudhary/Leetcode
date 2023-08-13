class Solution {
public:
    bool f(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return true;
        if(dp[i]!=-1)return dp[i];
        //The stuff
        if(i<nums.size()-1&&nums[i]==nums[i+1]&&f(i+2,nums,dp))return true;
        else if(i<nums.size()-2&&nums[i]==nums[i+1]&&nums[i]==nums[i+2]&&f(i+3,nums,dp))return true;
        else if(i<nums.size()-2&&nums[i]==nums[i+1]-1&&nums[i+1]==nums[i+2]-1&&f(i+3,nums,dp))return true;
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        // unordered_map<int,int>um;
        // for(auto i:nums)um[i]++;
        // int count2=0;
        // int count3=0;
        // for(auto i:um){
        //     if(i.second==2)count2++;
        //     else if(i.second==3)count3++;
        // }
        // if(count2==2)return true;

        //Recursive appproach will be more better here.
        // sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};