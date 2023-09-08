class Solution {
public:
//below code is giving error check why.
    vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> ans(numRows);
    //     vector<int>temp(numRows);
    //     temp.push_back(1);
    //     ans.push_back(temp);
    //     if(numRows==1)return ans;
    //     temp.push_back(1);
    //     ans.push_back(temp);
    //     int j=2;
    //     while(j<numRows){
    //         int end;
    //         if(j%2!=0){
    //             end=(j/2)-1;
    //         }
    //         else end=j/2;
    //     for(int i=1;i<=end;i++){
    //         temp[i]=temp[i-1]+temp[i];
    //     }
    //     int e=end;
    //     if(j%2==0)e=end-1;
    //     for(int i=end+1;i<=j;i++){
    //         temp.push_back(temp[e]);
    //         e--;
    //     }
    //     ans.push_back(temp);
    //     j++;
    //     }
    //     return ans;
    // }


    vector<vector<int>>ans;
    for(int i=0;i<numRows;i++){
        vector<int>temp(i+1,1);
        for(int j=1;j<i;j++){
            temp[j]=ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(temp);
    }
    return ans;
    }

};