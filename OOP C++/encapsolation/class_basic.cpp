#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;
// class
// attribute
// method, behavior
// access modifier
    // private
    // public
    // protected
// static

// constructor
// destructor

// this pointer
// setter getter

//operator
// cout -> ostream
// cin -> istream
class Distance;
class SoPhuc;

class Distance {
    public:
        double distance_A_and_B(SoPhuc, SoPhuc);
};

class SoPhuc {
    public:
        friend class Distance;
        //nhap so phuc
        friend istream& operator>> (istream&, SoPhuc&);
        friend ostream& operator<< (ostream&, SoPhuc);
        SoPhuc operator+ (SoPhuc another);
        SoPhuc operator- (SoPhuc another);
        double modulus();
        friend SoPhuc operator* (SoPhuc a, SoPhuc b);
    private:
        int thuc, ao;
};

int main() {
    SoPhuc a, b;
    cin >> a >> b;
    Distance s;
    double khoangcach;
    khoangcach = s.distance_A_and_B(a, b);
    cout << "Khoang cach = " << fixed << setprecision(3) << khoangcach << endl;
}

istream& operator>> (istream& input, SoPhuc& x) {
    cout << "Enter thuc, ao: ";
    input >> x.thuc >> x.ao;
    return input;
}

ostream& operator<< (ostream& output, SoPhuc x) {
    string dau;
    (x.ao > 0) ? dau = "+" : dau = "";
    output << x.thuc << dau;
    output << x.ao << 'i';
    return output;
}

SoPhuc SoPhuc::operator + (SoPhuc another) {
    SoPhuc Tong;
    Tong.thuc = this->thuc + another.thuc;
    Tong.ao = this->ao + another.ao;
    return Tong;
}

SoPhuc SoPhuc::operator - (SoPhuc another) {
    SoPhuc Hieu;
    Hieu.thuc = this->thuc - another.thuc;
    Hieu.ao = this->ao - another.ao;
    return Hieu;
}

SoPhuc operator* (SoPhuc a, SoPhuc b) {
    SoPhuc Tich;
    Tich.thuc = a.thuc * b.thuc + a.ao * b.ao;
    Tich.ao = a.thuc * b.ao + a.ao + b.thuc;
    return Tich;
}

double SoPhuc::modulus() {
    return sqrt(thuc * thuc + ao * ao);
}

double Distance::distance_A_and_B(SoPhuc a, SoPhuc b) {
    return sqrt( pow(a.thuc - b.ao, 2) + pow(a.ao - b.ao, 2) );
}