#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
// nhap, xuat
// tinh module, cong, tru, nhan, chia

class SoPhuc {
public:
    SoPhuc();
    SoPhuc(double thuc, double ao) : thuc(thuc), ao(ao) {}
    friend std::istream& operator>> (std::istream&, SoPhuc&);
    friend std::ostream& operator<< (std::ostream&, SoPhuc);
    double module();
    SoPhuc operator+ (SoPhuc);
    SoPhuc operator- (SoPhuc);
    SoPhuc operator* (SoPhuc);
private:
    double thuc, ao;
};

SoPhuc::SoPhuc() {
    this->thuc = 0;
    this->ao = 0;
}

std::istream& operator>> (std::istream& input, SoPhuc& number) {
    std::cout << "thuc = "; input >> number.thuc;
    std::cout << "ao = "; input >> number.ao;
    return input;
}

std::ostream& operator<< (std::ostream& output, SoPhuc number) {
    if (number.ao == 0) {
        output << number.thuc;
    }
    else {
        std::string dau = "";
        if (number.ao > 0) { dau = "+"; }
        output << number.thuc << dau << number.ao << 'i';
    }
    return output;
}

double SoPhuc::module(){
    return (double) std::sqrt(std::pow(this->thuc, 2) + std::pow(this->ao, 2));
}

SoPhuc SoPhuc::operator+ (SoPhuc another) {
    SoPhuc tong;
    tong.thuc = this->thuc + another.thuc;
    tong.ao = this->ao + another.ao;
    return tong;
}

SoPhuc SoPhuc::operator- (SoPhuc another) {
    SoPhuc hieu;
    hieu.thuc = this->thuc - another.thuc;
    hieu.ao = this->ao - another.ao;
    return hieu;
}

SoPhuc SoPhuc::operator* (SoPhuc another) {
    SoPhuc tich;
    tich.thuc = this->thuc * another.thuc + this->ao * another.ao;
    tich.ao = this->thuc * another.ao + this->ao * another.thuc;
    return tich;
}

typedef SoPhuc SP;

int main() {
    SP a;
    SP b(1, 2);
    std::cout << a << std::endl;
    std::cin >> a;
    std::cout << a << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "module a = " << std::fixed << std::setprecision(3) << a.module();
}