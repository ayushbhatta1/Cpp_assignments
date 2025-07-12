#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Numeric_limits

using namespace std;

class Student {
public:
    int id;
    string name;
    double grade;
    
    Student() {
        id = 0;
        name = "";
        grade = 0.0;
    }

    Student(int i, string n, double g) {
        id = i;
        name = n;
        grade = g;
    }
    
    void show() {
        cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << endl;
    }
};

// Manager class to handle student operations.
class Manager {
public:
    Student* students;  
    int count;
    
    Manager() {
        // Create dynamic array for 10 students.
        students = new Student[10];
        count = 0;
    }
    
    ~Manager() {
        // Delete dynamic array.
        delete[] students;
        cout << "Manager destroyed - memory cleaned up!" << endl;
    }
    
    void addStudent(int id, string name, double grade) {
        if (count < 10) {
            students[count] = Student(id, name, grade);
            count++;
            cout << "Student added!" << endl;
        } else {
            cout << "Cannot add more students - array is full!" << endl;
        }
    }
    
    void showAll() {
        cout << "\n--- All Students ---" << endl;
        for (int i = 0; i < count; i++) {
            students[i].show();
        }
        cout << "Total: " << count << " students\n" << endl;
    }
    
    // Binary search for student by ID.
    int binarySearch(int searchID) {
        // Sort by ID (Bubble Sort for simplicity).
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (students[j].id > students[j + 1].id) {
                    // Swap students.
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        
        int left = 0;
        int right = count - 1;
        
        cout << "Searching for ID: " << searchID << endl;
        
        while (left <= right) {
            int middle = (left + right) / 2;
            
            cout << "Checking position " << middle << " (ID: " << students[middle].id << ")" << endl;
            
            if (students[middle].id == searchID) {
                cout << "Found student!" << endl;
                return middle;  // Return 
            }
            else if (students[middle].id < searchID) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        
        cout << "Student not found!" << endl;
        return -1;  
    }
    
    // Save student data 
    void saveToFile() {
        ofstream file("students.txt");
        
        if (file.is_open()) {
            file << count << endl;
            
            for (int i = 0; i < count; i++) {
                file << students[i].id << " " << students[i].name << " " << students[i].grade << endl;
            }
            
            file.close();
            cout << "Data saved to students.txt!" << endl;
        } else {
            cout << "Could not open file for writing!" << endl;
        }
    }
    
    // Load student data from file.
    void loadFromFile() {
        ifstream file("students.txt");
        
        if (file.is_open()) {
            file >> count;
            
            for (int i = 0; i < count; i++) {
                file >> students[i].id >> students[i].name >> students[i].grade;
            }
            
            file.close();
            cout << "Data loaded from students.txt!" << endl;
        } else {
            cout << "Could not open file for reading!" << endl;
        }
    }
};

// show data types and their sizes.
void showDataTypes() {
    cout << "\n--- Data Types and Sizes ---" << endl;
    cout << "int size: " << sizeof(int) << " bytes" << endl;
    cout << "double size: " << sizeof(double) << " bytes" << endl;
    cout << "string size: " << sizeof(string) << " bytes" << endl;
    cout << "Student size: " << sizeof(Student) << " bytes" << endl;
}

// Function to show how pointers work.
void showPointers() {
    cout << "\n--- Pointer Example ---\n" << endl;
    int number = 42;
    int* ptr = &number;  // Pointer to number.
    
    cout << "Number: " << number << endl;
    cout << "Address of number: " << &number << endl;
    cout << "Pointer value (the address it holds): " << ptr << endl;
    cout << "Value pointed to (using *): " << *ptr << endl;
    
    *ptr = 100;  // Change value via pointer.
    cout << "After changing through pointer, number is now: " << number << endl;
}

// demonstrate arrays.
void showArrays() {
    cout << "\n--- Array Example ---" << endl;
    int grades[5] = {85, 90, 78, 92, 88};
    
    cout << "Array elements using bracket notation: ";
    for (int i = 0; i < 5; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
    
    // access the array.
    int* ptr = grades;
    cout << "Array elements using a pointer: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

// string operations.
void showStrings() {
    cout << "\n--- String Example ---" << endl;
    string name1 = "Ayush";
    string name2 = "Bhatt";
    string fullName = name1 + " " + name2;
    
    cout << "First name: " << name1 << endl;
    cout << "Last name: " << name2 << endl;
    cout << "Full name: " << fullName << endl;
    cout << "Length of full name: " << fullName.length() << endl;
}

// Main menu display.
void showMenu() {
    cout << "\n=== Student System ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Show All Students" << endl;
    cout << "3. Search Student (Binary Search)" << endl;
    cout << "4. Save to File" << endl;
    cout << "5. Load from File" << endl;
    cout << "6. Show Data Types" << endl;
    cout << "7. Show Pointers" << endl;
    cout << "8. Show Arrays" << endl;
    cout << "9. Show Strings" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose: ";
}

// Main function where program execution begins.
int main() {
    Manager manager;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        if (choice == 1) {
            int id;
            string name;
            double grade;
            
            cout << "Enter ID: ";
            cin >> id;
            
            cout << "Enter Name: ";
            // Clear input buffer after reading ID.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, name);
            
            cout << "Enter Grade: ";
            cin >> grade;
            
            manager.addStudent(id, name, grade);
        }
        else if (choice == 2) {
            manager.showAll();
        }
        else if (choice == 3) {
            int searchID;
            cout << "Enter ID to search: ";
            cin >> searchID;
            
            int found = manager.binarySearch(searchID);
            if (found != -1) {
                cout << "Student found: ";
                manager.students[found].show();
            }
        }
        else if (choice == 4) {
            manager.saveToFile();
        }
        else if (choice == 5) {
            manager.loadFromFile();
        }
        else if (choice == 6) {
            showDataTypes();
        }
        else if (choice == 7) {
            showPointers();
        }
        else if (choice == 8) {
            showArrays();
        }
        else if (choice == 9) {
            showStrings();
        }
        else if (choice == 0) {
            cout << "Goodbye! Till next time" << endl;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
