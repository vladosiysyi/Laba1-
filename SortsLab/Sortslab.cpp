#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

//выбор
void selectionSort(int arr[], int size, int& comparisons, int& swaps) {
	for (int index = 0; index < size - 1; index++)
	{
		int min_index = index;
		for (int j = index + 1; j < size; j++) {
			comparisons++;
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		if (min_index != index) {
			swap(arr[min_index], arr[index]);
			swaps++;
		}
	}

}

//пузырек
void bubbleSort(int arr[], int size, int& comparisons, int& swaps) {

	for (int index = 0; index < size - 1; index++) {
		for (int j = 0; j < size - index - 1; j++) {
			comparisons++;
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swaps++;
			}
		}
	}

}

//вставка
void insertionSort(int arr[], int size, int& comparisons, int& swaps) {
	int temp, j;
	for (int index = 1; index < size; index++) {
		j = index;
		temp = arr[index];
		while (j > 0 && temp < arr[j - 1]) {
			comparisons++;
			arr[j] = arr[j - 1];
			j--;
			swaps++;
		}
		comparisons++;
		arr[j] = temp;
	}

}



//шел
void shellSort(int arr[], int size, int& comparisons, int& swaps) {

	for (int interval = size / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < size; i++) {
			int temp = arr[i];
			int j = i;
			comparisons++;
			while (j >= interval && arr[j - interval] > temp) {
				comparisons++;
				arr[j] = arr[j - interval];
				swaps++;
				j -= interval;
			}
			arr[j] = temp;

		}
	}
}

//бинарка
void binaryInsertionSort(int arr[], int size, int& comparisons, int& swaps) {

	int left, right, mid, key;  // Объявление переменных для границ поиска, середины и текущего ключевого элемента
	for (int index = 1; index < size; index++) {
		key = arr[index];  // Запоминаем текущий элемент как ключ
		left = 0;
		right = index - 1; // Инициализируем правую границу как индекс предыдущего элемента

		comparisons++;
		while (left <= right) {
			comparisons++;
			mid = (left + right) / 2;  // Вычисляем середину между левой и правой границами
			if (key < arr[mid]) {      // Если ключ меньше среднего элемента
				right = mid - 1;       // Сдвигаем правую границу левее
			}
			else {                     // Если ключ больше или равен среднему элементу
				left = mid + 1;        // Сдвигаем левую границу правее
			}
		}

		// Сдвигаем элементы вправо, чтобы освободить место для ключа
		for (int j = index - 1; j >= left; j--) {
			comparisons++;
			arr[j + 1] = arr[j];  // Сдвигаем каждый элемент на одну позицию вправо
			swaps++;
		}

		arr[left] = key;  // Вставляем ключ на найденную позицию
	}

}

//шэйкер
void shakerSort(int arr[], int size, int& comparisons, int& swaps) {
	int start = 0, end = size - 1;
	while (start < end) {                // Цикл работает, пока начало не пересечется с концом
		for (int i = start; i < end; i++) {  // Проход по массиву слева направо
			comparisons++;
			if (arr[i] > arr[i + 1]) {       // Если текущий элемент больше следующего
				swaps++;
				swap(arr[i], arr[i + 1]);    // Обмен местами элементов
			}
		}
		--end;                              // Уменьшаем границу конца, так как последний элемент на месте

		for (int i = end; i > start; --i) {  // Проход по массиву справа налево
			comparisons++;
			if (arr[i] < arr[i - 1]) {       // Если текущий элемент меньше предыдущего
				swaps++;
				swap(arr[i], arr[i - 1]);    // Обмен местами элементов
			}
		}
		++start;                            // Увеличиваем границу начала, так как первый элемент на месте
	}
}

void  heapify(int arr[], int size, int root, int& comparisons, int& swaps) {

	int largest = root;        // Инициализируем наибольший элемент как корень
	int left = 2 * root + 1;   // Левый потомок
	int right = 2 * root + 2;  // Правый потомок

	// Если левый потомок больше корня
	comparisons++;
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	comparisons++;
	// Если правый потомок больше, чем самый большой элемент на данный момент
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	// Если наибольший элемент не корень
	if (largest != root) {
		swap(arr[root], arr[largest]);  // Меняем корень с самым большим элементом
		swaps++;
		// Рекурсивно преобразуем затронутое поддерево в кучу
		heapify(arr, size, largest, comparisons, swaps);
	}
}

//пирамидка
void heapSort(int arr[], int size, int& comparisons, int& swaps) {

	// Построение кучи (перегруппировка массива)
	for (int i = size / 2 - 1; i >= 0; --i)
		heapify(arr, size, i, comparisons, swaps);

	// Извлечение элементов из кучи
	for (int i = size - 1; i > 0; --i) {
		swap(arr[0], arr[i]);  // Перемещаем текущий корень в конец
		swaps++;
		heapify(arr, i, 0, comparisons, swaps);         // Вызываем heapify на уменьшенной куче
	}
}


int partition(int arr[], int low, int high, int& comparisons, int& swaps) {
	int pivot = arr[high];  // Опорный элемент (последний элемент)
	int i = (low - 1);      // Индекс наименьшего элемента

	for (int j = low; j < high; ++j) {
		comparisons++;
		// Если текущий элемент меньше или равен опорному
		if (arr[j] <= pivot) {
			i++;  // Увеличиваем индекс меньшего элемента
			swap(arr[i], arr[j]);
			swaps++;
		}
	}

	// Меняем местами опорный элемент и элемент на i+1 позиции
	swap(arr[i + 1], arr[high]);
	swaps++;
	return (i + 1);
}

// Функция быстрой сортировки
void quickSort(int arr[], int low, int high, int& comparisons, int& swaps) {
	if (low < high) {
		// Индекс разбиения
		int pi = partition(arr, low, high, comparisons, swaps);

		// Рекурсивно сортируем элементы до и после разбиения
		quickSort(arr, low, pi - 1, comparisons, swaps);
		quickSort(arr, pi + 1, high, comparisons, swaps);
	}

}

void printArray(int arr[], int size) {
	for (int index = 0; index < size; index++) {
		cout << arr[index] << " ";
	}
	cout << endl;
}



int main() {
	setlocale(LC_ALL, "RUS");

	const int size = 200;

	int originalSortedArray[size];
	int originalReverseSortedArray[size];
	int originalRandomArray[size];


	for (int i = 0; i < size; i++) {
		originalSortedArray[i] = i;
	}
	for (int i = 0; i < size; i++) {
		originalReverseSortedArray[i] = size - i - 1;
	}
	srand(time(0));
	for (int i = 0; i < size; i++) {
		originalRandomArray[i] = rand() % 100 + 1;
	}

	int arrSorted[size], arrReverse[size], arrRandom[size];

	cout << "Метод сортировки                     Количество сравнений          Количество перестановок" << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;

	// Сортировка методом выбора
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	int comparisons = 0;
	int swaps = 0;
	selectionSort(arrSorted, size, comparisons, swaps);
	cout << "Сортировка выбором упорядоченный" << "             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	selectionSort(arrReverse, size, comparisons, swaps);
	cout << "Сортировка выбором обратный" << "                  " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	selectionSort(arrRandom, size, comparisons, swaps);
	cout << "Сортировка выбором случайный" << "                 " << comparisons << "                            " << swaps << endl;

	cout << endl;

	// Сортировка методом пузырька
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	bubbleSort(arrSorted, size, comparisons, swaps);
	cout << "Сортировка пызырьком упорядоченный" << "           " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	bubbleSort(arrReverse, size, comparisons, swaps);
	cout << "Сортировка пызырьком обратный" << "                " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	bubbleSort(arrRandom, size, comparisons, swaps);
	cout << "Сортировка пызырьком случайный" << "               " << comparisons << "                            " << swaps << endl;


	cout << endl;

	// Сортировка методом вставками
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	insertionSort(arrSorted, size, comparisons, swaps);
	cout << "Сортировка вставками упорядоченный" << "           " << comparisons << "                              " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	insertionSort(arrReverse, size, comparisons, swaps);
	cout << "Сортировка вставками обратный" << "                " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	insertionSort(arrRandom, size, comparisons, swaps);
	cout << "Сортировка вставками случайный" << "               " << comparisons << "                             " << swaps << endl;

	cout << endl;

	// Сортировка методом шелла
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	shellSort(arrSorted, size, comparisons, swaps);
	cout << "Сортировка шелла упорядоченный" << "		     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shellSort(arrReverse, size, comparisons, swaps);
	cout << "Сортировка шелла обратный" << "	             " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shellSort(arrRandom, size, comparisons, swaps);
	cout << "Сортировка шелла случайный" << "		     " << comparisons << "                             " << swaps << endl;

	cout << endl;
	// Сортировка методом бинарки
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	binaryInsertionSort(arrSorted, size, comparisons, swaps);
	cout << "Сортировка бинарки упорядоченный" << "	     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	binaryInsertionSort(arrReverse, size, comparisons, swaps);
	cout << "Сортировка бинарки обратный" << "	             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	binaryInsertionSort(arrRandom, size, comparisons, swaps);
	cout << "Сортировка бинарки случайный" << "		     " << comparisons << "                            " << swaps << endl;


	cout << endl;
	// Сортировка методом шэйкера
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	shakerSort(arrSorted, size, comparisons, swaps);
	cout << "Сортировка шэйкера упорядоченный" << "	     " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shakerSort(arrReverse, size, comparisons, swaps);
	cout << "Сортировка шэйкера обратный" << "	             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shakerSort(arrRandom, size, comparisons, swaps);
	cout << "Сортировка шэйкера случайный" << "		     " << comparisons << "                            " << swaps << endl;

	cout << endl;
	// Сортировка методом пирамидальная
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	heapSort(arrSorted, size, comparisons, swaps);
	cout << "Сортировка пирамидальная упорядоченный" << "	     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	heapSort(arrReverse, size, comparisons, swaps);
	cout << "Сортировка пирамидальная обратный" << "	     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	heapSort(arrRandom, size, comparisons, swaps);
	cout << "Сортировка пирамидальная случайный" << "	     " << comparisons << "                             " << swaps << endl;

	cout << endl;
	// Сортировка методом быстрая
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	quickSort(arrSorted, 0, size - 1, comparisons, swaps);
	cout << "Сортировка быстрая упорядоченный" << "	     " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	quickSort(arrReverse, 0, size - 1, comparisons, swaps);
	cout << "Сортировка быстрая обратный" << "	             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	quickSort(arrRandom, 0, size - 1, comparisons, swaps);
	cout << "Сортировка быстрая случайный" << "	             " << comparisons << "                             " << swaps << endl;


	return 0;

}