//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        //The approach which is coming in my brain is to get the sum of firset k elements and then move with updating the maxsum.
        long maxsum=0;
        for(int i=0;i<K;i++){
            maxsum+=Arr[i];
        }
        long temp=maxsum;
        for(int i=K;i<N;i++){
            temp-=Arr[i-K];
            temp+=Arr[i];
            if(temp>maxsum)maxsum=temp;
        }
        return maxsum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends