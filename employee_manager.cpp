
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct Employee {
    string name, id, address;
    int salary, contact;
};

vector<Employee> employees;
const string FILE_NAME = "employees.json";

void loadFromFile() {
    ifstream infile(FILE_NAME);
    if (!infile) return;
    json j;
    infile >> j;
    for (auto& item : j) {
        employees.push_back({
            item["name"],
            item["id"],
            item["address"],
            item["salary"],
            item["contact"]
        });
    }
}

void saveToFile() {
    json j;
    for (const auto& e : employees) {
        j.push_back({
            {"name", e.name},
            {"id", e.id},
            {"address", e.address},
            {"salary", e.salary},
            {"contact", e.contact}
        });
    }
    ofstream outfile(FILE_NAME);
    outfile << j.dump(4);
}

void addEmployee() {
    Employee e;
    cout << "Enter name: "; cin >> e.name;
    cout << "Enter ID: "; cin >> e.id;
    cout << "Enter address: "; cin >> e.address;
    cout << "Enter contact: "; cin >> e.contact;
    cout << "Enter salary: "; cin >> e.salary;
    employees.push_back(e);
    saveToFile();
    cout << "Employee added successfully.\n";
}

void showEmployees() {
    if (employees.empty()) {
        cout << "No data available.\n";
        return;
    }
    for (size_t i = 0; i < employees.size(); ++i) {
        cout << "\nEmployee " << i+1 << ":\n";
        cout << "Name: " << employees[i].name << endl;
        cout << "ID: " << employees[i].id << endl;
        cout << "Address: " << employees[i].address << endl;
        cout << "Contact: " << employees[i].contact << endl;
        cout << "Salary: " << employees[i].salary << endl;
    }
}

void searchEmployee() {
    string id;
    cout << "Enter employee ID to search: ";
    cin >> id;
    for (const auto& e : employees) {
        if (e.id == id) {
            cout << "\nFound:\n";
            cout << "Name: " << e.name << endl;
            cout << "ID: " << e.id << endl;
            cout << "Address: " << e.address << endl;
            cout << "Contact: " << e.contact << endl;
            cout << "Salary: " << e.salary << endl;
            return;
        }
    }
    cout << "No employee found with ID: " << id << endl;
}

void updateEmployee() {
    string id;
    cout << "Enter employee ID to update: ";
    cin >> id;
    for (auto& e : employees) {
        if (e.id == id) {
            cout << "Enter new name: "; cin >> e.name;
            cout << "Enter new address: "; cin >> e.address;
            cout << "Enter new contact: "; cin >> e.contact;
            cout << "Enter new salary: "; cin >> e.salary;
            saveToFile();
            cout << "Employee updated successfully.\n";
            return;
        }
    }
    cout << "No employee found with ID: " << id << endl;
}

void deleteEmployee() {
    string id;
    cout << "Enter employee ID to delete: ";
    cin >> id;
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->id == id) {
            employees.erase(it);
            saveToFile();
            cout << "Employee deleted successfully.\n";
            return;
        }
    }
    cout << "No employee found with ID: " << id << endl;
}

void deleteAllEmployees() {
    employees.clear();
    saveToFile();
    cout << "All employee records deleted successfully.\n";
}

void menu() {
    char choice;
    do {
        cout << "\n1. Add Employee\n"
             << "2. Show All\n"
             << "3. Search by ID\n"
             << "4. Update Employee\n"
             << "5. Delete Employee\n"
             << "6. Delete All Employees\n"
             << "7. Exit\n"
             << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case '1': addEmployee(); break;
            case '2': showEmployees(); break;
            case '3': searchEmployee(); break;
            case '4': updateEmployee(); break;
            case '5': deleteEmployee(); break;
            case '6': deleteAllEmployees(); break;
            case '7': cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != '7');
}

int main() {
    loadFromFile();
    menu();
    return 0;
}
