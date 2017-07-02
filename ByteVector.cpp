#include "ByteVector.h"

std::vector<byte> ByteVector::to_vector(const int & object)
{
    std::cout<<"int"<<std::endl;
    std::vector<byte> bytes(sizeof(int) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(int) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes;
}


std::vector<byte> ByteVector::to_vector(const long & object)
{
    std::cout<<"int"<<std::endl;
    std::vector<byte> bytes(sizeof(long) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(long) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}


std::vector<byte> ByteVector::to_vector(const double & object)
{
    std::cout<<"int"<<std::endl;
    std::vector<byte> bytes(sizeof(double) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(double) ;
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}

std::vector<byte> ByteVector::to_vector(const float & object)
{
    std::cout<<"int"<<std::endl;
    std::vector<byte> bytes(sizeof(float) / sizeof(byte), 0);
    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
    const byte* end = begin + sizeof(float);
    std::copy(begin, end, std::begin(bytes));
    return bytes ;
}


std::vector<byte> ByteVector::to_vector(const std::string & s)
{   std::cout<<"string"<<std::endl;
    std::vector<byte> v;
    for (int i = 0; i < s.size(); i++)
    {
        v.push_back((byte)s[i]);
    }
    return v;
}

std::vector<byte> ByteVector::to_vector(const char * & c)
{
    std::cout<<"char *"<<std::endl;
    std::string s(c);
    std::vector<byte> v(s.begin(), s.end());
    return v;
}

template<typename T>
void ByteVector::print_vector(const T & v)
{
    for (auto a : v)
    {
        std::cout<<a<<std::endl;
    }
}
