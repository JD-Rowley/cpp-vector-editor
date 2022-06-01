#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void display_menu();
char capitalize(char a);

int main() {
    char selection {};
    int number {};

    vector <int> numbers {};

    do {
        display_menu();
        cin >> selection;

        switch (selection) {
            case 'p':
            case 'P':
                {
                    cout << "\nPrinting numbers...\n" << endl;
                    if (numbers.size() > 0) {
                        cout << "[";
                        for (auto num: numbers) {
                            cout << " " << num << " ";
                        }
                        cout << "]\n" << endl;
                    } else {
                        cout << "[] - the list is empty\n" << endl;
                    }
                }
                break;
            case 'a':
            case 'A':
                {
                    cout << "What number would you like to add? ";

                    cin >> number;

                    cout << "\nAdding " << number << "...\n" << endl;
                    numbers.push_back(number);
                }
                break;
            case 'm':
            case 'M':
                {
                    cout << "\nFinding vector's mean...\n" << endl;

                    if (numbers.size() > 0) {
                        int total {};

                        for (auto num: numbers) {
                            total += num;
                        }

                        cout << "The vector's mean is " << static_cast<double>(total)/numbers.size() << "." << endl;
                    } else {
                        cout << "Unable to calculate mean - list is empty..." << endl;
                    }
                }
                break;
            case 's':
            case 'S':
                {
                    cout << "\nFinding vector's smallest number...\n" << endl;
                    
                    if (numbers.size() > 0) {
                        int small_int = numbers.at(0);

                        for (auto i: numbers) {
                            if (i < small_int) {
                                small_int = i;
                            }
                        }

                        cout << "The vector's smallest element is " << small_int << "." << endl;
                    } else {
                        cout << "Cannot determine smallest integer - list is empty..." << endl;
                    }
                }
                break;
            case 'l':
            case 'L':
                {
                    cout << "\nFinding vector's largest number...\n" << endl;

                    if (numbers.size() > 0) {
                        int large_int = numbers.at(0);

                        for (auto i: numbers) {
                            if (i > large_int) {
                                large_int = i;
                            }
                        }

                        cout << "The vector's largest number is " << large_int << "." << endl;
                    } else {
                        cout << "Cannot determine largest integer - list is empty..." << endl;
                    }
                }
                break;
            case 'c':
            case 'C':
                {
                    cout << "\nClearing list...\n" << endl;

                    numbers.clear();
                }
                break;
            case 'q':
            case 'Q':
                cout << "\nGoodbye..." << endl;
                break;
            default:
                cout << "\nInvalid entry - please try again...\n" << endl;
        }
    } while (selection != 'q' && selection != 'Q');
    
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
