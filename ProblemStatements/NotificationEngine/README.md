# Notification Engine

## Funcitonal and Non Functional Requirement
![alt text](image.png)

## Start UML 
- Notification (abstract) class - child : Simple Notification (getContext(), sms)
- use Decorator to Decorate Notification dynamically
- Concrete Decorator : signatureDecorator, TimeStampDecorator
- Notification Service will send notificaiton to observable
- Observable : vector<Observer> , add(), remove(), notify
- ConcreteObservable : getNotification(), setNotification(), INotification
- Observer : update()
- ConcreteObserver : Logger, NotificationEngine (1-many with notificationstrategy)
- NotificationStrategy 
- NotificationService : singleton class because we don't need multiple history

## UML
```mermaid
classDiagram
class Notification{ 
 <<abstract>>
    getContent()
}
Notification <|-- SimpleNotification : is-a
class SimpleNotification{
    String text
    getContent()
}

class NotificationDecorator{
 <<abstract>>
 Notification notification
 getContent()
}

Notification <|-- NotificationDecorator: is-a
Notification o-- NotificationDecorator: has-a

class TimeStampDecorator{
 getContent()
}

class SignatureDecorator{
 getContent()
}

NotificationDecorator <|-- TimeStampDecorator : is-a
NotificationDecorator <|-- SignatureDecorator : is-a

class NotificationService{
 <<singleton>>
 vector<Notification> notifications
 NotificatoinObservable notiObservable
 sendNotificatoin()
}

NotificationService o-- Notification: has-a
NotificationService o-- NotificatoinObservable: has-a

class Observable{
 vector<Observer> observers
 add(Observer observer)
 remove(Observer observer)
 notify()
}

class NotificatoinObservable{
 vector<Observer> observers
 Notification notification
 add(Observer observer)
 remove(Observer observer)
 setNotification(Notification notification)
 getNotification(Notification notification)
}

Observable <|-- NotificatoinObservable: is-a

class Observer{
 update()
}

class Logger{
 NotificatoinObservable notifiObservable
 update()
}

class NotificationEngine{
 NotificatoinObservable notifiObservable
 vector<NotificationStrategy> ntStrategies
 update()
}

Logger o-- NotificatoinObservable : has-a
NotificationEngine o-- NotificatoinObservable  : has-a

Observer <|-- Logger : is-a
Observer <|-- NotificationEngine : is-a

class NotificationStrategy{
 <<abstract>>
 sendNotification(String content)
}

NotificationEngine o-- NotificationStrategy : has-a

class EmailStrategy{
 sendNotification(String content)
}

class SmsStrategy{
 sendNotification(String content)
}

class PopupStrategy{
 sendNotification(String content)
}

NotificationStrategy <|-- EmailStrategy
NotificationStrategy <|-- SmsStrategy
NotificationStrategy <|-- PopupStrategy
```