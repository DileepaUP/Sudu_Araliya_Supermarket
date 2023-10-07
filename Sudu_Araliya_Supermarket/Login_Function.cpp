#include <iostream>
using namespace std;

int main()
{
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 3)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "test" && userPassword == "test123")
        {
            cout << "Welcome User!\n";
            break;
        }
        else if (userName == "patrick" && userPassword == "dunn")
        {
            cout << "Welcome Patrick!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n";
            cout << "";
            system("cls");
            loginAttempt++;
        }
    }
    if (loginAttempt == 2)
    {
        cout << "Too many login attempts! The program will now terminate.";
        return 0;
    }

    cout << "Thank you for logging in.\n";
}





//#include<iostream>
//#include<string>
//using namespace std;
//
//
//int main() 
//{
//        //system("cls");
//        cout << "\t\t\t================================================" << endl;
//        cout << "\t\t\t\t***Welcome to Sudu Araliya***" << endl;
//        cout << "\t\t\t================================================" << endl;
//        cout << "" << endl;
//        string username, password;
//        cout << "\t\t\tEnter Username: ";
//        cin >> username;
//        cout << "\t\t\tEnter Password: ";
//        cin >> password;
//        if (username == "test" && password == "test")
//        {
//            cout << "Your credentials are correct";
//            //system("cls");
//            //menu()
//        }
//        else
//        {
//            cout << "" << endl;
//            cout << "\t\t\tInvalid username and Password please try again\n\n";
//            //welcome();
//        }
//
//        cout << endl;
// }




//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string username = "cool";
//    string password = "lol";
//    string user;
//    string pass;
//    cout << "Hello, Welcome to the App Login!" << std::endl;
//    cout << "Enter Your username: ";
//    cin >> user;
//    if (user == username) {
//        cout << "Enter password: " << endl;
//        cin >> pass;
//
//
//        if (pass == password) {
//            cout << "Successful Login!" << endl;
//        }
//        else {
//            cout << "Incorrect Password!" << endl;
//        }
//
//
//    }
//    else {
//    }
//
//        cout << "Incorrect Username!" << endl;
//    }
//}




