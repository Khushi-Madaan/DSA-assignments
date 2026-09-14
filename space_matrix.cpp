/*Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑐𝑜𝑙𝑢𝑚𝑛𝑠. 
Assuming an array is used to store elements of the following matrices, implement an efficient
way that reduces the space requirement. 
(a) Diagonal Matrix. 
(b) Tri-diagonal Matrix. 
(c) Lower triangular Matrix. 
(d) Upper triangular Matrix. 
(e) Symmetric Matrix */
#include <iostream>
using namespace std;
#define size 50
void diagonalMatrix()
{
    int n;
    int a[size];
    cout << "\nEnter size of Diagonal Matrix: ";
    cin >> n;
    cout << "\nEnter diagonal elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\nDiagonal Matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << a[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void triDiagonalMatrix()
{
    int n;
    int a[size];
    cout << "\nEnter size of Tri-diagonal Matrix: ";
    cin >> n;
    cout << "\nEnter elements row-wise:\n";
    for (int i = 0; i < 3 * n - 2; i++)
    {
        cin >> a[i];
    }
    int k = 0;
    cout << "\nTri-diagonal Matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == 1 || i == j || j - i == 1)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void lowerTriangularMatrix()
{
    int n;
    int a[size];
    cout << "\nEnter size of Lower Triangular Matrix: ";
    cin >> n;
    cout << "\nEnter elements row-wise:\n";
    for (int i = 0; i < n * (n + 1) / 2; i++)
    {
        cin >> a[i];
    }
    int k = 0;
    cout << "\nLower Triangular Matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void upperTriangularMatrix()
{
    int n;
    int a[size];
    cout << "\nEnter size of Upper Triangular Matrix: ";
    cin >> n;
    cout << "\nEnter elements row-wise:\n";
    for (int i = 0; i < n * (n + 1) / 2; i++)
    {
        cin >> a[i];
    }
    int k = 0;
    cout << "\nUpper Triangular Matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void symmetricMatrix()
{
    int n;
    int a[size];
    cout << "\nEnter size of Symmetric Matrix: ";
    cin >> n;
    cout << "\nEnter lower triangular elements row-wise:\n";
    for (int i = 0; i < n * (n + 1) / 2; i++)
    {
        cin >> a[i];
    }
    cout << "\nSymmetric Matrix is:\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                int index = j * (j + 1) / 2 + i;
                cout << a[index] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int choice;
    cout << "\n1. Diagonal Matrix";
    cout << "\n2. Tri-diagonal Matrix";
    cout << "\n3. Lower Triangular Matrix";
    cout << "\n4. Upper Triangular Matrix";
    cout << "\n5. Symmetric Matrix";
    cout << "\n\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            diagonalMatrix();
            break;
        case 2:
            triDiagonalMatrix();
            break;
        case 3:
            lowerTriangularMatrix();
            break;
        case 4:
            upperTriangularMatrix();
            break;
        case 5:
            symmetricMatrix();
            break;
        default:
            cout << "\nInvalid choice!";
    }
    return 0;
}
