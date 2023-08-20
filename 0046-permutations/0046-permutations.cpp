class Solution {
public:
  

    //Below code is my code and not above
    // void f(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,vector<int>&arr){
    //     if(temp.size()==nums.size()){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++ ){
    //         if(!arr[i]){
    //             temp.push_back(nums[i]);
    //             arr[i]=1;
    //             f(nums,ans,temp,arr);
    //             temp.pop_back();
    //             arr[i]=0;
    //         }
    //     }
    // }
    // void f(int i,vector<int>&nums,vector<vector<int>>&ans){
    //     if(i>=nums.size()){
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for(int index=i;index<nums.size();index++){
    //         swap(nums[index],nums[i]);
    //         f(i+1,nums,ans);
    //         swap(nums[index],nums[i]);
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
        // dfs(nums,0,nums.size()-1);
        // return ans;
        //Solving this question after understanding from the striver.
        //Approach 1- Using Recursion-
        // vector<vector<int>>ans;
        // vector<int>temp;
        // int n=nums.size();
        // vector<int>arr(n,0);
        // f(nums,ans,temp,arr);
        // return ans;

        //Approach 2- Swapping based backtracking technique
        // f(0,nums,ans);
        // return ans;
        //This above solution beats 100%
    // }


    //Solving for Intuit practice-
    // void f(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,vector<int>&freq){
    //     if(temp.size()==nums.size()){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(!freq[i]){
    //             freq[i]=1;
    //             temp.push_back(nums[i]);
    //             f(nums,temp,ans,freq);
    //             temp.pop_back();
    //             freq[i]=0;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     vector<int>freq(nums.size(),0);
    //     f(nums,temp,ans,freq);
    //     return ans;
    // }



//Swap approach without extra freq  space
    void f(int index,vector<int>&nums,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
                swap(nums[i],nums[index]);
                f(index+1,nums,ans);
                swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0,nums,ans);
        return ans;
    }
};






  // vector<vector<int>> ans;
    // void dfs(vector<int>&a,int l,int r){
    //     if(l==r)ans.push_back(a);
    //     else{
    //         for(int i=l;i<=r;i++){
    //             swap(a[l],a[i]);
    //             dfs(a,l+1,r);
    //             swap(a[l],a[i]);
    //         }
    //     }
    // }