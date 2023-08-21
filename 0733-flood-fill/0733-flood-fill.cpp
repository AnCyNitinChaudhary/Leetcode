class Solution {
public:
    // void dfs(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&image,int color,int initialcolor){
    //     vis[i][j]=1;
    //     //int tempcolor=image[i][j];
    //     image[i][j]=color;
    //     if(i+1>=0&&i+1<=n&&j>=0&&j<m)if(vis[i+1][j]==0&&image[i+1][j]==initialcolor)dfs(i+1,j,n,m,vis,image,color,initialcolor);
    //     if(i-1>=0&&i-1<=n&&j>=0&&j<m)if(vis[i-1][j]==0&&image[i-1][j]==initialcolor)dfs(i-1,j,n,m,vis,image,color,initialcolor);
    //     if(i>=0&&i<=n&&j+1>=0&&j+1<m)if(vis[i][j+1]==0&&image[i][j+1]==initialcolor)dfs(i,j+1,n,m,vis,image,color,initialcolor);
    //     if(i>=0&&i<=n&&j>=0&&j-1<m)if(vis[i][j-1]==0&&image[i][j-1]==initialcolor)dfs(i,j-1,n,m,vis,image,color,initialcolor);
    // }
    // vector<vector<int>> floodFill(vector<vector<int>>& images, int sr, int sc, int color) {
    //     int n=images.size();
    //     int m=images[0].size();
    //     vector<vector<int>>image;
    //     image.assign(images.begin(),images.end());//even if I am creating the copy of my vector, still i am getting the same error
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     dfs(sr,sc,n,m,vis,image,color,image[sr][sc]);
    //     return image;
    //     //The above code is giving same error as i got in previous question. So ask to pratham that why the error is coming while I am doing in a correct way.
    // }




























    //solving for intuit-
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
    void dfs(int i,int j,vector<vector<int>>&vis,int previouscolor,int color,int M,int N,vector<vector<int>>&ans){
        vis[i][j]=1;
        ans[i][j]=color;
        vector<int>temp1={-1,0,1,0};
        vector<int>temp2={0,1,0,-1};
             for(int temp=0;temp<=3;temp++){
                    int newrow=i+temp1[temp];
                    int newcol=j+temp2[temp];
                    if(newrow>=0&&newrow<M&&newcol>=0&&newcol<N&&ans[newrow][newcol]==previouscolor&&!vis[newrow][newcol]){
                        dfs(newrow,newcol,vis,previouscolor,color,M,N,ans);
                    }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& images, int sr, int sc, int color) {
        int M=images.size();
        int N=images[0].size();
        int count=0;
        vector<vector<int>>ans(images.begin(),images.end());
        vector<vector<int>>vis(M,vector<int>(N,0));
        // int previouscolor=images[sr][sc];
            // bfs(i,j,vis,grid,M,N);
        dfs(sr,sc,vis,images[sr][sc],color,M,N,ans);
        return ans;
    }
};