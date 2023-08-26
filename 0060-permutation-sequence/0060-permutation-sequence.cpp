class Solution {
public:
  
// int factorial(int n)
// {
//     // single line to find factorial
//     return (n==1 || n==0) ? 1: n * factorial(n - 1); 
// }
//     void solve(int n,int k,int start,vector<int>indexes){
//         if(k==0){
//             indexes.push_back(start);
//         }
//         int temp=factorial(n-1);
//         start=k/temp;
//         k%=temp;
//         solve(n,k,start,indexes);
//     }
    // string getPermutation(int n, int k) {
        //The idea behind this is that- the kth permutation will be in the block of k/((n-1)!) and in that block k%(n-1)! th will be the required permutaion considering 0 base indexing. So call it recursively and get the starting index block
        // vector<int>indexes;
        // solve(n-1,k-1,0,indexes);
        // string ans="";
        // for(auto i:indexes){
        //     ans+=(i+1);
        // }
        // return ans;
        //The above code is giving wrong output so I have to solve this by another method.
        //This code is written from striver video. So, solve this question again by your own.
        // int fact=1;
        // vector<int>nums;
        // for(int i=1;i<n;i++){
        //     fact=fact*i;
        //     nums.push_back(i);
        // }
        // string ans="";
        // nums.push_back(n);
        // k=k-1;
        // while(true){
        //     ans+=to_string(nums[k/fact]);
        //     nums.erase(nums.begin()+k/fact);
        //     if(nums.size()==0)break;
        //     k=k%fact;
        //     fact/=nums.size();
        // }
        // return ans;
    // }
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>numbers;
        for(int i=1;i<n;i++){
            fact*=i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans="";
        k=k-1;
        while(true){
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/numbers.size();
        }
        return ans;
    }
};