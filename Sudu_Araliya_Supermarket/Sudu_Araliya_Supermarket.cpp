#include <cstdlib>
#include <iostream> //header for input/ output
#include <iomanip>
#include <string>
#include <vector> //header for vector
#include <ctime>
#include <algorithm>
#include <map>
using namespace std;

string username;

struct Item {
    int itemNo{};
    string itemName{};
    double price{};
};

struct Sale {
    int invoiceNumber;
    double amount;
    time_t date; // Use time_t to store the date and time
};


vector<Sale> sales; // Vector to store sales information
vector<Item> items;
vector<int> selectedItems;

// Function declarations
void addItem(vector<Item>& items, const vector<int>& quantities, bool isAdmin);
void editItem(vector<Item>& items, const vector<int>& quantities, bool isAdmin);
void viewItems(vector<Item>& items,const vector<int>& quantities, bool isAdmin);
void deleteItem(vector<Item>& items);
//void selectItems(const vector<Item>& items);
void calculateBill(const vector<Item>& items, const vector<int>& quantities);
void printBill(const vector<Item>& items, const vector<int>& selectedItems, const vector<int>& enteredQuantities, double total);
void interface();
void backToManageItems(vector<Item>& items, const vector<int>& quantities, bool isAdmin);
void printDate();
void generateSalesReport(const vector<Sale>& sales, int reportType);



//Generate Sales Report
//void generateSalesReport(const vector<Item>& items, string& reportType) {
//
//    printDate();
//    cout << "*** Sales Report ***" << endl;
//
//    //string reportType;
//    cout << "Enter the report type (Day/Month/Year): ";
//    cin >> reportType;
//    //getline(cin ,reportType);
//
//    if (reportType != "Day" && reportType != "Month" && reportType != "Year") {
//        cout << "Invalid report type. Please choose Day, Month, or Year." << endl;
//        return;
//    }
//
//    double totalAmount = 0.0;
//    time_t currentDate = 0;
//
//    // Sort the sales vector by date
//    sort(sales.begin(), sales.end(), [](const Sale& a, const Sale& b) {
//        return a.date < b.date;
//        });
//
//    for (const Sale& sale : sales) {
//        struct tm timeinfo;
//        localtime_s(&timeinfo, &sale.date);
//
//        int compareValue = 0;
//
//        if (reportType == "Day") {
//            compareValue = timeinfo.tm_yday; // Day of the year
//        }
//        else if (reportType == "Month") {
//            compareValue = timeinfo.tm_mon; // Month (0-11)
//        }
//        else if (reportType == "Year") {
//            compareValue = timeinfo.tm_year; // Years since 1900
//        }
//
//        if (currentDate == 0) {
//            currentDate = compareValue;
//            printDate(/*timeinfo, reportType*/);
//        }
//        else if (compareValue != currentDate) {
//            //printTotal(totalAmount);
//            printDate(/*timeinfo, reportType*/);
//            currentDate = compareValue;
//            totalAmount = 0.0;
//        }
//
//        // Calculate and print individual sale details here
//        cout << "Invoice Number: " << sale.invoiceNumber << " Amount: " << sale.amount << endl;
//        totalAmount += sale.amount;
//    }
//
//    //printTotal(totalAmount);
//}



//Print Date
void printDate() {
    time_t now = time(0);
    struct tm timeinfo;

    // Use localtime_s to get the current local time
    if (localtime_s(&timeinfo, &now) == 0) {
        std::cout << "Date: " << timeinfo.tm_year + 1900 << "-"
            << timeinfo.tm_mon + 1 << "-"
            << timeinfo.tm_mday << endl;
    }
    else {
        std::cout << "Error getting local time." << endl;
    }
}


void generateSalesReport(const vector<Sale>& sales, int reportType) {
    std::cout << "*** Sales Report ***" << endl;

    if (reportType != 1 && reportType != 2 && reportType != 3) {
        std::cout << "Invalid report type. Please choose Day, Month, or Year." << endl;
        return;
    }

    map<string, double> salesByDate; // Using a map to store sales amount by    

    for (const Sale& sale : sales) {
        struct tm timeinfo;
        localtime_s(&timeinfo, &sale.date);

        string dateString;
        if (reportType == 1) {
            dateString = to_string(timeinfo.tm_year + 1900) + "-" +
                to_string(timeinfo.tm_mon + 1) + "-" +
                to_string(timeinfo.tm_mday);
        }
        else if (reportType == 2) {
            dateString = to_string(timeinfo.tm_year + 1900) + "-" +
                to_string(timeinfo.tm_mon + 1);
        }
        else if (reportType == 3) {
            dateString = to_string(timeinfo.tm_year + 1900);
        }

        salesByDate[dateString] += sale.amount;
    }

    double totalAmount = 0.0;

    std::cout << setw(15) << left << "Date";
    std::cout << setw(15) << right << "Total Sales" << endl;
    std::cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;

    for (const auto& entry : salesByDate) {
        std::cout << setw(15) << left << entry.first;
        std::cout << setw(15) << right << fixed << setprecision(2) << entry.second << endl;
        totalAmount += entry.second;
    }

    std::cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
    std::cout << setw(15) << left << "Total";
    std::cout << setw(15) << right << fixed << setprecision(2) << totalAmount << endl;
}



int main() {

    string password;
    interface();

    std::cout << "Enter your username: ";
    cin >> username;
    std::cout << "Enter your password: ";
    cin >> password;

    bool isAdmin = (username == "admin" && password == "admin123");
    system("cls");

    vector<Item> items;
    vector<int> quantities;

    int choice;
    do {
        interface();
        std::cout << "Menu:\n";
        if (isAdmin) {
            std::cout << "1. Manage Items\n";
            std::cout << "2. Manage Sales Details\n";
        }
        std::cout << "3. Select Items\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        cin >> choice;
        //system("cls");

        switch (choice) {
        case 1:
            if (isAdmin) {
                system("cls");
                interface();
                int manageItemsChoice;
                do {
                    std::cout << "Manage Items:\n";
                    std::cout << "1. Add Item\n";
                    std::cout << "2. Edit Item\n";
                    std::cout << "3. View Items\n";
                    std::cout << "4. Delete Item\n";
                    std::cout << "5. Back to main menu\n";
                    std::cout << "Enter your choice: ";
                    cin >> manageItemsChoice;

                    switch (manageItemsChoice) {
                    case 1:
                        system("cls");
                        addItem(items, quantities, isAdmin);
                        break;
                    case 2:
                        system("cls");
                        editItem(items, quantities, isAdmin);
                        break;
                    case 3:
                        system("cls");
                        viewItems(items, quantities, isAdmin);
                        break;
                    case 4:
                        system("cls");
                        deleteItem(items);
                        break;
                    case 5:
                        system("cls");
                        std::cout << "Returning to the main menu.\n";
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                    std::cout << endl;
                    system("cls");
                } while (manageItemsChoice != 5);
            }
            else {
                std::cout << "You don't have permission to manage items.\n";
            }
            break;
        case 2:
            if (isAdmin) {
                //int manageSalesChoice;
                int reportType;  // Declare the reportType variable here
                do {
                    std::cout << "Manage Sales Details:\n";
                    std::cout << "1. Generate Sales Report by Day\n";
                    std::cout << "2. Generate Sales Report by Month\n";
                    std::cout << "3. Generate Sales Report by Year\n";
                    std::cout << "4. Back to main menu\n";
                    std::cout << "Enter your choice: ";
                    cin >> reportType;
                    
                    switch (reportType) {
                    case 1:
                        system("cls");
                        generateSalesReport(sales, reportType);
                        break;
                    case 2:
                        system("cls");
                        generateSalesReport(sales, reportType);
                        break;
                    case 3:
                        system("cls");
                        generateSalesReport(sales, reportType);
                        break;                       
                    case 4:
                        std::cout << "Returning to the main menu.\n";
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                    }

                    std::cout << endl;
                } while (reportType != 4);
            }
            else {
                std::cout << "You don't have permission to manage sales details.\n";
            }
            break;

        /*case 3:
            selectItems(items);
            break;*/
        case 4:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << endl;
    } while (choice != 4);

    return 0;
}



//Interface
void interface() {
    string welcomeMsg = "***Welcome to Sudu Araliya***";
    string line = "================================================";
    int numLines = 2;

    for (int i = 0; i < numLines; i++) {
        std::cout << "\t\t" << line << endl;
    }
    std::cout << "\t\t\t" << welcomeMsg << endl;

    for (int i = 0; i < numLines; i++) {
        std::cout << "\t\t" << line << endl;
    }
}


//backToManageItems
void backToManageItems(vector<Item>& items, const vector<int>& quantities, bool isAdmin) {
    system("cls");
    interface();
    int addNumber;

    std::cout << "1. Add Item" << endl;
    std::cout << "2. Edit Item" << endl;
    std::cout << "3. View Items" << endl;
    std::cout << "4. Delete Item" << endl;
    std::cout << "5. Back to Main menu" << endl;
    std::cout << "Enter your choice" << endl;
    cin >> addNumber;
    switch (addNumber) {
    case 1:
        system("cls");
        addItem(items, quantities, isAdmin);
        break;
    case 2:
        system("cls");
        editItem(items, quantities, isAdmin);
        break;
    case 3:
        viewItems(items, quantities, isAdmin);
        break;
    case 4:
        deleteItem(items);
        break;
    case 5:
        system("cls");
        if (isAdmin) {
            std::cout << "1. Manage Items\n";
            std::cout << "2. Manage Sales Details\n";
        }
        std::cout << "3. Select Items\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        //cin >> choice;
        std::cout << "Returning to the main menu" << endl;
        break;
    default:
        std::cout << "Invalid choice. Please try again" << endl;
        break;
    }
    std::cout << endl;
}



//addItems
void addItem(vector<Item>& items, const vector<int>& quantities, bool isAdmin) {

    interface();

    Item newItem;

    char goBack;
    bool validInput = false;

    do {
        //interface();
        std::cout << "Do you want to go back to manage items? (y/n): ";
        cin >> goBack;

        if (goBack == 'y' || goBack == 'Y') {
            validInput = true;
            backToManageItems(items, quantities, isAdmin); // Go back to the manage items interface
        }
        else if (goBack == 'n' || goBack == 'N') {
            validInput = true;
            std::cout << "Enter item number: ";
            cin >> newItem.itemNo;

            std::cout << "Enter item name: ";
            cin >> ws;
            getline(cin, newItem.itemName);

            std::cout << "Enter item price: ";
           cin >> newItem.price;

            items.push_back(newItem); // Add the fully initialized item to the vector
            //std::cout << items(newItem.back()) << endl;
            std::cout << newItem.itemNo << endl;

            //cout << "Item added successfully.\n";
        }
        else {
            std::cout << "Invalid input. Please enter valid input and try again." << endl;
            system("cls");
            interface();
        }
    } while (!validInput);

}




//Edit Items
//void editItem(vector<Item>& items, bool isAdmin) {
//    interface();
//    int itemNo;
//
//    char goBack;
//    bool validInput = false;
//
//    do {
//        //interface();
//        cout << "Do you want to go back to manage items? (y/n): ";
//        cin >> goBack;
//
//        if (goBack == 'y' || goBack == 'Y') {
//            validInput = true;
//            backToManageItems(items, isAdmin); // Go back to the manage items interface
//        }
//        else if (goBack == 'n' || goBack == 'N') {
//            validInput = true;
//            items.push_back(newItem);
//            //cout << "Item added successfully.\n";
//        }
//        else {
//            cout << "Invalid input. Please enter valid input and try again." << endl;
//            system("cls");
//            interface();
//        }
//    } while (!validInput);
//    cout << "Enter the item number of the item to edit: ";
//    cin >> itemNo;
//
//    for (Item& item : items) {
//        if (item.itemNo == itemNo) {
//            cout << "Enter new item name: ";
//            cin >> ws;
//            getline(cin, item.itemName);
//
//            cout << "Enter new item price: ";
//            cin >> item.price;
//
//            cout << "Item updated successfully.\n";
//            return;
//        }
//    }
//
//    cout << "Item not found.\n";
//}



void editItem(vector<Item>& items, const vector<int>& quantities, bool isAdmin) {
    interface();
    int itemNo; 

    Item itemNew;

    char goBack;
    bool validInput = false;

    do {
        //interface();
        std::cout << "Do you want to go back to manage items? (y/n): ";
        cin >> goBack;

        if (goBack == 'y' || goBack == 'Y') {
            validInput = true;
            //std::cout << boolalpha << validInput << endl;
            backToManageItems(items, quantities, isAdmin); // Go back to the manage items interface
        }
        else if (goBack == 'n' || goBack == 'N') {
            validInput = true;
            std::cout << boolalpha << validInput << endl;

            std::cout << "Enter the item number of the item to edit: ";
            cin >> itemNo;

            bool found = false;
            for (Item& item : items) {
                //std::cout << itemNo << endl;
                //std::cout << item.itemNo << endl;
                if (item.itemNo == itemNo) {
                    std::cout << "Enter new item name: ";
                    cin >> ws;
                    getline(cin, item.itemName);

                    std::cout << "Enter new item price: ";
                    cin >> item.price;                    

                    std::cout << "Item updated successfully.\n";
                    found = true;
                    break;
                }
                //else {
                //    std::cout << "Invalid input. Please enter valid input and try again." << endl;
                //    //break;                 
                //}
            }
            if (!found) {
                std::cout << "Item not found.\n";
            }
            // No need to do anything here as we are not adding a new item
        }
        else {
            std::cout << "Invalid input. Please enter valid input and try again." << endl;
            system("cls");
            interface();
        }
        //bool conditionalResultNew = validInput;
        //std::cout << boolalpha << !validInput << endl;
    } while (!validInput);

    /*cout << "Enter the item number of the item to edit: ";
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
}*/

/*cout << "Enter the item number of the item to edit: ";
cin >> itemNo;


bool found = false;
for (Item& item : items) {
    if (item.itemNo == itemNo) {
        cout << "Enter new item name: ";
        cin >> ws;
        getline(cin, item.itemName);

        cout << "Enter new item price: ";
        cin >> item.price;

        cout << "Item updated successfully.\n";
        found = true;
        break;
    }
}

if (!found) {
    cout << "Item not found.\n";
}*/
}



//View Items
void viewItems(vector<Item>& items, const vector<int>& quantities, bool isAdmin) {
    interface();
    if (items.empty()) {
        std::cout << "No items available to view.\n";
        return;
    }

    std::cout << setw(10) << left << "Item No";
    std::cout << setw(20) << left << "Item Name";
    std::cout << setw(10) << right << "Price" << endl;

    std::cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (const Item& item : items) {
        std::cout << setw(10) << left << item.itemNo;
        std::cout << setw(20) << left << item.itemName;
        std::cout << setw(10) << right << fixed << setprecision(2) << item.price << endl;
    }

    //vector<Item> itemsCopy = items;

    char goBack;
    bool validInput = false;

    do {
        //interface();
        std::cout << "Do you want to go back to manage items? (y/n): ";
        cin >> goBack;

        if (goBack == 'y' || goBack == 'Y') {
            validInput = true;
            backToManageItems(items, quantities, isAdmin); // Go back to the manage items interface
        }
        else if (goBack == 'n' || goBack == 'N') {
            validInput = true;
            //selectItems(items);
            calculateBill(items, quantities);
        }
        else {
            std::cout << "Invalid input. Please enter valid input and try again." << endl;
            system("cls");
            interface();
        }
    } while (!validInput);

    //calculateBill(items, quantities);
}



//Delete Item
void deleteItem(vector<Item>& items) {
    interface();
    int itemNo;
    std::cout << "Enter the item number of the item to delete: ";
    cin >> itemNo;

    auto it = items.begin();
    while (it != items.end()) {
        if (it->itemNo == itemNo) {
            it = items.erase(it);
            std::cout << "Item deleted successfully.\n";
            return;
        }
        else {
            ++it;
        }
    }

    std::cout << "Item not found.\n";
}



//Select Items  
//void selectItems(const vector<Item>& items) {
//    int itemNo, quantity;
//    Item newItem;
//
//    vector<int> selectedItems;
//    vector<int> quantities;
//
//    std::cout << "Select the items\n";
//    std::cout << "Enter item number (-1 to finish): ";
//    cin >> itemNo;
//       
//    while(itemNo != -1){
//    for (size_t i = 0; i < items.size(); i++) {
//            selectedItems.push_back(itemNo);
//
//            std::cout << "Enter quantity: ";
//            cin >> quantity;
//            quantities.push_back(quantity);
//           
//                int itemNoo = items[i].itemNo;
//                std::cout << items[i].itemNo;
//                int quantity = quantities[i];
//                std::cout << quantities[i];
//                
//            std::cout << "Enter item number (-1 to finish): ";
//            cin >> itemNo;
//        }
//    }
//    calculateBill(items, quantities);
//}



// Function to generate a unique invoice number
int generateInvoiceNumber() {
    static int nextInvoiceNumber = 1; // Initialize the invoice number
    return nextInvoiceNumber++; // Return the current invoice number and increment for the next call
}



//Calculate Bill
//void calculateBill(const vector<Item>& items, const vector<int>& quantities) {
//    system("cls");
//
//    if (quantities.empty()) {
//        cout << "No items available to calculate the bill.\n";
//        return;
//    }
//
//    double total = 0.0; // Move the declaration of 'total' outside the else block
//
//    for (size_t i = 0; i < items.size(); i++) {
//        cout << "value of i: " << i << endl;
//        cout << "Size of the i: " << items.size() << "\n";
//        int itemNo = items[i].itemNo;
//        cout << "items[i].itemNo: " << items[i].itemNo << endl;
//        int quantity = quantities[i];
//        cout << "quantities[i]: " << quantities[i] << endl;
//        cout << endl;
//
//        // Find the item with the matching itemNo
//        auto it = find_if(items.begin(), items.end(), [itemNo](const Item& item) {
//            return item.itemNo == itemNo;
//            });
//
//        if (it != items.end()) {
//            double itemTotal = it->price * quantity;
//            total += itemTotal;
//            cout << "total: " << total << endl << endl;
//        }
//    }
//
//    int invoiceNumber = generateInvoiceNumber();
//    Sale sale;
//    sale.invoiceNumber = invoiceNumber;
//    cout << sale.invoiceNumber << endl;
//    sale.amount = total;
//    cout << sale.amount << endl;
//    sale.date = time(nullptr);
//    cout << sale.date << endl;
//    sales.push_back(sale);
//    //cout << sales.push_back(sale) << endl;
//
//    printBill(items, quantities, total);
//
//    //Sale sale(generateInvoiceNumber(), total, time(nullptr));
//    //sales.push_back(sale);
//
//    //Sale sale;
//    //sale.invoiceNumber = generateInvoiceNumber(); // Implement your invoice number generator
//    //sale.amount = total; // Assuming total is the bill amount
//    //sale.date = time(nullptr); // Store the current date and time
//    //sales.push_back(sale);
//
//    //printBill(items, quantities, total);
//}


void calculateBill(const vector<Item>& items, const vector<int>& quantities) {

    system("cls");

    //selectedItems selection;


    /*if (quantities.empty()) {
        cout << "No items available to calculate the bill.\n";
        return;
    }*/

    double total = 0.0;

    std::cout << "Available items:\n";
    for (size_t i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i].itemName << " - $" << items[i].price << endl;
    } 

    std::vector<int> selectedValues;
    std::vector<int> enteredQuantities;

    int selection;
    int quantity;

    do {
        std::cout << "Enter the number of the item you want to include (0 to finish): ";
        cin >> selection;
        if (selection >= 1 && selection <= items.size()) {  
            
            selectedItems.push_back(selection - 1);
            selectedValues.push_back(selection);
            
        }
        else if (selection != 0) {
            std::cout << "Invalid selection. Please try again.\n";
        }
            bool conditionResult = (selection >= 1 && selection <= items.size());
            std::cout << "Conditional result: " << boolalpha << conditionResult << endl;
    } while (selection != 0);

    std::cout << "Entered values: ";
    for (int value : selectedValues) {
        std::cout << value << " ";
    }
    std::cout << endl;
    
    for (int selectedItemIndex : selectedItems) {
        int itemNo = items[selectedItemIndex].itemNo;
        std::cout << "Enter the quantity of " << items[selectedItemIndex].itemName << ": ";
        cin >> quantity;

        enteredQuantities.push_back(quantity);

        auto it = find_if(items.begin(), items.end(), [itemNo](const Item& item) {
            return item.itemNo == itemNo;
            });

        if (it != items.end()) {
            double itemTotal = it->price * quantity;
            total += itemTotal;
        }
    }

    std::cout << "Entered Quantities: ";
    for (int quantity : enteredQuantities) {
        std::cout << quantity << " ";
    }

    std::cout << endl;

/*    std::cout << "Added item with index: " << selection << endl;
    std::cout << "Quantity: " << quantity*/;

    int invoiceNumber = generateInvoiceNumber();
    Sale sale;
    sale.invoiceNumber = invoiceNumber;
    sale.amount = total;
    sale.date = time(nullptr);
    sales.push_back(sale);

    printBill(items, selectedItems, enteredQuantities, total);
}



//Print Bill
void printBill(const vector<Item>& items, const vector<int>& selectedItems, const vector<int>& enteredQuantities, double total) {
    system("cls");

    std::cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    std::cout << "\t\t**Sudu Araliya Billing System**" << endl;
    std::cout << "\t\t\tSUPERMART" << endl;
    std::cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    std::cout << "\tNo 101 Colombo - Hanwella Low Level Rd, Kaduwela" << endl;
    std::cout << endl;
    std::cout << "\t\tTEL #0112 500000 / 0114 000000" << endl;
    std::cout << "CASHIER: " << username << endl;
    std::cout << "UNIT: "; //implement an automated unit num generator
    std::cout << "\t\t\t\t\t\tINVOICE: " << /*invoice_num <<*/ endl; //implement an automated invoice numbers generator
    std::cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;






    /*std::cout << "Entered values: ";
    for (int selectedItemIndex : selectedItems) {
        std::cout << items[selectedItemIndex].itemNo << " ";
    }
    std::cout << endl;

    std::cout << "Entered quantities: ";
    for (int quantity : enteredQuantities) {
        std::cout << quantity << " ";
    }
    std::cout << endl;*/



    for (size_t i = 0; i < enteredQuantities.size(); i++) {
        int itemNo = items[i].itemNo;
        /*std::cout << "For loop 1" << endl;
        std::cout << "Item no: " << items[i].itemNo << endl;
        std::cout << "Item name: " << items[i].itemName << endl; */
        int quantity = enteredQuantities[i];
        /*std::cout << "Quantities: " << enteredQuantities[i] << endl;*/


        /*for (int selectedItemIndex : selectedItems) {
            int itemNo = items[selectedItemIndex].itemNo;
            int quantity = quantities[selectedItemIndex];
        }*/



        for (const Item& item : items) {
            /*std::cout << "For loop 2" << endl;
            std::cout << "Item no: " << item.itemNo << std::endl;
            std::cout << "Item name: " << item.itemName << std::endl;*/

            if (item.itemNo == itemNo) {
                std::cout << setw(10) << left << itemNo;
                std::cout << setw(20) << left << item.itemName << endl;
                std::cout << setw(20) << right /*<< fixed << setprecision(2) */ << "(" << item.price << "*" << enteredQuantities[i] << ")";
                //cout << setw(10) << right << fixed << setprecision(2) << item.price;
                //cout << setw(10) << right << enteredQuantities[i] << endl;
                std::cout << setw(26) << right << fixed << setprecision(2) << item.price * enteredQuantities[i] << endl;
                break;
            }
            else {
                //std::cout << "Invalid selectedItemIndex: " << selectedItemIndex << std::endl;
            }
        }
    }








        std::cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
        std::cout << "Total: ";
        std::cout << setw(47) << std::right << fixed << setprecision(2) << total << std::endl;
        std::cout << setw(10) << right << fixed << setprecision(2) << total << endl;
        std::cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
        std::cout << "\t\tThank You Come Again" << endl;
        std::cout << "Dear Customer," << endl;
        std::cout << "Please note that food items, Pharmaceuticals and Sterile\nMedical devices will not be accepted as return or exchange." << endl;
        std::cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
        std::cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

        exit(0);
}