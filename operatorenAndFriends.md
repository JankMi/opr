# Operatoren, friends und friend-Operatoren

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Operatoren, friends und friend-Operatoren](#operatoren-friends-und-friend-operatoren)
  - [Operatoren überladen](#operatoren-%C3%BCberladen)
    - [Beispiel: Klassen-Element +/- Klassen-Element](#beispiel-klassen-element---klassen-element)
    - [Beispiel: Klassen-Element + int, beidseitig](#beispiel-klassen-element--int-beidseitig)
      - [Bei Sinnvollen operationen](#bei-sinnvollen-operationen)
    - [operatoren: Wann/Wie verwenden?](#operatoren-wannwie-verwenden)
  - [friend](#friend)
    - [friends: Wann/Wie verwenden?](#friends-wannwie-verwenden)
  - [friend-Operatoren:](#friend-operatoren)

<!-- /code_chunk_output -->

## Operatoren überladen
Hinweis: Häufig werden die Abkürzungen lhs und rhs verwendet, für left hand side bzw right hand side. Also links bzw. rechts des Operanden (lhs+rhs).

Die Unterschiede globaler Operatoren und Elementoperatoren am Beispiel der binären Operatoren + und - . Für unäre bzw. ternäre Operatoren ist analog.

Element-Operator + :
- in der Klasse deklariert
  - -> linker Operand muss Objekt der Klasse sein (this innerhalb des Operators)
  - -> nur der zweite Operand muss in der Klammer angeben werden
- Zugriff auf public, protected und private
  
Globaler Operator - :
- außerhalb der Klasse deklariert
  - -> beide Operanden müssen in der Klamemer angegeben werden
  - -> linker Operand kann einen anderen Typ haben
- Zugriff nur auf public 
  
### Beispiel: Klassen-Element +/- Klassen-Element

``` c++
// someclass.h
class SomeClass
{
public:
    SomeClass(std::string value):a(value){}
    std::string getA()const {return a;}

    // Element-Operator
    SomeClass operator+(SomeClass&);
private:
    std::string a;
};

// globaler Operator
SomeClass operator-(SomeClass&, SomeClass&);
```
``` c++
// someclass.cpp
SomeClass SomeClass::operator+(SomeClass& rhs){
    string a_added = a + "+" + rhs.a; //Zugrifff auf private Elemente
    SomeClass returnValue (a_added);
    return returnValue;
}


SomeClass operator-(SomeClass& lhs, SomeClass& rhs){
    string a_subtracted = lhs.getA()+"-"+rhs.getA(); //Zugrifff auf public Funktionen
    SomeClass retValue( a_subtracted);
    return retValue;
}

```

``` c++
//main.cpp
int main()
{
    SomeClass lhs("L");
    SomeClass rhs("R");
    cout << "result = lhs + rhs;"<< endl;
    SomeClass result = lhs+rhs;
    cout << "result.a == "<<result.getA() <<", lhs.a == "<<lhs.getA()<<", rhs.a == "<<rhs.getA()<<endl<<endl<<endl;

    cout<<"result = lhs - rhs;"<<endl;
    result = lhs-rhs;
    cout << "result.a == "<<result.getA() <<", lhs.a == "<<lhs.getA()<<", rhs.a == "<<rhs.getA()<<endl<<endl<<endl;
    return 0;
}
```
```
//output
result = lhs + rhs;
result.a == L+R, lhs.a == L, rhs.a == R


result = lhs - rhs;
result.a == L-R, lhs.a == L, rhs.a == R
```


### Beispiel: Klassen-Element + int, beidseitig

``` c++
// someclass.h
class SomeClass
{
public:
    SomeClass(std::string value):a(value){}
    std::string getA()const {return a;}

    // Element-Operator
    SomeClass operator+(const int);
private:
    std::string a;
};

// globaler Operator
SomeClass operator+(const int, SomeClass&);
```
``` c++
// someclass.cpp
SomeClass SomeClass::operator+(const int rhs){
    string a_added = a + "+" + to_string(rhs);
    SomeClass returnValue (a_added);
    return returnValue;
}


SomeClass operator+(const int lhs,SomeClass& rhs){
    string a_added = to_string(lhs) + "+" + rhs.getA();
    SomeClass returnValue (a_added);
    return returnValue;
}
```

``` c++
//main.cpp
int main()
{
    SomeClass lhs("L");
    SomeClass rhs("R");
    cout << "result = lhs + 1;"<< endl;
    SomeClass result = lhs+1;
    cout << "result.a == "<<result.getA() <<", lhs.a == "<<lhs.getA()<<", rhs.a == "<<rhs.getA()<<endl<<endl<<endl;

    cout<<"result = 1 + rhs;"<<endl;
    result = 1+rhs;
    cout << "result.a == "<<result.getA() <<", lhs.a == "<<lhs.getA()<<", rhs.a == "<<rhs.getA()<<endl<<endl<<endl;

    return 0;
}
```
```
//output
result = lhs + 1;
result.a == L+1, lhs.a == L, rhs.a == R


result = 1 + rhs;
result.a == 1+R, lhs.a == L, rhs.a == R
```
#### Bei Sinnvollen operationen
bietet es sich an im globalen Operator (int + Objekt) den Element-Operator zu verwenden (Vermeidung von redundantem Code), wie folgend gezeigt. Allerdings dreht sich dann die Aufrufreihenfolge, was im Beispiel zu R+1 anstatt 1+R fürht!
``` c++
// someclass.cpp
SomeClass SomeClass::operator+(const int rhs){
    string a_added = a + "+" + to_string(rhs);
    SomeClass returnValue (a_added);
    return returnValue;
}


SomeClass operator+(const int lhs,SomeClass& rhs){
    return rhs+lhs;
}
```
```
//output
result = lhs + 1;
result.a == L+1, lhs.a == L, rhs.a == R


result = 1 + rhs;
result.a == R+1, lhs.a == L, rhs.a == R
```

### operatoren: Wann/Wie verwenden?
(Meine persönliche Meinung) Verwenden Sie bevorzugt globale Operatoren. Müssen Sie auf private Elemente zugreifen z.B. bei einer Zuweiseung verwenden Sie Element-Operatoren.
Auszug aus dem [Google C++ StyleGuide](https://google.github.io/styleguide/cppguide.html#Operator_Overloading):
- Prefer to define non-modifying binary operators as non-member functions.[...]
- Don't go out of your way to avoid defining operator overloads. For example, prefer to define ==, =, and <<, rather than Equals(), CopyFrom(), and PrintTo(). [...]
- Define overloaded operators only if their meaning is obvious, unsurprising, and consistent with the corresponding built-in operators. For example, use | as a bitwise- or logical-or, not as a shell-style pipe.
- Define operators only on your own types. More precisely, define them in the same headers, .cc files, and namespaces as the types they operate on. That way, the operators are available wherever the type is, minimizing the risk of multiple definitions. [...]
- Do not overload &&, ||, , (comma), or unary &. Do not overload operator"", [...].

## friend
Friend-Funktionen und -Klassen haben Zugriff auf private und protected Elemente einer Klasse. Wobei Friend-Funktionen immer global sind. Man sollte sehr genau abwägen ob man tatsächlich friend-Funktionen bzw. -Klassen einsetzt. Siehe [Wann/Wie verwenden?](#friends-wannwie-verwenden)
``` c++
// someclass.h
class SomeOtherClass;

class SomeClass
{
    friend class SomeOtherClass;
public:
    SomeClass(std::string value):a(value){}

    std::string getA()const {return a;}

    friend SomeClass doSth(SomeClass&, SomeClass&);
private:
    std::string a;
};

class SomeOtherClass
{
public:
    SomeOtherClass();
    void func(SomeClass& param){param.a = "blablabla";}
};
```

``` c++
// someclass.cpp
SomeClass doSth(SomeClass& p1, SomeClass& p2){
    SomeClass resultValue("doneSth(" + p1.a + ", " +p2.a +")");
    p1.a += "(used by doSth)";
    p2.a += "(used by doSth)";
    return resultValue;
}
```

``` c++
int main(){
    SomeClass param1("param1");
    SomeClass param2("param2");

    SomeClass result = doSth(param1,param2);
    cout<<"result = doSth(param1,param2)"<<endl;
    cout << "result.a == "<<result.getA() <<", param1.a == "<<param1.getA()<<", param2.a == "<<param2.getA()<<endl<<endl<<endl;

    SomeOtherClass aFriend;
    aFriend.func(param1);
    cout<<"aFriend.func(param1)"<<endl;
    cout << "param1.a == "<<param1.getA()<<endl;

    retrun 0;
}
```

```
//output
result = doSth(param1,param2)
result.a == doneSth(param1, param2), param1.a == param1(used by doSth), param2.a == param2(used by doSth)


aFriend.func(param1)
param1.a == blablabla
```

### friends: Wann/Wie verwenden?
Das sagt der [Google C++ StyleGuide](https://google.github.io/styleguide/cppguide.html#Friends):
We allow use of friend classes and functions, within reason.

Friends should usually be defined in the same file so that the reader does not have to look in another file to find uses of the private members of a class. A common use of friend is to have a FooBuilder class be a friend of Foo so that it can construct the inner state of Foo correctly, without exposing this state to the world. In some cases it may be useful to make a unittest class a friend of the class it tests.

Friends extend, but do not break, the encapsulation boundary of a class. In some cases this is better than making a member public when you want to give only one other class access to it. However, most classes should interact with other classes solely through their public members.

## friend-Operatoren:
Zusammenfassend aus [Operatoren](#operatoren-%C3%BCberladen) und [friend](#friend) liest man heraus, dass friend-Operatoren globale Operatoren sind, die durch das friend-keyword Zugriff auf protected und private Elemente haben. Folgend ein Beispiel, mit impliziter Typumwandlung ( string lhs -> SomeClass(lhs) -> operator ).
Ich würde diese "Universal-Waffe" jedoch nur im Notfall einsetzen - die Meinungen gehen jedoch stark auseinander. (Reichen bei einem globalen Operator<< zu ostream public-Memberelemente und -methoden?)
```c++
//someclass.h
class SomeClass
{
//    friend class SomeOtherClass;
public:
    SomeClass(std::string value):a(value){}

    std::string getA()const {return a;}

    friend SomeClass operator+(SomeClass lhs, SomeClass rhs){return SomeClass(lhs.a +" + "+rhs.a);}
private:
    std::string a;
};
```
``` c++
int main(){

    SomeClass rhs("rhs");
    string lhs("string");
    SomeClass result = lhs+rhs;
    cout << "SomeClass result = lhs+rhs;"<<endl;
    cout << "result.a == "<<result.getA() <<", (string)lhs == "<<lhs<<", rhs.a == "<<rhs.getA()<<endl<<endl<<endl;

    retrun 0;
}
```

```
//ouput
SomeClass result = lhs+rhs;
result.a == string + rhs, (string)lhs == string, rhs.a == rhs
```