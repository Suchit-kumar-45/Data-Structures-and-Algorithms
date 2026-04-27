class Solution {
public:
    vector<vector<vector<int>>> dir = {
        {},
        {{0,-1},{0,1}},        // 1: left, right
        {{-1,0},{1,0}},        // 2: up, down
        {{0,-1},{1,0}},        // 3: left, down
        {{0,1},{1,0}},         // 4: right, down
        {{0,-1},{-1,0}},       // 5: left, up
        {{0,1},{-1,0}}         // 6: right, up
    };

    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();

        if(i == m-1 && j == n-1)
            return true;

        vis[i][j] = true;

        for(auto d : dir[grid[i][j]]) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(!isValid(ni, nj, m, n) || vis[ni][nj])
                continue;

            // check reverse connection
            for(auto back : dir[grid[ni][nj]]) {
                if(ni + back[0] == i && nj + back[1] == j) {
                    if(dfs(grid, ni, nj, vis))
                        return true;
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        return dfs(grid, 0, 0, vis);
    }
};