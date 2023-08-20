class Solution {
public:

//   bool isPalindrome(const string& s, int l, int r) {
//     while (l < r)
//       if (s[l++] != s[r--])
//         return false;
//     return true;
//   }
// void f(string s,int index,vector<vector<string>>&ans,vector<string>&temp){
//     if(index>=s.size()){
//         ans.push_back(temp);
//         return;
//     }
//     for(int i=index;i<s.size();i++){
//         if(isPalindrome(s,index,i)){
//             temp.push_back(s.substr(index,i-index+1));
//             f(s,i+1,ans,temp);
//             temp.pop_back();
//         }
//     }
// }
    // vector<vector<string>> partition(string s) {
        //below code generates all substring and not the partition
        // vector<vector<string>> v;
        // vector<string> v1;
        // for(int i=0;i<s.size();i++){
        //     string ans="";
        //     for(int j=i;j<s.size();j++){
        //         ans+=s[j];
        //         v1.push_back(ans);
        //         v.push_back(v1);
        //     }
        // }
        // return v;
    //}
//     vector<vector<string>> partition(string s) {
//     vector<vector<string>> ans;
//     dfs(s, 0, {}, ans);
//     return ans;
//   }

//  private:
//   void dfs(const string& s, int start, vector<string>&& path,
//            vector<vector<string>>& ans) {
//     if (start == s.length()) {
//       ans.push_back(path);
//       return;
//     }

//     for (int i = start; i < s.length(); ++i)
//       if (isPalindrome(s, start, i)) {
//         path.push_back(s.substr(start, i - start + 1));
//         dfs(s, i + 1, move(path), ans);
//         path.pop_back();
//       }
//   }
//Going to solve this problem by my own without any other resourse help.
// vector<vector<string>>ans;
// vector<string>temp;
// int index=0;
// f(s,0,ans,temp);
// return ans;
// }

//Solving for intuit preparation-
    bool palindrome(string &s,int i,int index){
        while(i<index){
            if(s[i]!=s[index])return false;
            i++;
            index--;
        }
        return true;
    }
    void solve(int i,string &s,vector<vector<string>>&ans,vector<string>&temp){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int index=i;index<s.size();index++){
            if(palindrome(s,i,index)){
                temp.push_back(s.substr(i,index-i+1));
                solve(index+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,ans,temp);
        return ans;

    }
};