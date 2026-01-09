#ifndef Cart_H
#define Cart_H

#include <bits/stdc++.h>
#include "MenuItem.h"
#include "Restaurant.h"
using namespace std;

class Cart {
    private:
        vector<MenuItem> items;
        Restaurant* restaurant;

    public:
        Cart() {
            restaurant = nullptr;
        }

        void addItem(const MenuItem& item, Restaurant* rest) {
            if (!restaurant){
                cerr<<"Cart: set restaurant before adding items\n";
                return;
            }
            items.push_back(item);
        }

        double getTotalCost() const {
            double total = 0.0;
            for (const auto& item : items) {
                total += item.getPrice();
            }
            return total;
        }

        bool isEmpty() const {
            return items.empty();
        }

        void clear() {
            items.clear();
            restaurant = nullptr;
        }

        void setRestaurant(Restaurant* rest) {
            restaurant = rest;
        }

        Restaurant* getRestaurant() const {
            return restaurant;
        }

        const vector<MenuItem>& getItems() const {
            return items;
        }
};

#endif