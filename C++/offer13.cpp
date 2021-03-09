#include"stdfax.h"
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>>mark(m,vector<bool>(n));
        int count=0;;
        dfs(mark,0,0,k,count);
        return count;
    }
    int countSum(int x,int y){
        int res=0;
        while(x>0){
            res+=x%10;
            x=x/10;
        }
        while(y>0){
            res+=y%10;
            y=y/10;
        }
        return res;
    }
    void dfs(vector<vector<bool>>&mark,int x,int y,int k,int&count){
        if(mark[x][y]){
            return;
        }
        if(countSum(x,y)>k){
            return;
        }
        mark[x][y]=true;
        count++;
        if(x+1<mark.size()){
            dfs(mark,x+1,y,k,count);
        }
        if(y+1<mark[0].size()){
            dfs(mark,x,y+1,k,count);
        }
        if(x-1>=0){
            dfs(mark,x-1,y,k,count);
        }
        if(y-1>=0){
            dfs(mark,x,y-1,k,count);
        }
    }
};
int main(){
    Solution x;
    cout<<x.movingCount(3,2,17);
    return 0;
}