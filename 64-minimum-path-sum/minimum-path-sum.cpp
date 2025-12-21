class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> prev(n,0);
        for( int i =0; i <= m-1; i++){
            vector<int> cur(n,0);
            for( int j =0; j <= n-1; j++){
                if(i ==0 && j == 0) cur[j] = grid[0][0];
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = grid[i][j] + prev[j];
                    if(j > 0) left = grid[i][j] + cur[j-1];
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};