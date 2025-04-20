#include <iostream>
using namespace std;

class Matrix{
    public:
    Matrix() {
        m_row = 0;
        m_col = 0;
        data = nullptr;
    }

    Matrix(int row, int col) {
        m_row = row;
        m_col = col;

        data = new int* [row];
        for (int i = 0; i < row; i++) {
            data[i] = new int[col];
        }
    }

    void matrixInput() {
        int userInput = 0;
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_col; j++) {
                cout << "Enter data for row: " << i << " and column : " << j << endl;
                cin >> userInput;
                data[i][j] = userInput;
            }
        }
    }

    void matrixTranspose() {
        int newRow = m_col;
        int newCol = m_row;
        int **newData = new int*[m_col];
        for (int i = 0; i < m_col; i++) {
            newData[i] = new int[m_row];
            for (int j = 0; j < m_row; j++) {
                newData[i][j] = data[j][i];
            }
        }

        //I will handle the memory leak (if I remember)
        for (int i = 0; i < m_row; i++) {
            delete[] data[i];
        }
        delete[] data;
        //I remembered.

        data = newData;
        m_row = newRow;
        m_col = newCol;
    }

    Matrix operator+(Matrix const mtr) {
        if (m_row == mtr.m_col && m_col == mtr.m_col) {
            for (int i = 0; i < m_row; i++) {
                for (int j = 0; j < m_col; j++) {
                    data[i][j] += mtr.data[i][j];
                }
            }
        }
        else {
            cout << "Undefined addition behavior - Matrix dimensions do not match." << endl;
        }
        return *this;
    }

    Matrix operator*(Matrix const& mtr) {
        if (m_col != mtr.m_row) {
            cout << "Undefined multiplication behavior" << endl;
            return *this; 
        }

        Matrix result(m_row, mtr.m_col);

        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < mtr.m_col; j++) {
                result.data[i][j] = 0; 
                for (int k = 0; k < m_col; k++) {
                    result.data[i][j] += data[i][k] * mtr.data[k][j]; 
                }
            }
        }

        return result;
    }

    Matrix operator*(int const num) {
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_col; j++) {
                data[i][j] *= num;
            }
        }
        return *this;
    }

    Matrix operator+(int const num) {
        return *this;
    }

    friend Matrix operator*(int num, Matrix const& mtr) {
        Matrix result(mtr.m_row, mtr.m_col);
        for (int i = 0; i < mtr.m_row; i++) {
            for (int j = 0; j < mtr.m_col; j++) {
                result.data[i][j] = num * mtr.data[i][j];
            }
        }
        return result; // Return the resulting matrix
    }

    Matrix operator=(Matrix const mtr) {
        m_row = mtr.m_row;
        m_col = mtr.m_col;
        data = mtr.data;

        return *this;
    }

    Matrix operator=(int const num) {
        return *this;
    }

    friend ostream& operator<<(ostream& os, Matrix const mtr) {
        cout << "Matrix Output: " << endl;
        //cout << "mrow " << mtr.m_row << endl;
        //cout << "mcol " << mtr.m_col << endl;
        for (int i = 0; i < mtr.m_row; i++) {
            //cout << "i " << i << endl;
            for (int j = 0; j < mtr.m_col; j++) {
               // cout << "j " << j << endl;
                cout << mtr.data[i][j] << " ";
                if (j == mtr.m_col - 1) {
                    cout << endl;
                }
            }
        }
        return os;
    }


    private:
    int m_row;
    int m_col;
    int **data;
};
int main() {
    Matrix matrixA(2, 2);
    Matrix matrixB(2, 3);
    Matrix matrixC(2, 3);
    Matrix matrixD;

    matrixA.matrixInput();
    matrixB.matrixInput();
    matrixC.matrixInput();
    matrixC.matrixTranspose();

    matrixB = matrixB * 3;
    matrixB = matrixB * matrixC;
    matrixD = matrixA + matrixB;
    cout << matrixD << endl;
    
};
