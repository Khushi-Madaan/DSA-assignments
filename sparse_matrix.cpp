/*Write a program to implement the following operations on a Sparse Matrix, assuming the matrix
 is represented using a triplet. 
 (a) Transpose of a matrix. 
 (b) Addition of two matrices. 
 (c) Multiplication of two matrices. */
#include <iostream>
using namespace std;
const int MAX = 100;
// Structure to keep track of a non-zero element
struct Element 
{
    int row;
    int col;
    int value;
};
// Display function
void display(Element matrix[], int count) 
{
    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i < count; i++) 
    {
        cout << matrix[i].row << "\t" << matrix[i].col << "\t" << matrix[i].value << "\n";
    }
}
// (a) Simple Transpose 
void simpleTranspose(Element source[], int srcCount, int totalCols, Element result[]) 
{
    int k = 0; 
    for (int c = 0; c < totalCols; c++) {
        for (int i = 0; i < srcCount; i++) 
        {
            if (source[i].col == c) 
            {
                result[k].row = source[i].col;
                result[k].col = source[i].row;
                result[k].value = source[i].value;
                k++;
            }
        }
    }
}
// (b) Addition of two matrices
int addMatrices(Element m1[], int count1, Element m2[], int count2, Element result[]) 
{
    int i = 0, j = 0, k = 0;
    while (i < count1 && j < count2) 
    {
        if (m1[i].row < m2[j].row) {
            result[k++] = m1[i++];
        } 
        else if (m1[i].row > m2[j].row) 
        {
            result[k++] = m2[j++];
        } 
        else 
        {
            if (m1[i].col < m2[j].col) 
            {
                result[k++] = m1[i++];
            } 
            else if (m1[i].col > m2[j].col) 
            {
                result[k++] = m2[j++];
            } 
            else 
            {
                int sum = m1[i].value + m2[j].value;
                if (sum != 0) 
                { 
                    result[k].row = m1[i].row;
                    result[k].col = m1[i].col;
                    result[k].value = sum;
                    k++;
                }
                i++;
                j++;
            }
        }
    }
    while (i < count1) 
    {
        result[k++] = m1[i++];
    }
    while (j < count2)
    {
        result[k++] = m2[j++];
    }
    return k; 
}
// (c) Multiplication of two matrices
int multiplyMatrices(Element m1[], int count1, int r1, int c1, 
                     Element m2[], int count2, int r2, int c2, 
                     Element result[]) 
{
    Element m2T[MAX];
    simpleTranspose(m2, count2, c2, m2T);
    int k = 0; 
    int i = 0;
    while (i < count1) 
    {
        int rA = m1[i].row; 
        int j = 0;
        while (j < count2) {
            int rB = m2T[j].row; 
            int scanA = i;
            int scanB = j;
            int sum = 0;
            while (scanA < count1 && m1[scanA].row == rA && 
                   scanB < count2 && m2T[scanB].row == rB) {
                
                if (m1[scanA].col < m2T[scanB].col) {
                    scanA++;
                } else if (m1[scanA].col > m2T[scanB].col) {
                    scanB++;
                } else {
                    sum += m1[scanA++].value * m2T[scanB++].value;
                }
            }
            if (sum != 0) 
            {
                result[k].row = rA;
                result[k].col = rB;
                result[k].value = sum;
                k++;
            }
            while (j < count2 && m2T[j].row == rB) 
            {
                j++;
            }
        }
        while (i < count1 && m1[i].row == rA) {
            i++;
        }
    }
    return k; 
}
int main() 
{
    Element A[MAX], B[MAX], TransposedA[MAX], SumResult[MAX], ProductResult[MAX];
    int r1, c1, count1;
    int r2, c2, count2;
    cout << "Enter total rows, columns, and non-zero counts for Matrix A: ";
    cin >> r1 >> c1 >> count1; 
    cout << "Enter the triplet elements (Row, Col, Value):\n";
    for (int i = 0; i < count1; i++) 
    {
        cin >> A[i].row >> A[i].col >> A[i].value;
    }
    simpleTranspose(A, count1, c1, TransposedA);
    cout << "\n=== Transposed Matrix A ===";
    display(TransposedA, count1);
    cout << "\nEnter total rows, columns, and non-zero counts for Matrix B: ";
    cin >> r2 >> c2 >> count2;
    cout << "Enter the triplet elements (Row, Col, Value):\n";
    for (int i = 0; i < count2; i++) 
    {
        cin >> B[i].row >> B[i].col >> B[i].value;
    }
    if (r1 == r2 && c1 == c2) {
        int sumCount = addMatrices(A, count1, B, count2, SumResult);
        cout << "\n=== Addition Result (A + B) ===";
        display(SumResult, sumCount);
    } 
    else 
    {
        cout << "\nAddition not possible (Dimensions mismatch).\n";
    }
    if (c1 == r2) 
    {
        int prodCount = multiplyMatrices(A, count1, r1, c1, B, count2, r2, c2, ProductResult);
        cout << "\n=== Multiplication Result (A * B) ===";
        display(ProductResult, prodCount);
    } 
    else
    {
        cout << "\nMultiplication not possible (Dimensions mismatch).\n";
    }
    return 0;
}