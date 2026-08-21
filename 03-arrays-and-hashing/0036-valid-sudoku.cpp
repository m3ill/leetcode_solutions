/*
* Problem: LeetCode 36 - Valid Sudoku
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Hash Set
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> row;
        std::unordered_set<char> column;
        std::unordered_set<char> box;

        //row controller
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j< board[i].size();j++){
                if(board[i][j] =='.'){continue;}
                if(row.contains(board[i][j])){
                    return false;
                }
                row.insert(board[i][j]);
            }
            row.clear();
        }

        //column controller
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[j][i] == '.'){continue;}
                if(column.contains(board[j][i])){
                    return false;
                }
                column.insert(board[j][i]);
            }
            column.clear();
        }
        
        //box controller
        for(int i = 0;i<board.size();i+=3){
            for(int j = 0;j<board[i].size();j+=3){
                for(int k = 0;k < board.size()/3;k++){
                    for(int l = 0;l < board[i].size()/3;l++){
                        if(board[i+k][j+l] == '.'){continue;}
                        if(box.contains(board[i+k][j+l])){
                            return false;
                        }
                        box.insert(board[i+k][j+l]);
                    }
                }
                box.clear();
            }
        }


    
        return true;
    }
};
