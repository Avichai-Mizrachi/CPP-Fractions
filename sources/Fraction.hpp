#pragma once

#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

        // Reduce by itself
        void reduce()
        {
            int gcd = __gcd(abs(numerator), abs(denominator));
            numerator = numerator / gcd;
            denominator = denominator / gcd;
        }

        // Reduce when getting two numbers
        static void reduce(int &num, int &den)
        {
            int gcd = __gcd(abs(num), abs(den));
            num = num / gcd;
            den = den / gcd;
        }

    public:
        Fraction(int, int);
        Fraction(float);
        Fraction();

        // Fraction with Fraction
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;

        // Equalition Fraction with Fraction
        bool operator<(const Fraction &other) const
        {
            return (numerator * other.denominator) < (other.numerator * denominator);
        }
        bool operator<=(const Fraction &other) const
        {
            return !(*this > other);
        }
        bool operator>(const Fraction &other) const
        {
            return (numerator * other.denominator) > (other.numerator * denominator);
        }
        bool operator>=(const Fraction &other) const
        {
            return !(*this < other);
        }
        bool operator==(const Fraction &other) const
        {
            return numerator == other.numerator && denominator == other.denominator;
        }
        bool operator!=(const Fraction &other) const
        {
            return !(*this == other);
        }

        // Fraction with float
        Fraction operator+(float other);
        Fraction operator-(float other);
        Fraction operator*(float other);
        Fraction operator/(float other);

        // Equalition with float
        bool operator<(float other) const
        {
            return *this < Fraction(other);
        }
        bool operator<=(float other) const
        {
            return *this <= Fraction(other);
        }
        bool operator>(float other) const
        {
            return *this > Fraction(other);
        }
        bool operator>=(float other) const
        {
            return *this >= Fraction(other);
        }
        bool operator==(float other) const
        {
            return *this == Fraction(other);
        }
        bool operator!=(float other) const
        {
            return *this != Fraction(other);
        }

        Fraction &operator++();
        Fraction operator++(int);
        Fraction &operator--();
        Fraction operator--(int);

        // Getters
        int getNumerator() const
        {
            return numerator;
        }
        int getDenominator() const
        {
            return denominator;
        }

        // Friend functions - When a function or class is declared as
        // a friend of another class, it can access the private
        // and protected members of that class as if they were its own.
        friend Fraction operator+(float other, const Fraction &fraction2);
        friend Fraction operator-(float other, const Fraction &fraction2);
        friend Fraction operator*(float other, const Fraction &fraction2);
        friend Fraction operator/(float other, const Fraction &fraction2);
        friend bool operator==(float other, const Fraction &fraction2);
        friend bool operator!=(float other, const Fraction &fraction2);
        friend bool operator>(float other, const Fraction &fraction2);
        friend bool operator>=(float other, const Fraction &fraction2);
        friend bool operator<(float other, const Fraction &fraction2);
        friend bool operator<=(float other, const Fraction &fraction2);

        friend std::ostream &operator<<(std::ostream &, const Fraction &);

        // The >> operator to read a fraction from an input stream by taking two integers as input.
        friend std::istream &operator>>(std::istream &input, Fraction &fraction)
        {
            if (input.peek() == EOF)
            {
                throw std::runtime_error("End of file");
            }
            int num = 1;
            input >> num;
            if (input.peek() == EOF)
            {
                throw std::runtime_error("End of file");
            }
            int den = 1;
            input >> den;
            if (den == 0)
            {
                throw std::runtime_error("Denominator is zero");
            }
            fraction = Fraction(num, den);
            return input;
        };
    };
}