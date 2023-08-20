class Solution {
public:
    // void dfs(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<char>>&grid){
    //     vis[i][j]=1;
    //     if(i>=0&&j+1>=0&&i<=n&&j+1<=m&&i!=j+1&&grid[i][j+1]=='1'&&vis[i][j+1]!=1)dfs(i,j+1,n,m,vis,grid);
    //     if(i+1>=0&&j>=0&&i+1<=n&&j<=m&&i+1!=j&&grid[i+1][j]=='1'&&vis[i+1][j]!=1)dfs(i+1,j,n,m,vis,grid);
    //     if(i>=0&&j-1>=0&&i<=n&&j-1<=m&&i!=j-1&&grid[i][j-1]=='1'&&vis[i][j-1]!=1)dfs(i,j-1,n,m,vis,grid);
    //     if(i-1>=0&&j>=0&&i-1<=n&&j<=m&&i-1!=j&&grid[i][j]=='1'&&vis[i-1][j]!=1)dfs(i-1,j,n,m,vis,grid);
    // }

// void DFS(vector<vector<char>>&grid, int m, int n, int i, int j){
//         if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')return;
//         if(grid[i][j]=='1'){
//             grid[i][j]='0';
//             DFS(grid,m,n,i-1,j);
//             DFS(grid,m,n,i+1,j);
//             DFS(grid,m,n,i,j+1);
//             DFS(grid,m,n,i,j-1);
//         }
//     }









    // void bfs(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<char>> &grid){
    //     vis[i][j]=1;
    //     queue<pair<int,int>>q;
    //     q.push({i,j});
    //     while(!q.empty()){
    //         int r=q.front().first;
    //         int c=q.front().second;
    //         q.pop();
    //     // if(i>=0&&j+1>=0&&i<=n&&j+1<=m&&i!=j+1&&grid[i][j+1]=='1'&&vis[i][j+1]!=1){
    //     //     q.push({i,j+1});
    //     //     vis[r][c]=1;
    //     // }
    //     // if(i+1>=0&&j>=0&&i+1<=n&&j<=m&&i+1!=j&&grid[i+1][j]=='1'&&vis[i+1][j]!=1){
    //     //     q.push({i+1,j});
    //     //     vis[r][c]=1;
    //     // }
    //     // if(i>=0&&j-1>=0&&i<=n&&j-1<=m&&i!=j-1&&grid[i][j-1]=='1'&&vis[i][j-1]!=1){
    //     //     q.push({i,j-1});
    //     //     vis[r][c]=1;
    //     // }
    //     // if(i-1>=0&&j>=0&&i-1<=n&&j<=m&&i-1!=j&&grid[i][j]=='1'&&vis[i-1][j]!=1){
    //     //     q.push({i-1,j});
    //     //     vis[r][c]=1;
    //     // }
    //     for(int delrow=-1;delrow<=1;delrow++){
    //         for(int delcol=-1;delcol<=1;delcol++){
    //             int nrow=nrow+delrow;
    //             int ncol=ncol+delcol;
    //             if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]=='1'&&!vis[nrow][ncol]){
    //                 vis[nrow][ncol]=1;
    //                 q.push({nrow,ncol});
    //             }
    //         }
    //     }
    //     }
    // }
    // int numIslands(vector<vector<char>>& grid) {
        //Creating the adjacency list for dfs 
       // vector<int> adj[n];//n is the number of ones in the matrix- as we are not already aware about the number of one in the matrix and hence we have to find it.So, I am solving this problem as per striver approach. But I will solve this both by dfs and bfs.
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(grid[i][j]){   
        //         }
        //     }
        // }
        // int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         vis[i][j]=0;
        //     }
        // }
        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]=='1'&&!vis[i][j]){
        //             count++;
        //             bfs(i,j,n,m,vis,grid); //bfs code is also giving same error similar to dfs. Try to find out why such errors are coming.
                    //OR
                    //dfs(i,j,n,m,vis,grid); dfs code is giving some error. Try to find and rectify it whenever you will be free.
        //         }
        //     }
        // }
        // return count;
    // int cnt=0;
    //     int m=grid.size(),n=grid[0].size();
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]=='1'){
    //                 cnt++;
    //                 DFS(grid,m,n,i,j);
    //             }
    //         }
    //     }
    //     return cnt;
    // }












//Solving for intuit...
    // void dfs(int i,vector<int>&vis,vector<int> adj[]){
    //     vis[i]=1;
    //     for(auto node:adj[i]){
    //         if(!vis[node])dfs(node,vis,adj);
    //     }
    // }
    // int numIslands(vector<vector<char>>& grid) {
    //     int M=grid.size();
    //     int N=grid[0].size();

    //     vector<int>adj[max(N,M)];
    //     for(int i=0;i<M;i++){
    //         for(int j=i+1;j<N;j++){
    //             if(grid[i][j]){
    //                 adj[i].push_back(j);
    //                 adj[j].push_back(i);
    //             }
    //         }
    //     }
    //     int count=0;
    //     vector<int>vis(max(N,M),0);
    //     for(int i=0;i<max(N,M);i++){
    //         if(!vis[i]){
    //             count++;
    //             dfs(0,vis,adj);
    //         }
    //     }
    //     return count;
    // }

    //My thinking using adj list was wrong but I will try to think why when I will be solving thuis problem again but for now solving the problem by using same matrix.
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,int m,int n){
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            vector<int>temp1={-1,0,1,0};
            vector<int>temp2={0,1,0,-1};
            for(int temp=0;temp<=3;temp++){
                    int newrow=p.first+temp1[temp];
                    int newcol=p.second+temp2[temp];
                    if(newrow>=0&&newrow<m&&newcol>=0&&newcol<n&&grid[newrow][newcol]=='1'&&!vis[newrow][newcol]){
                        vis[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
        }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int M=grid.size();
        int N=grid[0].size();
        int count=0;
        vector<vector<int>>vis(M,vector<int>(N,0));
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    count++;
                    bfs(i,j,vis,grid,M,N);
                    //dfs();
                }
            }
        }
        return count;


        //Try to find out the error if not able to correct the code then please see striver video again or see another tutorial for this question and then implement the code again.
        //If you are able to implement this by using bfs then must implement it using dfs to boost its implementation also.
    }
};