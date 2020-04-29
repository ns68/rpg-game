#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include "generator.hpp"



// int generator
int gen::int_generator(int min, int max) {
    std::vector<int> in;
    for( int i = min; i < max; i++ )
        in.push_back( i );
    //const std::vector<int> in {1, 2, 3, 5, 7, 8, 9, 10};
    std::vector<int> out;
    size_t nelems = 1; // nombre de chiffres à generer
    std::sample(
        in.begin(),
        in.end(),
        std::back_inserter(out),
        nelems,
        std::mt19937{std::random_device{}()}
    );
    
    //for (auto i : out)
    //    return i;
    return out[0];
}

// string generator
std::string gen::s_generator() {
    const std::vector<std::string> in 
        {"Brutus", "Patricius", "Goliath", "David", "Alexus", "Romulus"};
    std::vector<std::string> out;
    size_t nelems = 1; // nombre de chiffres à generer
    std::sample(
        in.begin(),
        in.end(),
        std::back_inserter(out),
        nelems,
        std::mt19937{std::random_device{}()}
    );
    //for (auto s : out)
    //    return s;
    return out[0];
}


std::string gen::from_vector_generator(const std::vector<std::string> &v)
{
    std::vector<std::string> in = v;
    std::vector<std::string> out;
    size_t nelems = 1; // nombre de chiffres à generer
    std::sample(
        in.begin(),
        in.end(),
        std::back_inserter(out),
        nelems,
        std::mt19937{std::random_device{}()}
    );
    //for (auto s : out)
    //    return s;
    return out[0];

}

#ifdef TEST_UTILITIES
int main()
{
    const std::vector<std::string> names {"Nicolas", "David", "Goliath", "Alex"};
    std::cout << gen::int_generator() << std::endl;
    std::cout << gen::s_generator() << std::endl;
    std::cout << gen::from_vector_generator(names) << std::endl;
}
#endif