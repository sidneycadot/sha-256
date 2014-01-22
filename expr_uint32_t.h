
/////////////////////
// expr_uint32_t.h //
/////////////////////

#ifndef expr_uint32_h_t
#define expr_uint32_h_t

#include <cstdint>
//#include <ostream>
#include <memory>

class expr_t
{
};

class expr_constant_t : public expr_t
{
};

shared_ptr<expr_t> & operator +=(shared_ptr<expr_t> & lhs, const shared_ptr<expr_t> & lhs)
{
    lhs = expr_plus_t(lhs, rhs);
    return lhs;
}

class expr_uint32_t
{
    public:

        expr_uint32_t() : v(std::make_shared<expr_constant_t>(0))
        {
        }

        expr_uint32_t(const uint32_t & vi) : v(std::make_shared<expr_constant_t>(vi)) {}

        expr_uint32_t(const expr_uint32_t & rhs) : v(rhs.v) {}

        std::shared_ptr<expr_t> value() const
        {
            return v;
        }

        expr_uint32_t & operator = (const expr_uint32_t & rhs)
        {
            v = rhs.v;
            return *this;
        }

        expr_uint32_t & operator += (const expr_uint32_t & rhs)
        {
            v +=rhs.v;
            return *this;
        }

        expr_uint32_t operator + (const expr_uint32_t & rhs) const
        {
            return v + rhs.v;
        }

        expr_uint32_t operator & (const expr_uint32_t & rhs) const
        {
            return v & rhs.v;
        }

        expr_uint32_t operator ^ (const expr_uint32_t & rhs) const
        {
            return v ^ rhs.v;
        }

        expr_uint32_t operator | (const expr_uint32_t & rhs) const
        {
            return v ^ rhs.v;
        }

        expr_uint32_t operator >> (const int & n) const
        {
            return v >> n;
        }

        expr_uint32_t operator << (const int & n) const
        {
            return v << n;
        }

        expr_uint32_t operator ~ () const
        {
            return ~v;
        }

    private:

        std::shared_ptr<expr_t> v;
};

std::ostream & operator << (std::ostream & os, const expr_uint32_t & x)
{
    os << x.value();
    return os;
}

#endif // xuint32_h_t
