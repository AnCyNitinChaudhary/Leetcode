//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // vector<int> ans;
        // if(arr1[0]<arr2[0])ans.push_back(arr1[0]);
        // else ans.push_back(arr2[0]);
        // int index=0;
        // int i=0;
        // int j=0;
        // while(i<n&&j<m){
        //     if(arr1[i]<=arr2[j]&&ans[index]!=arr1[i]){
        //         ans.push_back(arr1[i]);
        //         i++;
        //         index++;
        //     }
        //     else if(arr1[i]>arr2[j]&&ans[index]!=arr2[j]){
        //         ans.push_back(arr2[j]);
        //         j++;
        //         index++;
        //     }
        //     else{
        //         i++;
        //         j++;
        //     }
        // }
        // while(i<n){
        //     if(ans[index]!=arr1[i]){
        //         ans.push_back(arr1[i]);
        //         i++;
        //         index++;
        //     }
        // }
        //  while(j<m){
        //     if(ans[index]!=arr2[j]){
        //         ans.push_back(arr2[j]);
        //         j++;
        //         index++;
        //     }
        // }
        // return ans;
        //Your code here
        //return vector with correct order of elements
        //My approach is very much correct as per me but this is giving TLE to this question.
        //Let me run someone same approach solution below. Find why the similar approach is not giving TLE and what is the different between my and below code time complexity.
        vector<int>v;
        int i=0,j=0;
        while(i<n&&j<m){
            while(i+1<n&&arr1[i]==arr1[i+1]){
            i++;
            }
            while(j+1<m&&arr2[j]==arr2[j+1]){
            j++;
            }
            
        if(arr1[i]==arr2[j]){
            v.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            v.push_back(arr1[i]);
            i++;
        }
        else{
            v.push_back(arr2[j]);
            j++;
        }
        }
        while(i<n){
            while(i+1<n&&arr1[i]==arr1[i+1]){
                i++;
            }
            v.push_back(arr1[i++]);
        }
        while(j<m){
            while(j+1<m&&arr2[j]==arr2[j+1]){
                j++;
            }
            v.push_back(arr2[j++]);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends