class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        unordered_map<double,int>um;
        for(int i=0;i<rec.size();i++){
            double temp=rec[i][0]/(rec[i][1]*1.0);
            um[temp]++;
        }
        long long counti=0;
        for(auto i:um){
            int n=i.second;
            long long possibilities=(long long)n*(n-1)/2;
            // cout<<"Possibilities"<<possibilities<<endl;
            counti+=possibilities;
        }
        return counti;
    }
};