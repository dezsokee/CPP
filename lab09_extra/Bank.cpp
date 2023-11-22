#include <fstream>
#include "Bank.h"

using namespace std;

Bank::Bank(const string& name) : name(name) {}

int Bank::newCustomer(const string& firstName, const string& lastName ) {
    customers.push_back(Customer(firstName, lastName));
    return customers.size()-1;
}

bool Bank::deleteCustomer(int id) {
    if (id < 0 || id >= customers.size()) {
        return false;
    }

    for (int i = 0; i < customers.size(); ++i) {
        if (customers[i].getId() == id) {
            customers.erase(customers.begin() + i);
            return true;
        }
    }

    return false;
}

Customer& Bank::getCustomer(int id) {
    for (int i = 0; i < customers.size(); ++i) {
        if (customers[i].getId() == id) {
            return customers[i];
        }
    }

    throw runtime_error("Customer with id "+to_string(id)+" not found");
}

void Bank::printCustomers(ostream& os) const {
    for (int i = 0; i < customers.size(); ++i) {
        os<<i+1<<": "<<customers[i]<<endl;
    }
}

void Bank::printCustomersAndAccounts(ostream& os) const {
    for (int i = 0; i < customers.size(); ++i) {
        os<<i+1<<": "<<customers[i]<<endl;
    }
}

vector<int> Bank::loadCustomers(const string& filename) {
    ifstream ifs(filename);

    if (!ifs) {
        throw runtime_error("Could not open file "+filename);
    }

    vector<int> ids;
    string firstName, lastName;

    while (ifs>>firstName>>lastName) {
        newCustomer(firstName, lastName);
    }

    return ids;
}