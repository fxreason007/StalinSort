#include <iostream>

int* stalinSort(int matrix[], int n, int& newSize) {
    int* newMatrix = new int[n];
    newMatrix[0] = matrix[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (matrix[i] >= newMatrix[count - 1]) {
            newMatrix[count] = matrix[i];
            count++;
        }
        else {
            std::cout << "Элемент " << matrix[i] << " признан врагом народа и расстрелян!" << std::endl;
        }
    }
    newSize = count;
    return newMatrix;
}

void printMatrix(int matrix[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << matrix[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "RU_ru");

    int matrixOne[] = { 1, 5, 3, 2, 4, 5 };
    int n = sizeof(matrixOne) / sizeof(matrixOne[0]);
    int newSize = 0;

    std::cout << "До: ";
    printMatrix(matrixOne, n);

    int* newMatrix = stalinSort(matrixOne, n, newSize);

    std::cout << "После: ";
    printMatrix(newMatrix, newSize);

    delete[] newMatrix;
    return 0;
}
