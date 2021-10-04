#include <string>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n = s.length();
    int one = 0, two = 0;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && s[j] == '0') j++;
        int curr = j - i;
        if(curr > one) {
            two = one;
            one = curr;
        } else if(curr > two) {
            two = curr;
        }
        i = j;
    }
    string ans = (one % 2 && one / 2 + 1 > two) ? "A" : "B";
    cout<<ans<<endl;
}
