class Customer {
private:
    int customerID;   // data variables of class Customer
    string firstName;
    string lastName;
    string cnic;
    string phoneNumber;
    string email;
    string address;
    bool isActive;

public:
    // Default Constructor
    Customer()
    {
        customerID = 0;
        firstName = "";
        lastName = "";
        cnic = "";
        phoneNumber = "";
        email = "";
        address = "";
        isActive = true;
    }

    void addCustomer(); // member function of class Customer
    void displayCustomer();
    void searchCustomer();
    void viewCustomer();
    void updateCustomer();
    void deleteCustomer();

    /* These member functions are demonastrating encapsulation*/
    void updatePhoneNumber();
    void updateEmail();
    void updateAddress();
};

void Customer::addCustomer() {

    while (true) { // while will run until it fails 

        cout << endl << endl;
        cout << "Enter Customer ID: "; // asking customer ID

        if (!(cin >> customerID)) {  // check to see if the customer either int or not, suppose if not the it will become true

            cout << "Invalid input! Please enter numbers only.\n" << endl << endl;
            cin.clear();  // remove error state of cin so it works again
            cin.ignore(1000, '\n'); // suppose somone enters abc those characters will be in input buffer so this line means ignore and remove upto 1000 characters until enter key is reached 
            continue; // then continue again
        }

        cin.ignore(1000, '\n'); // suppose someone enter 100abc the cin will take 100 but still abc are there so thats why it is used

        string CheckCustomerFile = "vehicle rental management system details\\customer management\\add customer\\"; // opening folders after folders where the .txt file is saved
        CheckCustomerFile += "Customer file No " + to_string(customerID) + ".txt"; // assigning name of .txt file which is Customer file No followed by the entered customer ID

        ifstream checkFile(CheckCustomerFile); // reading that .txt file 

        if (checkFile.is_open()) { // if it is open then check whther that file exist with same customer id or not
            cout << "This Customer ID already exists!\n" << endl;
            checkFile.close();
        }

        else {
            break;
        }
    }

    cout << endl << endl;

    cout << "Enter First Name: "; // asking for first name
    getline(cin, firstName);

    cout << "Enter Last Name: "; // asking for last name
    getline(cin, lastName);

    cout << "Enter CNIC: "; // asking for cnic
    getline(cin, cnic);

    cout << "Enter Phone Number: "; // asking for Phone number 
    getline(cin, phoneNumber);

    cout << "Enter Email: "; // asking for email
    getline(cin, email);

    cout << "Enter Address: "; // asking for address
    getline(cin, address); // getting adress with spaces

   // isActive = true;

    fs::create_directories("vehicle rental management system details/customer management/add customer");     // Create customer folder automatically if it does not exist

    string AddCustomerFile = "vehicle rental management system details\\customer management\\add customer\\";
    AddCustomerFile += "Customer file No " + to_string(customerID) + ".txt";

    ofstream file(AddCustomerFile); // writing into customer .txt file
    cout << endl;

    if (file.is_open()) {

        file << "Customer ID: " << customerID << endl;
        file << "First Name: " << firstName << endl;
        file << "Last Name: " << lastName << endl;
        file << "CNIC: " << cnic << endl;
        file << "Phone: " << phoneNumber << endl;
        file << "Email: " << email << endl;
        file << "Address: " << address << endl;

        file << "Active: Yes" << endl;
        file.close();
        cout << endl;
        cout << "Customer saved successfully!" << endl;
    }
    else {
        cout << "File could not be created." << endl;
    }
}

void Customer::displayCustomer() { // to display information

    cout << "\n========== Customer Details ==========" << endl;
    cout << "Customer ID      : " << customerID << endl;
    cout << "First Name       : " << firstName << endl;
    cout << "Last Name        : " << lastName << endl;
    cout << "CNIC             : " << cnic << endl;
    cout << "Phone Number     : " << phoneNumber << endl;
    cout << "Email            : " << email << endl;
    cout << "Address          : " << address << endl;
    cout << "Account Status   : Active" << endl;

    cout << "======================================" << endl;
}