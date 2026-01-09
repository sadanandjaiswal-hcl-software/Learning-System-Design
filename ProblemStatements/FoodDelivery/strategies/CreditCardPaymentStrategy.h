#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include <bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy {
    private:
        string cardNumber;

    public:
        CreditCardPaymentStrategy(const string& number) : cardNumber(number) { }

        void pay(double amount) override {
            cout << "Paid " << amount << " using Credit Card ending with " 
                 << cardNumber.substr(cardNumber.length() - 4) << endl;
        }
};

#endif