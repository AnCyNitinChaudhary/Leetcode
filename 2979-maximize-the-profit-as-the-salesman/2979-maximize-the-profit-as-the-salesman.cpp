class Solution {
public:
//     int f(int n,vector<vector<int>>&offers,int i,unordered_map<pair<int,int>>&um){
//         if(i>=n)return 0;
//         int take=0;
//         if(um.find(offers[{offers[0],offers[1]}]==um.end()||offers[{offers[i][0],offers[1][1]}]<offeres[i][2]}){
//             um[{offers[i][0],offers[1][1]}]=offers[i][2];
//             flag=1;
//             take=offers[i][2]+f(n,offers,i+1,um);
//         }
//         int notTake=f(n,offers,i+1,us);
//         return max(take,notTake);
// }
    
    int maximum_profit(int n,vector<vector<int>>&intervals)
    {
    vector<pair<int,pair<int,int>>> events;
    for (int i=0;i<intervals.size();i++) {
        events.push_back({ intervals[i][0],{ intervals[i][1], intervals[i][2]}});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    sort(events.begin(), events.end());
    int max_profit=0;
    for(auto&e:events){
        while(!pq.empty()&&pq.top().first<e.first) {
            max_profit=max(max_profit,pq.top().second);
            pq.pop();
        }
        pq.push({e.second.first,max_profit+e.second.second});
    }
    while(!pq.empty()){
        max_profit = max(max_profit,pq.top().second);
        pq.pop();
    }
    return max_profit;
    }
 
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        //I have to try out all possible ways
        // unordered_map<pair<int,int>um;
        // return f(n,offers,0,um);
        return maximum_profit(n,offers);
    }
};