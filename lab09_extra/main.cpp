#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Bank.h"

using namespace std;

int main() {
    Account account1(0);
    cout<<account1<<endl;

    account1.deposit(1000);
    cout<<account1<<endl;

    account1.withdraw(500);
    cout<<account1<<endl;

    account1.withdraw(1000);
    cout<<account1<<endl;

    Customer customer1("John", "Doe");

    customer1.newAccount(0);
    customer1.newAccount(1000);

    cout<<customer1;

    Bank bank1("OTP Bank");

    bank1.loadCustomers("customers.txt");

    cout<<"Customers:"<<endl;
    bank1.printCustomers();

    bank1.getCustomer(2).newAccount(1000);
    bank1.getCustomer(2).newAccount(2000);

    bank1.getCustomer(3).newAccount(500);
    bank1.getCustomer(3).newAccount(20);

    bank1.getCustomer(4).newAccount(10000);
    bank1.getCustomer(4).newAccount(20000);

    bank1.getCustomer(5).newAccount(1);
    bank1.getCustomer(5).newAccount(0);

    cout<<"Customers and accounts:"<<endl;
    bank1.printCustomersAndAccounts();

    bank1.getCustomer(2).getAccount(4).withdraw(1000);
    bank1.getCustomer(2).getAccount(5).deposit(2000);

    bank1.getCustomer(3).getAccount(6).withdraw(500);
    bank1.getCustomer(3).getAccount(7).deposit(20);

    bank1.getCustomer(4).getAccount(8).deposit(10000);
    bank1.getCustomer(4).getAccount(9).withdraw(20000);

    bank1.getCustomer(5).getAccount(10).withdraw(1);
    bank1.getCustomer(5).getAccount(11).deposit(100);

    cout<<"Customers and accounts after modifications:"<<endl;
    bank1.printCustomersAndAccounts();

    return 0;
}
