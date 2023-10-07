//Based on the user credentials functions availability differs.Normal user can only view added, select data, calculate 
//the bill and print it.Admin user can do all the functions belongs to normal user and specifically add data, update 
//added data and delete the inserted data and ability to manage the sales data based on days, months, years wise.


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

struct Item {
    string name;
    double price;
};

// Function declarations
void addData(vector<Item>& items);
void viewData(const vector<Item>& items);
void updateData(vector<Item>& items);
void deleteData(vector<Item>& items);
double calculateBill(const vector<Item>& items);
void printBill(const vector<Item>& items, double total);
void manageSales(const vector<Item>& items);

int main() {
    vector<Item> items;

    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    bool isAdmin = (username == "admin" && password == "admin123");

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. View Added Data\n";
        cout << "2. Select Data\n";
        cout << "3. Calculate Bill\n";
        if (isAdmin) {
            cout << "4. Add Data\n";
            cout << "5. Update Data\n";
            cout << "6. Delete Data\n";
            cout << "7. Manage Sales\n";
        }
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewData(items);
            break;
        case 2:
            // Add logic for selecting data
            break;
        case 3:
            if (!items.empty()) {
                double total = calculateBill(items);
                printBill(items, total);
            }
            else {
                cout << "No data available to calculate the bill.\n";
            }
            break;
        case 4:
            if (isAdmin) {
                addData(items);
            }
            else {
                cout << "You don't have permission to add data.\n";
            }
            break;
        case 5:
            if (isAdmin) {
                updateData(items);
            }
            else {
                cout << "You don't have permission to update data.\n";
            }
            break;
        case 6:
            if (isAdmin) {
                deleteData(items);
            }
            else {
                cout << "You don't have permission to delete data.\n";
            }
            break;
        case 7:
            if (isAdmin) {
                manageSales(items);
            }
            else {
                cout << "You don't have permission to manage sales.\n";
            }
            break;
        case 8:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    } while (choice != 8);

    return 0;
}

void addData(vector<Item>& items) {
    Item newItem;

    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, newItem.name);

    cout << "Enter item price: ";
    cin >> newItem.price;

    items.push_back(newItem);

    cout << "Item added successfully.\n";
}

void viewData(const vector<Item>& items) {
    if (items.empty()) {
        cout << "No data to display.\n";
        return;
    }

    cout << setw(10) << left << "Item Name";
    cout << setw(10) << right << "Price" << endl;

    cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;

    for (const auto& item : items) {
        cout << setw(10) << left << item.name;
        cout << setw(10) << right << fixed << setprecision(2) << item.price << endl;
    }
}

void updateData(vector<Item>& items) {
    if (items.empty()) {
        cout << "No data to update.\n";
        return;
    }

    int index;
    cout << "Enter the index of the item to update (1-" << items.size() << "): ";
    cin >> index;

    if (index < 1 || index > items.size()) {
        cout << "Invalid index.\n";
        return;
    }

    Item& item = items[index - 1];

    cout << "Current item name: " << item.name << endl;
    cout << "Enter new item name: ";
    cin >> ws;
    getline(cin, item.name);

    cout << "Current item price: " << item.price << endl;
    cout << "Enter new item price: ";
    cin >> item.price;

    cout << "Item updated successfully.\n";
}

void deleteData(vector<Item>& items) {
    if (items.empty()) {
        cout << "No data to delete.\n";
        return;
    }

    int index;
    cout << "Enter the index of the item to delete (1-" << items.size() << "): ";
    cin >> index;

    if (index < 1 || index > items.size()) {
        cout << "Invalid index.\n";
        return;
    }

    items.erase(items.begin() + index - 1);

    cout << "Item deleted successfully.\n";
}

double calculateBill(const vector<Item>& items) {
    double total = 0.0;

    for (const auto& item : items) {
        total += item.price;
    }

    return total;
}

void printBill(const vector<Item>& items, double total) {
    if (items.empty()) {
        cout << "No data available to print the bill.\n";
        return;
    }

    cout << "Bill:\n";
    cout << setw(10) << left << "Item Name";
    cout << setw(10) << right << "Price" << endl;

    cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;

    for (const auto& item : items) {
        cout << setw(10) << left << item.name;
        cout << setw(10) << right << fixed << setprecision(2) << item.price << endl;
    }

    cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;
    cout << "Total: " << setw(10) << right << fixed << setprecision(2) << total << endl;
}

void manageSales(const vector<Item>& items) {
    if (items.empty()) {
        cout << "No data available to manage sales.\n";
        return;
    }

    int choice;
    do {
        cout << "Sales Management:\n";
        cout << "1. View sales by day\n";
        cout << "2. View sales by month\n";
        cout << "3. View sales by year\n";
        cout << "4. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Add logic to view sales by day
            break;
        case 2:
            // Add logic to view sales by month
            break;
        case 3:
            // Add logic to view sales by year
            break;
        case 4:
            cout << "Returning to the main menu.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    } while (choice != 4);
}
