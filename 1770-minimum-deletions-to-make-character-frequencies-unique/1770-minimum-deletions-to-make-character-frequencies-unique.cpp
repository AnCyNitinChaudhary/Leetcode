// class Solution {
// public:
//     int minDeletions(string s) {
//         unordered_map<char,int>um;
//         for(char i:s){
//             um[i]++;
//         }
//         unordered_set<int>us;
//         int counti=0;
//         for(auto i:um){
//             cout<<i.first<<i.second<<endl;
//             if(us.find(i.second)!=us.end()){
//             counti+=2;
//             us.erase(i.second);
//             }
//             else us.insert(i.second);
//         }
//         return counti;
//     }
// };
//will solve after t1
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq (26, 0);        
        for (char c : s) freq[c - 'a']++;
        sort(freq.begin(), freq.end());
        int del = 0;
        for (int i = 24; i >= 0; i--) {
            if(freq[i] == 0) break;            
            if(freq[i] >= freq[i+1]){
                int prev = freq[i];
                freq[i] = max(0, freq[i+1] -1);
                del += prev - freq[i]; 
            }
        }
        return del;
    }
};