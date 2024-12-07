class Solution {
private:
    int bfsRotting(vector<vector<int>>& grid,int m,int n){
        queue<pair<int,int>>rotten;
        int time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)rotten.push({i,j});
            }
        }
        int nRow[4]={0,-1,0,+1};
        int nCol[4]={-1,0,+1,0};
        while(!rotten.empty()){
            bool isChanged=false;
            int size=rotten.size();
            while(size--){
                pair<int,int> index=rotten.front();
                rotten.pop();
                for(int i=0;i<4;i++){
                    int cRow=index.first+nRow[i];
                    int cCol=index.second+nCol[i];
                     if (cRow >= 0 && cRow < m && cCol >= 0 && cCol < n && grid[cRow][cCol] == 1){
                        grid[cRow][cCol]=2;
                        rotten.push({cRow,cCol});
                        isChanged=true;
                    }
                }
            }
            if(isChanged)time++;
        }
        return time;
    }
public:
     int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int timeTaken = bfsRotting(grid, m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return timeTaken;
    }
};