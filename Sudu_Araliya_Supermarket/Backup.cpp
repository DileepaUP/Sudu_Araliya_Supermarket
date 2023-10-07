//Backup
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>

using namespace std;

int used_item;
int used_qty;
int l = 0;

//declaring a structure
struct customerOrder
{
	int used_item;
	int used_qty;
	double total;
};

//structure type
struct menuItemtype
{
	int itemNo;
	string menuItem;
	double Price;
};

void welcome();
void menu();
void quit();
void bill();
void list();
void viewPackages();
void selectPackages();
void addItems();


struct menuItemtype menulist[11];
struct customerOrder orderItems[100];

int main()
{

	welcome();

	/*system("pause>null");
	return 0;*/

}

char* int_to_char(int i, char b[]) {
	char const digit[] = "0123456789";
	char* p = b;
	if (i < 0) {
		*p++ = '-';
		i *= -1;
	}
	int shifter = i;
	do {
		++p;
		shifter = shifter / 10;
	} while (shifter);
	*p = '\0';
	do {
		*--p = digit[i % 10];
		i = i / 10;
	} while (i);
	return b;
}


void welcome()
{

	string userName;
	string userPassword;
	int loginAttempt = 0;

	while (loginAttempt < 3)
	{
		cout << "\t\t\t================================================" << endl;
		cout << "\t\t\t\t***Welcome to Sudu Araliya***" << endl;
		cout << "\t\t\t================================================" << endl;
		cout << "" << endl;
		cout << "Please enter your user name: ";
		cin >> userName;
		cout << "Please enter your user password: ";
		cin >> userPassword;

		if (userName == "admin" && userPassword == "admin123")
		{
			cout << "Welcome Admin!\n" << endl;
			system("cls");
			menu();
			break;
		}
		else if (userName == "patrick" && userPassword == "patrick123")
		{
			cout << "Welcome Patrick!\n" << endl;
			system("cls");
			menu();
			break;
			//continue;
		}
		else
		{
			cout << "Invalid login attempt. Please try again.\n";
			cout << "";
			system("cls");
			loginAttempt++;
		}

	}

	cout << "Invalid login attempt. Please try again.\n";
	cout << "";

	/*if (loginAttempt == 2)
	{
		cout << "Too many login attempts! The program will now terminate.";
		return 0;
	}

	cout << "Thank you for logging in.\n";*/
}

/*string username, password;
cout << "\t\t\tEnter Username: ";
cin >> username;
cout << "\t\t\tEnter Password: ";
cin >> password;
if (username == "test" && password == "test")
{
	system("cls");
	menu();
}
else
{
	cout << "" << endl;
	cout << "\t\t\tInvalid username and Password please try again\n\n";
	welcome();
}

cout << endl;
}*/

void menu()
{
	//system("cls");
	int option;
	cout << "\t\t\t================================================" << endl;
	cout << "\t\t\t\t***Welcome to Sudu Araliya***" << endl;
	cout << "\t\t\t================================================" << endl;
	//cout << "" << endl;
	cout << "\t\t\t\t\t**Main Menu**" << endl;
	cout << "\t\t\t================================================" << endl << endl;
	cout << "\t\t\t(1) View available Items" << '\n' << "\t\t\t(2) Select Items" << '\n' << "\t\t\t(3) Exit\n" << endl;


	cout << "\t\t\tEnter your option:";
	cin >> option;

	if (option == 1) {
		system("cls");
		//viewPackages();
		addItems();
	}
	else if (option == 2) {
		system("cls");
		selectPackages();
	}
	else if (option == 3) {
		quit();
	}
	else {
		cout << endl << "\t\t\tINVALID INPUT" << endl;
		cout << "\t\t\tTRY AGAIN" << endl;
		system("cls");
		menu();
	}
}



void addItems()
{
	const int NUM_CATEGORIES = 3;
	string categories[NUM_CATEGORIES];
	double prices[NUM_CATEGORIES];

	cout << "Enter the details for each category:\n";

	// Loop to get user input for each category
	for (int i = 0; i < NUM_CATEGORIES; i++)
	{
		cout << "Category " << (i + 1) << ":\n";
		cout << "Enter name: ";
		//getline(cin >> ws, categories[i]);
		cin >> categories[i];
		//cout << i << endl;
		cout << "Enter price: ";
		cin >> prices[i];
		//cout << i << endl;
	}

	cout << fixed << setprecision(2);

	// Print the table header
	cout << "\tNo.\t\tCode\t\tCategory\t\tPrice" << endl;

	// Loop through the categories and prices arrays
	for (int i = 0; i < NUM_CATEGORIES; i++)
	{
		// Print each row of the table
		cout << "\t" << (i + 1) << "\t\t";
		cout << setw(4) << setfill('0') << (i + 1);
		cout << "\t\t" << setw(15) << left << categories[i];
		cout << "\tRs " << setw(8) << right << prices[i] << endl;
	}

	//return 0;
}




void viewPackages()
{
	cout << "\t\t\t**Sudu Araliya Items Avaiable**" << endl;
	cout << "" << endl;
	cout << "\tItem No\t\tItem ID\t\tItem Name\t\t\Price (RS)" << endl << endl;

	cout << "\t1\t\t0001\t\t Meat \t\t\tRs 3000.00" << endl;
	cout << "\t2\t\t0002\t\t Fish \t\t\tRs 4500.00" << endl;
	cout << "\t3\t\t0003\t\t Vegis \t\t\tRs 4500.00" << endl;
	cout << "\t4\t\t0004\t\t Fruits \t\tRs 3800.00" << endl;
	cout << "\t5\t\t0005\t\t Grains \t\tRs 5500.00" << endl;
	cout << "\t6\t\t0006\t\t Beans \t\t\tRs 40000.00" << endl;
	cout << "\t7\t\t0007\t\t Dairy\t\t\tRs 28000.00" << endl;
	cout << "\t8\t\t0008\t\t Canned Food\t\tRs 35000.00" << endl;
	cout << "\t9\t\t0009\t\t Sealed Food\t\tRs 15000.00" << endl;
	cout << "\t10\t\t0010\t\t Hygine Products\tRs 4800.00" << endl;
	cout << "\t11\t\t0011\t\t Clothing\t\tRs 10000.00" << endl;

	cout << endl;

	int b;
	cout << "\t1. Back" << endl;
	cout << "\t2. Log out" << endl;
	cout << "\t3. Exit" << endl;
	cout << "\tEnter your option: ";
	cin >> b;

	switch (b)
	{
	case 1:
		system("cls");
		menu();
		break;
	case 2:
		system("cls");
		welcome();
		break;
	case 3:
		quit();
		break;
	default:
		cout << "\tInvalid option!" << endl;
		break;
	}
}


void selectPackages()
{
	int item[11];
	int qun[11];
	string proceed;

	system("cls");


	cout << "\t\t\t**Sudu Araliya Items Avaiable**" << endl;
	cout << "" << endl;
	cout << "\tItem No\t\tItem ID\t\tItem Name\t\t\t\t\tPrice (RS)" << endl << endl;

	cout << "\t1\t\t0001\t\t Meat \t\ttRs 3000.00" << endl;
	cout << "\t2\t\t0002\t\t Fish \t\tRs 4500.00" << endl;
	cout << "\t3\t\t0003\t\t Vegis \t\tRs 4500.00" << endl;
	cout << "\t4\t\t0004\t\t Fruits \t\tRs 3800.00" << endl;
	cout << "\t5\t\t0005\t\t Grains \t\tRs 5500.00" << endl;
	cout << "\t6\t\t0006\t\t Beans \t\tRs 40000.00" << endl;
	cout << "\t7\t\t0007\t\t Dairy\t\tRs 28000.00" << endl;
	cout << "\t8\t\t0008\t\t Canned Food\t\tRs 35000.00" << endl;
	cout << "\t9\t\t0009\t\t Sealed Food\t\t\Rs 15000.00" << endl;
	cout << "\t10\t\t0010\t\t Hygine Products\t\tRs 4800.00" << endl;
	cout << "\t11\t\t0011\t\t Clothing\t\tRs 10000.00" << endl;

	cout << endl;

	list();


	while (1)
	{
		cout << "\tEnter Package Number (1-11): ";
		cin >> orderItems[l++].used_item;

		if (orderItems[l - 1].used_item <= 11 && orderItems[l - 1].used_item >= 1)
		{
			cout << "\tEnter Quantity: ";
			cin >> orderItems[l - 1].used_qty;
			cout << "\tDo you want to proceed to bill? Yes/No ";
			cin >> proceed;

			/*if (proceed == "Yes")
			{
				system("cls");
				bill();
				cout << "Do you want to print the bill? Yes/No" << endl;
			}
			else
			{
				system("cls");
				menu();
			}*/
		}
		else
		{
			cout << "\tInvalid item number. Please enter again->" << endl;
			l--;
			continue;
		}

		if (proceed == "Yes")
		{
			system("Cls");
			bill();
			break;
		}
	}
}


void quit()
{
	exit(0);
}

void list()
{
	menulist[0].itemNo = 1;
	menulist[0].menuItem = "Meat";
	menulist[0].Price = 3000.00;

	menulist[1].itemNo = 2;
	menulist[1].menuItem = "Fish";
	menulist[1].Price = 4500.00;

	menulist[2].itemNo = 3;
	menulist[2].menuItem = "Vegis";
	menulist[2].Price = 4500.00;

	menulist[3].itemNo = 4;
	menulist[3].menuItem = "Fruits";
	menulist[3].Price = 3800.00;

	menulist[4].itemNo = 5;
	menulist[4].menuItem = "Grains";
	menulist[4].Price = 5500.00;

	menulist[5].itemNo = 6;
	menulist[5].menuItem = "Beans";
	menulist[5].Price = 40000.00;

	menulist[6].itemNo = 7;
	menulist[6].menuItem = "Dairy";
	menulist[6].Price = 28000.00;

	menulist[7].itemNo = 8;
	menulist[7].menuItem = "Canned Food";
	menulist[7].Price = 35000.00;

	menulist[8].itemNo = 9;
	menulist[8].menuItem = "Sealed Food";
	menulist[8].Price = 15000.00;

	menulist[9].itemNo = 10;
	menulist[9].menuItem = "Hygine Products";
	menulist[9].Price = 4800.00;

	menulist[10].itemNo = 11;
	menulist[10].menuItem = "Clothing";
	menulist[10].Price = 10000.00;
}


void bill()
{
	string printable;
	char str1[10], str2[10], str3[10], str4[10], str5[10];

	int orderTotal = 0;
	cout << "" << endl;
	cout << "" << endl;
	cout << "\t\t**Sudu Araliya Billing System**" << endl;
	cout << "" << endl;
	cout << "" << endl;



	cout << "Item ID\t\tItem name\t\t\tQuantity\tPrice" << endl;
	cout << "" << endl;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (menulist[j].itemNo == orderItems[i].used_item)
			{
				orderItems[i].total = orderItems[i].used_qty * menulist[j].Price;
				orderTotal += orderItems[i].total;

				int_to_char(orderItems[i].used_item, str1);
				int_to_char(orderItems[i].used_qty, str2);
				int_to_char(orderItems[i].total, str3);

				printable = string(str1) + "\t\t";
				printable += menulist[j].menuItem + "";
				printable += string(str2) + "\t\t" + string(str3);

				cout << printable << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------" << endl;
	int_to_char(orderTotal, str5);
	cout << "Total                    \t\t\t\t\t" + string((str5)) << endl;
	cout << "========================================================================" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "\t\t\***THANK YOU FOR SHOPPING ***" << endl;
}