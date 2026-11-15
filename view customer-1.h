void Customer::viewCustomer() {

	string addCustomerFolder = "vehicle rental management system details\\customer management\\add customer";

    for (const auto& file : fs::directory_iterator(addCustomerFolder)){
        cout << "\n========== Customer Details ==========\n";

        ifstream customerFile(file.path());

        string line;

        while (getline(customerFile, line)){
            cout << line << endl;
        }

        customerFile.close();
        cout << "======================================\n";
        cout << endl << endl;
    }
}