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

        // GCD
        static int _gcd(int num1, int num2)
        {
            if (num2 == 0)
            {
                return num1;
            }
            else
            {
                return _gcd(num2, num1 % num2);
            }
        }

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
        ~Fraction() = default;

        // Fraction with Fraction
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;

        // Equalition Fraction with Fraction
        bool operator<(const Fraction &other) const
        {
            return (other.numerator * denominator) > (numerator * other.denominator);
        }
        bool operator<=(const Fraction &other) const
        {
            return !(*this > other);
        }
        bool operator>(const Fraction &other) const
        {
            return (other.numerator * denominator) > (numerator * other.denominator);
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
        bool operator<(float other)
        {
            return *this < Fraction(other);
        }
        bool operator<=(float other)
        {
            return *this <= Fraction(other);
        }
        bool operator>(float other)
        {
            return *this > Fraction(other);
        }
        bool operator>=(float other)
        {
            return *this >= Fraction(other);
        }
        bool operator==(float other)
        {
            return *this == Fraction(other);
        }
        bool operator!=(float other)
        {
            return *this != Fraction(other);
        }

        Fraction &operator++();
        Fraction operator++(int);
        Fraction &operator--();
        Fraction operator--(int);

        // Getters
        float getNumerator()
        {
            return numerator;
        }
        float getDenominator()
        {
            return denominator;
        }

        // Friend functions
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