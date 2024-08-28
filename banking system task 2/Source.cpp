#include<iostream>
#include<string>
using namespace std;

class bank {
private:
    string fullname;
    string dateofb;
    string address;
    string phonenumber;
    long long int initiald;
    long long int balance;
    long long int toacc;
    string toaccname;

public:
    void createacc();
    void deposit();
    void withdraw();
    void transfer();
    void viewaccinfo();
};

void bank::createacc() {
    cout << "Enter your Full Name: " << endl;
    getline(cin, fullname);

    cout << "Enter your Date Of Birth: " << endl;
    getline(cin, dateofb);

    cout << "Enter your Address: " << endl;
    getline(cin, address);

    cout << "Enter your Phone Number: " << endl;
    getline(cin, phonenumber);

    cout << "Enter initial deposit amount: " << endl;
    cin >> initiald;
    balance = initiald;  

    cin.ignore();  

    cout << endl;
    cout << "Account is created successfully!!" << endl;
    cout << endl;
}

void bank::deposit() {
    while (true) {
        long long int damount;
        cout << "Enter amount you want to deposit: " << endl;
        cin >> damount;
        if (damount <= 0) {
            cout << "Please enter positive number.." << endl;
            continue;
        }
        else {
            balance += damount;
            cout << "Balance after deposit of " << damount << ": " << balance << endl;
            cout << endl;
            break;
        }
    }
}

void bank::withdraw() {
    while (true) {
        long long int wamount;
        cout << "Enter amount you want to withdraw: " << endl;
        cin >> wamount;
        if (wamount > balance) {
            cout << "Insufficient funds! Withdrawal failed." << endl;
            break;
        }
        else if (wamount <= 0) {
            cout << "Please enter positive number..." << endl;
            continue;
        }
        else {
            balance -= wamount;
            cout << "Balance after withdrawal of " << wamount << ": " << balance << endl;
            break;
        }
        cout << endl;
    }
}

void bank::transfer() {
    while (true) {
        long long int tamount;
        cout << "Enter the name of the account holder to transfer to: ";
        cin.ignore();
        getline(cin, toaccname);

        cout << "Enter the account number to transfer to: ";
        cin >> toacc;

        cout << "Enter amount to transfer: ";
        cin >> tamount;

        if (tamount > balance) {
            cout << "Insufficient funds! Transfer failed." << endl;
            break;
        }
        else if (tamount <= 0) {
            cout << "Please enter positive number.." << endl;
            continue;
        }
        else {
            balance -= tamount;
            cout << "Transfer successful!" << endl;
            cout << "Amount transferred: " << tamount << endl;
            cout << "New balance: " << balance << endl;
            break;
        }
        cout << endl;
    }
}

void bank::viewaccinfo() {
    cout << "Account Information:" << endl;
    cout << "---------------------------" << endl;
    cout << "Full Name: " << fullname << endl;
    cout << "Date of Birth: " << dateofb << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phonenumber << endl;
    cout << "Initial Deposit: " << initiald << endl;
    cout << "Current Balance: " << balance << endl;
    cout << "---------------------------" << endl;
    cout << endl;
}

int main() {
    bank mybankacc;  
    while (true) {
        int o;
        cout << "Welcome to our Banking System!!" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cout << "1)New Account\n2)Deposit Amount\n3)Withdraw Amount\n4)Transfer Amount\n5)Account Info\n6)Exit\n";
        cout << "Choose an option: " << endl;
        cin >> o;
        cin.ignore();  

        switch (o) {
        case 1:
            mybankacc.createacc();
            break;
        case 2:
            mybankacc.deposit();
            break;
        case 3:
            mybankacc.withdraw();
            break;
        case 4:
            mybankacc.transfer();
            break;
        case 5:
            mybankacc.viewaccinfo();
            break;  
        case 6:
            return 0;  
        default:
            cout << "Error: Invalid option selected" << endl;
            cout << endl;
        }
    }
}
