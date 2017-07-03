/*************************************************

@author:Wayne

@version : 1.1 -07/01/2017

@Description: Define a variadic template class with virtual hash function. 
                         Different classes extends this class to implement different hash algorithm

**************************************************/
#ifndef HASH_H
#define HASH_H
#include <vector>
#include <iostream>
#include <tuple>
#include <string>
#include <type_traits>
#include <iomanip>
#include "ByteVector.h"

template <typename... Types>
class Hash
{
public:
    /*apply function takes the lambda express*/
    template<typename ... Param, typename Functor>
    long apply(Functor getTuple, const Param& ... param)
    {
        std::tuple<Types...>  t = getTuple(param...);
        const std::vector<byte> v = tupleToByteArray(t);
        print_vector(v);
        long result = hash(v);
        return result;
    }
    
private:

    /*any hash algorithm that use byte array as input*/
    virtual long hash(const std::vector<byte> & v);

    /*print the byte array, debug */
    template<typename T>
    static void print_vector(const T & v)
    {
        std::cout<<"the byte array: [ "<<std::setfill('0');
        for (auto a : v)
        {
            std::cout<<std::setw(2)<<int(a)<<" ";
        }
        std::cout << "]\n\n" ;
    };

    /*Iterator the tuple recurively*/
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
    /*The end of tuple iteration*/
};

#endif // HASH_H

