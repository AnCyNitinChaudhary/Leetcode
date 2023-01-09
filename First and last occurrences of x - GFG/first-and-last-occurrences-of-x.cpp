//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int left=0;
    int right=n-1;
    int a=-1;
    //for leftinidex using binary search
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==x){
            a=mid;
            right=mid-1;
        }
        else if(arr[mid]>x)right=mid-1;
        else left=mid+1;
    }
    ans.push_back(a);
 //for rightinidex using binary search
    left=0;
    right=n-1;
    a=-1;
    while(left<=right){
        int mid=(left+right)/2;
            if(arr[mid]==x){
                a=mid;
                left=mid+1;
        }
        else if(arr[mid]>x)right=mid-1;
        else left=mid+1;
    }
    ans.push_back(a);
    return ans;
    // code here
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends