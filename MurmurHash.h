/*************************************************

@author:Wayne

@version : 1.1 -07/01/2017

@Description: MurmurHash class extends Hash class
	           Override hash function form Hash.	
                        Different classes extends this class to implement different hash algorithm

**************************************************/
#ifndef MURMURHASH_H
#define MURMURHASH_H
#include "Hash.h"

const int Seed = 4;

template<typename ...Types>
class MurmurHash : public Hash<Types...>
{
private:
    /*override the hash function in Hash class.
      @param 
      @return long 64-bits hash value
    */	
    long hash (const std::vector<byte> & data);

    /*smurmur hash algorithm
     @param data 
     @return 64-bits hash value
    */
    long murmurHash(const std::vector<byte> & data, int length, int seed);
};

#endif