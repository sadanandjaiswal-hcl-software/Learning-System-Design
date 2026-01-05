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

// Product Class and SubClass
class GarlicBread{
    public:
        virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Baisc GarlicBread\n";
        }
};

class StandardGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Standard GarlicBread\n";
        }
};

class BasicWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Baisc Wheat GarlicBread\n";
        }
};

class CheeseWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Cheese Wheat GarlicBread\n";
        }
};

// Factory and its concretion
class MealFactory{
    public:
        virtual Burger* createBurger(string type) = 0;
        virtual GarlicBread* createGarlicBread(string type) = 0;
};

class SinghBurger : public MealFactory{
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

        GarlicBread* createGarlicBread(string type) override{
            if(type=="basic"){
                return new BasicGarlicBread();
            }else if(type=="cheese"){
                return new CheeseWheatGarlicBread();
            }else{
                cout<<"Invalid GarlicBread type"<<endl;
                return nullptr;
            }
        }
};

class KingBurger : public MealFactory{
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

        GarlicBread* createGarlicBread(string type) override{
            if(type=="basic"){
                return new BasicGarlicBread();
            }else if(type=="cheese"){
                return new CheeseWheatGarlicBread();
            }else{
                cout<<"Invalid GarlicBread type"<<endl;
                return nullptr;
            }
        }
};

int main() {
    string burgerType = "standard";
    string garlicBreadType = "cheese";

    MealFactory* mealFactory = new SinghBurger();
    Burger* burger1 = mealFactory->createBurger(burgerType);
    GarlicBread* garlicBread1 = mealFactory->createGarlicBread(garlicBreadType);

    burger1->prepare();
    garlicBread1->prepare();
    
    return 0;
}
