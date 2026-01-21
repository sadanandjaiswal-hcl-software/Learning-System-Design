# Principle of Least Knowledge

Class should only interact with there or there immediate friend / child / parent method.

## Rule
- Call there method
- Call methods of Class passed as parameter to any method of there own class
    - Example: Class A{m1(), m2(), m3(B* b)}, Class B{m4(), m5()}
    - A* a = new A(); --> a.m1(), a.m2(), a.m3(b){b.m4, b.m5}
- Call method of Class whose object is created by its method
    - Example : class A(m1(){B* b = new B()})
    - can use b.m4(), b.m5()
- Call method of Class which are has-a relationship to that class
    - Class A{has-a : B, C, D}
    - b.m3(), c.m7(), d.m8()

- Don't
    - Class A() --> Class B() --> Class C()
    - a->b->c->m8()