/*
  Author: Wiki
  Date: 11/05/15 10:24
  Description: calcuate the Map of the wordname and the position of the word in the file
*/
#include <iostream>
#include <fstream>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

char temp[65535];

void    work() {
    int n = 0;
    string wordname;
    int offset;
    offset = cin.tellg();
    while (cin >> wordname) {
        string tmpwordname;
        char c;
        while (c = cin.get() != '\t') {
            cin >> tmpwordname;
            wordname = wordname + c + tmpwordname;
        }
        gets(temp);
        cout << wordname << endl;
        cout << offset << endl;
        offset = cin.tellg();
        wordname = "";
    }
}

int main() {
    freopen("CKG.txt","r",stdin);
    freopen("mapOffset.txt","w",stdout);
    
    work();
    
    return 0;
}
