class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // if(s.size()==1)return false;
        // unordered_map<char,int>um;
        // char c=s[0];
        // int tempcountc=0;
        // for(auto i:s){
        //     um[i]++;
        //     if(i==c)tempcountc++;
        // }
        // for(auto i:um){
        //     if(i.second!=tempcountc)return false;
        // }
        // return true;
        int n=s.size();
        for(int i=n/2;i>=1;i--){          
            if(n%i==0){                                                           
                if(s.substr(0,n-i)==s.substr(i))return true;        
            }
        }
        return false;
    }
};