//
// Created by koazg on 4/28/2023.
//

#ifndef FRACTION_B_FRACTION_HPP
#define FRACTION_B_FRACTION_HPP

#include <iostream>

namespace ariel {
    class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(); // Default constructor
        Fraction(int numerator, int denominator);
        Fraction(float value);

        int getNumerator() const;
        int getDenominator() const;

        // Arithmetic operators
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        friend Fraction operator+(float lhs, const Fraction& rhs);
        friend Fraction operator-(float lhs, const Fraction& rhs);
        friend Fraction operator*(float lhs, const Fraction& rhs);
        friend Fraction operator/(float lhs, const Fraction& rhs);

        // Comparison operators
        bool operator<(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator==(const Fraction& other) const;

        friend bool operator==(float lhs, const Fraction& rhs);
        friend bool operator!=(float lhs, const Fraction& rhs);
        friend bool operator<(float lhs, const Fraction& rhs);
        friend bool operator>(float lhs, const Fraction& rhs);
        friend bool operator<=(float lhs, const Fraction& rhs);
        friend bool operator>=(float lhs, const Fraction& rhs);

        friend bool operator==(const Fraction& lhs, float rhs);
        friend bool operator!=(const Fraction& lhs, float rhs);
        friend bool operator<(const Fraction& lhs, float rhs);
        friend bool operator>(const Fraction& lhs, float rhs);
        friend bool operator<=(const Fraction& lhs, float rhs);
        friend bool operator>=(const Fraction& lhs, float rhs);

        // Increment and decrement operators
        Fraction& operator++(); // Prefix
        Fraction operator++(int); // Postfix
        Fraction& operator--(); // Prefix
        Fraction operator--(int); // Postfix

        // Stream operators
        friend std::ostream& operator<<(std::ostream& stream, const Fraction& frac);
        friend std::istream& operator>>(std::istream& stream, Fraction& frac);
    };
}

#endif //FRACTION_B_FRACTION_HPP
