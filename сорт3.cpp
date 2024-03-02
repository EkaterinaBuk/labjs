#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения информации о курсах покупки и продажи валюты
struct ExchangeRate {
    int buyingRate;
    int sellingRate;
};

// Функция для разделения списка на две части относительно опорного элемента
int partition(vector<ExchangeRate>& arr, int low, int high, bool sortBySellingRate) {
    int pivot = sortBySellingRate ? arr[high].sellingRate : arr[high].buyingRate;// выбираем опорный элемент
    int i = low - 1;// индекс меньшего элемента
    for (int j = low; j < high; j++) {// если текущий элемент меньше или равен опорному
        if ((sortBySellingRate && arr[j].sellingRate >= pivot) || (!sortBySellingRate && arr[j].buyingRate <= pivot)) {
            i++; // увеличиваем индекс меньшего элемента
            swap(arr[i], arr[j]);// меняем элементы местами
        }
    }
    swap(arr[i + 1], arr[high]);// меняем опорный элемент местами
    return i + 1;// возвращаем индекс опорного элемента
}

// Функция быстрой сортировки
void quickSort(vector<ExchangeRate>& arr, int low, int high, bool sortBySellingRate, int& comparisons, int& moves) {
    if (low < high) {
        int pi = partition(arr, low, high, sortBySellingRate);// получаем индекс опорного элемента
        quickSort(arr, low, pi - 1, sortBySellingRate, comparisons, moves);// сортируем элементы до опорного
        quickSort(arr, pi + 1, high, sortBySellingRate, comparisons, moves);// сортируем элементы после опорного
        comparisons += high - low;
        moves += 2 * (high - low);
    }
}

// Функция для сортировки Шелла
void shellSort(vector<ExchangeRate>& arr, bool sortBySellingRate, int& comparisons, int& moves) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) { //начальное значение шага половина длины списка
        for (int i = gap; i < n; i++) { //выполняем сортировку вставками 
			//для каждого подсписка, начиная с первого элемента и двигаясь 
			//через шаг до конца списка
            ExchangeRate temp = arr[i];//текущий элемент ищем для него место
            int j;
            if (sortBySellingRate) {
                for (j = i; j >= gap && arr[j - gap].sellingRate < temp.sellingRate; j -= gap) {
                    arr[j] = arr[j - gap];
                    comparisons++;
                    moves++;
                }
            } else {
                for (j = i; j >= gap && arr[j - gap].buyingRate > temp.buyingRate; j -= gap) {
                    arr[j] = arr[j - gap];
                    comparisons++;
                    moves++;
                }
            }
            arr[j] = temp;
            moves++;
        }
    }
}

int main() {
    // Создаем список курсов покупки и продажи валюты
    vector<ExchangeRate> exchangeRates = {
        {30, 32}, {31, 33}, {29, 32}, {28, 33}, {30, 34}, {32, 36}, {31, 35}, {29, 34},
        {27, 32}, {28, 33}, {30, 35}, {31, 36}, {28, 34}, {27, 33}, {26, 32}, {29, 36},
        {31, 38}, {33, 40}, {30, 37}, {29, 36}, {28, 35}, {27, 34}, {25, 32}, {24, 30},
        {23, 28}, {22, 26}, {21, 24}, {20, 22}, {19, 20}, {18, 19}, {17, 18}, {16, 17}
    };

    // Сортируем список по выгоде продажи с помощью быстрой сортировки
    int comparisons = 0, moves = 0;
    quickSort(exchangeRates, 0, exchangeRates.size() - 1, true, comparisons, moves);
    cout << "Список в порядке выгоды продажи"<<endl;
    for (const auto& rate : exchangeRates) {
        cout << rate.buyingRate << " " << rate.sellingRate <<endl;
    }
    cout << "Количество сравнений: " << comparisons <<endl;
    cout << "Количество перемещений: " << moves <<endl;

    // Сортируем список по выгоде покупки с помощью сортировки Шелла
    comparisons = 0, moves = 0;
    shellSort(exchangeRates, false, comparisons, moves);
    cout << "Список в порядке выгоды покупки"<<endl;
    for (const auto& rate : exchangeRates) {
        cout << rate.buyingRate << " " << rate.sellingRate <<endl;
    }
    cout << "Количество сравнений: " << comparisons <<endl;
    cout << "Количество перемещений: " << moves <<endl;

    return 0;
}
