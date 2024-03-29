//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        //very beautiful question which take the use of priority queues.
        priority_queue<int,vector<int>,greater<int> > pq(arr.begin(),arr.end());//priority queue initialized with array elements and it will automatically store elements in sorted order.
        int ans=0;
        while(pq.size()>=2){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            pq.push(a+b);
            ans+=(a+b);
        }
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends