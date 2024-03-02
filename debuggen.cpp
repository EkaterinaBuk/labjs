#include <iostream>  
#include <chrono>  
#include <future>  
using namespace std; 
     //  А в этой подобрать n и к чтоб поточное было быстрее, либо исправить, я пыталась по-разному исправить, но не получается
unsigned long long factorial1(int n) { 
    unsigned long long result1 = 1; 
    for (int i = 2; i <= n; i++) { 
        result1 *= i; 
    } 
    return result1; 
} 
unsigned long long factorial2(int k) { 
    unsigned long long result2 = 1; 
    for (int i = 2; i <= k; i++) { 
        result2 *= i; 
    } 
    return result2; 
} 
unsigned long long factorial3(int n, int k) { 
    unsigned long long result3 = 1; 
    int r = n - k; 
    for (int i = 2; i <= r; i++) { 
        result3 *= i; 
    } 
    return result3; 
} 
unsigned long long combinations(int n, int k) { 
    unsigned long long fn = factorial1(n); 
    unsigned long long fk = factorial2(k); 
    unsigned long long fnk = factorial3(n, k); 
    return (fn / (fk * fnk)); 
} 
 
int main() { 
    setlocale(LC_ALL, "Russian"); 
    int n; 
    int k; 
    cout << "n = "; 
    cin >> n; 
    cout << "k = "; 
    cin >> k; 
 
    auto start_time = std::chrono::high_resolution_clock::now();// Начало измерения потоки  
    future<unsigned long long> fn = async(launch::async, factorial1, n); 
    future<unsigned long long> fk = async(launch::async, factorial2, k); 
    future<unsigned long long> fnk = async(launch::async, factorial3, n, k); 
    auto end_time = std::chrono::high_resolution_clock::now(); // Завершение измерения потоки  
    std::cout << "Время выполнения потоков: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << std::endl; //   
 
    unsigned long long fn1 = fn.get(); 
    unsigned long long fn2 = fk.get(); 
    unsigned long long fn3 = fnk.get(); 
 
    cout << "n! = " << fn1 << endl; 
    cout << "k! = " << fn2 << endl; 
    cout << "(n-k)! = " << fn3 << endl; 
    cout << "Число сочетаний потоки: " << ((fn1) / (fn2 * fn3)) << endl; 
 
    auto start_time1 = std::chrono::high_resolution_clock::now();// Начало измерения последовательно  
    unsigned long long result = combinations(n, k); 
    auto end_time1 = std::chrono::high_resolution_clock::now(); // Завершение измерения последовательно  
    std::cout << "Время при последовательном выполнении: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1).count() << std::endl; // время последовательно  
    cout << "Число сочетаний последовательно : " << result << endl; 
}