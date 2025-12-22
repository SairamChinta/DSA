class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev(n, 0);

        for (int j = 0; j < n; j++)
            prev[j] = triangle[n - 1][j];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> cur(n, 0);
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j + 1];
                cur[j] = min(down, diag);
            }
            prev = cur;
        }
        return prev[0];
    }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n,vector<int>(n,0));
    //     for(int j = 0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
    //     for(int i =n-2;i>=0;i--){
    //         for(int j = i;j>=0; j--){
    //             int down = triangle[i][j] + dp[i+1][j];
    //             int diag = triangle[i][j] + dp[i+1][j+1];
    //             dp[i][j] = min(down, diag);
    //         }
    //     }
    //     return dp[0][0];
    // }
};