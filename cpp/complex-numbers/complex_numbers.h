#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers
{

    class Complex
    {
    public:
        Complex(double real, double imag);
        double real() const;
        double imag() const;
        Complex operator*(Complex c) const;
        Complex operator*(double d) const;
        Complex operator/(Complex c) const;
        Complex operator/(double d) const;
        Complex operator+(Complex c) const;
        Complex operator+(double d) const;
        Complex operator-(Complex c) const;
        Complex operator-(double d) const;
        double abs() const;
        Complex conj() const;
        Complex exp() const;

    private:
        double a_;
        double b_;
    };

    Complex operator*(double d, const Complex &c);
    Complex operator/(double d, const Complex &c);
    Complex operator+(double d, const Complex &c);
    Complex operator-(double d, const Complex &c);

} // namespace complex_numbers

#endif // COMPLEX_NUMBERS_H
