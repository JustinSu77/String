#include <iostream>
#include "String.h"

using namespace justin_su;
int main()
{
    String s = "Justin Su";
    std::cout << s << std::endl;
    s.replace("Justin", "Sarah");
    std::cout << s << std::endl;
    return 0;
}
