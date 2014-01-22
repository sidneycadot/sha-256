
/////////////////
// xuint32_t.h //
/////////////////

#ifndef xuint32_h_t
#define xuint32_h_t

#include <cstdint>
#include <ostream>

class xuint32_t
{
    public:

        xuint32_t() : v(0)
        {
        }

        xuint32_t(const uint32_t & vi) : v(vi) {}

        xuint32_t(const xuint32_t & rhs) : v(rhs.v) {}

        uint32_t value() const
        {
            return v;
        }

        xuint32_t & operator = (const xuint32_t & rhs)
        {
            v = rhs.v;
            return *this;
        }

        xuint32_t & operator += (const xuint32_t & rhs)
        {
            v += rhs.v;
            return *this;
        }

        xuint32_t operator + (const xuint32_t & rhs) const
        {
            return v + rhs.v;
        }

        xuint32_t operator & (const xuint32_t & rhs) const
        {
            return v & rhs.v;
        }

        xuint32_t operator ^ (const xuint32_t & rhs) const
        {
            return v ^ rhs.v;
        }

        xuint32_t operator | (const xuint32_t & rhs) const
        {
            return v ^ rhs.v;
        }

        xuint32_t operator >> (const int & n) const
        {
            return v >> n;
        }

        xuint32_t operator << (const int & n) const
        {
            return v << n;
        }

        xuint32_t operator ~ () const
        {
            return ~v;
        }

    private:

        uint32_t v;
};

std::ostream & operator << (std::ostream & os, const xuint32_t & x)
{
    os << x.value();
    return os;
}

#endif // xuint32_h_t
