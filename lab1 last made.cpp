#include <iostream>

using namespace std;

int result_num, result_den;

// Function prototypes
void add_fractions(int, int, int, int);
void sub_fractions(int, int, int, int);
void multiply_fractions(int, int, int, int);
void divide_fractions(int, int, int, int);
void display_result();
void simplify(int &num, int &den);
int gcd(int a, int b);

int main()
{
    int f1_num, f1_den, f2_num, f2_den;
    char dummy; // dummy character to read the '/' in fraction 1/2

    cout << "Enter first fraction (e.g., 2/3): ";
    cin >> f1_num >> dummy >> f1_den;
    cout << "Enter second fraction (e.g., 3/4): ";
    cin >> f2_num >> dummy >> f2_den;

    cout << "Adding fractions results in: ";
    add_fractions(f1_num, f1_den, f2_num, f2_den);
    simplify(result_num, result_den);
    display_result();

    cout << "\nSubtracting fractions results in: ";
    sub_fractions(f1_num, f1_den, f2_num, f2_den);
    simplify(result_num, result_den);
    display_result();

    cout << "\nMultiplying fractions results in: ";
    multiply_fractions(f1_num, f1_den, f2_num, f2_den);
    simplify(result_num, result_den);
    display_result();

    cout << "\nDividing fractions results in: ";
    divide_fractions(f1_num, f1_den, f2_num, f2_den);
    simplify(result_num, result_den);
    display_result();

    cout << endl;
    return 0;
}

void add_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_den + f2_num * f1_den;
}

void sub_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_den - f2_num * f1_den;
}

void multiply_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_num;
}

void divide_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_num = f1_num * f2_den;
    result_den = f1_den * f2_num;
}

void display_result()
{
    cout << result_num << "/" << result_den;
}


int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void simplify(int &num, int &den)
{
    int divisor = gcd(num, den);
    num /= divisor;
    den /= divisor;
}

