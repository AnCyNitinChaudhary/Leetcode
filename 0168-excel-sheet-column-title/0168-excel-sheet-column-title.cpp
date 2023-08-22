class Solution {
public:
    string convertToTitle(int columnNumber) {
        // int times=ceil(columnNumber/26.0);
        // if(columnNumber!=26)columnNumber%=26;
        // char c=(char)(columnNumber+64);
        // string answer="";
        // for(int i=0;i<times;i++){
        //     answer+=c;
        // }
        // return answer;
        string ans;
        while(columnNumber > 0) {
            columnNumber--;
            int curr = columnNumber % 26;
            columnNumber/= 26;
            ans.push_back(curr + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};