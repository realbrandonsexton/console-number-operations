#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 12;

void ReadFromFile(int arr[], string filename);
void WriteToFile(int arr[], int size, string filename);
void InputList(int arr[]);
void ShowMenu();
void Display(int arr[]);
int GetTotal(int arr[]);
double GetAverage(int arr[]);
int GetLargest(int arr[]);
int GetSmallest(int arr[]);
int GetNumOccurrences(int arr[], int value);
void ScaleUp(int arr[], int scale);
void Reverse(int arr[]);
void ZeroBase(int arr[]);
void RemoveNumber(int arr[], int& size, int position);
void Sort(int arr[], int size);

int main() {
    int arr[SIZE], size = SIZE;
    int choice, value;

    //InputList(arr);
    ReadFromFile(arr, "Numbers.dat");

    do {
        ShowMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            Display(arr);
            break;
        case 2:
            cout << "Total: " << GetTotal(arr) << endl;
            break;
        case 3:
            cout << "Average: " << GetAverage(arr) << endl;
            break;
        case 4:
            cout << "Largest: " << GetLargest(arr) << endl;
            break;
        case 5:
            cout << "Smallest: " << GetSmallest(arr) << endl;
            break;
        case 6:
            cout << "Enter the number to find occurrences: ";
            cin >> value;
            cout << "Occurrences: " << GetNumOccurrences(arr, value) << endl;
            break;
        case 7:
            cout << "Enter scale factor: ";
            cin >> value;
            ScaleUp(arr, value);
            cout << "Array scaled up." << endl;
            break;
        case 8:
            Reverse(arr);
            cout << "Array reversed." << endl;
            break;
        case 9:
            ZeroBase(arr);
            cout << "Array zero-based." << endl;
            break;
        case 10:
            cout << "Enter position to remove (1-based index): ";
            cin >> value;
            RemoveNumber(arr, size, value - 1);
            cout << "Number removed." << endl;
            break;
        case 11:
            Sort(arr, size);
            cout << "Array sorted." << endl;
            break;
        case 12:
            cout << "Quitting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 12);

    WriteToFile(arr, size, "Numbers.dat");
    return 0;
}

void InputList(int arr[]) {
    cout << "Enter 12 integers:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }
}

void ShowMenu() {
    cout << "\nMenu Options:\n"
        << "1. Display\n"
        << "2. GetTotal\n"
        << "3. GetAverage\n"
        << "4. GetLargest\n"
        << "5. GetSmallest\n"
        << "6. GetNumOccurrences\n"
        << "7. ScaleUp\n"
        << "8. Reverse\n"
        << "9. ZeroBase\n"
        << "10. RemoveNumber\n"
        << "11. Sort\n"
        << "12. Quit\n"
        << "Enter your choice (1-12): ";
}

void Display(int arr[]) {
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int GetTotal(int arr[]) {
    int total = 0;
    for (int i = 0; i < SIZE; ++i) {
        total += arr[i];
    }
    return total;
}

double GetAverage(int arr[]) {
    int total = GetTotal(arr);
    return total / SIZE;
}

int GetLargest(int arr[]) {
    int largest = arr[0];
    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int GetSmallest(int arr[]) {
    int smallest = arr[0];
    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int GetNumOccurrences(int arr[], int value) {
    int count = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

void ScaleUp(int arr[], int scale) {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] *= scale;
    }
}

void Reverse(int arr[]) {
    for (int i = 0; i < SIZE / 2; ++i) {
        swap(arr[i], arr[SIZE - 1 - i]);
    }
}

void ZeroBase(int arr[]) {
    int smallest = GetSmallest(arr);
    for (int i = 0; i < SIZE; ++i) {
        arr[i] -= smallest;
    }
}

void RemoveNumber(int arr[], int& size, int position) {
    for (int i = position; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void Sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void ReadFromFile(int arr[], string filename) {
    ifstream fileInput(filename);
    if (!fileInput.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < SIZE && fileInput >> arr[i]; ++i);

    fileInput.close();
}

void WriteToFile(int arr[], int size, string filename) {
    ofstream fileOutput(filename);
    if (!fileOutput.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        fileOutput << arr[i] << endl;
    }

    fileOutput.close();
}