/*
  Author: Wiki
  Date: 11/05/15 13:28
  Description: calcuate Expand Explict Semantic Algorithm
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <cstring>

using namespace std;

map<string , int> mapOffset;


void    getMap() {
    freopen("mapOffset.txt","r",stdin);
    string wordname , tempwordname;
    int offset;
    while (cin >> wordname) {
        char c;
        while (c = getchar() != '\n') {
            cin >> tempwordname;
            wordname += c + tempwordname;
        }
        cin >> offset;
        mapOffset.insert(pair<string , int>(wordname , offset));
    }
    fclose(stdin);
}

int main() {
    getMap();
    return 0;
}
