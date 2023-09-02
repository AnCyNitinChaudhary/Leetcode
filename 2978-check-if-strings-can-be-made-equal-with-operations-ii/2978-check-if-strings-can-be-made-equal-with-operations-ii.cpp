class Solution {

public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,vector<int>>um;
        for(int i=0;i<s2.size();i++){
            um[s2[i]]={0,0};
        }
            for(int i=0;i<s2.size();i++){
                if(i%2==0){
                    um[s2[i]][0]+=1;
                }
                else{
                    um[s2[i]][1]+=1;
                }
            }
        unordered_map<char,int>um1;
        // for(int i=0;i<s1.size();i++){
        //     um1[s1[i]]++;
        // }
        // for(int i=0;i<s1.size();i++){
        //     if(um.find(s1[i])==um.end())return false;
        //     int f1=um[s1[i]][0];
        //     int f2=um[s1[i]][1];
        //     if(um1[s1[i]]!=(f1+f2))return false;
        // }
        for(int i=0;i<s1.size();i++){
            if(um.find(s1[i])==um.end())return false;
            if(i%2==0){
                if(um[s1[i]][0]==0)return false;
                um[s1[i]][0]=um[s1[i]][0]-1;
            }
            else {
                    if(um[s1[i]][1]==0)return false;;
                    um[s1[i]][1]=(um[s1[i]][1])-1;
                }
        }
        return true;

    }
};