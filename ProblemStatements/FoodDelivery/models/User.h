#ifndef User_H
#define User_H

#include <bits/stdc++.h>
#include "Cart.h"
using namespace std;

class User {
    private:
        int userId;
        string name;
        string address;
        Cart* cart;

    public:
        User(int userId, const string& name, const string& address) : userId(userId), name(name), address(address), cart(new Cart()) { }

        ~User() {
            delete cart; 
        }

        int getUserId() const {
            return userId;
        }
        string getName() const {
            return name;
        }
        string getAddress() const {
            return address;
        }
        Cart* getCart() const {
            return cart;
        }

        // setter
        void setName(const string& n) {
            name = n;
        }
        void setAddress(const string& addr) {
            address = addr;
        }
};

#endif