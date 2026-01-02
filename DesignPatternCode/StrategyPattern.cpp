
#include <bits/stdc++.h>
using namespace std;

// Strategy Interface for Walk
class WalkableRobot{
    public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

// Concrete Strategies for Walk
class NormalWalk : public WalkableRobot{
    public: 
        void walk() override{
            cout<<"Walking normally.."<<endl;
        }
};

class NoWalk : public WalkableRobot{
    public: 
        void walk() override{
            cout<<"Cannot Walk.."<<endl;
        }
};

// Strategy Interface for Talk
class TalkableRobot{
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

// Concrete Strategies for Talk
class NormalTalk : public TalkableRobot{
    public: 
        void talk() override{
            cout<<"Talking normally.."<<endl;
        }
};

class NoTalk : public TalkableRobot{
    public: 
        void talk() override{
            cout<<"Cannot Talk.."<<endl;
        }
};

// Strategy Interface for Fly
class FlyableRobot{
    public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

// Concrete Strategies for Fly
class NormalFly : public FlyableRobot{
    public: 
        void fly() override{
            cout<<"Flying normally.."<<endl;
        }
};

class NoFly : public FlyableRobot{
    public: 
        void fly() override{
            cout<<"Cannot Fly.."<<endl;
        }
};

// Robot base class
class Robot{
    private:
        WalkableRobot* walkBehavior;
        TalkableRobot* talkBehavior;
        FlyableRobot* flyBehavior;

    public:
        Robot(
            WalkableRobot* walkBehavior,
            TalkableRobot* talkBehavior,
            FlyableRobot* flyBehavior
        ) : 
        walkBehavior(walkBehavior),
        talkBehavior(talkBehavior),
        flyBehavior(flyBehavior)
        {}

        void walk(){
            walkBehavior->walk();
        }        
        void talk(){
            talkBehavior->talk();
        }
        void fly(){
            flyBehavior->fly();
        }

        virtual void projection() = 0;
};

// Concrete Robot Types
class CompanionRobot : public Robot{
    public:
        CompanionRobot(
            WalkableRobot* walkBehavior,
            TalkableRobot* talkBehavior,
            FlyableRobot* flyBehavior
        ) : Robot(walkBehavior, talkBehavior, flyBehavior) {}

        void projection() override{
            cout<<"Displaying Friendly Companion Features...\n";
        }
};

class WorkerRobot : public Robot{
    public:
        WorkerRobot(
            WalkableRobot* walkBehavior,
            TalkableRobot* talkBehavior,
            FlyableRobot* flyBehavior
        ) : Robot(walkBehavior, talkBehavior, flyBehavior) {}

        void projection() override{
            cout<<"Displaying Worker efficiency stats...\n";
        }
};

int main() {
    Robot* robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());

    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout<<"-------------------------\n";

    Robot* robot2 = new WorkerRobot(new NormalWalk(), new NoTalk(), new NormalFly());

    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}