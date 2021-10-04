using namespace std;
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;	
    int answer = n / 3 * 2 + (n % 3 > 0);
    cout<<answer<<endl;	
}
