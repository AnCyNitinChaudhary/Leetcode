//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int maxi = 0;
        int row = 0;
        int j = N-1;
        int i = 0;
        while(i < N && j >= 0) {
             if(mat[i][j] == 1) {
                 j--;
             }
             else {
                 if(maxi < N - j - 1) {
                     maxi = N -j - 1;
                     row = i;
                 }
                 i++;
             }
        }
        if(j<0) {
            return {i,N};
        }
        return {row,maxi};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends