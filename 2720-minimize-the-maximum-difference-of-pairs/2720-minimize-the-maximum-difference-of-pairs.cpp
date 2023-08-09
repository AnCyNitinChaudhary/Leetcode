// class Solution {
// public:
//     int f(int i,vector<int>&nums,int p){
//         if(i<=0)return 1e9;
//         if(p<=0)return 0;
//     //not take
//     int notTake=0;
//     if(i-1>=0)f(i-1,nums,p);
//     //Take
//     int take=0;
//     if(i-2>=0)take=max(abs(nums[i]-nums[i+1]),f(i-2,nums,p-1));
//     return min(take,notTake);
//     }
//     int minimizeMax(vector<int>& nums, int p){
//         if(nums.size()==0)return 0;
//         //In this problem we have to try out all the possible ways. So, we can use Dynamic programing here.
//         //Trying to solve using recursion
//         //let f(nums.size()-1,nums,p)returns the minimum maximum difference between all pairs.
//         sort(nums.begin(),nums.end());
//         return f(nums.size()-1,nums,p);
//     }
// };

//Above DP solution is giving error
//Solution using binary search
class Solution {
public:
    bool possible(vector<int>&nums,int p,int mid){
        int i=0;
        while(i<nums.size()-1){
            if(abs(nums[i]-nums[i+1])<=mid){
                p--;
                i+=2;
            }
            else i++;
        }
        if(p<=0)return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p){
    sort(nums.begin(),nums.end());
      int left=0;
      int right=nums[nums.size()-1];
      int ans=0;
      while(left<=right){
          int mid=(left+right)/2;
          if(possible(nums,p,mid)){
              ans=mid;
              right=mid-1;
          }
          else left=mid+1;
      }
      return ans;
    }
};