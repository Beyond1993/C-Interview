#ifndef MURMURHASH_H
#define MURMURHASH_H
#include <vector>
#include <iostream>
#include <tuple>
#include <string>
#include <type_traits>
#include <array>
#include <iomanip>
#include "ByteVector.h"
using byte = unsigned char;
//https://github.com/tnm/murmurhash-java/blob/master/src/main/java/ie/ucd/murmur/MurmurHash.java
template <typename... Types>
class Hash
{
public:

    template<typename ... Param, typename Functor>
    long apply(Functor getTuple, const Param& ... param)
    {
        std::tuple<Types...>  t = getTuple(param...);
        const std::vector<byte> v = tupleToByteArray(t);
        print_vector(v);
        long result = hash(v);
        //std::cout<<result<<std::endl;
        return result;
    }
    
private:
    virtual long hash(const std::vector<byte> & v);
    template<typename T>
    static void print_vector(const T & v)
    {
        std::cout<<std::setfill('0');
        for (auto a : v)
        {
            std::cout<<std::setw(2)<<int(a)<<std::endl;
        }
        std::cout << '\n' ;
    };

///////////////////////////////////////
    template<class... Args>
    std::vector<byte>  tupleToByteArray(const std::tuple<Args...>& t)
    {
        return TupleToByte<decltype(t), sizeof...(Args)>::tupleToByteArray(t);
    };
    
   template<class Tuple, std::size_t N>
    struct TupleToByte
    {
        static std::vector<byte> tupleToByteArray(const Tuple& t)
        {
            
            std::vector<byte> v = ByteVector::to_vector(std::get<N-1>(t)) ;
            const auto bytes = TupleToByte<Tuple, N-1>::tupleToByteArray(t);
            v.insert(v.end(), bytes.begin(), bytes.end());
            return v;
        }
    };
    template<class Tuple>
    struct TupleToByte<Tuple, 1>
    {
        static std::vector<byte> tupleToByteArray(const Tuple& t)
        {
            const auto bytes = ByteVector::to_vector(std::get<0>(t));
            return bytes;
        }
    };
};

#endif // MURMURHASH_H

