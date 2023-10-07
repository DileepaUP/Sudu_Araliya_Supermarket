#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Item {
    int itemNo;
    string itemName;
    double price;
};

// Function declarations
void addItem(vector<Item>& items);
void editItem(vector<Item>& items);
void viewItems(const vector<Item>& items);
void deleteItem(vector<Item>& items);
void generateSalesReport(const vector<Item>& items);
void selectItems(const vector<Item>& items);
void calculateBill(const vector<Item>& items, const vector<int>& quantities);
void printBill(const vector<Item>& items, const vector<int>& quantities, double total);

int main() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    bool isAdmin = (username == "admin");

    vector<Item> items;
    vector<int> quantities;

    int choice;
    do {
        cout << "Menu:\n";
        if (isAdmin) {
            cout << "1. Manage Items\n";
            cout << "2. Manage Sales Details\n";
        }
        cout << "3. Select Items\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (isAdmin) {
                int manageItemsChoice;
                do {
                    cout << "Manage Items:\n";
                    cout << "1. Add Item\n";
                    cout << "2. Edit Item\n";
                    cout << "3. View Items\n";
                    cout << "4. Delete Item\n";
                    cout << "5. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> manageItemsChoice;

                    switch (manageItemsChoice) {
                    case 1:
                        addItem(items);
                        break;
                    case 2:
                        editItem(items);
                        break;
                    case 3:
                        viewItems(items);
                        break;
                    case 4:
                        deleteItem(items);
                        break;
                    case 5:
                        cout << "Returning to the main menu.\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }

                    cout << endl;
                } while (manageItemsChoice != 5);
            }
            else {
                cout << "You don't have permission to manage items.\n";
            }
            break;
        case 2:
            if (isAdmin) {
                int manageSalesChoice;
                do {
                    cout << "Manage Sales Details:\n";
                    cout << "1. Generate Sales Report by Day\n";
                    cout << "2. Generate Sales Report by Month\n";
                    cout << "3. Generate Sales Report by Year\n";
                    cout << "4. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> manageSalesChoice;

                    switch (manageSalesChoice) {
                    case 1:
                        generateSalesReport(items);
                        break;
                    case 2:
                        generateSalesReport(items);
                        break;
                    case 3:
                        generateSalesReport(items);
                        break;
                    case 4:
                        cout << "Returning to the main menu.\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }

                    cout << endl;
                } while (manageSalesChoice != 4);
            }
            else {
                cout << "You don't have permission to manage sales details.\n";
            }
            break;
        case 3:
            selectItems(items);
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}

void addItem(vector<Item>& items) {
    Item newItem;

    cout << "Enter item number: ";
    cin >> newItem.itemNo;

    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, newItem.itemName);

    cout << "Enter item price: ";
    cin >> newItem.price;

    items.push_back(newItem);

    cout << "Item added successfully.\n";
}

void editItem(vector<Item>& items) {
    int itemNo;
    cout << "Enter the item number of the item to edit: ";
    cin >> itemNo;

    for (Item& item : items) {
        if (item.itemNo == itemNo) {
            cout << "Enter new item name: ";
            cin >> ws;
            getline(cin, item.itemName);

            cout << "Enter new item price: ";
            cin >> item.price;

            cout << "Item updated successfully.\n";
            return;
        }
    }

    cout << "Item not found.\n";
}

void viewItems(const vector<Item>& items) {
    if (items.empty()) {
        cout << "No items available to view.\n";
        return;
    }

    cout << setw(10) << left << "Item No";
    cout << setw(20) << left << "Item Name";
    cout << setw(10) << right << "Price" << endl;

    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (const Item& item : items) {
        cout << setw(10) << left << item.itemNo;
        cout << setw(20) << left << item.itemName;
        cout << setw(10) << right << fixed << setprecision(2) << item.price << endl;
    }
}

void deleteItem(vector<Item>& items) {
    int itemNo;
    cout << "Enter the item number of the item to delete: ";
    cin >> itemNo;

    auto it = items.begin();
    while (it != items.end()) {
        if (it->itemNo == itemNo) {
            it = items.erase(it);
            cout << "Item deleted successfully.\n";
            return;
        }
        else {
            ++it;
        }
    }

    cout << "Item not found.\n";
}

void generateSalesReport(const vector<Item>& items) {
    // Add logic to generate sales report
    cout << "Generating sales report...\n";
}

void selectItems(const vector<Item>& items) {
    int itemNo, quantity;
    vector<int> selectedItems;
    vector<int> quantities;

    cout << "Enter item number (-1 to finish): ";
    cin >> itemNo;

    while (itemNo != -1) {
        selectedItems.push_back(itemNo);

        cout << "Enter quantity: ";
        cin >> quantity;
        quantities.push_back(quantity);

        cout << "Enter item number (-1 to finish): ";
        cin >> itemNo;
    }

    calculateBill(items, quantities);
}

void calculateBill(const vector<Item>& items, const vector<int>& quantities) {
    if (items.empty()) {
        cout << "No items available to calculate the bill.\n";
        return;
    }

    double total = 0.0;
    for (size_t i = 0; i < items.size(); i++) {
        int itemNo = items[i].itemNo;
        int quantity = quantities[i];

        for (const Item& item : items) {
            if (item.itemNo == itemNo) {
                double itemTotal = item.price * quantity;
                total += itemTotal;
                break;
            }
        }
    }

    printBill(items, quantities, total);
}

void printBill(const vector<Item>& items, const vector<int>& quantities, double total) {
    cout << "\n*** Bill ***\n";

    cout << setw(10) << left << "Item No";
    cout << setw(20) << left << "Item Name";
    cout << setw(10) << right << "Price";
    cout << setw(10) << right << "Quantity";
    cout << setw(10) << right << "Total" << endl;

    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    for (size_t i = 0; i < items.size(); i++) {
        int itemNo = items[i].itemNo;
        int quantity = quantities[i];

        for (const Item& item : items) {
            if (item.itemNo == itemNo) {
                cout << setw(10) << left << itemNo;
                cout << setw(20) << left << item.itemName;
                cout << setw(10) << right << fixed << setprecision(2) << item.price;
                cout << setw(10) << right << quantity;
                cout << setw(10) << right << fixed << setprecision(2) << item.price * quantity << endl;
                break;
            }
        }
    }

    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    cout << setw(40) << right << "Total: ";
    cout << setw(10) << right << fixed << setprecision(2) << total << endl;
}
