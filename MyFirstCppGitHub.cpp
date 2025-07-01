// MyFirstCppGitHub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int n = 4;

void showBoard(vector<vector<int>>& board) {

    cout << " sudoku board \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            cout << board[i][j] << " ";

        }
        cout << endl;
    }

};

bool validChoice(vector<vector<int>>& board, int row, int col, int choice) {
    for (int i = 0; i < n; i++) {
        if (board[row][i] == choice || board[i][col] == choice) return false;
    }


    int rowbox = row / 2;
    int colbox = col / 2;

    for (int i = rowbox * 2; i < rowbox * 2 + 2; i++) {
        for (int j = colbox * 2; j < colbox * 2 + 2; j++) {
            if (board[i][j] == choice) return false;
        }
    }


    return true;
}

bool solveSudoku(vector<vector<int>>& board, int row, int col) {
    if (row == n) return true;

    if (col == n) return solveSudoku(board, row + 1, 0);

    if (board[row][col] != 0) return solveSudoku(board, row, col + 1);

    for (int choice = 1; choice <= 4; choice++) {
        if (validChoice(board, row, col, choice)) {
            board[row][col] = choice;
            if (solveSudoku(board, row, col + 1)) return true;
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> sudoku = {
        { 0 ,0 , 4 , 0 },
        { 0 ,0 , 0 , 0 },
        { 2 ,0 , 3 , 0 },
        { 0 ,1 , 0 , 0 },
    };
    cout << " initial board : \n";
    showBoard(sudoku);

    if (solveSudoku(sudoku, 0, 0)) {
        cout << " solved sudoku board \n";
        showBoard(sudoku);
    }
    else {
        cout << " the board is not solvable \n";
    }

    return 0;
}