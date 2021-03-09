#include"stdfax.h"
class Solution {
public:
    int cuttingRope(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            dp[i][1]=i;//length i ;i pieces
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=i;j++){
                int res=0;
                for(int k=1;i-k>=j-1;k++){
                    res=max(res,dp[i-k][j-1]*k);
                }
                dp[i][j]=res;
            }
        }
        int tmp=0;
        for(int i=2;i<=n;i++){
            tmp=max(tmp,dp[n][i]);
        }
        return tmp;
    }
};