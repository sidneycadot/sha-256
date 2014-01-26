
/////////////////////
// expr_uint32_t.h //
/////////////////////

#ifndef expr_uint32_h_t
#define expr_uint32_h_t

#include <ostream>
#include <memory>

class expr_t
{
};

class expr_uint32_t
{
    public:

        expr_uint32_t()
        {
        }

        expr_uint32_t(const uint32_t & vi)
        {
            (void)vi;
        }

        expr_uint32_t & operator = (const expr_uint32_t & rhs)
        {
            (void)rhs;
            return *this;
        }

    private:

        std::shared_ptr<expr_t> v;

    friend std::ostream & operator << (std::ostream & os, const expr_uint32_t & expr)
    {
        (void)expr;
        os << "expr";
        return os;
    }

};

expr_uint32_t operator >> (const expr_uint32_t & lhs, const int & n)
{
    (void)lhs;
    (void)n;
    return expr_uint32_t();
}

expr_uint32_t operator << (const expr_uint32_t & lhs, const int & n)
{
    (void)lhs;
    (void)n;
    return expr_uint32_t();
}

expr_uint32_t operator ^ (const expr_uint32_t & lhs, const expr_uint32_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return expr_uint32_t();
}

expr_uint32_t operator & (const expr_uint32_t & lhs, const expr_uint32_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return expr_uint32_t();
}

expr_uint32_t operator + (const expr_uint32_t & lhs, const expr_uint32_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return expr_uint32_t();
}

expr_uint32_t operator ~ (const expr_uint32_t & rhs)
{
    (void)rhs;
    return expr_uint32_t();
}

expr_uint32_t operator += (const expr_uint32_t & lhs, const expr_uint32_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return lhs;
}

std::ostream & operator << (std::ostream & os, const expr_uint32_t expr)
{
    (void)expr;
    os << "expr";
    return os;
}

#endif // xuint32_h_t
