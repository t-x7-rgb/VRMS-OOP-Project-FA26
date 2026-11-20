void Customer::updateCustomer(){
    int getCustomerIDforUpdate;

    cout << endl << endl;
    cout << "Enter Customer ID for updating information: ";
    cin >> getCustomerIDforUpdate;

    string updateCustomerFile = "Vehicle rental management system details\\customer management\\add customer\\";

    updateCustomerFile += "Customer file No "+ to_string(getCustomerIDforUpdate) + ".txt";

    ifstream file(updateCustomerFile);

    if (!file){
        cout << "Customer not found.\n";
        return;
    }

    string tempCustomerID;
    string tempMembershipType;
    string tempActive;

    getline(file, tempCustomerID);
    getline(file, firstName);
    getline(file, lastName);
    getline(file, cnic);
    getline(file, phoneNumber);
    getline(file, email);
    getline(file, address);

    string tempLine;
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
    
    cout << "\n========== Current Customer Information ==========\n";
    cout << tempCustomerID<<endl;
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
    cout << "======================================\n";

    int updateInformation;

    cout << "\n1. Update Phone Number";
    cout << "\n2. Update Email";
    cout << "\n3. Update Address";
    cout << "\n4. Back to Customer Management"<<endl;
    cout << "\nEnter your choice: ";
    cin >> updateInformation;

    cin.ignore();

    if (updateInformation == 1){
        cout << endl;
        updatePhoneNumber();
    }

    else if (updateInformation == 2){
        cout << endl;
        updateEmail();
    }

    else if (updateInformation == 3){
        cout << endl;
        updateAddress();
    }

    else {
        return;
    }

    ofstream updateFile(updateCustomerFile);

    if (updateFile.is_open()){

        updateFile << tempCustomerID << endl;
        updateFile << firstName << endl;
        updateFile << lastName << endl;
        updateFile << cnic << endl;
        updateFile << phoneNumber << endl;
        updateFile << email << endl;
        updateFile << address << endl;

        if (!tempMembershipType.empty()){
            updateFile << tempMembershipType << endl;
        }

        updateFile << tempActive << endl;
        updateFile.close();

        cout << "Customer information updated successfully.\n";
        cout << "\n========== Updated Customer Information ==========\n";

        cout << tempCustomerID << endl;
        cout << firstName << endl;
        cout << lastName << endl;
        cout << cnic << endl;
        cout << phoneNumber << endl;
        cout << email << endl;
        cout << address << endl;

        if (!tempMembershipType.empty()){
            cout << tempMembershipType << endl;
        }

        cout << tempActive << endl;
        cout << "======================================\n";
    }

    else{
        cout << "Customer information cannot be updated.\n";
    }
}

void Customer::updatePhoneNumber() {
    string newPhoneNumber;
    cout << "Enter new phone number: ";
    cin >> newPhoneNumber;
    phoneNumber ="Phone No: "+ newPhoneNumber;
}

void Customer::updateEmail() {
    string newEmail;
    cout << "Enter new email :";
    cin >> newEmail;
    email = "Email: "+newEmail;
}

void Customer::updateAddress() {
    string newAdress;
    cout << "Enter new address :";
    getline(cin, newAdress);
    address = "Address: "+newAdress;
}