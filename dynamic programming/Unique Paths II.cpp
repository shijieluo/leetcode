class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 1;
        int dp[obstacleGrid.size()+1][obstacleGrid[0].size()+1] = {0};
        if(!obstacleGrid[0][0]) dp[0][0] = 1;        
        for(int i = 0; i < obstacleGrid.size(); i ++) {
            for(int j = 0; j < obstacleGrid[0].size(); j ++) {
                if( i == 0 &&  j == 0) continue;                
                if(obstacleGrid[i][j]){
                    dp[i][j] = 0;
                }else if(i == 0){                    
                    dp[i][j] = dp[i][j-1];                    
                }else if(j == 0){                    
                    dp[i][j] = dp[i-1][j];
                }else{                    
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                cout << dp[i][j] << endl;
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};