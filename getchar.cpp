#include <iostream>

using namespace std;

int main(){
    int sum = 0;

    cout << "Please enter a series int:";

    int i;
    while (cin >> i){
        sum += i;
        while (cin.peek() == ' '){
            cin.get();
        }
        if(cin.peek() == '\n'){
            break;
        }
    }
    cout << "Answer is: " << sum << endl;
    return 0;
}
