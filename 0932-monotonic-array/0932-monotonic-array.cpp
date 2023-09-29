class Solution {
public:
    bool isIncreasing(vector<int>&nums){
        int start=nums[0];
        for(auto i:nums){
            if(start>i)return false;
            start=i;
        }
        return true;
    }
      bool isDecreasing(vector<int>&nums){
        int start=nums[0];
        for(auto i:nums){
            if(start<i)return false;
            start=i;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        bool temp1=isIncreasing(nums);
        bool temp2=isDecreasing(nums);
        return (temp1||temp2);

    }
};