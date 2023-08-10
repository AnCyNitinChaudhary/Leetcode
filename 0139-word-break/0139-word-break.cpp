class Solution {
public:
    // bool f(int i,string s,unordered_set<string>&us){
    //     //
    //     if(i<0)return true;
    //     for(int j=i;j>=0;j--){
    //     if(us.find(s.substr(j,s.size()))!=us.end()){
    //         if(f(i-j,s,us))return true;
    //         //else return false;
    //     }
    //     }
    //     return false;
    // }
    // bool f(int i,string s,unordered_set<string>&us){
    //     if(i==s.size())return true;
    //     string temp;
    //     for(int j=i;j<s.size();j++){
    //         temp+=s[j];
    //         if(us.find(temp)!=us.end()&&f(j+1,s,us)==true)return true;
    //     }
    //     return false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     //As I will need to seach a corresponding word in the dictionay wordDict and hence which take O(n) time complexity for me.
    //     //Hence, I will take an unordered_set<string>us so that it will be easy to seach a given word in a dictionary.
    //     unordered_set<string> us;
    //     for(int i=0;i<wordDict.size();i++)us.insert(wordDict[i]);
    //     //Let f(i,s,us) returns whether we can do space-separated sequence of s of one or more dictionary words till index i in s.
    //     // return f(s.size()-1,s,us);
    //     return f(0,s,us);
    // }
    //The above code is giving TLE and hence I will be in need to solve this by using memoization
    //     bool f(int i,string s,unordered_set<string>&us,vector<bool>&dp){
    //     if(i==s.size())return true;
    //     if(dp[i]!=false)return dp[i];
    //     string temp;
    //     for(int j=i;j<s.size();j++){
    //         temp+=s[j];
    //         if(us.find(temp)!=us.end()&&f(j+1,s,us,dp)==true)return dp[i]=true;
    //     }
    //     return dp[i]=false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     vector<bool>dp(s.size(),false);
    //     unordered_set<string> us;
    //     for(int i=0;i<wordDict.size();i++)us.insert(wordDict[i]);

    //     return f(0,s,us,dp);
    // }
    //The above code of memoization is giving the TLE and hence I will be in need to do it by using tabulation or space optimization
    //Do it's tabulation when ever you will be free.
    // bool f(int i,int j,string &s,unordered_set<string>&us){
    //     if(i==j&&i>=s.size())return true;
    //     if(j>=s.size())return false;
    //     //stuff
    //     bool exist=false;
    //     bool notexist=false;
    //     if(us.find(s.substr(i,j))!=us.end())exist=f(j+1,j+1,s,us);
    //     notexist=f(i,j+1,s,us);
    //     return exist||notexist;
    // }

    //The below code gives TLE
    //   bool f(int start,string &s,unordered_set<string>&us){
    //     if(start==s.size())return true;
    //     //stuff
    //     for(int i=start;i<s.size();i++){
    //     if(us.find(s.substr(start,i+1-start))!=us.end()&&f(i+1,s,us))return true;
    //     }
    //     return false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     //The approach which I am thinking is to store these words in an unordered set and then I can try to solve it recursively.
    //     if(s.size()==0)return true;
    //     unordered_set<string>us(wordDict.begin(),wordDict.end());
    //     return f(0,s,us);
    // }

    // After applying memoization to the recursive code-
    bool f(int start,string &s,unordered_set<string>&us,vector<int>&dp){
        if(start==s.size())return true;
        if(dp[start]!=-1)return dp[start];
        //stuff
        for(int i=start;i<s.size();i++){
        if(us.find(s.substr(start,i+1-start))!=us.end()&&f(i+1,s,us,dp))return dp[start]=true;
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //The approach which I am thinking is to store these words in an unordered set and then I can try to solve it recursively.
        if(s.size()==0)return true;
        unordered_set<string>us(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return f(0,s,us,dp);
    }
};