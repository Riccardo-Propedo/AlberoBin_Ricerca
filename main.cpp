#include <iostream>
#include "AlberoBin_Ricerca.cpp"

int main() {
    AlberoBinarioRicerca<int> albero;

    // Inserimento di nodi
    albero.inserisci(10);
    albero.inserisci(5);
    albero.inserisci(15);
    albero.inserisci(3);
    albero.inserisci(7);

    // Stampa dell'albero in ordine crescente
    std::cout << "Albero in ordine crescente: ";
    albero.stampaInOrdine();

    // Ricerca di un valore
    int valoreDaCercare = 7;
    if (albero.cerca(valoreDaCercare)) {
        std::cout << valoreDaCercare << " trovato nell'albero.\n";
    } else {
        std::cout << valoreDaCercare << " non trovato.\n";
    }

    return 0;
}
