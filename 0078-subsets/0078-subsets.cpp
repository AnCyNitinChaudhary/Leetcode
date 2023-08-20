class Solution {
public:
    void f(int i,vector<int>&nums,vector<int>&temp,set<vector<int>>&us){
        if(i<0){
            us.insert(temp);
            return;
        }
        //take
        temp.push_back(nums[i]);
        f(i-1,nums,temp,us);
        temp.pop_back();
        //not Take
        f(i-1,nums,temp,us);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>us;
        vector<int>temp;
        f(nums.size()-1,nums,temp,us);
        vector<vector<int>>ans(us.begin(),us.end());
        return ans;
    }
};