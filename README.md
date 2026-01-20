# System Design

## OOPs
- Procedural Programming lacks: a) Real World Modeling b) Data Security c) Highly Scalable / Reusable

- **Objects have**: a) characteristics b) behaviours

- **oops**: real world objects interact

- **Encapsulation**: focus on Data Security
- **Abstraction**: focus on Data hiding, showing only the necessary part

## Solid Principles

### Problem Arries when SOLID Principles not followed
- Maintability : If want to introduce new feature so it should be easily available to introduce without affecting the earlier code 
- Readebility : Easiy to read and understand
- BUGs 

**SOLID (stand for)**
1. **S –** Single Responsibility Principle

2. **O –** Open-Closed Principle

3. **L –** Liskov Substitution Principle

4. **I –** Interface Segregation Principle

5. **D –** Dependency Inversion Principle

## Principle of Least Knowledge
every class should talk to its immidiate friend not to friend of friend

<br>
<br>

# Design Patterns

## 1. Strategy Design Pattern
**Defination** : Define family of algorithms, put each one in seperate class, and make them interchangeable at runtime.

- Abstract what varies.
- Client choose which algorithm to use at runtime
- Follow Open-Close Principle

**Key Idea**: Same task, different ways of doing it!

**Example**: Sorting Algorithm, Payment Methods(credit card, upi, netbanking)



## 2. Factory Method
**Defination**:  Define a interface for creating object but allow subclass or logic to decide which class to instantiate / create

- Encapsulate object creation logic
- Reduce tight coupling
- client don't know about the concrete class
- Return one product

**Key Idea**: Lets factory to decide which object to create

**Example**: NotificationService, Creating Shapes



## 3. Abstract Factory Method
**Defination**: Provides an interface for creating families of related object, without specifying their concrete class

- Factory of factories
- Ensure compatibility between products
- Strongly support consistency

**Key Idea**: Create related object when they are ment to work together

**Example**: UI themes (Button + checkbox for windows and mac)



## 4. Singleton Design Pattern
**Defination**: It ensure that a class has only one instance, and provide a global access to it.

- One and only one object
- Private constructor
- controlled object creation
- Must handle thread safety

**Key Idea**: Only One instance should exist

**Example**: Configuration Manager, Database Connection, Logger



## 5. Observer Design Pattern
**Defination**: Define One to Many relationship between objects, so that when one object change state, all of its dependents are notified and updated automatically

- Subject & Observer
- Event driven design

**Key Idea**: Notify all listeners when something changes

**Example**: Event listeners, Stock price update

**Note**: Observer pattern works well in small systems.
At scale, we replace it with event-driven Pub-Sub using Kafka or similar systems.


## 6. Decorator Design Pattern
**Definition**: Decorator Pattern attaches additional responsibilites to an object dynamically, Decorator provides a flexible alternative to subclassing for extending functionality.

- Uses composition instead of inheritance
- Adds responsibilities at runtime
- Avoids subclass explosion
- Supports multiple combinations of behaviors

**Key Idea**: Wrap an object to add new behavior

**Example**: 
- Text formatting (Bold, Italic, Underline)
- Notification system (Logging, Encryption, Retry, Rate Limiting)


## 7. Command Design Pattern
**Definition**: Command Pattern encapsulates a request as an object, thereby allowing you to parameterize clients with different requests, queue or log requests, and support undo/redo operations.

- Encapsulates an action/request as an object
- Decouples the sender (Invoker) from the receiver
- Uses composition instead of direct method calls
- Enables undo/redo, logging, and request queuing
- Allows runtime binding of actions to invokers

**Key Idea**: Represent an action as an object and execute it via an invoker

**Core Participants**:
- **Command** – declares execution interface (`execute()`, optional `undo()`)
- **ConcreteCommand** – binds a receiver and implements action
- **Receiver** – performs actual business logic
- **Invoker** – triggers command execution
- **Client** – creates and wires commands with receivers

**Example**:
- Remote control (Button → Command → Appliance)
- Menu / toolbar actions in editors
- Job queues and task schedulers
- Transactional operations with undo/redo
- Ticket/SLA actions (`CloseTicketCommand`, `RecalculateSlaCommand`)

**When to Use**:
- Actions need to be decoupled from callers
- Undo/redo or rollback is required
- Commands must be queued, logged, or retried
- UI actions (buttons, menus) trigger business logic

**When NOT to Use**:
- Only one simple action exists
- No undo/redo, logging, or variation needed
- Direct method call is sufficient (avoid over-engineering)

**Common Combinations**:
- **Command + Memento** → undo/redo with state restoration
- **Command + Composite** → macro commands
- **Command + Queue** → async job processing

**Key Difference**:
- **Command vs Strategy** → Command represents *what action to perform*, Strategy represents *how to perform an algorithm*
