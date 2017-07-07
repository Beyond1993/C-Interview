//@author:Wayne
//@version : 1.1 -07/01/2017
//@Description: Variadic template MurmurHash class extends Hash class
//
//Return murmur hash value according to byte array.
// Example:
//    auto getTuple = [](const auto& ... p)
//   {
//        const auto items = std::make_tuple(p...);
//        return items;
//    };
//    MurmurHash<std::string, int, double,float> key;
//    std::cout<<"key: <std::string, int, double, float> (\"abc\", 3, 1.2, 1.3) \n";
//    auto hashcode = key.apply(getTuple , "abc", 3, 1.2, 1.3);
//    std::cout<<"hashcode is "<<hashcode<<std::endl<<std::endl;

#ifndef MURMURHASH_H
#define MURMURHASH_H
#include "Hash.h"

const std::uint32_t Seed = 0xbc9f1d34;

template<typename ...Types>
class MurmurHash : public Hash<Types...>
{
private:
    //override the hash function in Hash class.
    //@param data byte array
    //@return  32-bits hash value
    std::uint32_t hash (const std::vector<std::uint8_t> & data) const
    {
        int len = data.size();
        const std::uint8_t * a = &data[0];
        return murmurHash(a, len, Seed);
    }

    //murmur hash algorithm
    //@param key byte array
    //@param len length of array
    // @param seed randon seed.
    //@return 32-bits hash value
    std::uint32_t murmurHash(const std::uint8_t* key, std::size_t len, std::uint32_t seed) const
    {
        std::uint32_t h = seed;
        if (len > 3)
        {
            const std::uint32_t* key_x4 = (const std::uint32_t*) key;
            std::size_t i = len >> 2;
            do
            {
                std::uint32_t k = *key_x4++;
                k *= 0xcc9e2d51;
                k = (k << 15) | (k >> 17);
                k *= 0x1b873593;
                h ^= k;
                h = (h << 13) | (h >> 19);
                h = (h * 5) + 0xe6546b64;
            }
            while (--i);
            key = (const std::uint8_t*) key_x4;
        }
        if (len & 3)
        {
            std::size_t i = len & 3;
            std::uint32_t k = 0;
            key = &key[i - 1];
            do
            {
                k <<= 8;
                k |= *key--;
            }
            while (--i);
            k *= 0xcc9e2d51;
            k = (k << 15) | (k >> 17);
            k *= 0x1b873593;
            h ^= k;
        }
        h ^= len;
        h ^= h >> 16;
        h *= 0x85ebca6b;
        h ^= h >> 13;
        h *= 0xc2b2ae35;
        h ^= h >> 16;
        return h;

    }
};

#endif
