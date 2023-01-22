#include <iostream>
#include "Matrix.h"

using namespace std;

// Parametric constructor
Matrix::Matrix(const int row, const int col) : rows(row), cols(col)
{
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
}

// Function to take input from the user and store in the matrix
void Matrix::takeInput()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// Function to show addition result if addition is possible
void Matrix::showAdditionResult(const Matrix &m2)
{
    if (rows == m2.rows && cols == m2.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] + m2.matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Addition not possible" << endl;
    }
}

// Function to show multiplication result if multiplication is possible
void Matrix::showMultiplicationResult(const Matrix &m2)
{
    int sum{};
    if (cols == m2.rows)
    {
        // create a new matrix to store the result
        Matrix result(m2.cols, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m2.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    sum += matrix[i][k] * m2.matrix[k][j];
                }
                result.matrix[i][j] = sum;
                sum = 0;
            }
        }
    }
    else
    {
        cout << "Multiplication not possible" << endl;
    }
}

// Copy Constructor
Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols)
{
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

// assignment operator overloaded
Matrix &Matrix::operator=(const Matrix &m)
{
    if (this != &m)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        rows{m.rows};
        cols = m.cols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    return *this;
}

// destructor
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
