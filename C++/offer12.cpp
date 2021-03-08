#include"stdfax.h"
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>mark(board.size(),vector<bool>(board[0].size()));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j]=false;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,mark,i,j,word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>&mark,int x,int y,string word){
        if(board[x][y]!=word[0]){
            return false;
        }
        if(word.size()==1){
            return true;
        }
        mark[x][y]=true;
        string newWord=word.substr(1,int(word.size()-1));
        int res=false;
        if(x+1<board.size()&&!mark[x+1][y]){
            res=dfs(board,mark,x+1,y,newWord);
        }
        if(res){
            mark[x][y]=false;
            return true;
        }

        if(y+1<board[0].size()&&!mark[x][y+1]){
            res=dfs(board,mark,x,y+1,newWord);
        }
        if(res){
            mark[x][y]=false;
            return true;
        }

        if(x-1>=0&&!mark[x-1][y]){
            res=dfs(board,mark,x-1,y,newWord);
        }
        if(res){
            mark[x][y]=false;
            return true;
        }

        if(y-1>=0&&!mark[x][y-1]){
            res=dfs(board,mark,x,y-1,newWord);
        }
        if(res){
            mark[x][y]=false;
            return true;
        }
        mark[x][y]=false;
        return false;
    }
};
int main(){
    Solution x;
    vector<vector<char>>board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    cout<<x.exist(board,string("ABCCED"));

    return 0;
}