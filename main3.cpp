#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
void func(int** arr, int n)
{
    int a, b, c, d;
    c = (n / 2) + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 1;            // fill the matrix with the symbol "1"
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            a = n - j - 1;
            arr[i][j] = 0;            // fill in the "0" with the edge
            arr[i][a] = 0;            // of the diagonals at the top
        }
    }

    for (int i = c; i < n; i++)
    {
        a = n - i;
        for (int j = 0; j < a; j++)
        {
            b = n - j - 1;
            arr[i][j] = 0;            // fill in the "0" with the edge
            arr[i][b] = 0;            // of the diagonals at the bottom
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0) { arr[i][j] = 1; }
            cout << setw(4) << arr[i][j];            // output matrix
        }
        cout << endl;
    }
}
int main()
{
    int** arr, n;
    cout << "Enter order of matrix:";
    cin >> n;
    cout << "-----------------------------------------------------" << endl;
    arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];    // create a dynamic two-dimensional array
    }
    func(arr, n);
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];        //  clear memory
    }
    delete[] arr;
    return 0;
}
