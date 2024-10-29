
#include <iostream>

void moveDisk(int disk, char source, char target) {
    std::cout << "ѕереместить диск " << disk << " с " << source << " на " << target << std::endl;
}

void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        moveDisk(1, source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    moveDisk(n, source, target); 
    hanoi(n - 1, auxiliary, target, source); 
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;

    std::cout << "¬ведите количество дисков: ";
    std::cin >> n;

    std::cout << "ѕоследовательность перемещений:" << std::endl;
    hanoi(n, 'A', 'C', 'B'); // A - источник, C - цель, B - вспомогательный

    return 0;
}
