#include <iostream>
using namespace std;

void TowerOfHanoi(int, char, char, char);

int main() {
    int numRods;
    char leftRod = 'A', rightRod = 'C', middleRod = 'B';

    do {
       cout << "Enter number of rods (2 or 3): ";
       cin >> numRods;
    } while (numRods != 2 && numRods != 3);

    TowerOfHanoi(numRods, leftRod, rightRod, middleRod);

}

void TowerOfHanoi(int num, char fromRod, char toRod, char waitRod) {
    if (num == 1) {
        cout << "Disk 1 moved from " << fromRod << " to " << toRod << endl;
        return;
    }
    TowerOfHanoi(num - 1, fromRod, waitRod, toRod);
    cout << "Disk " << num << " moved from " << fromRod << " to " << toRod <<endl;
    TowerOfHanoi(num - 1, waitRod, toRod, fromRod);
}

