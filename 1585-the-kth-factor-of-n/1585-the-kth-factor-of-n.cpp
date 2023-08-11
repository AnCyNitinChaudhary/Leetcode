class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>facts;
        facts.push_back(1);
        for(int i=2;i<=n;i++){
            if(n%i==0)facts.push_back(i);
        }
        if(facts.size()<k)return -1;
        return facts[k-1];
    }
};