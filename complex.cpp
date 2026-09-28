#include<iostream>
using namespace std;

class Complex {
    private:
        int real, imag;

    public:
        Complex(int real, int imag) {
            this->real = real;
            this->imag = imag;
        }

        Complex operator+(const Complex& other) {
            return Complex(real + other.real, imag + other.imag);
        }

        Complex operator-(const Complex& other) {
            return Complex(real - other.real, imag - other.imag);
        }

        Complex operator*(const Complex& other) {
            return Complex((real*other.real)-(imag*other.imag), (imag*other.real)+(real*other.imag));
        }

        friend ostream& operator<<(ostream& out, Complex obj){
            if(obj.real != 0){
                if(obj.imag > 0)
                    out << obj.real << "+" << obj.imag << "i";
                else if (obj.imag == 0)
                    out << obj.real;
                else
                    out << obj.real << obj.imag << "i";
            } else if(obj.imag != 0) {
                out << obj.imag << "i";
            } else out << "0";
            return out;
        }
};

int main() {
    int x1, y1 = 0;
    cout << "Enter two complex numbers (If the imaginary part is 1 then write 1i not just i): ";
    scanf("%d+%di", &x1, &y1);
    int x2, y2 = 0;
    scanf(" %d+%di", &x2, &y2);

    Complex cmplx1(x1, y1), cmplx2(x2, y2);
    char op;
    cout << "Enter the symbol of the operation(+,-,*): ";
    cin >> op;

    switch(op){
        case '+':
            cout << "(" << cmplx1 << ")" << " + " << "(" << cmplx2 << ")" << " = " << (cmplx1+cmplx2) << endl;
            break;

        case '-':
            cout << "(" << cmplx1 << ")" << " - " << "(" << cmplx2 << ")" << " = " << (cmplx1-cmplx2) << endl;
            break;

        case '*':
            cout << "(" << cmplx1 << ")" << " * " << "(" << cmplx2 << ")" << " = " << (cmplx1*cmplx2) << endl;
            break;
        
        default:
            cout << "Invalid operation." << endl;
    }
    return 0;
}