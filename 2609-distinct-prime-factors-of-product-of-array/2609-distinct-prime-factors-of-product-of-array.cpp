class Solution {
public:
  
bool isPrime(int n)
{
    if (n <= 1)return false;
    for (int i = 2; i <= n / 2; i++){
        if (n % i == 0)return false;
    }
    return true;
}
    int distinctPrimeFactors(vector<int>& nums) {
        int counti=0;
        unordered_set<int>us;
        for(int i=0;i<nums.size();i++){
            if(us.find(nums[i])==us.end()){
                for(int j=1;j<=nums[i];j++){
                    if(nums[i]%j==0&&isPrime(j)&&us.find(j)==us.end()){
                        counti++;
                        us.insert(j);
                    }
                }
            }
        }
        return counti;
    }
};