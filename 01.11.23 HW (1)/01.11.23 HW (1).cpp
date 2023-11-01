#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

//Task 1 
void add_column(int** arr, int rows, int& cols, int colIndex) {

    int** newArr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        newArr[i] = new int[cols + 1];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols + 1; ++j) {
            if (j < colIndex) {
                newArr[i][j] = arr[i][j];
            }
            else if (j == colIndex) {
                newArr[i][j] = rand() % 100;
            }
            else {
                newArr[i][j] = arr[i][j - 1];
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;
    ++cols;
}


//Task 2 func
void delete_column(int** arr, int rows, int cols, int colToDelete) {
    for (int i = 0; i < rows; i++) {
        for (int j = colToDelete; j < cols - 1; j++) {
            arr[i][j] = arr[i][j + 1];
        }
    }
}

//Task 3 func
void cyclical_rows_shift(int** matrix, int M, int N) {
    int* tempRow = matrix[M - 1];
    for (int i = M - 1; i > 0; --i) {
        matrix[i] = matrix[i - 1];
    }
    matrix[0] = tempRow;
}


void  cyclical_columns_shift(int** matrix, int M, int N) {
    for (int i = 0; i < M; ++i) {
        int tempVal = matrix[i][N - 1];
        for (int j = N - 1; j > 0; --j) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][0] = tempVal;
    }
}


int main()
{
    //Task 2
    srand(time(0));
    int rows = 5;
    int cols = 5;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int colToDelete = 2;
    delete_column(arr, rows, cols, colToDelete);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;


    //Task 3
    srand(time(0));
    int M = 5;
    int N = 5;

    int** matrix = new int* [M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 100;
            cout << matrix[i][j] << " ";
        }
            cout << "\n";
    }

    cyclical_rows_shift(matrix, M, N);
    cyclical_columns_shift(matrix, M, N);

    cout << "\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

