#include <iostream>
#include <type_traits>

class A
{
    A() noexcept = delete;
};

class B
{
    
};

int main()
{
    std::cout << std::is_nothrow_default_constructible_v<A> << std::endl;
    std::cout << std::is_nothrow_default_constructible_v<B> << std::endl;
}