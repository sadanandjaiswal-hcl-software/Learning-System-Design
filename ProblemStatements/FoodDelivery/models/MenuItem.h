#ifndef MENUITEM_H
#define MENUITEM_H

#include <bits/stdc++.h>
using namespace std;

class MenuItem{
    private:
        string code;
        string name;
        double price;
    
    public:
        MenuItem(const string& code, const string& name, double price){
            this->code = code;
            this->name = name;
            this->price = price;
        }

        string getCode() const {
            return code;
        }

        void setCode(const string& c){
            code = c;
        }

        string getName() const {
            return name;
        }
        
        void setName(const string& n){
            name = n;
        }

        double getPrice() const {
            return price;
        }

        void setPrice(double p){
            price = p;
        }
};

#endif