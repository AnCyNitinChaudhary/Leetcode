class Solution {
public:
    int bestClosingTime(string customers) {
        // vector<int>penaltyclose;
        // vector<int>penaltyopen;
        // if(customers[0]=='Y'){
        //     penaltyopen.push_back(0);
        //     penaltyclose.push_back(1);
        // }
        // else{
        //     penaltyopen.push_back(1);
        //     penaltyclose.push_back(0);
        // }
        // for(int i=1;i<customers.size();i++){
        //     if(customers[i]=='Y'){
        //          penaltyopen.push_back(penaltyopen[i-1]);
        //         penaltyclose.push_back(penaltyclose[i-1]+1);
        //     }
        //     else{
        //         penaltyopen.push_back(penaltyopen[i-1]+1);
        //         penaltyclose.push_back(penaltyclose[i-1]);
        //     }
        // }
        // int ans=INT_MAX;
        // int index;
        // // for(int i=0;i<penaltyopen.size();i++){
        // //     if(penaltyopen[i]<ans){
        // //         ans=penaltyopen[i];
        // //         index=i;
        // //     }
        // // }
        // for(int i=0;i<penaltyclose.size();i++){
        //     if(penaltyclose[i]<ans){
        //         ans=penaltyclose[i];
        //         index=i;
        //     }
        // }
        // return index;
        
        
        // int answer;
        // int penaltymin=INT_MAX;
        // for(int i=0;i<=customers.size();i++){
        //    int temppenalty=0;
        //     for(int j=0;j<i;j++){
        //         if(customers[j]=='N')temppenalty++;
        //     }
        //     for(int j=i;j<customers.size();j++){
        //         if(customers[j]=='Y')temppenalty++;
        //     }
        //     if(penaltymin>temppenalty){
        //         penaltymin=temppenalty;
        //         answer=i;
        //         // cout<<temppenalty<<" "<<answer<<endl;
        //     }
        // }
        // return answer;
        
        //The above code is correct but it is giving TLE...
        
        //The approach which I am thinking is to find the penalty when i am closing the shop in end time and then do o(n) traversal from the backside to find out the minimum penalty by updating the answer simulataneously.
//         int answer=customers.size();
//         int penaltymin=0;
        
//         //if closing the shop in last
//         for(int i=0;i<customers.size();i++){
//             if(customers[i]=='N')penaltymin++;
//         }
//         int temppenalty=penaltymin;
//         for(int i=customers.size()-1;i>=0;i--){
//             if(customers[i]=='N')temppenalty--;
//             if(penaltymin>temppenalty){
//                 penaltymin=temppenalty;
//                 answer=i;
//             }
//         }
//         return answer;
        //This appraching is failing .
    
    //Another better approach which is coming in my brain is that- I can observe that in left part I always need to find out the number of N and in right part including present index, I need to find out the number of Y to find out the penalty at any present index.
        //So, I can create two arrays- prefix and suffix and store the values for corresponding index in them and then I can find out the answer in just O(n) time complexity.
        int n=customers.size();
        vector<int>prefix(n+1);//prefix[i] means number of N before i
        vector<int>suffix(n+1);//suffix[i] means number of Y after i and including i
        //filling prefix
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N'){
                prefix[i]=prefix[i-1]+1;
            }
            else prefix[i]=prefix[i-1];
        }
        
        //filling suffix
        suffix[n]=0;
        // if(customers[n-1]=='Y')suffix[n-1]=1;
        // else suffix[n-1]=0;
        for(int i=n-1;i>=0;i--) {
            if(customers[i]=='Y'){
                suffix[i]=suffix[i+1]+1;
            }
            else suffix[i]=suffix[i+1];
        }
        
        
        //finding answer index where the penalty is minimum.
        int index;
        int penalty=INT_MAX;
        for(int i=0;i<=n;i++){
            if(penalty>prefix[i]+suffix[i]){
                penalty=prefix[i]+suffix[i];
                index=i;
            }
        }
        return index;
        
    }
};