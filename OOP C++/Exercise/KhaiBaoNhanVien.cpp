#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

class NhanVien {
    public:
        NhanVien();
        friend istream& operator>> (istream&, NhanVien&);
        friend ostream& operator<< (ostream&, NhanVien);
        friend bool operator< (NhanVien, NhanVien);
        friend void SapXep(NhanVien ds[], int);
        void tangdem();
        int getdem();
    private:
        string ten, gioitinh, ngaysinh, diachi, masothue, ngayky;
        int ma;
        static int dem;
};

NhanVien::NhanVien() {
    ten = gioitinh = ngaysinh = diachi = masothue = ngayky = "";
}

void NhanVien::tangdem() {
    dem++;
}

int NhanVien::getdem() {
    return dem;
}

bool operator< (NhanVien a, NhanVien b) {
    int i = 0, j = 0;
    map<int, int> nsa, nsb;
    stringstream sub_a(a.ngaysinh);
    stringstream sub_b(b.ngaysinh);
    string token;
    while (getline(sub_a, token, '/')) {
        nsa[i++] = stoi(token);
    }
    while (getline(sub_a, token, '/')) {
        nsb[j++] = stoi(token);
    }
    if (nsa[3] != nsb[3]) return nsa[3] < nsb[3];
    if (nsa[1] != nsb[1]) return nsa[1] < nsb[1];
    return nsa[0] < nsb[0];
}

istream& operator>> (istream& in, NhanVien& x) {
    x.tangdem();
    x.ma = x.getdem();
    in.ignore();
    cout << "ten: "; getline(in, x.ten);
    cout << "gioi tinh: "; in >> x.gioitinh;
    cout << "ngay sinh: "; in >> x.ngaysinh;
    in.ignore();
    cout << "dia chi: "; getline(in, x.diachi);
    cout << "ma so thue: "; in >> x.masothue;
    cout << "ngay ky hop dong: "; in >> x.ngayky;
    return in;
}

ostream& operator<< (ostream& out, NhanVien x) {
    out << setfill('0') << setw(5) << x.ma + " "
        << x.ten + " " + x.ngaysinh + " " + x.diachi + " " + x.masothue + " " + x.ngayky;
    return out;
}

int NhanVien::dem = 0;

void SapXep(NhanVien ds[], int n) {
    sort(ds, ds + n);
}

int main() {
    NhanVien ds[30];
    int n;
    cout << "enter n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ds[i];
    }
    SapXep(ds, n);
    for (int i = 0; i < n; i++) {
        cout << ds[i];
        cout << endl;
    }
}