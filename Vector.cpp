// Vector.cpp: implementation of the Vector class.

#include <iostream>
#include "Vector.h"

using namespace std;

// Default constructor
//Vector::Vector() 
//    : size{ 5 }, elements{0} {
//        numbers = new int[size]  {0};
//}

// Parametric constructor
Vector::Vector(const int size)
    : size{size}, elements{0} {
    numbers = new int[size] {0};
}

// Use of delegating constructor
Vector::Vector()
    :Vector(5) {}

// Copy constructor
Vector::Vector(const Vector& vect)
{
    copyContent(vect);
}

// Assignment operator overloaded
Vector& Vector::operator=(const Vector& vect)
{
    if (this != &vect) {
        
        delete[] this->numbers;
        copyContent(vect);
    }
    return *this;
}

// Function to add value to end of vector
void Vector::insert(const int num)
{
    if (size == elements)
    {
        size *= 2;
        int* temp = new int[size];
        for (int i = 0; i < elements; i++)
        {
            temp[i] = numbers[i];
        }
        delete[] numbers;
        numbers = temp;
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

int Vector::getSize() const
{
    return size;
}

int Vector::getElements() const
{
    return elements;
}

void Vector::copyContent(const Vector& source)
{
    size = source.size;
    elements = source.elements;
    numbers = new int[size];
    for (int i = 0; i < elements; i++)
    {
        numbers[i] = source.numbers[i];
    }
}

int Vector::getValue(int index)
{
    return numbers[index];
}