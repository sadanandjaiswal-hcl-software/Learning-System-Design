#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include "MenuItem.h"
using namespace std;

class Restaurant{
    private:
        static int nextRestaurantId;
        int restaurantId;
        string name;
        string location;
        vector<MenuItem> menu;
    
    public:
        Restaurant(const string& name, const string& location){
            this->name = name;
            this->location = location;
            this->restaurantId = ++nextRestaurantId;
        }

        ~Restaurant(){
            cout<<"Destroying Restaurant "<<name<<" and clearing its menu\n";
            menu.clear();
        }

        string getName() const {
            return name;
        }

        void setName(const string& n){
            name = n;
        }

        string getLocation() const {
            return location;
        }

        void setLocation(const string& n){
            location = n;
        }

        void addMenuItem(const MenuItem &item){
            menu.push_back(item);
        }

        const vector<MenuItem>& getMenu(){
            return menu;
        }
};

int Restaurant::nextRestaurantId = 0;

#endif