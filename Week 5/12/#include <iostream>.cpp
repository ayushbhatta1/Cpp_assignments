#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
public:
    int employeeId;
    string name;
    int age;
    string jobRole;
    string mentalHealthStatus;
    double productivityScore;

    Employee(int id, string n, int a, string jr, string mhs, double ps)
        : employeeId(id), name(n), age(a), jobRole(jr), mentalHealthStatus(mhs), productivityScore(ps) {}

    // Display employee information with aligned formatting
    void display() const {
        cout << left
             << setw(15) << "Employee ID: " << employeeId << "\n"
             << setw(15) << "Name: " << name << "\n"
             << setw(15) << "Age: " << age << "\n"
             << setw(15) << "Job Role: " << jobRole << "\n"
             << setw(15) << "Mental Health: " << mentalHealthStatus << "\n"
             << setw(15) << "Productivity: " << productivityScore << "\n"
             << "------------------------\n";
    }
};

int main() {
    vector<Employee> employees;

    ifstream file("mental_health_remote_workers.csv");
    if (!file.is_open()) {
        cout << "Error: Could not open 'mental_health_remote_workers.csv'. Please ensure the file is in the same directory as the program.\n";
        return 1;
    }

    string header;
    getline(file, header);

    int count = 0;
    string line;

    // Read up to 10 rows from the CSV
    while (getline(file, line) && count < 10) {
        stringstream ss(line);
        string token;

        int employeeId;
        string name, jobRole, mentalHealthStatus;
        int age;
        double productivityScore;

        try {
            // Parse Employee ID
            getline(ss, token, ',');
            if (token.empty()) throw runtime_error("Empty Employee ID");
            employeeId = stoi(token);

            // Parse Name
            getline(ss, token, ',');
            name = token;

            // Parse Age
            getline(ss, token, ',');
            if (token.empty()) throw runtime_error("Empty Age");
            age = stoi(token);

            // Skip Gender and Country
            getline(ss, token, ',');
            getline(ss, token, ',');

            // Parse Job Role
            getline(ss, token, ',');
            jobRole = token;

            // Skip Experience Years, Work Mode, Hours Worked
            getline(ss, token, ',');
            getline(ss, token, ',');
            getline(ss, token, ',');

            // Parse Productivity Score
            getline(ss, token, ',');
            if (token.empty()) throw runtime_error("Empty Productivity Score");
            productivityScore = stod(token);

            // Parse Mental Health Status
            getline(ss, token, ',');
            mentalHealthStatus = token;

            employees.emplace_back(employeeId, name, age, jobRole, mentalHealthStatus, productivityScore);
            count++;
        } catch (const exception& e) {
            // Skip malformed lines
            cout << "Error parsing line: " << line << "\n";
            continue;
        }
    }

    file.close();

    cout << "\nDisplaying Employee Data (First 10 Entries):\n\n";
    for (const auto& emp : employees) {
        emp.display();
    }

    cout << "Total entries loaded: " << employees.size() << "\n";
    if (employees.size() < 10) {
        cout << "Note: The file contained fewer than 10 valid entries.\n";
    }




    return 0;
}