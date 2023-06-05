#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    // Constructors
    Fraction::Fraction(int num, int den)
    {
        numerator = num;
        denominator = den;
        if (den == 0)
        {
            throw invalid_argument("Denominator can't be zero");
        }

        if (den < 0)
        {
            numerator = numerator * -1;
            denominator = denominator * -1;
        }

        reduce();
    }
    Fraction::Fraction(float num)
    {
        numerator = num * 1000;
        denominator = 1000;
        reduce();
    }
    Fraction::Fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    Fraction Fraction::operator+(const Fraction &other) const
    {
        int a, b, num, den;

        if (__builtin_smul_overflow(numerator, other.denominator, &a) || __builtin_smul_overflow(other.numerator, denominator, &b), __builtin_smul_overflow(denominator, other.denominator, &den))
            throw overflow_error("Overflow");

        if (__builtin_sadd_overflow(a, b, &num))
            throw overflow_error("Overflow");

        return Fraction(num, den);
    }
    Fraction Fraction::operator-(const Fraction &other) const
    {
        int a, b, num, den;

        if (__builtin_smul_overflow(numerator, other.denominator, &a) || __builtin_smul_overflow(other.numerator, denominator, &b) || __builtin_smul_overflow(denominator, other.denominator, &den))
            throw overflow_error("Overflow");

        if (__builtin_ssub_overflow(a, b, &num))
            throw overflow_error("Overflow");

        return Fraction(num, den);
    }
    Fraction Fraction::operator*(const Fraction &other) const
    {
        int num, den;

        if (__builtin_smul_overflow(numerator, other.numerator, &num) || __builtin_smul_overflow(denominator, other.denominator, &den))
            throw overflow_error("Overflow");

        return Fraction(num, den);
    }
    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.numerator == 0)
            throw runtime_error("Can't divide by zero!");

        int num, den;

        if (__builtin_smul_overflow(numerator, other.denominator, &num) || __builtin_smul_overflow(denominator, other.numerator, &den))
            throw overflow_error("Overflow");

        return Fraction(num, den);
    }

    Fraction Fraction::operator+(float other)
    {
        return *this + Fraction(other);
    }
    Fraction Fraction::operator-(float other)
    {
        return *this - Fraction(other);
    }
    Fraction Fraction::operator*(float other)
    {
        return *this * Fraction(other);
    }
    Fraction Fraction::operator/(float other)
    {
        return *this / Fraction(other);
    }

    Fraction operator+(float num, const Fraction &other)
    {
        return Fraction(num) + other;
    }

    Fraction operator-(float num, const Fraction &other)
    {
        return Fraction(num) - other;
    }

    Fraction operator*(float num, const Fraction &other)
    {
        return Fraction(num) * other;
    }

    Fraction operator/(float num, const Fraction &other)
    {
        return Fraction(num) / other;
    }

    bool operator==(float num, const Fraction &other)
    {
        return Fraction(num) == other;
    }

    bool operator!=(float num, const Fraction &other)
    {
        return Fraction(num) != other;
    }

    bool operator<(float num, const Fraction &other)
    {
        return Fraction(num) < other;
    }

    bool operator<=(float num, const Fraction &other)
    {
        return Fraction(num) <= other;
    }

    bool operator>(float num, const Fraction &other)
    {
        return Fraction(num) > other;
    }

    bool operator>=(float num, const Fraction &other)
    {
        return Fraction(num) >= other;
    }

    Fraction &Fraction::operator++()
    {
        numerator = numerator + denominator;
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        Fraction tmp(numerator, denominator);
        ++(*this);
        return tmp;
    }

    Fraction &Fraction::operator--()
    {
        numerator = numerator - denominator;
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        Fraction tmp(numerator, denominator);
        --(*this);
        return tmp;
    }

    ostream &operator<<(ostream &outstream, const Fraction &fraction)
    {
        outstream << fraction.numerator << "/" << fraction.denominator;
        return outstream;
    }
}