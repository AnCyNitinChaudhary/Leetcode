//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string small="",big="",ans="";
        for(int i=0;i<str.size();i++){
            if(isupper(str[i])){
                big+=str[i];
            }
            else small+=str[i];
        }
        sort(small.begin(),small.end());
        sort(big.begin(),big.end());
        int s=0;
        int b=0;
        for(int i=0;i<str.size();i++){
            if(isupper(str[i])){
                ans+=big[b];
                b++;
            }
            else{
                ans+=small[s];
                s++;
            }
        }
        return ans;
        // your code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends