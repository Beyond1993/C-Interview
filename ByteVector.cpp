#include "ByteVector.h"

std::vector<std::uint8_t> ByteVector::to_vector(const int & value)
{
    std::vector<std::uint8_t> bytes(sizeof(int) / sizeof(std::uint8_t), 0);
    const std::uint8_t* begin = reinterpret_cast< const std::uint8_t* >( std::addressof(value) ) ;
    const std::uint8_t* end = begin + sizeof(int) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes;
}

std::vector<std::uint8_t> ByteVector::to_vector(const long & value)
{
    std::vector<std::uint8_t> bytes(sizeof(long) / sizeof(std::uint8_t), 0);
    const std::uint8_t* begin = reinterpret_cast< const std::uint8_t* >( std::addressof(value) ) ;
    const std::uint8_t* end = begin + sizeof(long) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}

std::vector<std::uint8_t> ByteVector::to_vector(const double & value)
{
    std::vector<std::uint8_t> bytes(sizeof(double) / sizeof(std::uint8_t), 0);
    const std::uint8_t* begin = reinterpret_cast< const std::uint8_t* >( std::addressof(value) ) ;
    const std::uint8_t* end = begin + sizeof(double) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}

std::vector<std::uint8_t> ByteVector::to_vector(const float & value)
{
    std::vector<std::uint8_t> bytes(sizeof(float) / sizeof(std::uint8_t), 0);
    const std::uint8_t* begin = reinterpret_cast< const std::uint8_t* >( std::addressof(value) ) ;
    const std::uint8_t* end = begin + sizeof(float);
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}


std::vector<std::uint8_t> ByteVector::to_vector(const std::string & value)
{
    std::vector<std::uint8_t> v(value.begin(), value.end());
    return v;
}

std::vector<std::uint8_t> ByteVector::to_vector(const char * & value)
{
    std::vector<std::uint8_t> v(value, value + strlen(value));
    return v;
}
