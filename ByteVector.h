#ifndef BYTEVECTOR_H
#define BYTEVECTOR_H
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
//@author:Wayne
//@version : 1.1 07/01/2017
//@Description: ByteVector class
//
//Return byte array with simple  types of variable.
// Example:
//    int  a = 1;
//    std::vector<std::unit8_t> v = ByteVector::to_vector(a);
//
// @TODO The first version just supports the simple types of variable.
//                It is easy to add other types, such as long long.
class ByteVector
{
public:
    static std::vector<std::uint8_t> to_vector(const int & value);
    static std::vector<std::uint8_t> to_vector(const double & value);
    static std::vector<std::uint8_t> to_vector(const long & value);
    static std::vector<std::uint8_t> to_vector(const float & value);
    static std::vector<std::uint8_t> to_vector(const char & value);
    static std::vector<std::uint8_t> to_vector(const std::string & value);
    static std::vector<std::uint8_t> to_vector(const char * & value);
};

#endif // BYTEVECTOR_H