#include <iostream>
#include "String.h"

using namespace justin_su;
int main()
{
    String s = "AAABBBCCC";
    std::cout << s << std::endl;
    s.replace("X", "YYY");
    std::cout << s << std::endl;
    return 0;
}
