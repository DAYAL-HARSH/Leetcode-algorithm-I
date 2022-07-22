class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int Max = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = 1;
                if(grid[i][j] == 1)
                {
                    count_island(grid,i,j,count);
                    Max = max(Max,count);
                }
            }
        }
        return Max;
    }
    int count_island(vector<vector<int>>& grid,int i,int j,int& count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return 0;
        
        if(grid[i][j] == 0)
            return 0;
        
        grid[i][j] =0;
        
        if(count_island(grid,i-1,j,count))
            count++;
        if(count_island(grid,i+1,j,count))
            count++;
        if(count_island(grid,i,j-1,count))
            count++;
        if(count_island(grid,i,j+1,count))
            count++;
        
        return 1;
        
    }
};
