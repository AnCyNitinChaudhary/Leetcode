//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
       unordered_map<char,int>um;
       for(char i='a';i<='z';i++)um[i]=0;
       for(int i=0;i<s.size();i++){
           if(s[i]=='b'||s[i]=='a'||s[i]=='l'||s[i]=='o'||s[i]=='n')um[s[i]]++;
       }
       um['o']/=2;
       um['l']/=2;
       int temp=min(um['b'],um['a']);
       temp=min(temp,um['l']);
       temp=min(temp,um['o']);
       temp=min(temp,um['n']);
      return temp;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends