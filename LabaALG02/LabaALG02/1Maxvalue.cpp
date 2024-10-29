
#include <iostream>
using namespace std;

// Рекурсивная функция для поиска максимального элемента массива
pair<int, int> findMax(int arr[], int size, int index = 0) {
    // Базовый случай: если индекс достиг конца массива
    if (index == size - 1) {
        return { arr[index], index }; // Возврат значения и индекса
    }

    // Рекурсивный вызов для следующего элемента
    pair<int, int> maxFromRest = findMax(arr, size, index + 1);

    // Сравнение текущего элемента с максимальным из оставшихся
    if (arr[index] > maxFromRest.first) {
        return { arr[index], index }; // Если текущий элемент больше, вернуть его
    }
    return maxFromRest; // Иначе вернуть максимальный из оставшихся
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;

    cout << "Введите количество элементов массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть положительным." << endl;
        return 1;
    }

    int* arr = new int[n];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = findMax(arr, n);
    cout << "Максимальный элемент: " << result.first << " (номер: " << result.second << ")" << endl;

    delete[] arr; // Освобождение памяти
    return 0;
}
