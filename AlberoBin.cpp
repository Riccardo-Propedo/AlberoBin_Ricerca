#include <iostream>

const int MAX_NODI = 100; // Numero massimo di nodi nell'albero
const int NODO_VUOTO = -1; // Costante per indicare un figlio assente

template <typename T>
class AlberoBin {
private:
    struct Nodo {
        int sx = NODO_VUOTO;      // Indice del figlio sinistro
        T valore;    // Valore del nodo
        int dx = NODO_VUOTO;      // Indice del figlio destro
    };

    Nodo nodi[MAX_NODI]; // Matrice dei nodi
    int radiceIndice;    // Indice della radice
    int prossimoIndice;  // Prossimo indice disponibile

public:
    // Costruttore
    AlberoBin() {
        prossimoIndice = 0;
        radiceIndice = NODO_VUOTO;
    }

    // Verifica se l'albero è vuoto
    bool alberoVuoto() const {
        return radiceIndice == NODO_VUOTO;
    }

    // Inserisce la radice
    void insRadice(const T& valore) {
        if (!alberoVuoto()) {
            std::cout << "Errore: la radice esiste già.\n";
            return;
        }
        nodi[prossimoIndice].valore = valore;
        radiceIndice = prossimoIndice;
        prossimoIndice++;
    }

    // Restituisce il valore della radice
    T radice() const {
        if (alberoVuoto()) {
            std::cout << "Errore: l'albero è vuoto.\n";
            return T();
        }
        return nodi[radiceIndice].valore;
    }

    // Verifica se un nodo è foglia
    bool isFoglia(int indice) const {
        if (indice < 0 && indice > prossimoIndice) {
            std::cout << "Errore: indice non valido.\n";
            return false;
        }
        return nodi[indice].sx == NODO_VUOTO && nodi[indice].dx == NODO_VUOTO;
    }

    // Restituisce l'indice del figlio sinistro
    int figlioSinistro(int indice) const {
        if (indice < 0 && indice > prossimoIndice) {
            std::cout << "Errore: indice non valido.\n";
            return NODO_VUOTO;
        }
        return nodi[indice].sx;
    }

    // Restituisce l'indice del figlio destro
    int figlioDestro(int indice) const {
        if (indice < 0 && indice > prossimoIndice) {
            std::cout << "Errore: indice non valido.\n";
            return NODO_VUOTO;
        }
        return nodi[indice].dx;
    }

    // Verifica se il figlio sinistro è vuoto
    bool sinistroVuoto(int indice) const {
        return figlioSinistro(indice) == NODO_VUOTO;
    }

    // Verifica se il figlio destro è vuoto
    bool destroVuoto(int indice) const {
        return figlioDestro(indice) == NODO_VUOTO;
    }

    // Inserisce il figlio sinistro
    void insFiglioSinistro(int indice, const T& valore) {
        if (indice < 0 && indice > prossimoIndice) {
            std::cout << "Errore: indice non valido.\n";
            return;
        }
        if (nodi[indice].sx != NODO_VUOTO) {
            std::cout << "Errore: il figlio sinistro esiste già.\n";
            return;
        }
        if (prossimoIndice >= MAX_NODI) {
            std::cout << "Errore: spazio esaurito.\n";
            return;
        }
        nodi[prossimoIndice].valore = valore;
        nodi[indice].sx = prossimoIndice;
        prossimoIndice++;
    }

    // Inserisce il figlio destro
    void insFiglioDestro(int indice, const T& valore) {
        if (indice < 0 && indice > prossimoIndice) {
            std::cout << "Errore: indice non valido.\n";
            return;
        }
        if (nodi[indice].dx != NODO_VUOTO) {
            std::cout << "Errore: il figlio destro esiste già.\n";
            return;
        }
        if (prossimoIndice >= MAX_NODI) {
            std::cout << "Errore: spazio esaurito.\n";
            return;
        }
        nodi[prossimoIndice].valore = valore;
        nodi[indice].dx = prossimoIndice;
        prossimoIndice++;
    }

    // Stampa l'albero (per debugging)
    void stampa() const {
        for (int i = 0; i < prossimoIndice; ++i) {
            std::cout << "Nodo " << i << ": Valore = " << nodi[i].valore
                      << ", Figlio Sinistro = " << nodi[i].sx
                      << ", Figlio Destro = " << nodi[i].dx << "\n";
        }
    }

};