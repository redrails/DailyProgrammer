#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
    Main Problem
*/

int largest_digit(int last, int n){
    if(n < 10){
        if(n > last){
            return n;
        } else {
            return last;
        }
    } else {
        if(last > n%10){
            return largest_digit(last, n/10);
        } else {
            return largest_digit(n%10, n/10);
        }
    }
}

/*
    Bonus 1
*/
int backToInt(const vector<int>& numbers){
    int c = 1;
    int result = 0;
    for(int i=0; i<numbers.size(); i++){
        result += numbers.at(i)*c;
        c*=10;
    }
    return result;
}

int desc_digits(int n){

    vector<int> numbers{};
    for(int i=0; i<4; i++){
        numbers.push_back(n%10);
        n /= 10;
    }

    if(numbers.size() < 4){
        int toPush = 4-numbers.size();
        for(int i=0; i<toPush; i++){
            numbers.insert(numbers.begin(), 0);
        }
    }
    sort(numbers.begin(),numbers.end());
    return backToInt(numbers);

}

int main(){

    cout << largest_digit(0, 1234) << "\n";
    cout << largest_digit(0, 3253) << "\n";
    cout << largest_digit(0, 9800) << "\n";
    cout << largest_digit(0, 3333) << "\n";
    cout << largest_digit(0, 120) << "\n";

    cout << "======================\n";
    cout << desc_digits(1234) << "\n";
    cout << desc_digits(3253) << "\n";
    cout << desc_digits(9800) << "\n";
    cout << desc_digits(3333) << "\n";
    cout << desc_digits(120) << "\n";

}
