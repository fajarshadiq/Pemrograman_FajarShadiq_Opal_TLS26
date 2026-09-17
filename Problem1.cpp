#include <iostream>

using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    if (!(cin >> N) || N <= 0) {
        cout << "Jumlah astronot harus lebih dari 0." << endl;
        return 1;
    }

    cout << "Masukkan nilai awal K: ";
    if (!(cin >> K) || K < 2) {
        cout << "Nilai awal K tidak boleh kurang dari 2." << endl;
        return 1;
    }

    int astronauts[1000];
    for (int i = 0; i < N; ++i) {
        astronauts[i] = i + 1;
    }

    int activeCount = N;
    int currentIndex = 0;

    cout << "\n========================================\n";
    cout << "Urutan astronot yang dieliminasi: ";

    while (activeCount > 1) {
       
        currentIndex = (currentIndex + K - 1) % activeCount;

        int eliminatedAstronaut = astronauts[currentIndex];

        cout << eliminatedAstronaut << (activeCount == 2 ? "" : " -> ");

        for (int i = currentIndex; i < activeCount - 1; ++i) {
            astronauts[i] = astronauts[i + 1];
        }

        activeCount--; 
        if (eliminatedAstronaut % 2 == 0) {
            K += 2; 
        } else {
            K -= 1; 
        }

        if (K < 2) {
            K = 2;
        }
    }

   
    cout << "\nAstronot terakhir yang bertahan: " << astronauts[0] << endl;
    cout << "========================================\n";

    return 0;
}
