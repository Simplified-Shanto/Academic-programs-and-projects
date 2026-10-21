#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;
const int boardSize = 4;  // Number of queens to place and board rows/columns.

bool isSafe(const vector<int>& queenColumnByRow, int candidateRow, int candidateColumn) {
    // Check only earlier rows because later rows do not have queens yet.
    for (int placedQueenRow = 0; placedQueenRow < candidateRow; placedQueenRow++) {
        int placedQueenColumn = queenColumnByRow[placedQueenRow];

        // A queen in the same column can attack the candidate queen.
        if (placedQueenColumn == candidateColumn) {
            return false;
        }
        // Equal row and column distances mean both squares share a diagonal.
        if (abs(placedQueenColumn - candidateColumn) ==
            abs(placedQueenRow - candidateRow)) {
            return false;
        }
    }
    return true;
}


bool solveNQueens(vector<int>& queenColumnByRow, int currentRow)
{
 // Every row has a safely placed queen.
 if (currentRow == boardSize) { return true; }

 // Try every candidate column in the current row.
 for (int candidateColumn = 0; candidateColumn < boardSize; candidateColumn++) {
    if (isSafe(queenColumnByRow, currentRow, candidateColumn)) {
        queenColumnByRow[currentRow] = candidateColumn;

        // Try to place a queen in the next row.
        if (solveNQueens(queenColumnByRow, currentRow + 1)) {
            return true;
        }

        // Later rows failed, so remove this candidate queen and try again.
        queenColumnByRow[currentRow] = -1;
    }
 }

 // No safe column exists in the current row.
 return false;
}

int main() {
    // queenColumnByRow[row] stores the queen's column in that row.
    // -1 means no queen has been placed in the row yet.
    vector<int> queenColumnByRow(boardSize, -1);

    solveNQueens(queenColumnByRow, 0);

    for (int boardRow = 0; boardRow < boardSize; boardRow++)
    {
        for (int boardColumn = 0; boardColumn < boardSize; boardColumn++) {
           if (queenColumnByRow[boardRow] == boardColumn) {
            cout << 1 << " ";
           } else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
