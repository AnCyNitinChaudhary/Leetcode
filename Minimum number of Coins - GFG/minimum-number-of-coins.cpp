//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        //I think greedy will work in this case and hence trying greedy.
        vector<int> ans;
        int deno[]={2000,500,200,100,50,20,10,5,2,1};
        int i=0;
        while(true){
            if(N==0)return ans;
            else if(deno[i]<=N){
                ans.push_back(deno[i]);
                N-=deno[i];
            }
            else i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends