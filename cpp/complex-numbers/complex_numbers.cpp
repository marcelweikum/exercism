#include "complex_numbers.h"

#include <cmath>

namespace complex_numbers
{

    Complex::Complex(double real, double imag) : a_{real}, b_{imag}
    {
    }
    double Complex::real() const
    {
        return a_;
    }
    double Complex::imag() const
    {
        return b_;
    }

    Complex Complex::operator*(Complex c) const
    {
        return Complex(
            a_ * c.a_ - b_ * c.b_,
            a_ * c.b_ + b_ * c.a_);
    }

    Complex Complex::operator*(double d) const
    {
        return Complex(
            a_ * d,
            b_ * d);
    }

    Complex operator*(double d, const Complex &c)
    {
        return Complex(c.real() * d, c.imag() * d);
    }

    Complex Complex::operator/(Complex c) const
    {
        return Complex(
            (a_ * c.a_ + b_ * c.b_) / (std::pow(c.a_, 2) + std::pow(c.b_, 2)),
            (b_ * c.a_ - a_ * c.b_) / (std::pow(c.a_, 2) + std::pow(c.b_, 2)));
    }

    Complex Complex::operator/(double d) const
    {
        return Complex(
            a_ / d,
            b_ / d);
    }

    Complex operator/(double d, const Complex &c)
    {
        return Complex(
            (d * c.conj().real()) / (std::pow(c.real(), 2) + std::pow(c.imag(), 2)),
            (d * c.conj().imag()) / (std::pow(c.real(), 2) + std::pow(c.imag(), 2)));
    }

    Complex Complex::operator+(Complex c) const
    {
        return Complex(
            a_ + c.a_,
            b_ + c.b_);
    }

    Complex Complex::operator+(double d) const
    {
        return Complex(a_ + d, b_);
    }

    Complex operator+(double d, const Complex &c)
    {
        return Complex(c.real() + d, c.imag());
    }

    Complex Complex::operator-(Complex c) const
    {
        return Complex(
            a_ - c.a_,
            b_ - c.b_);
    }

    Complex Complex::operator-(double d) const
    {
        return Complex(
            a_ - d, b_);
    }

    Complex operator-(double d, const Complex &c)
    {
        return Complex(d - c.real(), -c.imag());
    }

    double Complex::abs() const
    {
        return std::sqrt(std::pow(a_, 2) + std::pow(b_, 2));
    }

    Complex Complex::conj() const
    {
        return Complex(a_, -b_);
    }

    Complex Complex::exp() const
    {
        Complex c{cos(b_), sin(b_)};
        return Complex(std::exp(a_) * cos(b_), std::exp(a_) * sin(b_));
    }

} // namespace complex_numbers
