#include<iostream>
#include<string>
using namespace std;

class Fraction{
    int num, denom;
    static int GCD(int a, int b) {
        if(a < b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int rem;
        do {
            rem = a % b;
            a = b;
            b = rem;
        } while(rem != 0);
        return a;
    }

    public:
        Fraction(int n, int d=1){ num = n/GCD(n, d); denom = d/GCD(n, d); }

        Fraction operator+(const Fraction& frac) {
            int other_num = frac.num;
            int other_denom = frac.denom;

            int out_denom = denom * other_denom;
            int out_num = num*other_denom + other_num*denom;
            return Fraction(out_num, out_denom);
        }

        Fraction operator-(const Fraction& frac) {
            int other_num = frac.num;
            int other_denom = frac.denom;

            int out_denom = denom * other_denom;
            int out_num = num*other_denom - other_num*denom;
            return Fraction(out_num, out_denom);
        }

        Fraction operator*(const Fraction& frac) {
            int other_num = frac.num;
            int other_denom = frac.denom;

            int out_denom = denom * other_denom;
            int out_num = num * other_num;
            return Fraction(out_num, out_denom);
        }

        Fraction operator/(Fraction frac) {
            int temp = frac.num;
            frac.num = frac.denom;
            frac.denom = temp;
            return (*this)*(frac);
        }

        friend ostream& operator<<(ostream& out, const Fraction& frac) {
            int num = frac.num;
            int denom = frac.denom;
            if(denom < 0) {
                num = -num;
                denom = -denom;
            }
            if(denom != 1)
                out << num << "/" << denom;
            else
                out << num;

            return out;
        }
};

Fraction parseFraction(string& token) {
    int pos = token.find('/');
    if (pos == string::npos) {
        int n = stoi(token);
        return Fraction(n);
    } else {
        int n = stoi(token.substr(0, pos));
        int d = stoi(token.substr(pos + 1));
        return Fraction(n, d);
    }
}

int main() {
    string input1, input2;
    cin >> input1 >> input2;
    Fraction frac1 = parseFraction(input1), frac2 = parseFraction(input2);

    Fraction add = frac1+frac2, sub = frac1-frac2, mul = frac1*frac2, div = frac1/frac2;
    cout << frac1 << " + " << frac2 << " = " << add << endl;
    cout << frac1 << " - " << frac2 << " = " << sub << endl;
    cout << frac1 << " * " << frac2 << " = " << mul << endl;
    cout << frac1 << " / " << frac2 << " = " << div << endl;
    return 0;
}