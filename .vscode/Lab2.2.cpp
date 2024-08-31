#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Allocate memory for the 2D character array
    char** array = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new char[cols];
    }

    // Take character strings as input from the user
    cout << "Enter the strings (one per row):" << endl;
    for (int i = 0; i < rows; ++i) {
        cin >> array[i];
    }

    // Print the character strings
    cout << "The strings are:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << array[i] << endl;
    }

    // De-allocate the memory
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}