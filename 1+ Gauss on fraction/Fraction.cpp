#include "Fraction.h"

Fraction::Fraction() {
    this->m_numerator = 0;
    this->m_denominator = 1;
}

Fraction::Fraction(const int numerator, const int denominator) {
    this->m_numerator = numerator;
    if (denominator == 0) {
        this->m_denominator = 1;
    } else {
        this->m_denominator = denominator;
    }
}

int Fraction::getNumerator() {
    return this->m_numerator;
}

void Fraction::setNumerator(const int numerator) {
    this->m_numerator = numerator;
}

int Fraction::getDenominator() {
    return this->m_denominator;
}

void Fraction::setDenominator(const int denominator) {
    this->m_denominator = denominator;
}

int Fraction::gcd(int number1, int number2) {
    while (number2 != 0) {
        int temp = number2;
        number2 = number1 % number2;
        number1 = temp;
    }
    if (number1 > 0) {
        return number1;
    } else {
        return -number1;
    }
}

double Fraction::convertToDouble() {
    return ((static_cast<double>(this->m_numerator)) / (static_cast<double>(this->m_denominator)));
}

int Fraction::covertToInt() {
    return ((this->m_numerator) / (this->m_denominator));
}

const Fraction &Fraction::operator=(const int number) {
    this->m_numerator = number;
    this->m_denominator = 1;
    return *this;
}

Fraction Fraction::operator-() const {
    Fraction temp{0, 1};
    temp.m_numerator = -(this->m_numerator);
    temp.m_denominator = this->m_denominator;
    return temp;
}

const Fraction Fraction::operator+(const Fraction &fraction) const {
    Fraction temp{0, 1};
    temp.m_numerator = (this->m_numerator) * (fraction.m_denominator) + (fraction.m_numerator) * (this->m_denominator);
    temp.m_denominator = (this->m_denominator) * (fraction.m_denominator);

    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

    temp.m_numerator = temp.m_numerator / gcd;
    temp.m_denominator = temp.m_denominator / gcd;

    return temp;
}

const Fraction Fraction::operator-(const Fraction &fraction) const {
    Fraction temp{0, 1};
    temp.m_numerator = (this->m_numerator) * (fraction.m_denominator) - (fraction.m_numerator) * (this->m_denominator);
    temp.m_denominator = (this->m_denominator) * (fraction.m_denominator);

    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

    if (gcd > 0) {
        temp.m_numerator = temp.m_numerator / gcd;
        temp.m_denominator = temp.m_denominator / gcd;
    }
    return temp;
}

const Fraction Fraction::operator*(const Fraction &fraction) const {
    Fraction temp{0, 1};
    temp.m_numerator = (this->m_numerator) * (fraction.m_numerator);
    temp.m_denominator = (this->m_denominator) * (fraction.m_denominator);

    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);
    if (gcd > 0) {
        temp.m_numerator = temp.m_numerator / gcd;
        temp.m_denominator = temp.m_denominator / gcd;
    }
    return temp;
}

const Fraction Fraction::operator/(const Fraction &fraction) const {
    if (!fraction.m_numerator == 0) {
        Fraction temp{0, 1};
        temp.m_numerator = (this->m_numerator) * (fraction.m_denominator);
        temp.m_denominator = (this->m_denominator) * (fraction.m_numerator);

        int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

        if (gcd > 0) {
            temp.m_numerator = temp.m_numerator / gcd;
            temp.m_denominator = temp.m_denominator / gcd;
        }

        return temp;
    }
}

const Fraction Fraction::operator+(const int number) const {
    Fraction temp{0, 1};
    temp.m_numerator = (this->m_numerator) + number * (this->m_denominator);
    temp.m_denominator = this->m_denominator;

    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

    temp.m_numerator = temp.m_numerator / gcd;
    temp.m_denominator = temp.m_denominator / gcd;

    return temp;
}

const Fraction Fraction::operator-(const int number) const {
    Fraction temp{0, 1};
    temp.m_numerator = (this->m_numerator) - number * (this->m_denominator);
    temp.m_denominator = this->m_denominator;

    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

    temp.m_numerator = temp.m_numerator / gcd;
    temp.m_denominator = temp.m_denominator / gcd;

    return temp;
}

const Fraction Fraction::operator*(const int number) const {
    Fraction temp{0, 1};
    temp.m_numerator = (this->m_numerator) * number;
    temp.m_denominator = this->m_denominator;

    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

    temp.m_numerator = temp.m_numerator / gcd;
    temp.m_denominator = temp.m_denominator / gcd;

    return temp;
}

const Fraction Fraction::operator/(const int number) const {
    if (number == 0) {
        std::cout << "Error! Can not divied for 0\n";
        exit(-1);
    } else {
        Fraction temp{0, 1};
        temp.m_numerator = (this->m_numerator);
        temp.m_denominator = this->m_denominator * number;

        int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

        temp.m_numerator = temp.m_numerator / gcd;
        temp.m_denominator = temp.m_denominator / gcd;

        return temp;
    }
}

Fraction &Fraction::operator++() {
    *this = *this + 1;
    return *this;
}

Fraction Fraction::operator++(const int) {
    Fraction temp{this->m_numerator, this->m_denominator};
    *this = *this + 1;
    return temp;
}

Fraction &Fraction::operator--() {
    *this = *this - 1;
    return *this;
}

Fraction Fraction::operator--(const int) {
    Fraction temp{this->m_numerator, this->m_denominator};
    *this = *this - 1;
    return temp;
}

const Fraction &Fraction::operator+=(const int number) {
    *this = *this + number;
    return *this;
}

const Fraction &Fraction::operator-=(const int number) {
    *this = *this - number;
    return *this;
}

const Fraction &Fraction::operator*=(const int number) {
    *this = *this * number;
    return *this;
}

const Fraction &Fraction::operator/=(const int number) {
    if (number == 0) {
        std::cout << "Error! Can not divied for 0\n";
        exit(-1);
    } else {
        *this = *this / number;
        return *this;
    }
}

const Fraction &Fraction::operator+=(const Fraction &fraction) {
    *this = *this + fraction;
    return *this;
}

const Fraction &Fraction::operator-=(const Fraction &fraction) {
    *this = *this - fraction;
    return *this;
}

const Fraction &Fraction::operator*=(const Fraction &fraction) {
    *this = *this * fraction;
    return *this;
}

const Fraction &Fraction::operator/=(const Fraction &fraction) {
    if (fraction.m_numerator == 0) {
        std::cout << "Error! Can not divied for 0\n";
        exit(-1);
    } else {
        *this = *this / fraction;
        return *this;
    }
}

const bool Fraction::operator>(const Fraction &fraction) const {
    return (this->m_numerator) * (fraction.m_denominator) > (fraction.m_numerator) * (this->m_denominator);
}

const bool Fraction::operator>=(const Fraction &fraction) const {
    return (this->m_numerator) * (fraction.m_denominator) >= (fraction.m_numerator) * (this->m_denominator);
}

const bool Fraction::operator<(const Fraction &fraction) const {
    return (this->m_numerator) * (fraction.m_denominator) < (fraction.m_numerator) * (this->m_denominator);
}

const bool Fraction::operator<=(const Fraction &fraction) const {
    return (this->m_numerator) * (fraction.m_denominator) <= (fraction.m_numerator) * (this->m_denominator);
}

const bool Fraction::operator==(const Fraction &fraction) const {
    return (this->m_numerator) * (fraction.m_denominator) == (fraction.m_numerator) * (this->m_denominator);
}

const bool Fraction::operator!=(const Fraction &fraction) const {
    return (this->m_numerator) * (fraction.m_denominator) != (fraction.m_numerator) * (this->m_denominator);
}

const Fraction Fraction::operator^(const int n) const {
    Fraction temp{(this->m_numerator), (this->m_denominator)};
    temp.m_numerator = static_cast<int>(pow(this->m_numerator, n));
    temp.m_denominator = static_cast<int>(pow(this->m_denominator, n));
    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

    temp.m_numerator = temp.m_numerator / gcd;
    temp.m_denominator = temp.m_denominator / gcd;
    return temp;
}

Fraction::~Fraction() = default;

std::istream &operator>>(std::istream &input, Fraction &fraction) {
    std::string trash;

    input >> fraction.m_numerator;
    input >> trash;
    input >> fraction.m_denominator;

    return input;
}

std::ostream &operator<<(std::ostream &output, const Fraction &fraction) {
    if (fraction.m_denominator == 0) return output;
    if (fraction.m_numerator % fraction.m_denominator == 0) {
        output << (fraction.m_numerator / fraction.m_denominator);
    } else {
        if (fraction.m_denominator < 0) {
            output << -fraction.m_numerator << "/" << -fraction.m_denominator;
        } else {
            output << fraction.m_numerator << "/" << fraction.m_denominator;
        }
    }
    return output;
}

const Fraction operator+(const int &number, const Fraction &fraction) {
    Fraction temp{1, 0};
    temp = fraction + number;
    return temp;
}

const Fraction operator-(const int &number, const Fraction &fraction) {
    Fraction temp{0, 1};
    temp.m_numerator = number * (fraction.m_denominator) - (fraction.m_numerator);
    temp.m_denominator = fraction.m_denominator;

    int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

    temp.m_numerator = temp.m_numerator / gcd;
    temp.m_denominator = temp.m_denominator / gcd;

    return temp;
}

const Fraction operator*(const int &number, const Fraction &fraction) {
    Fraction temp{1, 0};
    temp = fraction * number;
    return temp;
}

const Fraction operator/(const int &number, const Fraction &fraction) {
    if (fraction.m_numerator == 0) {
        std::cout << "Error! Can not divied for 0\n";
        exit(-1);
    } else {
        Fraction temp{0, 1};
        temp.m_numerator = number * (fraction.m_denominator);
        temp.m_denominator = fraction.m_numerator;

        int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

        temp.m_numerator = temp.m_numerator / gcd;
        temp.m_denominator = temp.m_denominator / gcd;

        return temp;
    }
}

const bool operator>(const int &number, const Fraction &fraction) {
    return static_cast<double>(number) >
           ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator>=(const int &number, const Fraction &fraction) {
    return static_cast<double>(number) >=
           ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator<(const int &number, const Fraction &fraction) {
    return static_cast<double>(number) <
           ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator<=(const int &number, const Fraction &fraction) {
    return static_cast<double>(number) <=
           ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator==(const int &number, const Fraction &fraction) {
    return static_cast<double>(number) ==
           ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator!=(const int &number, const Fraction &fraction) {
    return static_cast<double>(number) !=
           ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator>(const double &number, const Fraction &fraction) {
    return number > ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator>=(const double &number, const Fraction &fraction) {
    return number >= ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator<(const double &number, const Fraction &fraction) {
    return number < ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator<=(const double &number, const Fraction &fraction) {
    return number <= ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator==(const double &number, const Fraction &fraction) {
    return number == ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}

const bool operator!=(const double &number, const Fraction &fraction) {
    return number != ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator)));
}
