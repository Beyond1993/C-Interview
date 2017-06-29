#include <iostream>
#include <tuple>
#include <string>
#include <memory>
#include <type_traits>
#include <array>
#include <iomanip>
#include "ByteVector.h"
#include "MurmurHash.h"
using byte = unsigned char ;

template <typename... Types>
class Data
{

public:

    template<typename ... Param>
    std::tuple<Types...> apply(const Param& ... param)
    {
        std::tuple<Types...>  items = std::tuple<Types...>(param...);
        return items;
    }

    // helper function to print a tuple of any size
    template<class Tuple, std::size_t N>
    struct TuplePrinter
    {
        static std::vector<byte> tupleToByteArray(const Tuple& t)
        {
            std::vector<byte> v = ByteVector::to_vector(std::get<N-1>(t)) ;

            const auto bytes = TuplePrinter<Tuple, N-1>::tupleToByteArray(t);
            //return bytes;
            /*std::cout << std::hex << std::setfill('0') ;
            for( byte b : bytes ) std::cout << std::setw(2) << int(b) << ' ' ;
            std::cout << '\n' ;*/

            v.insert(v.end(), bytes.begin(), bytes.end());
            return v;
        }
    };

    template<class Tuple>
    struct TuplePrinter<Tuple, 1>
    {
        static std::vector<byte> tupleToByteArray(const Tuple& t)
        {
            const auto bytes = ByteVector::to_vector(std::get<0>(t)) ;

            /*std::cout << std::hex << std::setfill('0') ;
            for( byte b : bytes ) std::cout << std::setw(2) << int(b) << ' ' ;
            std::cout << '\n' ;*/
            return bytes;

        }
    };


    template<class... Args>
    std::vector<byte> tupleToByteArray(const std::tuple<Args...>& t)
    {
        return TuplePrinter<decltype(t), sizeof...(Args)>::tupleToByteArray(t);

    }

};



int main()
{
    Data<std::string, int,double> data1;
    const auto t = data1.apply("hello", 3,1.9);

    const std::vector<byte> v = data1.tupleToByteArray(t);
    long result = MurmurHash::hash(v, v.size(),40);
    std::cout<<result<<std::endl;    //ByteVector::print_vector(v);
    return 0;
}
