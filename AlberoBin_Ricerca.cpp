#include <iostream>
#include "AlberoBin.cpp"

template <typename T>
class AlberoBinarioRicerca : public AlberoBin<T> {
public:
    // Inserisce un valore nell'albero
    void inserisci(const T& valore) {
        if (this->alberoVuoto()) {
            this->insRadice(valore);
        } else {
            inserisciNodo(0, valore);
        }
    }

    // Cerca un valore nell'albero
    bool cerca(const T& valore) const {
        return cercaNodo(0, valore);
    }

    // Stampa i valori dell'albero in ordine crescente
    void stampaInOrdine() const {
        stampaNodoInOrdine(0);
        std::cout << std::endl;
    }

private:
    // Funzione ricorsiva per inserire un valore
    void inserisciNodo(int indice, const T& valore) {
        if (valore < this->nodi[indice].valore) {
            if (this->sinistroVuoto(indice)) {
                this->insFiglioSinistro(indice, valore);
            } else {
                inserisciNodo(this->figlioSinistro(indice), valore);
            }
        } else if (valore > this->nodi[indice].valore) {
            if (this->destroVuoto(indice)) {
                this->insFiglioDestro(indice, valore);
            } else {
                inserisciNodo(this->figlioDestro(indice), valore);
            }
        }
        // Valori uguali non vengono inseriti
    }

    // Funzione ricorsiva per cercare un valore
    bool cercaNodo(int indice, const T& valore) const {
        if (indice == NODO_VUOTO) return false;
        if (this->nodi[indice].valore == valore) return true;

        if (valore < this->nodi[indice].valore) {
            return cercaNodo(this->figlioSinistro(indice), valore);
        } else {
            return cercaNodo(this->figlioDestro(indice), valore);
        }
    }

    // Funzione ricorsiva per stampare l'albero in ordine crescente
    void stampaNodoInOrdine(int indice) const {
        if (indice != NODO_VUOTO) {
            stampaNodoInOrdine(this->figlioSinistro(indice));
            std::cout << this->nodi[indice].valore << " ";
            stampaNodoInOrdine(this->figlioDestro(indice));
        }
    }
};
