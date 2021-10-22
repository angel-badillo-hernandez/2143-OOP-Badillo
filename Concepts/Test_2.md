# Object-Oriented Programming <br> Test 2

* Hierarchical Inheritance:
> Base class branches out to multiple derived class. <br>
> (E.g, Animal extends to mammal, reptile, amphibian, etc.)
> Another example: Charter => warrior/archer/mage <br><br>
> class A{ }; <br> 
> class B: public A{ }; <br> 
> class C: public A{ }; <br> 
> class D: public A{ };

* Multilevel Inheritance:
> Base class has derived class and further has derived classes <br>
> Parent -> Child -> Grandchild ... etc. <br><br>
> class A{ }; <br> 
> class B: public A{ }; <br> 
> class C: public B{ };

* Multiple Inheritance
> class A{ }; <br> 
> class B{ }; <br> 
> class C: public A, public B{ }; <br>

* Polymorphism
  - Overload / Override / Runtime

* Is-A
  - Inheritance <br><br>
* Has-A
    - Also inheritance <br><br>
* Kind-of
  - ?? <br>

* Abstract Class
  - virtual functions
  - some implementation

* Pure Abstract Class (C++ term)
  - virtual function() = 0;

* Interface
  - class with no implementation at all
  - and no = 0

* What can access private data members or member functions of a class?
  - friend keyword

* What type of data member can be shared by all instances of its class?
  - static member variables

* Base Class vs Derived class
* Parent class vs. Child class
* Inheritance depends on access modifiers

* Run time is dynamic
* Compile time is static

