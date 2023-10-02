class Solution {
public:
    bool winnerOfGame(string colors) {
        int al=0,bb=0;
        for(int i=1;i<colors.length()-1;i++){
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
                if(colors[i] == 'A') al++;
                else bb++;
            }
        }
        return al>bb;
    }
};