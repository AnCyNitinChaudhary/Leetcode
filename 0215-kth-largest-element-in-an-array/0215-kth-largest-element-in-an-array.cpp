class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Using brute force of sorting
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
};