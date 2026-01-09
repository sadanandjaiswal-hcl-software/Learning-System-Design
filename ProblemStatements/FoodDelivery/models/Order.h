#ifndef Order_H
#define Order_H

#include <bits/stdc++.h>
#include "Restaurant.h"
#include "User.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
using namespace std;

class Order {
    private:
        static int nextOrderId;
        int orderId;
        User* user;
        Restaurant* restaurant;
        PaymentStrategy* paymentStrategy;
        vector<MenuItem> items;
        double totalAmount;
        string scheduled;

    public:
        Order() {
            orderId = ++nextOrderId;
            totalAmount = 0.0;
            paymentStrategy = nullptr;
            restaurant = nullptr;
            user = nullptr;
            scheduled = "";
        }

        // virtual ~Order : this will first delete its child then parent, for : Order* o = new OrderChild(); delete o;
        virtual ~Order() {
            delete paymentStrategy;
        }

        bool processPayment() {
            if (paymentStrategy) {
                paymentStrategy->pay(totalAmount);
                return true;
            } else {
                cerr << "Please choose a payment mode first\n";
                return false;
            }
        }

        virtual string getType() const = 0;

        // setters and getters
        int getOrderId() const {
            return orderId;
        }
        void setUser(User* u) {
            user = u;
        }   
        User* getUser() const {
            return user;
        }
        void setRestaurant(Restaurant* r) {
            restaurant = r;
        }
        Restaurant* getRestaurant() const {
            return restaurant;
        }
        void setPaymentStrategy(PaymentStrategy* ps) {
            paymentStrategy = ps;
        }
        PaymentStrategy* getPaymentStrategy() const {
            return paymentStrategy;
        }
        void addItem(const vector<MenuItem>& itemList) {
            items = itemList;
            totalAmount = 0.0;
            // items.insert(items.end(), itemList.begin(), itemList.end());
            for (const auto& item : itemList) {
                totalAmount += item.getPrice();
            }
        }

        double getTotalAmount() const {
            return totalAmount;
        }

        void setTotalAmount(double amount) {
            totalAmount = amount;
        }
        
        const vector<MenuItem>& getItems() const {
            return items;
        }

        void setScheduled(const string& time) {
            scheduled = time;
        }

        const string& getScheduled() const {
            return scheduled;
        }
};

int Order::nextOrderId = 0;

#endif