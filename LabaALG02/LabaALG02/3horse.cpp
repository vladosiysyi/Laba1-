
#include <iostream>

using namespace std;

const int N = 5;
int board[N][N];
int moveX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int moveY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool solveHorseTour(int x, int y, int moveCount) {
    if (moveCount == N * N) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (isSafe(nextX, nextY)) {
            board[nextX][nextY] = moveCount + 1;
            if (solveHorseTour(nextX, nextY, moveCount + 1)) {
                return true;
            }
            else {
                board[nextX][nextY] = -1; // Откат
            }
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    int startX = 2, startY = 2; // Начальная позиция коня
    board[startX][startY] = 0; // Устанавливаем начальную позицию

    if (solveHorseTour(startX, startY, 1)) {
        printBoard();
    }
    else {
        cout << "Решение не найдено." << endl;
    }

    return 0;
}
