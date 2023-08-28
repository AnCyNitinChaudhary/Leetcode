class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if(nums2.size()<nums1.size())return findMedianSortedArrays(nums2,nums1);
    //     int n1=nums1.size();
    //     int n2=nums2.size();
    //     int l=0,h=n1;
    //     while(l<=h){
    //         int c1=(l+h)/2;
            // int c2=(n1+n2+1)/2-c1;
    //         int l1,l2,r1,r2;
    //         if(c1==0)l1=INT_MIN;
    //         else l1=nums1[c1-1];
    //         if(c2==0)l2=INT_MIN;
    //         else l2=nums2[c2-1];
    //         if(c1==n1)r1=INT_MAX;
    //         else r1=nums1[c1];
    //         if(c2==n2)r2=INT_MAX;
    //         else r2=nums2[c2];

            // if(l1<=r2&&l2<=r1){
            //     if((n1+n2)%2==0)return (max(l1,l2)+min(r1,r2))/2.0;
            //     else return max(l1,l2);
            // }
            // else if(l1>r2)h=c1-1;
            // else l=c1+1;
    //     }
    //     return 0.0;

    














    //Solving hard solved

    //My idea to solve this problem is to merge both the sorted array using the merge function of the merge sort and then easily find out the answer.
    // int n=nums1.size()+nums2.size();
    // cout<<n<<endl;
    // vector<int>result;
    // int i=0;
    // int j=0;
    // while(i<nums1.size()&&j<nums2.size()){
    //     if(nums1[i]<=nums2[j]){
    //         result.push_back(nums1[i]);
    //         i++;
    //     }
    //     else 
    //     {
    //         result.push_back(nums2[j]);
    //         j++;
    //     }
    // }
    // while(i<nums1.size()){
    //     result.push_back(nums1[i]);
    //     i++;
    // }
    // while(j<nums2.size()){
    //     result.push_back(nums2[j]);
    //     j++;
    // }
    // cout<<result.size()<<endl;
    // for(auto i:result)cout<<i<<" "<<endl;
    // if(result.size()%2==0){
    //     int ans=result[n/2-1]+result[n/2];
    //     return ans/2.0;
    // }
    // return (double)result[n/2];


    //Solving using binary search-
    //The main idea to use binary search is this-
    //Mai chahta hu ki left part mai kitne elements honge 1st array and right part mai kitne elements honge 1st array k and same for 2nd array. Let me try to do binary serach on smaller length array then I can easily find the correct index in logarithmic time because agar symmetry nahi mili to aasaani se search space ko reduce kra ja skta hai.
    //The entire implemetation is given below by me-
    if(nums2.size()<nums1.size())return findMedianSortedArrays(nums2,nums1);
    int n=nums1.size()+nums2.size();
    int low=0;
    int high=nums1.size();
    while(low<=high){
        int mid=(low+high)/2;
        int mid2=(n+1)/2-mid;
        int l1;
        if(mid==0)l1=INT_MIN;
        else l1=nums1[mid-1];
        int l2;
        if(mid2==0)l2=INT_MIN;
        else l2=nums2[mid2-1];
        int r1;
        if(mid==nums1.size())r1=INT_MAX;
        else r1=nums1[mid];
        int r2;
        if(mid2==nums2.size())r2=INT_MAX;
        else r2=nums2[mid2];
        // if(l2>r1)low=mid+1;
        // else if(l1>r2)high=mid-1;
        // else return (max(l1,l2)+min(r1,r2))/2.0;
        if(l1<=r2&&l2<=r1){
            if((n)%2==0)return (max(l1,l2)+min(r1,r2))/2.0;
            else return max(l1,l2);
        }
        else if(l1>r2)high=mid-1;
        else low=mid+1;
    }
    return 0.0;
    }
};