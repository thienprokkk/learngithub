#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class A {
    public:
        A() {
            cout << "Constructor in A" << endl;
        }
        ~A() {
            cout << "Destructor in A" << endl;
        }
        void Hello() {
            cout << "Hello in A !" << endl;
        }
};

class B {
    public:
        B() {
            cout << "Constructor in B" << endl;
        }
        ~B() {
            cout << "Destructor in B" << endl;
        }
        void Hello() {
            cout << "Hello in B" << endl;
        }
};

class C: public B, public A {
    public:
        C() {
            cout << "Constructor in C" << endl;
        }
        ~C() {
            cout << "Destructor in C" << endl;
        }
        void Hello() {
            cout << "Hello in C" << endl;
        }
};

int main() {
    C obj;
    obj.A::Hello();
}