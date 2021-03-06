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

vector<int> getNumberAsVector(int n){
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
    return numbers;
}

int desc_digits(int n){

    vector<int> nums = getNumberAsVector(n);
    sort(nums.begin(),nums.end());
    return backToInt(nums);

}

int asc_digits(int n){

    vector<int> nums = getNumberAsVector(n);
    sort(nums.begin(),nums.end(), greater<int>());
    return backToInt(nums);

}

bool twoUnique(int n){

    vector<int> numbers = getNumberAsVector(n);

    for(int i=1; i<4; i++){
        if(numbers[i] != numbers[0]){
            return true;
        }
    }

    return false;

}

int kaprekar(int iter, int number){

    if(!twoUnique(number)){
        return 0;
    }

    if(number == 6174){
        return iter;
    } else {
        return kaprekar(++iter, desc_digits(number) - asc_digits(number));
    }
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

    cout << "======================\n";

    cout << kaprekar(0, 6589) << "\n";
    cout << kaprekar(0, 5455) << "\n";
    cout << kaprekar(0, 6174) << "\n";

}
