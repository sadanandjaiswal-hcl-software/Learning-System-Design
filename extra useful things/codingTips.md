# Software Design – Personal Handbook (Quick Reference)

> Purpose: Write clean, extensible, readable code without overengineering.

---

## 1. Core Design Mindset

- **Design patterns are tools, not goals**
- Never start with a pattern  
  → Start with a **problem / pain**
- Good design = **change is localized and predictable**

> Build → Feel pain → Refactor → Name the solution

---

## 2. Before Using Any Design Pattern, Ask

- What is **changing**?
- How often does it change?
- Who owns the change?
- What breaks when it changes?

If you can’t answer these → **don’t apply a pattern yet**

---

## 3. Strategy Pattern – When to Use

### Use Strategy when:
- Behavior varies (not data)
- `if-else / switch` represents **different algorithms**
- You want to change behavior **without modifying the context**
- Behavior may change independently in the future

### Do NOT use Strategy when:
- Only one implementation exists
- Behavior will never change
- Logic is trivial and stable

> Strategy = Replace conditional behavior with polymorphism

---

## 4. Strategy Pattern – Mental Model

- **Context**: Stable class that uses behavior
- **Strategy Interface**: Defines what varies
- **Concrete Strategies**: Different implementations of behavior

> Behavior changes, context stays stable

---

## 5. Map vs Strategy (Important Distinction)

- **Map** = lookup mechanism
- **Strategy** = behavior ownership

Use:
- Map only → for tiny, stable logic
- Strategy → when behavior grows, needs testing, or evolves
- Map + Strategy → production-grade systems

> Removing `if-else` is NOT the goal  
> Owning behavior correctly IS the goal

---

## 6. Naming Guidelines (Very Important)

### Classes
- Name by **responsibility**, not pattern  
  ❌ `StrategyNotificationService`  
  ✅ `NotificationService`

### Interfaces
- Represent **capability / role**  
  ✅ `NotificationSender`, `PaymentProcessor`

### Methods
- Read like English  
  ❌ `sendNotification()`  
  ✅ `notifyUser()`

> If code reads like a sentence, naming is good

---

## 7. Interface & Override Rules (Java)

- Interface methods are **implicitly public**
- Omitting `public` in interfaces is idiomatic
- Always use `@Override` in implementations

> `@Override` is not optional in professional code

---

## 8. Avoid These Design Smells

- Magic strings (`"email"`, `"sms"`)
- God classes
- Flags controlling behavior
- Pattern names in class names
- Premature abstractions

Prefer:
- Enums
- Composition
- Clear ownership of behavior

---

## 9. Open–Closed Principle (Practical View)

- OCP is **not binary**
- Some controlled violations are acceptable
- Goal is to **contain change**, not eliminate it

> Change should touch **one place**, not many

---

## 10. Senior Engineer Rule of Thumb

- Simple > Clever
- Explicit > Implicit
- Readability > Shortness
- Stability > Over-abstraction

> Write code for the next engineer — not for the compiler

---

## 11. Learning Rule (Non-Negotiable)

- Never learn patterns in isolation
- Always apply on:
  - A small example OR
  - A real project

If you can’t explain **why** you used it → you didn’t learn it

---

## 12. Final Reminder

> Patterns help you manage change  
> They don’t replace thinking

---
