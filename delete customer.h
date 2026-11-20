
void Customer::searchCustomer(){
    int searchID;
cout<<endl<<endl;
    cout<<"enter Customer ID to search:\n";
    cin>>searchID;

    string SearchCustomerFile="Vehicle rental management system details\\customer management\\add customer\\";
    SearchCustomerFile+="Customer file No " + to_string(searchID) + ".txt";

    ifstream file(SearchCustomerFile);

    if (file.is_open()){
        string line;
      cout<<"\n========== Customer Details=========="<< endl;
      while (getline(file, line)){
            cout << line << endl;
        }
        cout<<"======================================" << endl;
        file.close();
    }
    else{
        cout<<"\nCustomer record not found!" << endl;
    }
}
