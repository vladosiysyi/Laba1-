
#include <iostream>
using namespace std;

// ����������� ������� ��� ������ ������������� �������� �������
pair<int, int> findMax(int arr[], int size, int index = 0) {
    // ������� ������: ���� ������ ������ ����� �������
    if (index == size - 1) {
        return { arr[index], index }; // ������� �������� � �������
    }

    // ����������� ����� ��� ���������� ��������
    pair<int, int> maxFromRest = findMax(arr, size, index + 1);

    // ��������� �������� �������� � ������������ �� ����������
    if (arr[index] > maxFromRest.first) {
        return { arr[index], index }; // ���� ������� ������� ������, ������� ���
    }
    return maxFromRest; // ����� ������� ������������ �� ����������
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;

    cout << "������� ���������� ��������� �������: ";
    cin >> n;

    if (n <= 0) {
        cout << "���������� ��������� ������ ���� �������������." << endl;
        return 1;
    }

    int* arr = new int[n];

    cout << "������� �������� �������:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = findMax(arr, n);
    cout << "������������ �������: " << result.first << " (�����: " << result.second << ")" << endl;

    delete[] arr; // ������������ ������
    return 0;
}
