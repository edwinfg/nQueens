#include <iostream>
using namespace std;

#define N 13

void printSolution(int board[][N]){
    static int solutionCount = 0;
    cout << "Solucion " << ++solutionCount << ":\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Comprueba si es seguro colocar una reina 
// en la posición board[row][col]. Ojo, sólo una posición
bool isSafe(int board[][N], int row, int col){
    
    // Comprobar la misma colunma dada pero sólo arriba
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Comprobar la diagonal superior izquierda
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    
    // Comprobar la diagonal superior derecha
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}


bool solveNQueen(int board[][N], int row){
    if (row >= N){
        printSolution(board);
        return false;
    }

    bool res = false;
    for (int j = 0; j < N; j++){
        if (isSafe(board, row, j)) {
            board[row][j] = 1;

            res = solveNQueen(board, row + 1) || res;

            board[row][j] = 0;
        }
    }
    return false;
}

int main(){
    int board[N][N] = {0};

    if (!solveNQueen(board, 0))
        cout << "No existe soluciones!" << endl;
    
    return 0;
}
