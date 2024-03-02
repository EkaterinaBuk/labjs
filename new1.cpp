#include <iostream>  
#include <vector>  
#include <thread>  
#include <chrono>  
#include <numeric>  
using namespace std; 
     //  Нужно найти значение где поточное эффективнее последовательного, при этом что-то она готоворит по времени ей не очень нравится
long long scalar_proizv(vector<long long>& v1, vector<long long>& v2, long long start, long long end, long long& result) // функция для параллельного вычисления произведения  
{ 
    long long sum = 0; 
    for (long long i = start; i < end; ++i) 
    { 
        sum += v1[i] * v2[i]; 
    } 
    result = sum; 
    return result; 
} 
 
int main() 
{ 
    setlocale(LC_ALL, "Russian"); 
    const long long size = 1000000; 
    vector<long long> v1(size); // создаём 2 вектора и заполняем их случайными значениями  
    vector<long long> v2(size); 
    for (long long i = 0; i < size; ++i) 
    { 
        v1[i] = rand() % 100; 
        v2[i] = rand() % 100; 
    } 
 
    // вычисление скалярного произведения последовательно с помощью функции ьб  
    auto start_time = chrono::high_resolution_clock::now(); 
    long long scalar_product_posled = inner_product(v1.begin(), v1.end(), v2.begin(), 0); 
    auto end_time = chrono::high_resolution_clock::now(); 
    auto vremya_posled = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time); 
    cout << "Скалярное произведение при последовательном вычислении: " << scalar_product_posled << endl; 
    cout << "Затраченное время при последовательном вычислении: " << vremya_posled.count() << " нс" << endl; 
 
    // Вычисление скалярного произведения многопоточно  
    long long num_threads = thread::hardware_concurrency(); // количество доступных аппаратных потоков   
    cout << "Количество доступных аппаратных потоков: "<< num_threads << endl; 
    cout << "Введите не больше " << num_threads-1 <<" потоков: "; 
    int num_threads1; 
    cin >> num_threads1; 
    vector<long long> paral_results(num_threads1); 
    vector<thread> threads(num_threads1); 
    start_time = chrono::high_resolution_clock::now(); 
    long long blok_size = size / num_threads1; // размер каждого блока элементов, которые обрабатывает поток = общий размер векторов на кол-во потоков  
    for (long long i = 0; i < num_threads1; ++i) // создаются потоки, указывая диапазон элементов, которые должен обработать каждый поток  
    { 
        long long start = i * blok_size; 
        long long end = (i == num_threads1 - 1) ? size : (i + 1) * blok_size; // если этот поток не последний, то по формуле; если последний то size  
        threads[i] = thread(scalar_proizv, ref(v1), ref(v2), start, end, ref(paral_results[i])); 
    } 
    for (auto& t : threads) 
    { 
        t.join(); 
    } 
 
    long long scalar_product_par = accumulate(paral_results.begin(), paral_results.end(), 0); // суммируем всё в этом диапазоне  
    end_time = chrono::high_resolution_clock::now(); 
    auto vremya_paral = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time); 
    cout << "Скалярное произведение при параллельном вычислении: " << scalar_product_par << endl; 
    cout << "Затраченное время при параллельном вычислении: " << vremya_paral.count() << " нс" << endl; 
 
    // Анализ эффективности параллельного алгоритма  
    double speed = static_cast<double>(vremya_posled.count()) / vremya_paral.count(); 
    double efficiency = speed / num_threads; // ускорение на на кол-во потоков  
    cout << "Ускорение: " << speed << endl; 
    cout << "Эффективность: " << efficiency << endl; 
    return 0; 
}