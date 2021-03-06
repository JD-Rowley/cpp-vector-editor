#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void display_menu();
char capitalize(char a);
void print_numbers(vector<int> v);
void add_number(vector<int> &v);
void find_mean(vector<int> &v);
void smallest_number(vector<int> &v);
void largest_number(vector<int> &v);
void clear_vector(vector<int> &v);

int main() {
    char selection {};

    vector <int> numbers {};

    do {
        display_menu();

        cin >> selection;

        switch (capitalize(selection)) {
            case 'P':
                {
                    print_numbers(numbers);
                }
                break;
            case 'A':
                {
                    add_number(numbers);
                }
                break;
            case 'M':
                {
                    find_mean(numbers);
                }
                break;
            case 'S':
                {
                    smallest_number(numbers);
                }
                break;
            case 'L':
                {
                    largest_number(numbers);
                }
                break;
            case 'C':
                {
                    clear_vector(numbers);
                }
                break;
            case 'Q':
                cout << "\nGoodbye..." << endl;
                break;
            default:
                cout << "\nInvalid entry - please try again...\n" << endl;
        }
    } while (capitalize(selection) != 'Q');
    
    cout << endl;
    return 0;
}

void display_menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "C - Clear list" << endl;
    cout << "Q - Quit" << endl;

    cout << "\nEnter your choice: ";
}

char capitalize(char a) {
    return toupper(a);
}

void print_numbers(vector<int> v) {
    cout << "\nPrinting numbers...\n" << endl;
    if (v.size() > 0) {
        cout << "[";
        for (auto num: v) {
            cout << " " << num << " ";
        }
        cout << "]\n" << endl;
    } else {
        cout << "[] - the list is empty\n" << endl;
    }
}

void add_number(vector<int> &v) {
    int num_added {};
    cout << "What number would you like to add? ";

    cin >> num_added;

    cout << "\nAdding " << num_added << "...\n" << endl;
    v.push_back(num_added);
}

void find_mean(vector<int> &v) {
    cout << "\nFinding vector's mean...\n" << endl;

    if (v.size() > 0) {
        int total {};

        for (auto num: v) {
            total += num;
        }

        cout << "The vector's mean is " << static_cast<double>(total)/v.size() << "." << endl;
    } else {
        cout << "Unable to calculate mean - list is empty..." << endl;
    }
}

void smallest_number(vector<int> &v) {
    cout << "\nFinding vector's smallest number...\n" << endl;
    
    if (v.size() > 0) {
        int small_int = v.at(0);

        for (auto i: v) {
            if (i < small_int) {
                small_int = i;
            }
        }

        cout << "The vector's smallest element is " << small_int << "." << endl;
    } else {
        cout << "Cannot determine smallest integer - list is empty..." << endl;
    }
}

void largest_number(vector<int> &v) {
    cout << "\nFinding vector's largest number...\n" << endl;

    if (v.size() > 0) {
        int large_int = v.at(0);

        for (auto i: v) {
            if (i > large_int) {
                large_int = i;
            }
        }

        cout << "The vector's largest number is " << large_int << "." << endl;
    } else {
        cout << "Cannot determine largest integer - list is empty..." << endl;
    }
}

void clear_vector(vector<int> &v) {
    cout << "\nClearing list...\n" << endl;

    v.clear();

}