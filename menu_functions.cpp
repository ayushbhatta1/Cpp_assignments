#include <iostream>
using namespace std;

// Function to display the menu
void showMenu() {
    cout << "1. Add Item\n";
    cout << "2. View Items\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int option;

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                cout << "Item added!\n";
                break;
            case 2:
                cout << "Displaying items...\n";
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
                break;
        }

        cout << endl; // Print a blank line for readability

    } while (option != 3);

    return 0;
}
