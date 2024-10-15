#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

//�����
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

//�������
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

//�������
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



//���
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

//�������
void binaryInsertionSort(int arr[], int size, int& comparisons, int& swaps) {

	int left, right, mid, key;  // ���������� ���������� ��� ������ ������, �������� � �������� ��������� ��������
	for (int index = 1; index < size; index++) {
		key = arr[index];  // ���������� ������� ������� ��� ����
		left = 0;
		right = index - 1; // �������������� ������ ������� ��� ������ ����������� ��������

		comparisons++;
		while (left <= right) {
			comparisons++;
			mid = (left + right) / 2;  // ��������� �������� ����� ����� � ������ ���������
			if (key < arr[mid]) {      // ���� ���� ������ �������� ��������
				right = mid - 1;       // �������� ������ ������� �����
			}
			else {                     // ���� ���� ������ ��� ����� �������� ��������
				left = mid + 1;        // �������� ����� ������� ������
			}
		}

		// �������� �������� ������, ����� ���������� ����� ��� �����
		for (int j = index - 1; j >= left; j--) {
			comparisons++;
			arr[j + 1] = arr[j];  // �������� ������ ������� �� ���� ������� ������
			swaps++;
		}

		arr[left] = key;  // ��������� ���� �� ��������� �������
	}

}

//������
void shakerSort(int arr[], int size, int& comparisons, int& swaps) {
	int start = 0, end = size - 1;
	while (start < end) {                // ���� ��������, ���� ������ �� ����������� � ������
		for (int i = start; i < end; i++) {  // ������ �� ������� ����� �������
			comparisons++;
			if (arr[i] > arr[i + 1]) {       // ���� ������� ������� ������ ����������
				swaps++;
				swap(arr[i], arr[i + 1]);    // ����� ������� ���������
			}
		}
		--end;                              // ��������� ������� �����, ��� ��� ��������� ������� �� �����

		for (int i = end; i > start; --i) {  // ������ �� ������� ������ ������
			comparisons++;
			if (arr[i] < arr[i - 1]) {       // ���� ������� ������� ������ �����������
				swaps++;
				swap(arr[i], arr[i - 1]);    // ����� ������� ���������
			}
		}
		++start;                            // ����������� ������� ������, ��� ��� ������ ������� �� �����
	}
}

void  heapify(int arr[], int size, int root, int& comparisons, int& swaps) {

	int largest = root;        // �������������� ���������� ������� ��� ������
	int left = 2 * root + 1;   // ����� �������
	int right = 2 * root + 2;  // ������ �������

	// ���� ����� ������� ������ �����
	comparisons++;
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	comparisons++;
	// ���� ������ ������� ������, ��� ����� ������� ������� �� ������ ������
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	// ���� ���������� ������� �� ������
	if (largest != root) {
		swap(arr[root], arr[largest]);  // ������ ������ � ����� ������� ���������
		swaps++;
		// ���������� ����������� ���������� ��������� � ����
		heapify(arr, size, largest, comparisons, swaps);
	}
}

//���������
void heapSort(int arr[], int size, int& comparisons, int& swaps) {

	// ���������� ���� (��������������� �������)
	for (int i = size / 2 - 1; i >= 0; --i)
		heapify(arr, size, i, comparisons, swaps);

	// ���������� ��������� �� ����
	for (int i = size - 1; i > 0; --i) {
		swap(arr[0], arr[i]);  // ���������� ������� ������ � �����
		swaps++;
		heapify(arr, i, 0, comparisons, swaps);         // �������� heapify �� ����������� ����
	}
}


int partition(int arr[], int low, int high, int& comparisons, int& swaps) {
	int pivot = arr[high];  // ������� ������� (��������� �������)
	int i = (low - 1);      // ������ ����������� ��������

	for (int j = low; j < high; ++j) {
		comparisons++;
		// ���� ������� ������� ������ ��� ����� ��������
		if (arr[j] <= pivot) {
			i++;  // ����������� ������ �������� ��������
			swap(arr[i], arr[j]);
			swaps++;
		}
	}

	// ������ ������� ������� ������� � ������� �� i+1 �������
	swap(arr[i + 1], arr[high]);
	swaps++;
	return (i + 1);
}

// ������� ������� ����������
void quickSort(int arr[], int low, int high, int& comparisons, int& swaps) {
	if (low < high) {
		// ������ ���������
		int pi = partition(arr, low, high, comparisons, swaps);

		// ���������� ��������� �������� �� � ����� ���������
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

	cout << "����� ����������                     ���������� ���������          ���������� ������������" << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;

	// ���������� ������� ������
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	int comparisons = 0;
	int swaps = 0;
	selectionSort(arrSorted, size, comparisons, swaps);
	cout << "���������� ������� �������������" << "             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	selectionSort(arrReverse, size, comparisons, swaps);
	cout << "���������� ������� ��������" << "                  " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	selectionSort(arrRandom, size, comparisons, swaps);
	cout << "���������� ������� ���������" << "                 " << comparisons << "                            " << swaps << endl;

	cout << endl;

	// ���������� ������� ��������
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	bubbleSort(arrSorted, size, comparisons, swaps);
	cout << "���������� ��������� �������������" << "           " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	bubbleSort(arrReverse, size, comparisons, swaps);
	cout << "���������� ��������� ��������" << "                " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	bubbleSort(arrRandom, size, comparisons, swaps);
	cout << "���������� ��������� ���������" << "               " << comparisons << "                            " << swaps << endl;


	cout << endl;

	// ���������� ������� ���������
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	insertionSort(arrSorted, size, comparisons, swaps);
	cout << "���������� ��������� �������������" << "           " << comparisons << "                              " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	insertionSort(arrReverse, size, comparisons, swaps);
	cout << "���������� ��������� ��������" << "                " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	insertionSort(arrRandom, size, comparisons, swaps);
	cout << "���������� ��������� ���������" << "               " << comparisons << "                             " << swaps << endl;

	cout << endl;

	// ���������� ������� �����
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	shellSort(arrSorted, size, comparisons, swaps);
	cout << "���������� ����� �������������" << "		     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shellSort(arrReverse, size, comparisons, swaps);
	cout << "���������� ����� ��������" << "	             " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shellSort(arrRandom, size, comparisons, swaps);
	cout << "���������� ����� ���������" << "		     " << comparisons << "                             " << swaps << endl;

	cout << endl;
	// ���������� ������� �������
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	binaryInsertionSort(arrSorted, size, comparisons, swaps);
	cout << "���������� ������� �������������" << "	     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	binaryInsertionSort(arrReverse, size, comparisons, swaps);
	cout << "���������� ������� ��������" << "	             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	binaryInsertionSort(arrRandom, size, comparisons, swaps);
	cout << "���������� ������� ���������" << "		     " << comparisons << "                            " << swaps << endl;


	cout << endl;
	// ���������� ������� �������
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	shakerSort(arrSorted, size, comparisons, swaps);
	cout << "���������� ������� �������������" << "	     " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shakerSort(arrReverse, size, comparisons, swaps);
	cout << "���������� ������� ��������" << "	             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	shakerSort(arrRandom, size, comparisons, swaps);
	cout << "���������� ������� ���������" << "		     " << comparisons << "                            " << swaps << endl;

	cout << endl;
	// ���������� ������� �������������
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	heapSort(arrSorted, size, comparisons, swaps);
	cout << "���������� ������������� �������������" << "	     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	heapSort(arrReverse, size, comparisons, swaps);
	cout << "���������� ������������� ��������" << "	     " << comparisons << "                             " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	heapSort(arrRandom, size, comparisons, swaps);
	cout << "���������� ������������� ���������" << "	     " << comparisons << "                             " << swaps << endl;

	cout << endl;
	// ���������� ������� �������
	copy(originalSortedArray, originalSortedArray + size, arrSorted);
	copy(originalReverseSortedArray, originalReverseSortedArray + size, arrReverse);
	copy(originalRandomArray, originalRandomArray + size, arrRandom);
	comparisons = 0;
	swaps = 0;
	quickSort(arrSorted, 0, size - 1, comparisons, swaps);
	cout << "���������� ������� �������������" << "	     " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	quickSort(arrReverse, 0, size - 1, comparisons, swaps);
	cout << "���������� ������� ��������" << "	             " << comparisons << "                            " << swaps << endl;
	comparisons = 0;
	swaps = 0;
	quickSort(arrRandom, 0, size - 1, comparisons, swaps);
	cout << "���������� ������� ���������" << "	             " << comparisons << "                             " << swaps << endl;


	return 0;

}