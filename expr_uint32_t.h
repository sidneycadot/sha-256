
/////////////////////
// expr_uint32_t.h //
/////////////////////

#ifndef expr_uint32_h_t
#define expr_uint32_h_t

#include <ostream>
//#include <cstdint>
//#include <ostream>
#include <memory>

class expr_uint32_t;

typedef std::shared_ptr<const expr_uint32_t> expr_uint32_ptr_t;

class expr_uint32_t
{
    expr_uint32_t(const uint32_t & vi)
    {
        (void)vi;
    }

    friend std::ostream & operator << (std::ostream & os, const expr_uint32_t & expr)
    {
        (void)expr;
        os << "expr";
        return os;
    }

};

expr_uint32_ptr_t operator >> (const expr_uint32_ptr_t & lhs, const int & n)
{
    (void)lhs;
    (void)n;
    return expr_uint32_ptr_t();
}

expr_uint32_ptr_t operator << (const expr_uint32_ptr_t & lhs, const int & n)
{
    (void)lhs;
    (void)n;
    return expr_uint32_ptr_t();
}

expr_uint32_ptr_t operator ^ (const expr_uint32_ptr_t & lhs, const expr_uint32_ptr_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return expr_uint32_ptr_t();
}

expr_uint32_ptr_t operator & (const expr_uint32_ptr_t & lhs, const expr_uint32_ptr_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return expr_uint32_ptr_t();
}

expr_uint32_ptr_t operator + (const expr_uint32_ptr_t & lhs, const expr_uint32_ptr_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return expr_uint32_ptr_t();
}

expr_uint32_ptr_t operator ~ (const expr_uint32_ptr_t & rhs)
{
    (void)rhs;
    return expr_uint32_ptr_t();
}

expr_uint32_ptr_t operator += (const expr_uint32_ptr_t & lhs, const expr_uint32_ptr_t & rhs)
{
    (void)lhs;
    (void)rhs;
    return expr_uint32_ptr_t();
}

std::ostream & operator << (std::ostream & os, const expr_uint32_ptr_t expr)
{
    os << *expr;
    return os;
}

#endif // xuint32_h_t
