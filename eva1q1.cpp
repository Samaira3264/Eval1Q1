#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Cofactor(vector<vector<int>>& matrix, vector<vector<int>>& temp, int x, int y, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != x && col != y) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(vector<vector<int>>& matrix, int n) {
    if (n == 1)
        return matrix[0][0];
    int det = 0;
    vector<vector<int>> temp(n, vector<int>(n));
    int sign = 1;

    for (int k = 0; k < n; k++) {
        Cofactor(matrix, temp, 0, k, n);
        det += sign * matrix[0][k] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

int main() {
    int n;
    cout << "enter size of the matrix (n x n): ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "enter elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "entered matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int det = determinant(matrix, n);
    cout << "Determinant of the matrix: " << det << endl;
    return 0;
}
