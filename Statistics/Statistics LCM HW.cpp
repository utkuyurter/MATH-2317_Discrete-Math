#include<iostream>#include<vector>#define pb push_backusing namespace std;int a , b , c , d, lcm;int GCD(int a, int b){ //  Great Common Divisor function with recursion.        if(b == 0){        return a;    }else{        return GCD(b, a%b);    }    }int main () {        cin >> a >> b >> c;    while(a != 0 && b != 0 && c!= 0){                cout << "a = " << a << " - b = " << b << " - c = " << c << endl;        cout << "---SETS---\n";        lcm = (((a * b) / GCD(a, b)) * c) / GCD(((a * b) / GCD(a, b)), c);        a = lcm/a;        b = lcm/b;        c = lcm/c;        d = lcm - a - b - c;        vector<int> as,bs,us;        for(int i = 0; i < a-c; ++i)            as.pb(i);        for(int i = a; i < b+a-c; ++i)            bs.pb(i);        for(int i = b+a-c; i < b+a; ++i){            bs.pb(i);            as.pb(i);        }        for(int i = b+a; i < b+a+d; ++i)            us.pb(i);                cout << "Set A : ";        for(vector<int>::iterator i = as.begin(); i != as.end(); ++i)            cout << *i << " ";        cout << endl << "Set B : ";        for(vector<int>::iterator i = bs.begin(); i != bs.end(); ++i)            cout << *i << " ";        cout << endl << "Universal Set : ";        for(vector<int>::iterator i = as.begin(); i != as.end(); ++i)            cout << *i << " ";        for(vector<int>::iterator i = bs.begin(); i != bs.end(); ++i)            cout << *i << " ";        for(vector<int>::iterator i = us.begin(); i != us.end(); ++i)            cout << *i << " ";        cout << endl << endl;        cin >> a >> b >> c;    }    }