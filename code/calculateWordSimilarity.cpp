#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct word {
       string name;
       int linkNum;
       vector<string> linkWord;
       vector<double> tfidf;
       vector<int> depth;
       int category_depth;
};

const int MAXN = 3000000;
const int K = 3;

int N;
word data[MAXN];
bool hash[MAXN];
map<string , int> index;

void    inputData() {
    freopen("page_link_page.txt","r",stdin);
    string str;
    int n = 0;
    double tmp;
    while (cin >> str) {
        index.insert(pair<string , int>(str , n));
        data[n].name = str;
        cin >> data[n].linkNum;
        for (int i = 0;i < data[n].linkNum;i ++) {
            cin >> str;
            cin >> tmp;
            data[n].linkWord.push_back(str);
            data[n].tfidf.push_back(tmp);
            data[n].depth.push_back(1);
        }
        n ++;
        N = n;
    }
}

void    category() {
    freopen("category.txt","r",stdin);
    string str;
    int category_depth;
    while (cin >> str) {
        cin >> category_depth;
        int n = index[str];
        data[n].category_depth = category_depth;
    }
}

void    work() {
    for (int i = 0;i < N;i ++) {
        map<string , bool> hash;
        
        for (int j = 0;j < data[i].linkNum;j ++) {
            hash.insert(pair<string , bool>(data[i].linkWord[j] , true));
        }
        
        for (int j = 0;j < data[i].linkWord.size();j ++)
            if (data[i].depth[j] <= K) {
                int t = index[data[i].linkWord[j]];
                for (int k = 0;k < data[t].linkNum;k ++) {
                    double tfidf;
                    tfidf = 1.0/(1.0/data[i].tfidf[j] + 1.0/data[t].tfidf[k]);
                    data[i].linkWord.push_back(data[t].linkWord[k]);
                    data[i].depth.push_back(data[i].depth[j] + 1);
                    data[i].tfidf.push_back(tfidf);
                }
            }
    }
}

double  calcws(string a , string b) {
    int a_index = index[a] , b_index = index[b];
    return 0.0;
}

int main () {
    inputData();
    category();
    work();
    return 0;
}
