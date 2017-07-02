#include "MurmurHash.h"
using byte = unsigned char ;

int main()
{
    MurmurHash<std::string, int, char *> key;
    auto getTuple = [](const auto& ... p)
    {
        const auto items = std::make_tuple(p...);
        return items;
    };
    char * c = "cba";
    const auto hashcode = key.apply(getTuple , "abc", 3, c);
    std::cout<<hashcode<<std::endl;
    return 0;
}
