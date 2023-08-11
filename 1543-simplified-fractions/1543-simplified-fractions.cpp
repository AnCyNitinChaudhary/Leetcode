class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        unordered_set<double>us;
        for(double i=1;i<=n-1;i++){
            for(double j=2;j<=n;j++){
                double temp=i/j;
                if(temp!=(int)temp&&us.find(temp)==us.end()&&temp<1.0){
                    string str=to_string((int)i)+'/'+to_string((int)j);
                    ans.push_back(str);
                    us.insert(temp);
                }
            }
        }
        return ans;
    }
};