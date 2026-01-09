#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include <bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy {
    private:
        string mobile;

    public:
        UpiPaymentStrategy(const string& mobile) : mobile(mobile) { }

        void pay(double amount) override {
            cout << "Processing UPI payment of $" << amount << " for mobile: " << mobile << endl;
            // Here, you would integrate with a real payment gateway
            cout << "Payment successful using UPI linked to mobile " << mobile << endl;
        }
};

#endif