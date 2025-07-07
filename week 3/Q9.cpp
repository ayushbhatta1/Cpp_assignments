#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;
};

void searchItem(Item inventory[], int size, string searchName) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].name == searchName) {
            cout << "Found: " << inventory[i].name << " - Quantity: " << inventory[i].quantity << endl;
            return;
        }
    }
    cout << "Item not found in inventory." << endl;
}

int main() {
    const int SIZE = 5;
    Item inventory[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter name for item " << (i + 1) << ": ";
        cin >> inventory[i].name;
        cout << "Enter quantity for " << inventory[i].name << ": ";
        cin >> inventory[i].quantity;
    }
    
    cout << "\nInventory List:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Item: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << endl;
    }
    
    string searchName;
    cout << "\nEnter item name to search: ";
    cin >> searchName;
    searchItem(inventory, SIZE, searchName);
    
    return 0;
}