#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>
using namespace std;

int** createArray(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 21 - 10;
        }
    }
    return arr;
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


//n1
void addColumn(int**& arr, int& rows, int& cols, int pos) {
    if (pos < 0 || pos > cols) {
        cout << "некоректна позиція " << endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols + 1]; 
        for (int j = 0; j < pos; j++) {
            newRow[j] = arr[i][j];
        }
        newRow[pos] = rand() % 21 - 10;
        for (int j = pos; j < cols; j++) {
            newRow[j + 1] = arr[i][j];
        }
        delete[] arr[i]; 
        arr[i] = newRow; 
    }
    cols++; 
}

//n2
void removeColumn(int**& arr, int& rows, int& cols, int pos) {
    if (pos < 0 || pos >= cols) return;
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols - 1];
        for (int j = 0,k=0; j < cols; j++) {
            if (j != pos) newRow[k++] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = newRow;
    }
    cols--;
}



int main()
{
    system("chcp 1251>null");
    srand(time(0));
    int rowsA, colsA, rowsB, colsB, rowsC, colsC,num;
    cout << "кількість рядків і стовпців для A: ";
    cin >> rowsA >> colsA;
    cout << "кількість рядків і стовпців для B: ";
    cin >> rowsB >> colsB;
    cout << "кількість рядків і стовпців для C: ";
    cin >> rowsC >> colsC;
    int** A = createArray(rowsA, colsA);
    int** B = createArray(rowsB, colsB);
    int** C = createArray(rowsC, colsC);
    cout << "зазначена позиція додавання/видалення стовпця: ";
    cin >> num;
    //n1
    addColumn(A, rowsA, colsA, num);
    cout << "A після додавання стовпця:" << endl;
    printArray(A, rowsA, colsA);
    //n2
    removeColumn(B, rowsB, colsB, num);
    cout << "B після видалення стовпця:" << endl;
    printArray(B, rowsB, colsB);

}

