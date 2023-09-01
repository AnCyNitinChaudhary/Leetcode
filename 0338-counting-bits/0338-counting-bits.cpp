class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int counti=0;
            int tempi=i;
             while (tempi) {
                counti += tempi & 1;
                tempi >>= 1;
            }
            ans.push_back(counti);
        }
        return ans;
    }
};