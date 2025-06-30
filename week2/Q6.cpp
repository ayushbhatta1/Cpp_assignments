#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    void saveToFile() {
        ofstream out("items.txt");
        if (out.is_open()) {
            out << name << "," << quantity << endl;
            out.close();
            cout << "Item saved to file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
    

    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            cout << "\nData from file:" << endl;
            while (getline(in, line)) {
                cout << line << endl;
            }
            in.close();
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {

    Item item;

    item.name = "Laptop";
    item.quantity = 10;

    cout << "Item: " << item.name << ", Quantity: " << item.quantity << endl;

    item.saveToFile();

    item.loadFromFile();
    
    return 0;
}