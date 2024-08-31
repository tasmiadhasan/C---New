#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Allocate memory for the array
    int* array = new int[size];

    // Assign values to the array elements
    for (int i = 0; i < size; ++i) {
        cout << "Enter value for element " << i << ": ";
        cin >> array[i];
    }

    // Print the values of the array elements
    cout << "Array elements are: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    // De-allocate the memory
    delete[] array;

    return 0;
}