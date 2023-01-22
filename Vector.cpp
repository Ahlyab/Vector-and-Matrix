// Vector.cpp: implementation of the Vector class.

#include <iostream>
#include "Vector.h"

using namespace std;

// Default constructor
Vector::Vector() : size(5), elements(0), numbers(new int[size]) {}

// Parametric constructor
Vector::Vector(const int size)
{
    this->size = size;
    elements = 0;
    numbers = new int[size];
}

// Copy constructor
Vector::Vector(const Vector &vect)
{
    size = vect.size;
    elements = vect.elements;
    numbers = new int[size];
    for (int i = 0; i < elements; i++)
    {
        numbers[i] = vect.numbers[i];
    }
}

// Assignment operator overloaded
Vector &Vector::operator=(const Vector &vect)
{
    if (this != &vect)
    {
        delete[] numbers;
        size = vect.size;
        elements = vect.elements;
        numbers = new int[size];
        for (int i = 0; i < elements; i++)
        {
            numbers[i] = vect.numbers[i];
        }
    }
    return *this;
}

// Function to add value to end of vector
void Vector::insert(const int num)
{
    if (elements == size)
    {
        int *temp = new int[size * 2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = numbers[i];
        }
        delete[] numbers;
        numbers = temp;
        size *= 2;
    }
    numbers[elements++] = num;
}

// Function to remove value from the vector
bool Vector::remove(const int num)
{
    if (!search(num))
        return false;
    for (int i = 0; i < elements; i++)
    {
        if (numbers[i] == num)
        {
            for (int j = i; j < elements - 1; j++)
            {
                numbers[j] = numbers[j + 1];
            }
            elements--;
            return true;
        }
    }
    return false;
}

// Function to search for value in the vector
bool Vector::search(const int num) const
{
    for (int i = 0; i < elements; i++)
    {
        if (numbers[i] == num)
        {
            return true;
        }
    }
    return false;
}

// Function to print all values in the vector
void Vector::printAllValues() const
{
    for (int i = 0; i < elements; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

// Destructor
Vector::~Vector()
{
    delete[] numbers;
}