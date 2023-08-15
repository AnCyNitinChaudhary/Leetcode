class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Brute Force
        //finding the minimum length
        // int mini=INT_MAX;
        // for(int i=0;i<strs.size();i++){
        //     int temp=strs[i].size();
        //     mini=min(mini,temp);
        // }
        // string ans="";
        // int flag=0;
        // for(int i=0;i<mini;i++){
        //     for(int j=0;j<strs.size()-1;j++){
        //         if(strs[j][i]==strs[j][i+1]){
        //             if(j==strs.size()-2)ans+=strs[j][i];
        //         }
        //         else{
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(flag)break;
        // }
        // return ans;

        int n=strs.size();
        if(n==0)return "";
        string ans="";
        sort(strs.begin(),strs.end());
        string start=strs[0];
        string ending=strs[n-1];
        for(int i=0;i<min(start.size(),ending.size());i++){
                if(start[i]==ending[i])ans+=start[i];
                else break;
        }
        return ans;
    }
};