#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <bits/stdc++.h>
#include "../models/Order.h"
using namespace std;

class OrderManager {
    private:
        vector<Order*> orders;
        static OrderManager* instance;

        OrderManager() {}

    public:
        static OrderManager* getInstance(){
            if(instance == nullptr){
                instance = new OrderManager();
            }
            return instance;
        }

        void addOrder(Order* order){
            orders.push_back(order);
        }

        void listOrders() const {
            cout<<"**************** Orders List ****************\n";
            for(const auto& order : orders){
                cout<<"Order ID: "<<order->getOrderId()<<endl;
                cout<<order->getType()<<" Order for User : "<<order->getUser()->getName()<<" | Total Amount: "<<order->getTotalAmount();
                if(order->getType() == "Pickup"){
                    cout<<" | At: "<<order->getScheduled();
                }
                cout<<endl<<endl;
            }
        }
};

OrderManager* OrderManager::instance = nullptr;

#endif