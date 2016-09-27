#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#define pb push_back
using namespace std;
map<string, int> checking;
vector<string> vc;

template<typename It>
bool permutate(It begin, It end){
    
    if (begin == end) return false;
    It i = begin+1;
    if (i == end) return false;
    
    i = end-1;
    
    while (true){
        It j = i--;
        if (*i < *j){
            It k = end;
            while (!(*i < *--k));
            iter_swap(i, k);
            reverse(j, end);
            return true;
        }
        if (i == begin){
            reverse(begin, end);
            return false;
        }
    }
}


int main () {
    string myStr;
    cin >> myStr;
    sort(myStr.begin(), myStr.end());
    // Time computating
    clock_t start, finish;
    start = clock();
    do {
        if (!checking[myStr]){
            checking[myStr] = 1;
            vc.pb(myStr);
        }
    } while (permutate(myStr.begin(), myStr.end()));
    
    sort(vc.begin(),vc.end());
    int count = 1;
    for (vector<string>::iterator it = vc.begin(); it != vc.end(); ++it) {
        cout << count++ << "\t" << *it << endl;
    }
    
    // Time Printing
    finish = clock();
    cout << endl << "Time took for computing is: " << ((double)(finish - start))/CLOCKS_PER_SEC << endl;
    return 0;
}