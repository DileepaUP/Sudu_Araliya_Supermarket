//Implement a code with specific functions to add data, view added data, update added data and delete the inserted data.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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

int main() {
    vector<Item> items;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add Data\n";
        cout << "2. View Data\n";
        cout << "3. Update Data\n";
        cout << "4. Delete Data\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addData(items);
            break;
        case 2:
            viewData(items);
            break;
        case 3:
            updateData(items);
            break;
        case 4:
            deleteData(items);
            break;
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    } while (choice != 5);

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
