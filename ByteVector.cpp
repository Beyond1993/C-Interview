#include "ByteVector.h"

std::vector<byte> ByteVector::to_vector(const int & object)
{
    std::vector<byte> bytes(sizeof(int) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(int) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes;
}

std::vector<byte> ByteVector::to_vector(const long & object)
{
    std::vector<byte> bytes(sizeof(long) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(long) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}

std::vector<byte> ByteVector::to_vector(const double & object)
{
    std::vector<byte> bytes(sizeof(double) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(double) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}

std::vector<byte> ByteVector::to_vector(const float & object)
{
    std::vector<byte> bytes(sizeof(float) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(float);
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}


std::vector<byte> ByteVector::to_vector(const std::string & s)
{ 
    std::vector<byte> v(s.begin(), s.end());
    return v;
}

std::vector<byte> ByteVector::to_vector(const char * & c)
{
    std::string s(c);
    std::vector<byte> v(s.begin(), s.end());
    return v;
}
