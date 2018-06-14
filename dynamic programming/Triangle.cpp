class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[triangle.size()-1].size();
        int dp[m][n];
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(0<j&&j<triangle[i].size()-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }else if(j==triangle[i].size()-1){
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }
            }
        }
        int min=0x7fffffff;
        for(int i=0;i<triangle[m-1].size();i++){
            if(dp[m-1][i]<min){
                min=dp[m-1][i];
            }
        }
        return min;
    }
};