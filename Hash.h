//@author:Wayne
//@version : 1.1 07/01/2017
//@Description: Variadic template Hash class
//
//Convert tuple to byte array, provide virtual hash function for subclass
// Example:
//    template<typename ...Types>
//    class MurmurHash : public Hash<Types...>
//    {
//    private:
//        std::uint32_t hash (const std::vector<std::uint8_t> & data) const {
//        int len = data.size();
//       const std::uint8_t * a = &data[0];
//       return murmurHash(a, len, Seed);
//   }
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
    //apply function takes the lambda express with variadic template
    template<typename ... Param, typename Functor>
    std::uint32_t apply(Functor getTuple, const Param& ... param)
    {
        std::tuple<Types...>  t = getTuple(param...);
        const std::vector<std::uint8_t> v = tupleToByteArray(t);
        print_vector(v);
        std::uint32_t result = hash(v);
        return result;
    }

private:

    // Returns a 32-bit hash value for byte array.
    // you have to implement hash function in sub class with specific hash algorithm.
    //@param byte array
    //@std::uint32_t 32-bit hash value
    virtual std::uint32_t hash(const std::vector<std::uint8_t> & v) const =0;

    //print the std::uint8_t array, debug
    template<typename T>
    static void print_vector(const T & v)
    {
        std::cout<<"the std::uint8_t array: [ "<<std::setfill('0');
        for (auto a : v)
        {
            std::cout<<std::setw(2)<<int(a)<<" ";
        }
        std::cout << "]\n\n" ;
    };

    //Iterates over the contents of a tuple and convert tuple to byte array.
    //@param t tuple
    //@return  byte array
    template<class... Args>
    std::vector<std::uint8_t>  tupleToByteArray(const std::tuple<Args...>& t)
    {
        return TupleToByte<decltype(t), sizeof...(Args)>::tupleToByteArray(t);
    };
    //start itertation
    template<class Tuple, std::size_t N>
    struct TupleToByte
    {
        static std::vector<std::uint8_t> tupleToByteArray(const Tuple& t)
        {
            std::vector<std::uint8_t> v = ByteVector::to_vector(std::get<N-1>(t)) ;
            const auto bytes= TupleToByte<Tuple, N-1>::tupleToByteArray(t);
            v.insert(v.end(), bytes.begin(), bytes.end());
            return v;
        }
    };
    //The end of tuple iteration
    template<class Tuple>
    struct TupleToByte<Tuple, 1>
    {
        static std::vector<std::uint8_t> tupleToByteArray(const Tuple& t)
        {
            const auto bytes= ByteVector::to_vector(std::get<0>(t));
            return bytes;
        }
    };

};

#endif // HASH_H

