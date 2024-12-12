#include <iostream>
#include "AlberoBin.cpp"

int main() {
    AlberoBin<int> albero;

    // Creazione dell'albero
    albero.insRadice(10);
    albero.insFiglioSinistro(0, 20);
    albero.insFiglioDestro(0, 30);
    albero.insFiglioSinistro(1, 40);
    albero.insFiglioDestro(1, 50);

    // Stampa l'albero
    albero.stampa();

    // Operazioni
    std::cout << "Radice: " << albero.radice() << "\n";
    std::cout << "Figlio sinistro della radice: " << albero.figlioSinistro(0) << "\n";
    std::cout << "Figlio destro della radice: " << albero.figlioDestro(0) << "\n";

    return 0;
}