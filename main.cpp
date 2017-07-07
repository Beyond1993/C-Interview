#include "MurmurHash.h"
//main function for the demo.
//@TODO The context of this class is not clear, to simplify this problem.
//              assume the parameter is valid.
//              But it is necessary to add try catch or verification.

int main()
{
    auto getTuple = [](const auto& ... p)
    {
        const auto items = std::make_tuple(p...);
        return items;
    };

    MurmurHash<std::string, int, double,float> key1;
    std::cout<<"key: <std::string, int, double, float> (\"abc\", 3, 1.2, 1.3) \n";
    auto hashcode = key1.apply(getTuple, "abc", 3, 1.2, 1.3);
    std::cout<<"hashcode is "<<hashcode<<std::endl<<std::endl;

    MurmurHash<std::string, int, char *> key2;
    char a[] = "cba";
    char * c = a;
    std::cout<<"key: <std::string, int, char *> (\"abc\", 3, char * c = \"cba\") \n";
    hashcode = key2.apply(getTuple, "abc", 3, c);
    std::cout<<"hashcode is "<<hashcode<<std::endl<<std::endl;

    MurmurHash<std::string, int, long> key3;
    std::cout<<"key: <std::string, int, long> (\"abc\", 3, 10000000000000000) \n";
    hashcode = key3.apply(getTuple, "abc", 3, 10000000000000000);
    std::cout<<"hashcode is "<<hashcode<<std::endl<<std::endl;

    MurmurHash<std::string, int, int,int,int,int,int> key4;
    std::cout<<"key: <std::string, int, int,int,int,int,int> (\"abc\", 1, 2, 3,4,5,6) \n";
    hashcode = key4.apply(getTuple, "abc", 1, 2, 3,4,5,6);
    std::cout<<"hashcode is "<<hashcode<<std::endl<<std::endl;

    MurmurHash<std::string> key5;
    std::cout<<"key: <std::string> (\"Hello BigStream\") \n";
    hashcode = key5.apply(getTuple, "Hello BigStream");
    std::cout<<"hashcode is "<<hashcode<<std::endl<<std::endl;

    MurmurHash<int, double, std::string> key6;
    std::cout<<"key: <int, double, std::string> (NULL, NULL,\"\") \n";
    hashcode = key6.apply(getTuple,NULL, NULL, "");
    std::cout<<"hashcode is "<<hashcode<<std::endl<<std::endl;

    return 0;
}
