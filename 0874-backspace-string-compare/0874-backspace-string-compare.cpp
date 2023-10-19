class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temps="";
        for(auto i:s){
            if(i=='#'&&temps.size()>0)temps.pop_back();
            else if(i!='#')temps.push_back(i);
        }
        string tempt="";
        for(auto i:t){
            if(i=='#'&&tempt.size()>0)tempt.pop_back();
            else if(i!='#')tempt.push_back(i);
        }
        // cout<<temps<<endl;
        // cout<<tempt<<endl;
        return temps==tempt;
    }
};

