#include <bits/stdc++.h>
#include <format>
using namespace std;

class Notification{
    public:
        virtual string getContent() const = 0;
        virtual ~Notification() {}
};

class SimpleNotification : public Notification{
    private: 
        string text;
    public:
        SimpleNotification(const string& msg) : text(msg) {}
        
        string getContent() const override{
            return text;
        }
};

class NotificationDecorator : public Notification{
    protected:
        Notification* notification;
    public:
        NotificationDecorator(Notification* notification) : notification(notification) {}
        
        virtual ~NotificationDecorator(){
            delete notification;
        }
};

class TimeStampDecorator : public NotificationDecorator{
    public:
        TimeStampDecorator(Notification* n) : NotificationDecorator(n) {}
        
        string getContent() const override{
            auto currentTime = chrono::system_clock::now();
            
            // return "[2026-01-21 12:57:10] " + notification->getContent() + " ";
            return "[" + format("{:%F %T}", currentTime) + "] " + notification->getContent() + " ";
        }
};

class SignatureDecorator : public NotificationDecorator{
    private:
        string signature;
    public:
        SignatureDecorator(Notification* n, const string& sig) : NotificationDecorator(n) , signature(sig) {}
        
        string getContent() const override{
            return notification->getContent() + "\n-- " + signature + "\n\n";
        }
};

class Observer{
    public:
        virtual void update() = 0;
        virtual ~Observer() {}
};

// Observer Design Pattern
class Observable{
    public:
        virtual void addObserver(Observer* observer) = 0;
        virtual void removeObserver(Observer* observer) = 0;
        virtual void notifyObservers() = 0;
};

class NotificationObservable : public Observable{
    private:
        vector<Observer*> observers;
        Notification* currentNotification;
    public:
        NotificationObservable() : currentNotification(nullptr) {}
        
        void addObserver(Observer* observer) override{
                observers.push_back(observer);
        }
        
        void removeObserver(Observer* observer) override{
            observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        }
        
        void notifyObservers() override{
            for(auto observer : observers){
                observer->update();
            }
        }
        
        Notification* getNotification(){
            return currentNotification;
        }
        
        string getnotificationContent(){
            return currentNotification->getContent();
        }
        
        void setNotification(Notification* notification){
            if(currentNotification!=nullptr){
                delete currentNotification;
            }
            currentNotification = notification;
            notifyObservers();
        }
};

class NotificationService{
    private:
        vector<Notification*> notifications;    // history
        NotificationObservable* observable;
        static NotificationService* instance;   // singleton
        
        NotificationService(){
            observable = new NotificationObservable();
        }
    public:
        static NotificationService* getInstance(){
            if(instance==nullptr){
                instance = new NotificationService();
            }
            return instance;
        }
        
        NotificationObservable* getObservable(){
            return observable;
        }
        
        void sendNotification(Notification* notification){
            notifications.push_back(notification);
            observable->setNotification(notification);
        }
        
        ~NotificationService(){
            delete observable;
        }
};


class Logger : public Observer{
    private:
        NotificationObservable* notificationObservable;
    public:
        // Added Default Constructor
        Logger(){
            this->notificationObservable = NotificationService::getInstance()->getObservable();
            notificationObservable->addObserver(this);
        }

        Logger(NotificationObservable* observable) : notificationObservable(observable) {}
        
        void update() override{
            cout<<"Logging new Notification: \n" + notificationObservable->getnotificationContent();
        }
};

// Strategy and Concrete Strategy

class NotificationStrategy{
    public:
        virtual void sendNotification(const string& content) = 0;
};

class EmailStrategy : public NotificationStrategy{
    private:
        string emailId;
    public:
        EmailStrategy(const string& email){
            this->emailId = email;
        }
        void sendNotification(const string& content) override{
            cout<<"Sending Email Notificatoin to: "<<emailId<<endl<<content<<endl;
        }
};

class SmsStrategy : public NotificationStrategy{
    private:
        string mobileNumber;
    public:
        SmsStrategy(const string& mobileNumber){
            this->mobileNumber = mobileNumber;
        }
        void sendNotification(const string& content) override{
            cout<<"Sending Sms Notificatoin to: "<<mobileNumber<<"\n"<<content<<endl;
        }
};

class PopupStrategy : public NotificationStrategy{
    public:
        void sendNotification(const string& content) override{
            cout<<"Sending Popup Notificatoin..\n"<<content<<endl;
        }
};


class NotificationEngine : public Observer{
    private:
        NotificationObservable* notificationObservable;
        vector<NotificationStrategy*> notificationStrategies;
        
    public:
        // Added Default Constructor
        NotificationEngine(){
            this->notificationObservable = NotificationService::getInstance()->getObservable();
            notificationObservable->addObserver(this);
        }

        NotificationEngine(NotificationObservable* observable) : notificationObservable(observable) {}

        void addNotificationStrategy(NotificationStrategy* strategy){
            notificationStrategies.push_back(strategy);
        }
        
        void update() override{
            string notificationContent = notificationObservable->getnotificationContent();
            for(auto strategy : notificationStrategies){
                strategy->sendNotification(notificationContent);
            }
        }
};


NotificationService* NotificationService::instance = nullptr;

int main() {
    NotificationService* notificationService = NotificationService::getInstance();
    
    Logger* logger = new Logger();
    
    NotificationEngine* notificationEngine = new NotificationEngine();
    
    notificationEngine->addNotificationStrategy(new EmailStrategy("user@mail.com"));
    notificationEngine->addNotificationStrategy(new SmsStrategy("+91 1234567890"));
    notificationEngine->addNotificationStrategy(new PopupStrategy());
    
    Notification* notification = new SimpleNotification("Hello World, this is my first notification");
    notification = new TimeStampDecorator(notification);
    notification = new SignatureDecorator(notification, "Customer Care");
    
    notificationService->sendNotification(notification);
    
    delete logger;
    delete notificationEngine;
    
    return 0;
}
