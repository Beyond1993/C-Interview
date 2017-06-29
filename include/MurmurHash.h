#ifndef MURMURHASH_H
#define MURMURHASH_H
#include <vector>
using byte = unsigned char;
//https://github.com/tnm/murmurhash-java/blob/master/src/main/java/ie/ucd/murmur/MurmurHash.java
class MurmurHash
{
    public:
        MurmurHash();
        virtual ~MurmurHash();
        static long hash(const std::vector<byte> & data, int length, int seed);

    protected:

    private:
};

#endif // MURMURHASH_H
