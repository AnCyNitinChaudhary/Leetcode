class Solution {
public:
    //Try to find out where the error is coming. Try to implement it using kth larges inplace of n-k+1th smallest
    // int f(vector<int>&nums,int k,int start,int end){
    //     if(start==end)return nums[start];
    //     int index=start+(rand()%(end-start+1));
    //     // cout<<end-start<<endl;
    //     vector<int>small;
    //     vector<int>equal;
    //     vector<int>large;
    //     for(int i=start;i<=end;i++){
    //         if(nums[i]==nums[index])equal.push_back(nums[i]);
    //         else if(nums[i]<nums[index])small.push_back(nums[i]);
    //         else large.push_back(nums[i]);
    //     }
    //     if(large.size()<k)return f(large,k-large.size(),0,large.size()-1);
    //     else if(large.size()+equal.size()>=k)return equal[0];
    //     return f(small,k-large.size()-equal.size(),0,small.size()-1);
    // }
    int median(int A[],int l,int r,int k)
{

int ind = r-l+1;

int index = rand() % ind;

int i,j=0,m=0,n=0;

int S1[ind],S3[ind],S2[ind];

for(i=0;i<=r;i++)

{

if(A[i]<A[index])

{

S1[j]=A[i];

j++;

}

else if(A[i]==A[index])

{

S2[n]=A[i];

n++;

}

else

{

S3[m]=A[i];

m++;

} }

if(j>=k)

{

return median(S1,0,j-1,k);

}

else if((j+n)>=k)

return A[index];

else

return median(S3,0,m-1,k-(j+n));

}
    int findKthLargest(vector<int>& nums, int k) {
        //Using brute force of sorting
        // sort(nums.begin(),nums.end(),greater<int>());
        // return nums[k-1];

        //Using Median Search Algorithm to find out kth largest element
        int a[nums.size()];
        for(int i=0;i<nums.size();i++)a[i]=nums[i];
        return median(a,0,nums.size()-1,nums.size()-k+1);
    }
};