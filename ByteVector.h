#ifndef BYTEVECTOR_H
#define BYTEVECTOR_H
#include <vector>
#include <string>
#include <iostream>
using byte = unsigned char;
/*convert the primary type to byte array*/
class ByteVector
{
public:
    static std::vector<byte> to_vector(const int & object);
    static std::vector<byte> to_vector(const double & c);
    static std::vector<byte> to_vector(const long & c);
    static std::vector<byte> to_vector(const float & c);
    static std::vector<byte> to_vector(const char & c);
    static std::vector<byte> to_vector(const std::string & s);
    static std::vector<byte> to_vector(const char * & c);
};

#endif // BYTEVECTOR_H
