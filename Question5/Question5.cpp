using namespace std;
#include <string>
#include <iostream>

string solution(string n){
    // code here
    int m = n.length();
    int one = 0, two = 0;
    for(int i = 0; i < m; i++) {
		int j = i;
		while(j < m && n[j] == '0') {
			j++;
		}
		int curr = j - i;
		if(curr > one) {
			two = one;
			one = curr;
		} else if(curr > two) {
			two = curr;
		}
		i = j;
	}
	return (one % 2 && one / 2 + 1 > two) ? "A" : "B";
}

/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}
