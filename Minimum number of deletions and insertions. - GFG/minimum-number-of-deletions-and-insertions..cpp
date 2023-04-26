//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
// 		int f(string s1,int n1,string target,int n2){
// 		    if(s1==target)
// 		}
//I am not able to write recursive+memoization code  for this question while I know how to solve this using tabulation dp and which I will solve today definitely.
	public:
	int minOperations(string word1, string word2) 
	{ 
	    // Your code goes here
	    //Let f(str1,n1,str2,n2) returns minimum number of insertion+deletion to transform str1 to str2
	    //return f(str1,str1.size()-1,str2,str2.size()-1);
	    //solve using tabulation dp after revising class notes.
	    int n1=word1.size();
        int n2=word2.size();
	    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    for(int j=0;j<=n2;j++)dp[0][j]=0;
    for(int i=0;i<=n1;i++)dp[i][0]=0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs=dp[n1][n2];
    int deletion=n1-lcs;
    int insertion=n2-lcs;
    return (insertion+deletion);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends