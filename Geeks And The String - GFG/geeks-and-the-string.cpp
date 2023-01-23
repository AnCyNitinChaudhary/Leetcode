//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // string ans="";
        // int flag=0;
        // for(int i=0;i<s.size()-1;i++){
        //     if(s[i]!=s[i+1]&&flag==0){
        //         ans+=s[i];
        //         flag=1;
        //     }
        //     else flag=0;
        // }
        // return ans;
        // code here
        stack<int>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            char ch=s[i];
            if(st.empty()||st.top()!=ch)st.push(ch);
            else if(st.top()==ch)st.pop();
        }
        if(st.empty())return "-1";
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends