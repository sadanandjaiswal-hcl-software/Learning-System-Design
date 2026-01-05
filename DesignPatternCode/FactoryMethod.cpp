#include <bits/stdc++.h>
using namespace std;

// Product Class and SubClass
class Burger{
    public:
        virtual void prepare() = 0;
};

class BasicBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Baisc Burger\n";
        }
};

class StandardBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Standard Burger\n";
        }
};

class PremiumBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Premium Burger\n";
        }
};

class BasicWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Baisc Wheat Burger\n";
        }
};

class StandardWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Standard Wheat Burger\n";
        }
};

class PremiumWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Premium Wheat Burger\n";
        }
};

// Factory and its concretion
class BurgerFactory{
    public:
        virtual Burger* createBurger(string type) = 0;
};

class SinghBurger : public BurgerFactory{
    public:
        Burger* createBurger(string type) override{
            if(type=="basic"){
                return new BasicBurger();
            }else if(type=="standard"){
                return new StandardBurger();
            }else if(type=="premium"){
                return new PremiumBurger();
            }else{
                cout<<"Invalid Burger type"<<endl;
                return nullptr;
            }
        }
};

class KingBurger : public BurgerFactory{
    public:
        Burger* createBurger(string type) override{
            if(type=="basic"){
                return new BasicWheatBurger();
            }else if(type=="standard"){
                return new StandardWheatBurger();
            }else if(type=="premium"){
                return new PremiumWheatBurger();
            }else{
                cout<<"Invalid Burger type"<<endl;
                return nullptr;
            }
        }
};



int main() {
    string type = "standard";
    
    BurgerFactory* mySinghBurgerFactory = new SinghBurger();
    BurgerFactory* myKingBurgerFactory = new KingBurger();
    
    Burger* burger = mySinghBurgerFactory->createBurger("basic");
    burger->prepare();
    Burger* burger2 = myKingBurgerFactory->createBurger("basic");
    burger2->prepare();
    
    return 0;
}
