#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data     *ptr, *deserial;
    uintptr_t serial;

    ptr          = new Data(false, 'h', 42, "test");
    serial   = Serializer::serialize(ptr);
    deserial = Serializer::deserialize(serial);
    std::cout << std::endl << "Data before serialization:    " << std::endl << *ptr
            	<< "Serial: " << serial << std::endl
				<< "Data after serialization:     " << std::endl << *deserial <<std::endl;
    delete ptr;
}