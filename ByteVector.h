#ifndef BYTEVECTOR_H
#define BYTEVECTOR_H
#include <vector>
#include <string>
#include <iostream>

using byte = unsigned char;
class ByteVector
{
public:
    //ByteVector();
    //virtual ~ByteVector();
    static std::vector<byte> to_vector(const int & object);
    static std::vector<byte> to_vector(const double & c);
    static std::vector<byte> to_vector(const long & c);
    static std::vector<byte> to_vector(const float & c);
    static std::vector<byte> to_vector(const char & c);
    static std::vector<byte> to_vector(const std::string & s);
    static std::vector<byte> to_vector(const char * & c);


    template<typename T>
    static void print_vector(const T & v);
protected:

private:
};

#endif // BYTEVECTOR_H
