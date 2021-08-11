#include <iostream>
#include <string>
#include <set>
using namespace std;

bool mycomp(int a, int b){
	if(a>b)
	return true;
	return false;
}

int main() {
    set<int, decltype(&mycomp)> s(&mycomp);

    s.insert(1);
    s.insert(10);
    s.insert(11);
    s.insert(100);

    for (int x : s)
        cout << x << ' ';

    return 0;
}
