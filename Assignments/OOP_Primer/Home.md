## A05

- Name: Angel Badillo
- Date: 26 Nov 2021
- Class: 2143 OOP

## Definitions

#### Abstraction
> Abstraction is the concept of only providing the most prominent, defining data or attributes to users, but not revealing the implementation or the information not necessary to the users. A good way to think of it is that the average person knows that a light switch, when flipped to the ON position, will provide power to a lamp, light bulb, etc. but would not know exactly how the whole circuit is wired. To use properly wired lamp, all a user needs is to have access to the light switch, and how to flip it.
>
><img src="https://image.slidesharecdn.com/tiny-house-design-and-construction-guide-sample-150404185316-conversion-gate01/95/tiny-housedesignandconstructionguidesample-12-638.jpg?cb=1428173639" width=250>
>
> Sources: 
> 
> https://www.geeksforgeeks.org/abstraction-in-c/#:~:text=Abstraction%20in%20C%2B%2B.%20Data%20abstraction%20is%20one%20of,displaying%20only%20essential%20information%20and%20hiding%20the%20details.
> 
> https://image.slidesharecdn.com/tiny-house-design-and-construction-guide-sample-150404185316-conversion-gate01/95/tiny-housedesignandconstructionguidesample-12-638.jpg?cb=1428173639

```c++
class Lamp
{
private:
/* code */
public:
/* other methods */
    void on() {/* code */}
    void off() {/* code */}
};

/* When a user calls Lamp::on or Lamp::off on an object of type Lamp, the user does not need to know how it is coded,
   the user simply needs to know what it does overall. */
```

#### Attributes / Properties
> Attributes, in C++ 11 and onward, are meant to "annotate C++ constructs" (E.g. classes, structs, functions, variables, etc.) with more constraints or information. The compiler uses the additional information or contstraints to send out helpful messages, such as warning messages to ensure the constructs are being used correctly. In Object-Oriented Programming, the terms "attributes" and "properties" refer to the data pertaining to a class or structure (I.e data members, class variables, instance variables) that are operated on by methods (functions) in said class or structure.
>
><img src="https://study.com/cimages/multimages/16/9679ceaf-0c2a-4209-8ed5-4b107ab1c634_class.png" width=250>

> Sources:
>  
> https://docs.microsoft.com/en-us/cpp/cpp/attributes?view=msvc-170
> 
> https://www.tutorialspoint.com/What-is-object-oriented-programming-OOP
> 
> https://study.com/cimages/multimages/16/9679ceaf-0c2a-4209-8ed5-4b107ab1c634_class.png
```c++
class Car
{
protected:
    /* Attributes / Properties of Car class */
    string vin;
    string make;
    string model;
    int year;
public:
    /* Methods of Car Class */
    Car();
    ~Car();
    void setVIN(string vin);
    void setMake(string make);
    void setModel(string model);
    void setYear(int year);
    string getVIN();
    string getMake();
    string getModel();
    int getYear();
    
};
```

#### Class
> A class is a data type that encapsulates data and the functions *(methods)* that manipulate them, together. Classes have access levels *(e.g: private, protected, public)* that can limit what can be accessed and manipulated outside of the class. Classes do not allocate memory by just being defined. However, an instance of a class, or object, does allocate memory.
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>
>
> Sources:
>  
> https://docs.microsoft.com/en-us/cpp/cpp/classes-and-structs-cpp?view=msvc-170
> 
> https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png
```c++
#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string vin;
    string make;
    string model;
public:
    Car(string vin, string model, string make);
    string getVIN();
    string getMake();
    string getModel();
    void setVIN(string vin);
    void setMake(string make);
    void setModel(string model);
};

int main()
{
    Car sportsCar("4DoorsMoreChores", "Challenger", "Dodge");
    sportsCar.setVIN("4DoorsMoreScores");  // Modifies sportsCar.vin
    cout << sportsCar.getVIN();            // Output: 4DoorsMoreScores
    Car momCar("37DSAGD237", "Mustang", "Ford");
    string momCarBrand = momCar.getMake(); // Sets momCarBrand to momCar.make, "Ford"
}
```

#### Class Variable
> A class variable is a static variable declared within a class. Class variables are shared among all instances of a class (object). It cannot be accessed by object name, rather it is accessed by class name followed by scope resolution operator and variable name. Class variables are contructed when the program executes and destructed when the program finishes executing.
>
><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png" width=250>
>
> Sources:
> https://www.geeksforgeeks.org/variables-in-c/
> 
> https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png
```c++
class Person
{
private:
    int ssn; // Instance variable
    static string species; // Class variable
public:
    static string name;    // Class variable
    /*other methods */

    static string getSpecies() {return species;}
};

string Person::species = "Homo-sapien"; // All instances will share species with value of "Homo-Sapien".
string Person::name = "Kyle";           // All instances will share name with value of "Kyle".
```

#### Composition
> Composition is the idea of building a complex class or structure from other simpler classes or structures. For something to qualify as being composition, the object must "know" about the component but not the other way around, the component must be declared in the class, and "the object must manage the existence of the component. In a general sense, the "has-a" relationship is modeled by composition. A controller is composed of buttons and other components, in other words a controller "has-a" button (well, it has 1 or more buttons), thus that qualifies as composition. 
> 
><img src="https://i5.walmartimages.com/asr/5fb0a05f-4eba-45f8-bdb7-f5a09ad5fdce_1.93e794bbf9fd3b958ce48531356090b2.jpeg" width=350>
>
> Sources:
> 
> https://www.learncpp.com/cpp-tutorial/composition/
> 
> https://i5.walmartimages.com/asr/5fb0a05f-4eba-45f8-bdb7-f5a09ad5fdce_1.93e794bbf9fd3b958ce48531356090b2.jpeg
```c++
class Button
{
    /* code */
};

class Controller
{
private:
    Button L; // Controller is composed of buttons
    Button R;
    Button X;
    Button Y;
    Button B;
    Button A;
    
    /* other buttons and components */
public:

    /* methods */
};
```

#### Constructor
> A constructor is a function (method) in a class that intializes it's member variables. The constructor has the same name as the class, but it does not have a return type. The three main types of constructors are: default constructor (not parameterized), parameterized constructor, and copy constructor. A default constructor has no parameters and is used to assign default values to member variables. A parameterized constructor is used to assign specific values to member variables via arguments passed in when the constructor is called. A copy constructor creates a copy of another instance of a class. In modern C++, a copy constructor automatically is generated, however, it performs a shallow copy, which could cause issues when member variables are pointer types.
> 
><img src="https://prepinsta.com/wp-content/uploads/2021/10/custom-%E2%80%93-1@2x16-1.webp" width=250>
>
> Sources:
> 
> https://docs.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=msvc-170
> 
> https://prepinsta.com/wp-content/uploads/2021/10/custom-%E2%80%93-1@2x16-1.webp
```c++
class Person
{
private:
    string name{""};
public:
    Person(){}                         // Default constructor
    Person(string name): name(name) {} // Parameterized constructor
    Person(Person &other) 
    {
        if(this != &other)             // Copy Constructor
        this->name = other.name; 
    }
};
```

#### Encapsulation
> Encapsulation is the wrapping of the functions that operate on a set of data with the aforementioned data in a single component (such as a class or structure). Encapsulation is meant to conceal implementation and hide an objects data by limiting access to it to member's of its class or structure. In other words, often an objects data will not be directly mutable or accessable, but it can be modified or returned via methods in its class or structure.
> 
><img src="https://media.geeksforgeeks.org/wp-content/uploads/Encapsulation-in-C-1.jpg" width=250>
>
> Sources: 
> 
> https://www.geeksforgeeks.org/encapsulation-in-c/
>
> https://media.geeksforgeeks.org/wp-content/uploads/Encapsulation-in-C-1.jpg

#### Friends
> The C++ keyword, <code>friend</code>, is used in a class/structure definition to give "member-level access" to a class, structure, or function that is not a member of the aforementioned class or structure.
>
> <img src="https://blog.kakaocdn.net/dn/c0aUps/btqFpLcrseg/FQ5a4qgvYC7daRedgkqEO0/img.png" width=250>
> 
> Sources: 
> 
> https://docs.microsoft.com/en-us/cpp/cpp/friend-cpp?view=msvc-170
> 
> https://blog.kakaocdn.net/dn/c0aUps/btqFpLcrseg/FQ5a4qgvYC7daRedgkqEO0/img.png
```c++
class Person
{
private:
    int ssn;
protected:
    string address;
public:
    string name; 
    Person(string name, int ssn, string address);
    ~Person();
    friend class FaceBook; // Introduces Facebook Class but doesn't define it.
                           // FaceBook class has access to Person class's private/protected members.
};

class FaceBook
{
public:
    vector<Person> users;
    FaceBook();
    ~FaceBook();
    int getSSN(Person &user);        // Returns ssn attribute of Person object.
    string getAddress(Person &user); // Returns address attribute of Person object.
};
```

#### Inheritance
> Inheritance is the concept of deriving members from one class or structure and applying them to another class or structure. A derived class inherits members from another class, and the class that is being inherited from is called the base class. Inheritance can also be done in different modes. See [Public/Private/Protected](#public--private--protected). A very simple example would that there is a Vehicle class, and taking into account different types of vehicles operate differently to some extent, there would be a derived class for each one, such as a Bus class, Car class, and Truck class. Each derived class could have more members on top of what was inherited, or the derived classes could have different implementations for existing methods  in the base class.
> 
> <img src="https://media.geeksforgeeks.org/wp-content/uploads/inheritance2.png" width=350>
>
> Sources: 
> 
> https://www.geeksforgeeks.org/inheritance-in-c/#:~:text=Inheritance%20in%20C%2B%2B%201%20Single%20Inheritance%3A%20In%20single,from%20another%20derived%20class.%20...%20More%20items...%20
> 
> https://media.geeksforgeeks.org/wp-content/uploads/inheritance2.png
```c++
class Vehicle
{
protected:
    string vin;
    int fuel;
    int capacity;
public:
    /* Constructors and destructors here */

    virtual void applyBrakes() = 0; // Pure virtual function
};

class Bus: public Vehicle
{
private:
    int wheelAmount;
public:
    /* Constructors and destructors */

    void applyBrakes override() // Overides pure virtual function
    {
        /* code */
    }
};
```

#### Instance Variable
> An instance variable is non-static variable declared within a class. Each object instantianted from the class has it's own copy of the variable, meaning altering the variable in once instance does not modify it in the rest. An instance variable of an object is created when the object is instantiated, and it is destroyed when the object goes out of scope. Instance variables are accessed by the name of the object followed by the dot operator and name of the variable, whereas class variables are accessed by class name followed by the scope resolution operator and name of the variable.
> 
><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png" width=250>
>
> Sources:
> 
> https://www.geeksforgeeks.org/variables-in-c/
> 
> https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png
```c++
#include <iostream>
#include <string>
using namespace std;

class TikTokUser
{
private:
    string user_name; // Instance variable

    /* other variables */
public:
    string name;     // Instance variable

    /* other methods */

    /* Alters user_name for a specific object */
    void setUsername(string userName) { user_name = userName; }
    string getUsername(){ return user_name; }
};

int main()
{
    TikTokUser u364698;
    u364698.name = "Wridden HyleKouse"; // Value of u364698.name is now "Wridden HyleKouse"
    u364698.setUsername("4DoorsMoreScores"); // Value of u364698.user_name is "4DoorsMoreScores"
    cout << u364698.getUsername(); // Output: 4DoorsMoreScores
}
```

#### Member Variable
> A member variable is a variable declared within a class. It can either be an instance variable or class variable. See [Instance Variable](#instance-variable) and [Class Variable](#class-variable) for more information.
> 
><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png" width=250>

> Sources:
> 
> https://www.geeksforgeeks.org/encapsulation-in-c/https://www.geeksforgeeks.org/encapsulation-in-c/
> 
> https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png
```c++
class Person
{
private:
    int ssn;               // Instance variable
    static string species; // Class variable
public:
    static string name;    // Class variable
    
    /* methods */
};
```

#### Method
> A method (member function) is an operation or procedure that pertains to a set of data (member variables) and operates on said data. In C++, a method is a function defined within a class or structure that can access or modify member variables within the class or structure.
> 
><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/Classes-and-Objects-in-C.png" width=250>
>
> Sources:
> 
> https://www.geeksforgeeks.org/methods-vs-functions-in-c-with-examples/
> 
> https://media.geeksforgeeks.org/wp-content/cdn-uploads/Classes-and-Objects-in-C.png
```c++
class Student
{
private:
    string name{""};
public:
    /* All of these below are methods */
    Student() {}
    Student(string name): name(name){}
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};
```

#### Multiple Inheritance
> Multiple Inheritance is where a derived class inherits from two or more base classes. See [Inheritance](#inheritance) for information on simple inheritance.
> 
><img src="https://media.geeksforgeeks.org/wp-content/uploads/multiple-inheritance.png" width=350>
>
> Sources:
> 
> https://www.geeksforgeeks.org/inheritance-in-c/#:~:text=Inheritance%20in%20C%2B%2B%201%20Single%20Inheritance%3A%20In%20single,from%20another%20derived%20class.%20...%20More%20items...%20
> 
> https://media.geeksforgeeks.org/wp-content/uploads/multiple-inheritance.png
```c++
class A
{
    /* code */
};

class B
{
    /* code */
};

class C: public A, public B // Class inherits from both class A and class B
{
    /* code */
};
```

#### Object
> An object is an instantiation of a class or structure. See [Class](#class) for more information on classes. Objects allocate memory when declared, while a class is just a "template" for creating objects. A way of thinking about it is that the class simply defines what the object will be like, but the object itself has state and is mutable during runtime while a class is not.
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>
>
> Sources:
> 
> https://www.geeksforgeeks.org/c-classes-and-objects/
> 
> https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png
```c++
class TikTokUser // Class definition + implementation
{
private:
    string user_name{""};
public:
    TikTokUser(){}
    TikTokUser(int userName): user_name(userName) {}
    void setUser(int userName) { user_name = userName; }
    string getUser() { return user_name; }
};

int main()
{
    TikTokUser kyle("4DoorsMoreScores");             // Object
    TikTokUser legend27("NotLegend_27");             // Object
    TikTokUser msu_spanishClub("msu.spanish.club");  // Object
}
```

#### Overloading
> Function overloading is giving functions the same name, but giving them different parameters and implementing them to perform similar tasks with slight variation. Operator overloading is similar. Overloaded operators are implemented as functions, which are meant to provide "meaning" to operators when used among instances of a class. For example, the + operator is overloaded for std::string so strings can be concenated 
> 
><img src="http://www.trytoprogram.com/images/cpp-function-overloading.jpg" width=550>
>
> Sources:
> 
> https://docs.microsoft.com/en-us/cpp/cpp/function-overloading?view=msvc-170
> 
> https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170
> 
> http://www.trytoprogram.com/images/cpp-function-overloading.jpg
```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(int x)
{
    cout << x << '\n';
} 

void print(string s)
{
    cout << s << '\n';
}

void print(vector<char> &c)
{
    for( char i : c) // For-each loop
    cout << i << ' ';

    cout << '\n';
}

/* Counts as operator overloading, technically. A bit unnecessary, however. */
bool operator==(const string &s, const char &c)
{
    if((s.length() == 1) && (s[0] == c))
    return true;
}

/* Overloading both ways... */
bool operator==(const char &c, const string &s)
{
    if((s.length() == 1) && (s[0] == c))
    return true;
}

int main()
{
    int num = 4;
    string userName = "4DoorsMoreScores";
    vector<char> letters{'4','D','O','O','R','S'};
    print(num);      // Output: 4
    print(userName); // Output: "4DoorsMoreScores"
    print(letters);  // Output: '4' 'D' 'O' 'O' 'R' 'S'
    string s = "C";
    char c = 'C';
    bool isEqual = (s == c);
    cout << isEqual; // Output: 1
}
```

#### Polymorphism
> The exact definition of polymorphism is "many-shaped". In programming, polymporphism is when a construct is able to take more than one form. In C++, there is run-time polmorphism and compile-time polymorphism. Templates, function overloading, and operator overloading are all examples of compile-time polypmorphism. The type used in a templated class or function, the different sets of parameters a function can take, and the different behaviors of operators, are all defined at compile-time. Function ovveriding and virtual functions, however, are examples of run-time polymorphism. This occurs when a derived class has a different implementation of a function defined in the base class, and overrides it. VIrtual functions are resolved at run-time.
> 
><img src="https://media.geeksforgeeks.org/wp-content/uploads/20200703160531/Polymorphism-in-CPP.png" width=350>
>
> Sources:
> 
> https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/object-oriented/polymorphism
> 
> https://docs.microsoft.com/en-us/cpp/cpp/override-specifier?view=msvc-170
> 
> https://www.geeksforgeeks.org/polymorphism-in-c/
> 
> https://media.geeksforgeeks.org/wp-content/uploads/20200703160531/Polymorphism-in-CPP.png
```c++
class  A
{
protected:
    /* code */
public:
    virtual void print();
    void print(int x);             // Overloads print method
};

class B: public A
{
private:
    /* code */
public:
    virtual void print() override; // Overrides print method
};
```

#### Public / Private / Protected
> In C++, the keywords <code>public</code>, <code>private</code>, and <code>protected</code> are access specifiers. Access specifiers limit what what members can be accessed in a class externally, and also specify how a derived class will inherit from a base class. Private only allows methods and friends of the class to access the members, protected only allows methods, friends, and derived classes of a class to access the members, and public allows anything to access the members.
> 
><img src="https://cdn.educba.com/academy/wp-content/uploads/2019/11/Access-Modifiers-in-C.png.webp" width=350>
>
> Sources:
> 
> https://docs.microsoft.com/en-us/cpp/cpp/member-access-control-cpp?view=msvc-170
> 
> https://cdn.educba.com/academy/wp-content/uploads/2019/11/Access-Modifiers-in-C.png.webp
```c++
class TikTokUser
{
protected:
    vector<string> rights; // These two are accessible by
    string user_name;      // friends, class methods, and derived classes
private:
    string address;        // Only accessible by friend or class methods
public:
    string name;           // Accessible anywhere

    /* Constructors and destructor */

    void setAddress(string address);
    string getAddress();
};

class Court: public TikTokUser
{
public:
    /* code */

   void setUser(string user_name);
   string getUser(); 
};

int main()
{
    TikTokUser kyle;
    kyle.name = "Ryle HittenKrouse";
}
```

#### Static
> In C++, the <code>static</code> keyword is used to declare or define variables within functions, member variables, and methods that are only intialized once (if a variable) and exist until the execution of the program ends. Static variables within a function are only intialized once but can continue to exist and be modified until the program terminates. A static member variable, or class variable is shared across all instances of a class. See [class variable](#class-variable) for more details. Static member functions, or static methods, can be called even if there is not an instance of the class. The method is called using the name of the class followed by the scope resolution operator and the name of the method.
> 
><img src="https://www.ebhor.com/wp-content/uploads/2020/05/static-variable-min.jpg?x66413" width=350>
>
> Sources:
> 
> https://docs.microsoft.com/en-us/cpp/cpp/static-members-cpp?view=msvc-170
> 
> https://www.geeksforgeeks.org/static-keyword-cpp/
> 
> https://www.ebhor.com/wp-content/uploads/2020/05/static-variable-min.jpg?x66413
```c++
#include <iostream>
using namespace std;

void counter()
{
    static int count = 0;
    cout << count << ' ';
    count++;
}

class MathStuff
{
public:
    static coolNumber;
    static void meaningOfLife()
    {
        cout << "4DoorsMoreChores";
    }
};

int MathStuff::coolNumber{42};

int main()
{
   MathStuff::meaningOfLife() << '\n';    // Output: "4DoorsMoreChores"
   cout << MathStuff::coolNumber << '\n'; // Output: 42

   for(int i = 0; i < 5; i++)
   counter();                             // Output: 0 1 2 3 4
}
```

#### Virtual
> The <code>virtual</code> keyword is used to "declare virtual function or virtual base class". A virtual function can be a method shared between a derived class and a base class. A virtual function may be "a friend function from another class", as well.
> A virtual base class is used to prevent inheritance issues such as the "diamond problem". A virtual base class to prevent the same base class to be inherited from multiple times, so instead virtual inheritance is used.
> 
><img src="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/VirtualFunctionInC.png" width=250>
> 
> <img src="https://media.geeksforgeeks.org/wp-content/uploads/20190312133527/Need-of-Containership-in-C.jpg" width=250>
> 
> Sources:
> 
> https://docs.microsoft.com/en-us/cpp/cpp/virtual-cpp?view=msvc-170
> 
> https://www.geeksforgeeks.org/virtual-function-cpp/
> 
> https://www.geeksforgeeks.org/virtual-base-class-in-c/#:~:text=Virtual%20base%20classes%20are%20used%20in%20virtual%20inheritance,inherited%20by%20two%20other%20classes%20B%20and%20C.
> 
> https://cdncontribute.geeksforgeeks.org/wp-content/uploads/VirtualFunctionInC.png
```c++
// Virtual Function example
class A
{
public:
    virtual void print(); // Allows print to be overriden in derived classes
};

// Virtual base Class example (diamond problem)
class B: public A
{
public:
    virtual void print() override; // Overrides print.
};

class V
{
    /* code */
};

class W: public virtual V
{
    /* code */
};

class X: public virtual V
{
    /* code */
};

class Z: public W, public X
{
    /* code */
};

// No issues, Z would inherit from V only once instead of twice.
```
