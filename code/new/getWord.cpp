#include <iostream>
#include <cstring>
#include <cstdio>

char str[65535];

int main() {
    freopen("mapOffset.txt","r",stdin);
    freopen("word.txt","w",stdout);
    while (gets(str)) {
        std::cout << str << std::endl;
        gets(str);
    }
    return 0;
}
