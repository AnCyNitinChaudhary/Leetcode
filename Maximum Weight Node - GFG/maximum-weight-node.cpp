//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  //The approach which i used here is to store the weghts in a array of size N
  //as range will never cross N which is given in question.
  int maxWeightCell(int N, vector<int> Edge)
  {
      unordered_map<int,int>weight;
      for(int i=0;i<N;i++)weight[i]=0;
      for(int i=0;i<N;i++){
          if(Edge[i]!=-1)weight[Edge[i]]+=i;
      }
      int max_weight=INT_MIN;
      int max_weight_index=-1;
      for(auto weigh:weight){
          if(weigh.second>=max_weight){//= is used to handle the case for greater index return is asked in questoin
              max_weight=weigh.second;
              max_weight_index=weigh.first;
          }
      }
      return max_weight_index;
      // code here
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends