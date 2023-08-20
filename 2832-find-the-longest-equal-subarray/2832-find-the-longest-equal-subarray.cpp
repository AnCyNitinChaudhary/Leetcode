class Solution {
public:
    // int f(vector<int>&nums,int k,int last,int deleted,int i,int len){
    //     if(i>=nums.size())return len;
    //     if(deleted==k)return len;
    //     int take=0;
    //     if(last==-1||nums[i]==last){
    //         take=f(nums,k,last,deleted,i+1,len+1);
    //     }
    //     int notTake=0;
    //     if(last==-1)notTake=f(nums,k,last,deleted,i+1,len);
    //     else notTake=f(nums,k,nums[i],deleted+1,i+1,len);
    //     return max(take,notTake);
    // }
    int longestEqualSubarray(vector<int>& nums, int k){
        int left=0;
        unordered_map<int,int>freq;
        int maxi=0;
        for (int right=0;right<nums.size();++right){
            freq[nums[right]]++;
            maxi=max(maxi,freq[nums[right]]);
            int deletionsNeeded =(right-left+1)-maxi;
            
            while (deletionsNeeded>k){
                freq[nums[left]]--;
                left++;
                deletionsNeeded=(right-left+1)-maxi; 
            }
        } 
        return maxi;
    }
//     int longestEqualSubarray(vector<int>& nums, int k) {
//         //Try out all possible ways
//         // return f(nums,k,-1,0,0,0);
        
//         //sliding window approach
        
//     }
};