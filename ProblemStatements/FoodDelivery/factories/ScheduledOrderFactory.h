#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include <bits/stdc++.h>
#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class ScheduledOrderFactory : public OrderFactory{
    private:
        string scheduleTime;

    public:
        ScheduledOrderFactory(const string& time) : scheduleTime(time) { }

        Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, vector<MenuItem>& menuItems, PaymentStrategy* paymentStrategy, const string& orderType){
            Order* order = nullptr;

            if(orderType == "Delivery"){
                auto deliveryOrder = new DeliveryOrder();
                deliveryOrder->setUserAddress(user->getAddress());
                order = deliveryOrder;
            }else{
                auto pickupOrder = new PickupOrder();
                pickupOrder->setRestaurantAddress(restaurant->getLocation());
                order = pickupOrder;
            }

            order->setUser(user);
            order->setRestaurant(restaurant);
            order->addItem(menuItems);
            order->setPaymentStrategy(paymentStrategy);
            order->setScheduled(scheduleTime);
            order->setTotalAmount(cart->getTotalCost());

            return order;
        }

        virtual ~ScheduledOrderFactory() { }
};

#endif