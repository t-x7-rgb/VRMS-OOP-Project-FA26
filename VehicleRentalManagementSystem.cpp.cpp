#include<filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include<vector>
#include<limits>

namespace fs = std::filesystem;
using namespace std;

#include"add customer.h"
#include"view customer.h"
#include"search customer.h"
#include"update customer.h"
#include"delete customer.h"

int main()
{
    Customer customer; // customer object of class Customer

    int VehicleRentalManagementSystemOption; // int variable to choose 4 options from vehicle rental management system
    int CustomerManagementOption; // int variable to choose options from customer management

    fs::create_directories("vehicle rental management system details/admin");     // Create folder for Admin

    string ownerName; // string variable to store owner name
    string ownerPassword; // string to store owner password

    bool accountExists = false; // flag to check that whether owner account exists or not

    ifstream checkFile("vehicle rental management system details/admin/admin.txt"); // to read owner .txt file 

    if (checkFile.is_open())  // check if file is open
    {
        string temp; // string type temp variable

        if (getline(checkFile, temp)) // read one line of owner .txt file so if the file exact content accountExists will be initialized to true
        {
            accountExists = true;  
        }

        checkFile.close(); // close the file
    }

    if (accountExists == false) // if it is false which will be false for first time then if will be executed
    {
        cout << "\n========================================\n";
        cout << "         OWNER REGISTRATION             \n";
        cout << "========================================\n";

        cout << endl << endl;
        cout << "Enter Owner Name: "; // asking for owner name 
        getline(cin, ownerName); // getting owner name with spaces 

        cout << "Create Password: "; // asking for owner password 
        cin >> ownerPassword; // taking onwer password without spaces

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clear previous input before taking new input

        ofstream adminFile("vehicle rental management system details/admin/admin.txt"); // writing owner name and password inside the .txt file

        adminFile << ownerName << endl;  // writing owner name
        adminFile << ownerPassword << endl; // writing onwer password

        adminFile.close(); // closing the file

        cout << "\nOwner account created successfully!\n";
        cin.ignore();
    }

    while (true) // while (true) means keep asking successful login
    {
        string enteredName; // string variable to get name for registration
        string enteredPassword; // string variable to get pasword for registration

        string savedName; // string variable to read owner name from .txt file
        string savedPassword; // string variable to read owner pasword from .txt file

        ifstream adminFile("vehicle rental management system details/admin/admin.txt"); // reading from owner file

        getline(adminFile, savedName); // read a line and save it into savedName
        getline(adminFile, savedPassword); // read next line and save it into svaedPassword

        adminFile.close(); // clsoing file

        cout << "\n========================================\n";
        cout << "             OWNER LOGIN               \n";
        cout << "========================================\n";

        cout << endl << endl;
        cout << "Owner Name: "; // asking owner name for login
        getline(cin, enteredName); // taking owner with spaces

        cout << "Password: "; // asking for owner name for login
        cin >> enteredPassword; // taking owner name without spaces
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (enteredName == savedName && enteredPassword == savedPassword) { // condition to check is login name,password equal to .txt file content or not 

            cout << "\nLogin Successful!\n";
            break;
        }
        else{ // not matches show below message

            cout << "\nInvalid Owner Name or Password!\n";
        }
    }

    while (1){ // condition to run infinite loop until break executes

        cout << endl << endl;

        cout << "========================================================\n"
            << "        VEHICLE RENTAL MANAGEMENT SYSTEM                \n"
            << "========================================================\n"
            << "                                                        \n"
            << "1. Customer Management                                  \n"
            << "2. Exit 
            << "                                                        \n"
            << "Select an option:                                      \n";
        cin >> VehicleRentalManagementSystemOption; // asking for options

        if (VehicleRentalManagementSystemOption == 1){ 

            while (1){

                cout << endl << endl;
                cout << "================ CUSTOMER MANAGEMENT ================\n"
                    << "                                                     \n"
                    << "1. Add Customer                                      \n"
                    << "2. View Customers                                    \n"
                    << "3. Search Customer                                   \n"
                    << "4. Update Customer                                   \n"
                    << "5. Delete Customer                                   \n"
                    << "6. Membership for Existing Customers                 \n"
                    << "7. Back to Main Menu                                 \n"
                    << "                                                     \n"
                    << "Select an option:                                    \n";
                cin >> CustomerManagementOption; // asking to select any option from customer management

                if (CustomerManagementOption == 1){

                    customer.addCustomer(); // call member function of class Customer using its object customer

                    customer.displayCustomer();
                }

                else if (CustomerManagementOption == 2){

                    customer.viewCustomer();
                }

                else if (CustomerManagementOption == 3){

                    customer.searchCustomer();
                }

                else if (CustomerManagementOption == 4){

                    customer.updateCustomer();
                }

                else if (CustomerManagementOption == 5){

                    customer.deleteCustomer();
                }

                else if (CustomerManagementOption == 6){

                    break;
                }

                else{

                    cout << "Invalid option!" << endl;
                }
            }
        }

        else if (VehicleRentalManagementSystemOption == 2)
        {

            cout << "Exiting system..." << endl;

            break;

        }

        else
        {

            cout << "Invalid option!" << endl;

        }

    }

    return 0;

}