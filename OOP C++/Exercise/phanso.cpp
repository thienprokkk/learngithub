// nhap, in, operator+ , operator- , operator* 
// su dung nap chong toan tu
// ket hop vs struct
#include <iostream>

class PhanSo {
public:
    friend PhanSo rutGon(PhanSo);
    friend std::ostream& operator<< (std::ostream&, PhanSo);
    friend std::istream& operator>> (std::istream&, PhanSo&);
    PhanSo operator+ (PhanSo);
    PhanSo operator- (PhanSo);
    PhanSo operator* (PhanSo);
private:
    int tu, mau;
};

int gcd(int firstNumber, int secondNumber) {
    if (secondNumber == 0) return firstNumber;
    return gcd(secondNumber, firstNumber % secondNumber);
}

PhanSo rutGon(PhanSo number) {
    PhanSo *newNumber = new PhanSo();
    int x = gcd(number.mau, number.tu);
    newNumber->tu = number.tu / x;
    newNumber->mau = number.mau / x;
    return *newNumber; 
}

std::istream& operator>> (std::istream& input, PhanSo &number) {
    std::cout << "enter tu "; input >> number.tu;
    std::cout << "enter mau "; input >> number.mau;
    number = rutGon(number);
    return input;
}

std::ostream& operator<< (std::ostream& output, PhanSo number) {
    output << number.tu << "/" << number.mau;
    return output;
}

PhanSo PhanSo::operator+ (PhanSo another) {
    PhanSo *newNumber = new PhanSo();
    newNumber->tu = this->tu * another.mau + another.tu * this->mau;
    newNumber->mau = this->mau * another.mau;
    return rutGon(*newNumber);
}
PhanSo PhanSo::operator- (PhanSo another) {
    PhanSo *newNumber = new PhanSo();
    newNumber->tu = this->tu * another.mau - another.tu * this->mau;
    newNumber->mau = this->mau * another.mau;
    return rutGon(*newNumber);
}

PhanSo PhanSo::operator* (PhanSo another) {
    PhanSo *newNumber = new PhanSo();
    newNumber->tu = this->tu * another.tu;
    newNumber->mau = this->mau * another.mau;
    return rutGon(*newNumber);
}
int main() {
    PhanSo a, b;
    std::cin >> a >> b;
    std::cout << a << " " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    PhanSo c = (a - b) * a + b;
    std::cout << "(a - b) * a + b = " << c << std::endl;
}