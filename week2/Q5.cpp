#include <iostream>
#include <string>

using namespace std;

struct Item {
    string name;
    int id;
};

int binarySearch(Item* items, int size, int id) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (items[mid].id == id)
            return mid;
        else if (items[mid].id < id)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int size = 5;
    Item* items = new Item[size]{
        {"Apple", 101},
        {"Banana", 203},
        {"Cherry", 304},
        {"Date", 405},
        {"Elderberry", 506}
    };

    int searchId;
    cout << "Enter item ID to search: ";
    cin >> searchId;

    int index = binarySearch(items, size, searchId);

    if (index != -1)
        cout << "Item found: " << items[index].name << " (ID: " << items[index].id << ")" << endl;
    else
        cout << "Item with ID " << searchId << " not found." << endl;

    delete[] items;
    return 0;
}
