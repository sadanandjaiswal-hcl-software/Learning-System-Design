# UML Diagram
1. Structural (Static) : Structure of the applicaiton --> Total **7 Types**
2. Behavioural (dynamic) : how commponent communicate with each other  --> Total **7 Types**

## 1.1 Class Diagram
- class sturcture
- associates / connection

### Structure
```mermaid
classDiagram
class className{
    <<abstract>>
    characteristics - variables
    behaviours() - methods
}

class ExampleCar{
    <<interface>>
    - brand : String
    - model : String
    # engineCC : int

    + startEngine() void
    + stopEngine()  void
    + accelerate()  void
    + brake() void
}
```
#### Access Modifier
- public : `+`
- protected : `#`
- private : `-`

- <<abstract>> , <<interface>>

#### Associations
- Two types : `class association` and `object association`
- `class association` : `inheritance`
- `object association` : `simple association` , `aggregation`, `composition`

##### **a) inheritance** - (is-a) relationship
- Cow is a Animal, Human is a Animal 
- use `arrow` : --|>
```mermaid
classDiagram
Animal <|-- Dog : is-a
Animal <|-- Human : is-a
Animal <|-- Cow : is-a
```

##### **b) composition** - (has-a relationship)
```cpp
class A{
    public:
        auto method1(){}
};
class B{
    private: 
        A* a;

    public:
        B(){
            a = new A();
        }
        auto method2(){}
}
int main(){
    B* b = new B();
    b->method2();
    b->a->method1();    // We call a and then it call method1 : composition
}
```
**note** : In LLD we use composition more than inheritance

###### 1) Simple Association : [-->] 
Exmaple : Arjun lives in house , arjun --> house
```mermaid
classDiagram
House <-- Arjun : has-a
```
###### 2) Aggregatoin : [--<>]
Room is a aggregator : sofa, chair, bed all inside room
<br>
Here `Chair`, `Sofa`, `Bed` are part of `Room` but they can live independently of Room as well
```mermaid
classDiagram
Room o-- Sofa : has-a
Room o-- Chair : has-a
Room o-- Bed : has-a
```

###### c) Composition : [--<> filled diamond]
Class is made of many other subclass and all subclass are dependent of parent class and can't live independently of parent class
```mermaid
classDiagram
Chair *-- Arms : has-a
Chair *-- Wheels : has-a
Chair *-- Seat : has-a
```

#### Mermaid Example
Relationships Covered
| UML Concept | Used                              |
| ----------- | --------------------------------- |
| Inheritance | `Student`, `Professor` ← `Person` |
| Association | `Professor` — `Course`            |
| Aggregation | `Department` o-- `Professor`      |
| Composition | `Course` *-- `Assignment`         |
| Interface   | `Payable`                         |
| Dependency  | `Student ..> Library`             |

```mermaid
classDiagram
    %% Abstract base class
    class Person {
        <<abstract>>
        -int id
        -string name
        +getDetails()
    }

    %% Inheritance
    class Student {
        -int rollNo
        +enroll()
    }

    class Professor {
        -string employeeId
        +teach()
    }

    Person <|-- Student
    Person <|-- Professor

    %% Aggregation
    class Department {
        -string deptName
    }

    Department o-- "1..*" Professor : employs

    %% Association
    class Course {
        -string courseCode
        +startCourse()
    }

    Professor "1" -- "1..*" Course : teaches

    %% Composition
    class Assignment {
        -string title
    }

    Course *-- "1..*" Assignment : contains

    %% Interface
    class Payable {
        <<interface>>
        +calculatePay()
    }

    Professor <|.. Payable

    %% Dependency
    class Library {
        +issueBook()
    }

    Student ..> Library : uses
```



## 2.1 Sequence Diagram
Communication / Interaction between two Object
**Components**
Class (box), Lifeline, Activation Bar
![alt text](assets/Seq-1.png)

**Messages**
Two type: asynchronous, synchronous
<br>
**Synchronous** [--|>]: reuest, wait , response
<br>
**Ashynchronous** [-->] : request, request, request, response, request, .... (don't wait for response)

<br>
**Create Message**
<br>
**Destroy Message**

| Syntax  | Meaning                      |
| ------- | ---------------------------- |
| `->>`   | Synchronous call             |
| `-->>`  | Return message               |
| `-)`    | Asynchronous message         |
| `->>+`  | Call + activate receiver     |
| `-->>-` | Return + deactivate receiver |

```mermaid
sequenceDiagram
    participant Client
    participant API

    %% Synchronous request
    Client->>API: sync request
    activate API
    API-->>Client: response
    deactivate API

    %% Asynchronous message
    Client-)API: async event

    %% Create participant
    Client->>+Worker: create worker
    Worker-->>Client: ready

    %% Loop
    loop Retry up to 3 times
        Client->>Worker: process job
        activate Worker
        Worker-->>Client: result
        deactivate Worker
    end

    %% Conditional logic
    alt Success
        Worker->>Client: notify success
    else Failure
        Worker->>Client: notify failure
    end

    %% Parallel execution
    par In parallel
        Client->>API: log metrics
        Client->>Worker: cleanup
    end

    %% Notes
    Note right of Client: End of flow
```

![alt text](assets/lostFound-2.png)

### Exmaple 
Use Case : User --> ATM --> Transaction --> Cash --> User
<br>
**Steps**:
- User Go to ATM
- Provide Account Detail (Pin, Card, etc)
- ATM create Transactoin
- Transaction get verified
- if Transaction Successful --> Cash Dispenser will be called
- Cash Dispenser provide cash to user

![alt text](assets/seqExampleATM-3.png)