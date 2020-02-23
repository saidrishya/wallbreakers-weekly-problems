class Solution {
    public boolean isValidSudoku(char[][] board) {
        
         HashSet<String> m= new HashSet();
        
         for(int i=0; i<9; i++){
             for(int j=0; j<9; j++){
                 char ch = board[i][j];
                 if(ch!= '.'){
                     if(!m.add(ch + "found in row" + i) ||
                       !m.add(ch + "found in column" + j) ||
                       !m.add(ch + "found in grid" + i/3 + "-" + j/3)) return false;
                 }
             }
         }
        return true;
    }
}
