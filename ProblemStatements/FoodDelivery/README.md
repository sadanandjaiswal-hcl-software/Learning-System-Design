# Food Delivery

## Functional Requirements
- User can serach for restaurants based on location
- user can add items to cart
- user can checkout by making payment
- user should be notified once order i splaced successfully

## Non Functional Requirement
- Each part of design should be scalable and modifiable

## Happy Flow
- User Login to App
- List of Restaurants will be visible to user
- User select one restaurant
- Menu of that Restaurant will be visible to user
- User Place Items to Cart
- Do Payment
- Notificaiton will be sent to user for successful order

**Note** : Ask Interviewer:

Type of Order : `Delivery` only or `PickUp` also

Actor: Only `User` Centric or `Delivery Agent` also, i.e Functionality for user to place order or agent to know which restaurant order is where to deliver, etc

## UML Designing
- First lets start with Restaurant creation, what restaurant will have : `id`, `name`, `address`, `Menu`
- Menu will have MenuItem which will be object it self, so lets make that first
- MenuItem: `code`, `name`, `price` this will be model class
- Restaurant 'has-a' Menu (1 to many) , MenuItem is not independent to Restaurant (for this question but it can be) so it is strict composition relationship
- RestaurantManager : perform CRUD on Restaurant and search List of Restaurant based on Locaiton
- RestaurantManager has a Restaurant but Restaurant can live without RestaurantManager 
- Cart has Restaurant (1) and MenuItem (many)
- User have Cart and cart is dependent on User : string composition relationship

- We will use Strategy design pattern for Payment
- after successful payment order will be created

- Single point of contact to manage Order : OrderManager - create, saveToDB, etc

- **Modal Classes** : `Restaurant`, `MenuItem`, `User`
- **Singleton** : `RestaurantManager` , `OrderManager`

```mermaid
classDiagram
direction TD
class RestaurantManager{
    -restaurants : vector<Restaurant>
    +crudOperations()
    +searchByLocatoin()
}

RestaurantManager o.. Restaurant : "has-a"

class MenuItem{
    -code : int
    -name : string
    -price : double
}

class Restaurant{
    -id : long
    -name : string
    -address : string
    -menu : vector<MenuItem>
}

MenuItem "*" ..* "1" Restaurant


class User{
    -id : long
    -name : string
    -address : string
    -cart : Cart
}

User *.. Cart : "has-a"

class Cart{
    -restaurant : Restaurant
    -items : vector<MenuItem>
    -totalPrice : double
    +addToCart()
    +removeFromCart()
    +totalPrice()
    +clear()
    +isEmpty()
}

Cart "1" o.. "1" Restaurant 
Cart "1"o.. "*"MenuItem

class OrderManager{
    orders : vector<Order>
    +addOrder()
}

OrderManager "1" o-- "*"Order : "has-a"

class NotificationService{
    +notify(Order)
}

Order --> NotificationService : "has-a"

class Order{
    -id : long
    -restaurant : Restaurant
    -items : vector<MenuItem>
    -user : User
    -paymentStrategy : PaymentStrategy
    +getType()

}

Order o..  User: "has-a"
Order o..  Restaurant: "has-a"
PaymentStrategy ..o Order : "has-a"
Order o..  MenuItem: "has-a"

class Delivery{
    +getType()
}

class PickUp{
    +getType()
}

Delivery--> Order 
PickUp--> Order 

class PaymentStrategy{
    pay()
}

PaymentStrategy <-- NetBanking : "is-a"
PaymentStrategy <-- UPI : "is-a"
PaymentStrategy <-- CreditCard : "is-a"

class NetBanking{
    pay()
}
class UPI{
    pay()
}
class CreditCard{
    pay()
}


class OrderFactory{
    <<interface>>
    +createOrder(type)
}

OrderFactory <-- NowOrderFactory
OrderFactory <-- ScheduleOrderFactory

class NowOrderFactory{
    +createOrder()
}

class ScheduleOrderFactory{
    +createOrder()
}
NowOrderFactory ..> Order : create
ScheduleOrderFactory ..> Order : create
```

![alt text](image.png)


## Extra
- **Model Class** : Simple class that have only attributes and Getter Setter, no functionality

- **Mangers** are Singleton Class