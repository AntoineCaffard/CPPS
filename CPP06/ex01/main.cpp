#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->day = 19;
    data->month = 10;
    data->year = 1998;

    uintptr_t raw = Serializer::serialize(data);

    std::cout << "raw = " << raw << std::endl << std::endl;

    Data *deserialized = Serializer::deserialize(raw);

    std::cout << deserialized->day << std::endl;
    std::cout << deserialized->month << std::endl;
    std::cout << deserialized->year << std::endl;

    delete data;
    return 0;
}