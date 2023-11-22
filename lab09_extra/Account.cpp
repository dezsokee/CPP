#include "Account.h"

int Account::counter = 1;

Account::Account(double balance) {
    this->id = counter++;
    this->balance = balance;
}

void Account::deposit(double amount) {
    this->balance += amount;
}

bool Account::withdraw(double amount) {
    if (this->balance >= amount) {
        this->balance -= amount;
        return true;
    }
    return false;
}

int Account::getId() const {
    return this->id;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::print(ostream& os) const {
    os << "Account ID: " << this->id << ", Balance: " << this->balance;
}

ostream& operator<<(ostream& os, const Account& account) {
    account.print(os);
    return os;
}
