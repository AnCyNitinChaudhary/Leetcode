//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    //giving some error while this code is correctly written by me.
    // public:
    // void merge(int arr[], int const l, int const m, int const r)
    // {
    //     int sizeofl=m-l+1;
    //     int sizeofr=r-m;
    //     int *arrl=new int[sizeofl];
    //     int *arrr=new int[sizeofr];
    //     for(int i=0;i<sizeofl;i++){
    //         arrl[i]=arr[l+i];
    //     }
    //     for(int j=0;j<r;j++){
    //         arrr[j]=arr[m+1+j];
    //     }
    //     int j=0;
    //     int i=0;
    //     int index=l;
    //     while(i<sizeofl&&j<sizeofr){
    //         if(arrl[i]<arrr[j]){
    //             arr[index]=arrl[i];
    //             i++;
    //             index++;
    //         }
    //         else{
    //             arr[index]=arrr[j];
    //             j++;
    //             index++;
    //         }
    //     }
    //     while(i<sizeofl){
    //         arr[index]=arrl[i];
    //         i++;
    //         index++;
    //     }
    //     while(j<sizeofr){
    //         arr[index]=arrr[j];
    //         j++;
    //         index++;
    //     }
    //     delete[] arrl;
    //     delete[] arrr;
    //      // Your code here
    // }
    // public:
    // void mergeSort(int arr[], int const l, int const r)
    // {
    //     if(l>=r)return;
    //     int const mid=(l+r)/2;
    //     mergeSort(arr,l,mid);
    //     mergeSort(arr,mid+1,r);
    //     merge(arr,l,mid,r);
    //     //code here
    // }
     public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         vector<int> v1={arr+l, arr+m+1};
         vector<int> v2={arr+m+1, arr+r+1};
         int i=l, j=0, k=0;
         while(j<v1.size() && k<v2.size()){
             if(v1[j]<v2[k])
             {
                 arr[i++]=v1[j++];
                 
             }
             else
             arr[i++]=v2[k++];
         }
         
         while(j<v1.size()){
             arr[i++]=v1[j++];
         }
         while(k<v2.size()){
             arr[i++]=v2[k++];
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    { int mid;
        //code here
        if(l<r){
            mid=(l+r)/2;
           mergeSort(arr, l,mid);
           mergeSort(arr,mid+1,r);
            merge(arr, l, mid, r);
        }
       
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends