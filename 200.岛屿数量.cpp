/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    // bfs(grid, i, j);
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    // void bfs(vector<vector<char>>& grid, int i, int j){
    //     int m = grid.size(), n = grid[0].size();
    //     pair<int, int> pos(i,j);
    //     queue<pair<int, int>> q;
    //     q.push(pos);
    //     while(!q.empty()){
    //         pair<int, int>cur = q.front();
    //         q.pop();
    //         int size = q.size();
    //         int i = cur.first, j = cur.second;
    //         if(i+1 < m && grid[i+1][j] == '1'){
    //             q.push(make_pair(i+1, j));
    //             grid[i+1][j] = '0';
    //         }
    //         if(i-1 >= 0 && grid[i-1][j] == '1'){
    //             q.push(make_pair(i-1, j));
    //             grid[i-1][j] = '0';
    //         }
    //         if(j+1 < n && grid[i][j+1] == '1'){
    //             q.push(make_pair(i, j+1));
    //             grid[i][j+1] = '0';
    //         }
    //         if(j-1 >= 0 && grid[i][j-1] == '1'){
    //             q.push(make_pair(i, j-1));
    //             grid[i][j-1] = '0';
    //         }
    //     }
    // }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0') return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};
// @lc code=end

