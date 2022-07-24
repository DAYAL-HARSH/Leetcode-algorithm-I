#define vvi vector<vector<int>>
#define iPair pair<int,int>
class Solution {
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    void bfs(queue<iPair> &q, vvi &res, int r, int c) {
         while(!q.empty()) {
            iPair curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            for(auto d:dir) {
                int newX = x+d[0], newY = y+d[1];
                
                if(newX >= 0 && newX < r && newY>=0 && newY < c) {
                    if(res[newX][newY] > res[x][y] + 1) {
                        res[newX][newY] = res[x][y] + 1;
                        q.push({newX,newY});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        vvi res(r, vector<int> (c,INT_MAX));
        queue<iPair> q;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(!mat[i][j]) {
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        bfs(q, res, r, c);       
        return res;
    }
};
