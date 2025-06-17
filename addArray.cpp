#include <iostream>

 // using namespace std;

int addArray(int array[], int n);

int main(){
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(data) / sizeof(data[0]);

    std::cout << "Answer is: " << addArray(data, size) <<std::endl;
    return 0;
}
int addArray(int *array, int n){
    int sum =0;
    int i;

    for(i=0; i < n; i++){
        sum += *array++;
    }
    return sum;
}