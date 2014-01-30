
///////////////
// xuint_t.h //
///////////////

#ifndef xuint_t_h
#define xuint_t_h

#include <cstdint>
#include <ostream>

template <typename basetype>
class xuint_t
{
    public:

        xuint_t() : v(0)
        {
        }

        xuint_t(const basetype & vi) : v(vi) {}

        xuint_t(const xuint_t & rhs) : v(rhs.v) {}

        // xuint_t(const uint32_value_t & vi) : v(vi) {}

        xuint_t & operator = (const xuint_t & rhs)
        {
            v = rhs.v;
            return *this;
        }

        xuint_t & operator = (const basetype & rhs)
        {
            v = rhs;
            return *this;
        }

        xuint_t & operator += (const xuint_t & rhs)
        {
            v += rhs.v;
            return *this;
        }

        xuint_t operator + (const xuint_t & rhs) const
        {
            return v + rhs.v;
        }

        xuint_t operator & (const xuint_t & rhs) const
        {
            return v & rhs.v;
        }

        xuint_t operator ^ (const xuint_t & rhs) const
        {
            return v ^ rhs.v;
        }

        xuint_t operator | (const xuint_t & rhs) const
        {
            return v ^ rhs.v;
        }

        xuint_t operator >> (const int & n) const
        {
            return v >> n;
        }

        xuint_t operator << (const int & n) const
        {
            return v << n;
        }

        xuint_t operator ~ () const
        {
            return ~v;
        }

    private:

        basetype v;

    friend std::ostream & operator << (std::ostream & os, const xuint_t & x)
    {
        os << x.v;
        return os;
    }
};

#endif // xuint_t_h
