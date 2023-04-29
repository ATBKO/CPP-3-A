//
// Created by koazg on 4/28/2023.
//
#include "Fraction.hpp"
#include <stdexcept>
#include <numeric>
#include <cmath>
#include <iostream>

namespace ariel {

    Fraction::Fraction() : numerator(0), denominator(1) {} // Implement default constructor

    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        int gcd = std::gcd(numerator, denominator);
        this->numerator = numerator / gcd;
        this->denominator = denominator / gcd;
    }

    Fraction::Fraction(float value) {
        int multiplier = 1000; // Use 1000 to preserve 3 decimal points
        int numerator = std::round(value * multiplier);
        int denominator = multiplier;
        int gcd = std::gcd(numerator, denominator);
        this->numerator = numerator / gcd;
        this->denominator = denominator / gcd;
    }

    int Fraction::getNumerator() const {
        return numerator;
    }

    int Fraction::getDenominator() const {
        return denominator;
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        int common_denominator = std::lcm(denominator, other.denominator);
        int new_numerator = numerator * (common_denominator / denominator) + other.numerator * (common_denominator / other.denominator);
        return Fraction(new_numerator, common_denominator);
    }

    Fraction Fraction::operator-(const Fraction& other) const {
        int common_denominator = std::lcm(denominator, other.denominator);
        int new_numerator = numerator * (common_denominator / denominator) - other.numerator * (common_denominator / other.denominator);
        return Fraction(new_numerator, common_denominator);
    }

    Fraction Fraction::operator*(const Fraction& other) const {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction Fraction::operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero");
        }
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Fraction(new_numerator, new_denominator);
    }

    bool Fraction::operator<(const Fraction& other) const {
        return (double)numerator / denominator < (double)other.numerator / other.denominator;
    }

    bool Fraction::operator<=(const Fraction& other) const {
        return (double)numerator / denominator <= (double)other.numerator / other.denominator;
    }

    bool Fraction::operator>(const Fraction& other) const {
        return (double)numerator / denominator > (double)other.numerator / other.denominator;
    }

    bool Fraction::operator>=(const Fraction& other) const {
        return (double)numerator / denominator >= (double)other.numerator / other.denominator;
    }

    bool Fraction::operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }


    // In Fraction.cpp

    bool operator==(float lhs, const Fraction& rhs) {
        return Fraction(lhs) == rhs;
    }

    bool operator!=(float lhs, const Fraction& rhs) {
        return !(lhs == rhs);
    }

    bool operator<(float lhs, const Fraction& rhs) {
        return Fraction(lhs) < rhs;
    }

    bool operator>(float lhs, const Fraction& rhs) {
        return rhs < lhs;
    }

    bool operator<=(float lhs, const Fraction& rhs) {
        return !(lhs > rhs);
    }

    bool operator>=(float lhs, const Fraction& rhs) {
        return !(lhs < rhs);
    }


    // In Fraction.cpp

    bool operator==(const Fraction& lhs, float rhs) {
        return lhs == Fraction(rhs);
    }

    bool operator!=(const Fraction& lhs, float rhs) {
        return !(lhs == rhs);
    }

    bool operator<(const Fraction& lhs, float rhs) {
        return lhs < Fraction(rhs);
    }

    bool operator>(const Fraction& lhs, float rhs) {
        return Fraction(rhs) < lhs;
    }

    bool operator<=(const Fraction& lhs, float rhs) {
        return !(lhs > rhs);
    }

    bool operator>=(const Fraction& lhs, float rhs) {
        return !(lhs < rhs);
    }



    Fraction& Fraction::operator++() {
        numerator += denominator;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }

    Fraction& Fraction::operator--() {
        numerator -= denominator;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        numerator -= denominator;
        return temp;
    }

    // In Fraction.cpp

    Fraction operator+(float lhs, const Fraction& rhs) {
        return rhs + lhs;
    }

    Fraction operator-(float lhs, const Fraction& rhs) {
        return Fraction(lhs) - rhs;
    }

    Fraction operator*(float lhs, const Fraction& rhs) {
        return rhs * lhs;
    }

    Fraction operator/(float lhs, const Fraction& rhs) {
        if (rhs == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return Fraction(lhs) / rhs;
    }



//    Fraction& Fraction::operator+=(const Fraction& other) {
//        *this = *this + other;
//        return *this;
//    }
//
//    Fraction& Fraction::operator-=(const Fraction& other) {
//        *this = *this - other;
//        return *this;
//    }
//
//    Fraction& Fraction::operator*=(const Fraction& other) {
//        *this = *this * other;
//        return *this;
//    }
//
//    Fraction& Fraction::operator/=(const Fraction& other) {
//        *this = *this / other;
//        return *this;
//    }

    std::ostream& operator<<(std::ostream& stream, const Fraction& fraction) {
        stream << fraction.getNumerator() << "/" << fraction.getDenominator();
        return stream;
    }

    std::istream& operator>>(std::istream& stream, Fraction& fraction){
        int numerator, denominator;
        char delimiter;
        if (stream >> numerator >> delimiter >> denominator) {
            if (delimiter == '/' || delimiter == ',' || delimiter == ' ') {
                fraction = Fraction(numerator, denominator);
            } else {
                throw std::runtime_error("Not a fraction");
            }
        } else {
            throw std::runtime_error("One Number");
        }
        return stream;
    }
} // end namespace ariel
