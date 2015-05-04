#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

char word[1000][50];
char str[50];

int main() {
    freopen("a.txt","r",stdin);
    freopen("word.txt","w",stdout);
    int n = 0;
    while (cin >> str) {
        bool flag = true;
        for (int i = 0;i < n;i ++)
            if (!strcmp(str,word[i])) {
                flag = false;
                break;
            }
        if (flag) {
            cout << str << endl;
            strcpy(word[n ++] , str);
        }
    }
    
    return 0;
}
