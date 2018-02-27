#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction();

    Fraction(int numerator, int denominator);

    int getNumerator();

    void setNumerator(int numerator);

    int getDenominator();

    void setDenominator(int denominator);

    double convertToDouble();

    int covertToInt();

    friend std::istream &operator>>(std::istream &input, Fraction &fraction);

    friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction);

    const Fraction &operator=(int number);

    Fraction operator-() const;

    const Fraction operator+(const Fraction &fraction) const;

    const Fraction operator-(const Fraction &fraction) const;

    const Fraction operator*(const Fraction &fraction) const;

    const Fraction operator/(const Fraction &fraction) const;

    const Fraction operator+(int number) const;

    const Fraction operator-(const int number) const;

    const Fraction operator*(const int number) const;

    const Fraction operator/(const int number) const;

    const friend Fraction operator+(const int &number, const Fraction &fraction);

    const friend Fraction operator-(const int &number, const Fraction &fraction);

    const friend Fraction operator*(const int &number, const Fraction &fraction);

    const friend Fraction operator/(const int &number, const Fraction &fraction);

    Fraction &operator++();

    Fraction operator++(const int);

    Fraction &operator--();

    Fraction operator--(const int);

    const Fraction &operator+=(const int number);

    const Fraction &operator-=(const int number);

    const Fraction &operator*=(const int number);

    const Fraction &operator/=(const int number);

    const Fraction &operator+=(const Fraction &fraction);

    const Fraction &operator-=(const Fraction &fraction);

    const Fraction &operator*=(const Fraction &fraction);

    const Fraction &operator/=(const Fraction &fraction);

    const bool operator>(const Fraction &fraction) const;

    const bool operator>=(const Fraction &fraction) const;

    const bool operator<(const Fraction &fraction) const;

    const bool operator<=(const Fraction &fraction) const;

    const bool operator==(const Fraction &fraction) const;

    const bool operator!=(const Fraction &fraction) const;

    friend const bool operator>(const int &number, const Fraction &fraction);

    friend const bool operator>=(const int &number, const Fraction &fraction);

    friend const bool operator<(const int &number, const Fraction &fraction);

    friend const bool operator<=(const int &number, const Fraction &fraction);

    friend const bool operator==(const int &number, const Fraction &fraction);

    friend const bool operator!=(const int &number, const Fraction &fraction);

    friend const bool operator>(const double &number, const Fraction &fraction);

    friend const bool operator>=(const double &number, const Fraction &fraction);

    friend const bool operator<(const double &number, const Fraction &fraction);

    friend const bool operator<=(const double &number, const Fraction &fraction);

    friend const bool operator==(const double &number, const Fraction &fraction);

    friend const bool operator!=(const double &number, const Fraction &fraction);

    const Fraction operator^(int n) const;

    ~Fraction();

private:
    int gcd(int mumber1, int number2);

};
