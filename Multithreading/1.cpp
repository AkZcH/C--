#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
using namespace::chrono;
typedef unsigned long long ull;

void findEven(ull start, ull end, ull& result){
    ull sum = 0;
    ull i = (start % 2 == 0) ? start : start + 1;
    for(; i<=end; i+=2){
        sum += i;
    }
    result = sum;
}

void findOdd(ull start, ull end, ull& result){
    ull sum = 0;
    ull i = (start % 2 == 0) ? start : start + 1;
    for(; i<=end; i+=2){
            sum += i;
    }
    result = sum;
}

int main(){
    ull start = 0;
    ull end = 70000000000;

    ull evenSum = 0;
    ull oddSum = 0;

    auto start_time = std::chrono::steady_clock::now();

    std::thread t1(findEven, start, end, std::ref(evenSum));
    std::thread t2(findOdd, start, end, std::ref(oddSum));

    t1.join();
    t2.join();
                                                             
    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Even Sum: " << evenSum << endl;
    cout << "Odd Sum: " << oddSum << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}