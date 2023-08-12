class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int counti=0;
        for(int i=0;i<nums.size();i++){
            int temp=1;
            for(int j=i;j<nums.size();j++){
                temp=lcm(temp,nums[j]);
                if(temp==k)counti++;
                if(temp>k)break;
            }
        }
        return counti;
    }
};