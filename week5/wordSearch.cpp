class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word, int i, int j , int count)
    {
        if(count==word.size())
            return true;
       if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j] != word[count])
           return false;
        char temp=board[i][j];
          board[i][j]='\0';
        bool ans = dfs(board,word,i+1,j,count+1) || 
                     dfs(board,word,i-1,j,count+1) ||
                        dfs(board,word,i,j+1,count+1) ||
                            dfs(board,word,i,j-1,count+1);
        board[i][j]=temp;
return ans;
    }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        //if(board.size()==0) return false;
        for(int i=0; i<board.size();i++)
        {
            for(int j=0; j<board[i].size();j++)
            {
                if(board[i][j]==word[0] && dfs(board,word,i,j,0))  return true;
            }
        }
return false;
    }
};
