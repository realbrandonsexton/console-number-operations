#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 50;

void ReadFromFile(int arr[], int& size, string filename);
void WriteToFile(int arr[], int size, string filename);
void InputList(int arr[]);
void ShowMenu();
void Display(int arr[], int size);
int GetTotal(int arr[], int size);
double GetAverage(int arr[], int size);
int GetLargest(int arr[], int size);
int GetSmallest(int arr[], int size);
int GetNumOccurrences(int arr[], int size, int value);
void ScaleUp(int arr[], int size, int scale);
void Reverse(int arr[], int size);
void ZeroBase(int arr[], int size);
void RemoveNumber(int arr[], int& size, int position);
void Sort(int arr[], int size);

int main() {
    int arr[MAX_SIZE], size = 0;
    int choice, value;

    //InputList(arr);
    ReadFromFile(arr, size, "Numbers.dat");

    do {
        ShowMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            Display(arr, size);
            system("pause");
            break;
        case 2:
            cout << "Total: " << GetTotal(arr, size) << endl;
            system("pause");
            break;
        case 3:
            cout << "Average: " << GetAverage(arr, size) << endl;
            system("pause");
            break;
        case 4:
            cout << "Largest: " << GetLargest(arr, size) << endl;
            system("pause");
            break;
        case 5:
            cout << "Smallest: " << GetSmallest(arr, size) << endl;
            system("pause");
            break;
        case 6:
            cout << "Enter the number to find occurrences: ";
            cin >> value;
            cout << "Occurrences: " << GetNumOccurrences(arr, size, value) << endl;
            system("pause");
            break;
        case 7:
            cout << "Enter scale factor: ";
            cin >> value;
            ScaleUp(arr, size, value);
            cout << "Array scaled up." << endl;
            system("pause");
            break;
        case 8:
            Reverse(arr, size);
            cout << "Array reversed." << endl;
            system("pause");
            break;
        case 9:
            ZeroBase(arr, size);
            cout << "Array zero-based." << endl;
            system("pause");
            break;
        case 10:
            cout << "Enter position to remove (1-based index): ";
            cin >> value;
            RemoveNumber(arr, size, value - 1);
            cout << "Number removed." << endl;
            system("pause");
            break;
        case 11:
            Sort(arr, size);
            cout << "Array sorted." << endl;
            system("pause");
            break;
        case 12:
            cout << "Quitting program." << endl;
            system("pause");
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
    for (int i = 0; i < MAX_SIZE; ++i) {
        cin >> arr[i];
    }

}

void ShowMenu() {
    system("cls");
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

void Display(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int GetTotal(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total;

}

double GetAverage(int arr[], int size) {
    int total = GetTotal(arr, size);
    return double (total )/ double (size);

}

int GetLargest(int arr[], int size) {
    int largest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;

}

int GetSmallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;

}

int GetNumOccurrences(int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

void ScaleUp(int arr[], int size, int scale) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= scale;
    }
}

void Reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

void ZeroBase(int arr[], int size) {
    int smallest = GetSmallest(arr, size);
    for (int i = 0; i < size; ++i) {
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

void ReadFromFile(int arr[], int& size, string filename) {
    ifstream fileInput(filename);
    if (!fileInput.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    size = 0;
    while (size < MAX_SIZE && fileInput >> arr[size]) {
        ++size;
    }


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