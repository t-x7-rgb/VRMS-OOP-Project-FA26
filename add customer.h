#include"membership management.h"

class Customer {
private:
    Membership membership; // composition of class Membership

    int customerID;   // data variables of class Customer
    string firstName;
    string lastName;
    string cnic;
    string phoneNumber;
    string email;
    string address;
    string storeMembership;
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
        storeMembership = "";
        isActive = true;
    }

    void addCustomer(); // member function of class Customer
    void displayCustomer();
    void searchCustomer();
    void viewCustomer();
    void updateCustomer();
    void deleteCustomer();
    void updateExistingCustomerMembership();

    /* These member functions are demonastrating encapsulation*/
    void updatePhoneNumber();
    void updateEmail();
    void updateAddress();
};

void Customer::addCustomer() {

    storeMembership = "";

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

    int membershipTypeSelectionForNewCustomer; // int type varaible to choose membership for customer
    char choiceOfMembershipForNewCustomer; // to ask customer whether he wants membership or not

    cout << endl << endl;

    cout << "Do you want membership: \n"
        << "Press y for yes or press n for no :\n" << endl;
    cin >> choiceOfMembershipForNewCustomer;

    if (choiceOfMembershipForNewCustomer == 'y' || choiceOfMembershipForNewCustomer == 'Y') {
        cout << endl << endl;

        cout << "Enter Membership Type: \n"
            << "1. Bronze  ( Fee 1000, dicount on rental cars is 5 %) \n"
            << "2. Silver  ( Fee 2500, dicount on rental cars is 10 %) \n"
            << "3. Gold    ( Fee 5000, dicount on rental cars is 15 %) \n"
            << "4. Diamond ( Fee 8000, dicount on rental cars is 25 %) \n" << endl;
        cin >> membershipTypeSelectionForNewCustomer;

        if (membershipTypeSelectionForNewCustomer == 1) {
            membership.bronzeMembership(); // member function of class Membership is called by using its object membership which is in (membership management.h)
        }

        else if (membershipTypeSelectionForNewCustomer == 2) {
            membership.silverMembership(); // member function of class Membership is called by using its object membership which is in (membership management.h)
        }

        else if (membershipTypeSelectionForNewCustomer == 3) {
            membership.goldMembership(); // member function of class Membership is called by using its object membership which is in (membership management.h)
        }

        else if (membershipTypeSelectionForNewCustomer == 4) {
            membership.diamondMembership(); // member function of class Membership is called by using its object membership which is in (membership management.h)
        }

        else {
            cout << "Invalid Selection!" << endl;
        }
    }

    else {
        cout << "No membership is selected \n";
        membership.clearMembership(); // member function of class Membership is called by using its object membership which is in (membership management.h) and it is done so that previous data should not remain in it
        storeMembership = "";
    }

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

        if (!membership.getMembershipType().empty()) { // member function of class Member is called which is in ( membership management.h) 
                                                       //it is for those customer who didnt choose any memberhsip so it wont write it into their .txt files
            file << "Membership: " << membership.getMembershipType() << endl;
        }

        file << "Active: Yes" << endl;
        file.close();
        cout << endl;
        cout << "Customer saved successfully!" << endl;
    }
    else {
        cout << "File could not be created." << endl;
    }

    storeMembership = membership.getMembershipType(); // member function of class membership is called which is in (membership management.h)
                                                      //it is used here for this reason so the customer who chooses any membership should be
                                                      // on console screen as well
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

    if (!storeMembership.empty()) { // if it is not empty display it as well we mentioned that above
        cout << "Membership       : " << storeMembership << endl;
    }
    cout << "======================================" << endl;
}

void Customer::updateExistingCustomerMembership() {
    int accountIDForMembership;

    string tempCustomerID;
    string tempActive;
    string tempLine;
    string tempMembershipType;

    cout << endl << endl;
    cout << "Enter customer account ID to update membership: "; // getting id to update membership for existing customers
    cin >> accountIDForMembership;

    string UpdateCustomerFile ="Vehicle rental management system details\\customer management\\add customer\\";

    UpdateCustomerFile += "Customer file No " + to_string(accountIDForMembership) + ".txt";

    ifstream file(UpdateCustomerFile); //read file

    if (!file) {
        cout << "Customer not found!" << endl;
        return;
    }

    getline(file, tempCustomerID); // read single line and store it into variable
    getline(file, firstName);
    getline(file, lastName);
    getline(file, cnic);
    getline(file, phoneNumber);
    getline(file, email);
    getline(file, address);
    getline(file, tempLine);

    if (tempLine.find("Membership") != string::npos) {
        tempMembershipType = tempLine;
        getline(file, tempActive);
    }

    else {
        tempMembershipType = "";
        tempActive = tempLine;
    }

    file.close();

    membership.membershipForExistingCustomer();

    if (!membership.getMembershipType().empty()) {
        tempMembershipType = "Membership: " + membership.getMembershipType();
    }

    ofstream updateFile(UpdateCustomerFile);

    if (updateFile.is_open()) {

        updateFile << tempCustomerID << endl;
        updateFile << firstName << endl;
        updateFile << lastName << endl;
        updateFile << cnic << endl;
        updateFile << phoneNumber << endl;
        updateFile << email << endl;
        updateFile << address << endl;

        if (!tempMembershipType.empty()) {
            updateFile << tempMembershipType << endl;
        }

        updateFile << tempActive << endl;
        updateFile.close();

        cout << "\nMembership updated successfully!" << endl;
        cout << endl << endl;

        cout << "========== Updated Customer Information ==========" << endl;
        cout << tempCustomerID << endl;
        cout << firstName << endl;
        cout << lastName << endl;
        cout << cnic << endl;
        cout << phoneNumber << endl;
        cout << email << endl;
        cout << address << endl;

        if (!tempMembershipType.empty()) {
            cout << tempMembershipType << endl;
        }

        cout << tempActive << endl;
        cout << "==================================================" << endl;
    }

    else {
        cout << "File cannot be updated!" << endl;
    }
}