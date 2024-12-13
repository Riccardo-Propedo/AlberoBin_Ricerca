#include <iostream>
using namespace std;

const int MAX_NODI = 100; // Numero massimo di nodi nell'albero
const int NODO_VUOTO = -1; // Costante per indicare un nodo assente

struct Nodo {
    int valore;
    int sinistro; // Indice del figlio sinistro
    int destro;   // Indice del figlio destro
};

class AlberoBinarioRicerca {
private:
    Nodo nodi[MAX_NODI]; // Array dei nodi
    int radice;          // Indice della radice
    int prossimoIndice;  // Prossimo indice libero

public:
    AlberoBinarioRicerca() {
        radice = NODO_VUOTO;
        prossimoIndice = 0;
    }

    void inserisci(int valore) {
        if (prossimoIndice >= MAX_NODI) {
            cout << "Errore: limite massimo raggiunto.\n";
            return;
        }

        if (radice == NODO_VUOTO) {
            // L'albero è vuoto: inserisci il primo nodo come radice
            nodi[prossimoIndice] = {valore, NODO_VUOTO, NODO_VUOTO};
            radice = prossimoIndice++;
        } else {
            // Inserisci ricorsivamente partendo dalla radice
            inserisciNodo(radice, valore);
        }
    }

    void inserisciNodo(int indice, int valore) {
        if (valore < nodi[indice].valore) {
            if (nodi[indice].sinistro == NODO_VUOTO) {
                // Inserisci come figlio sinistro
                nodi[prossimoIndice] = {valore, NODO_VUOTO, NODO_VUOTO};
                nodi[indice].sinistro = prossimoIndice++;
            } else {
                // Continua la ricerca nel sottoalbero sinistro
                inserisciNodo(nodi[indice].sinistro, valore);
            }
        } else if (valore > nodi[indice].valore) {
            if (nodi[indice].destro == NODO_VUOTO) {
                // Inserisci come figlio destro
                nodi[prossimoIndice] = {valore, NODO_VUOTO, NODO_VUOTO};
                nodi[indice].destro = prossimoIndice++;
            } else {
                // Continua la ricerca nel sottoalbero destro
                inserisciNodo(nodi[indice].destro, valore);
            }
        } else {
            cout << "Il valore " << valore << " esiste già nell'albero.\n";
        }
    }

    bool cerca(int valore) const {
        return cercaNodo(radice, valore);
    }

    bool cercaNodo(int indice, int valore) const {
        if (indice == NODO_VUOTO) return false;
        if (nodi[indice].valore == valore) return true;
        if (valore < nodi[indice].valore) {
            return cercaNodo(nodi[indice].sinistro, valore);
        } else {
            return cercaNodo(nodi[indice].destro, valore);
        }
    }

    void stampaInOrdine() const {
        stampaInOrdineNodo(radice);
        cout << endl;
    }

    void stampaInOrdineNodo(int indice) const {
        if (indice != NODO_VUOTO) {
            stampaInOrdineNodo(nodi[indice].sinistro);
            cout << nodi[indice].valore << " ";
            stampaInOrdineNodo(nodi[indice].destro);
        }
    }
};

int main() {
    AlberoBinarioRicerca albero;

    int n, valore;
    cout << "Quanti numeri vuoi inserire? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Inserisci un numero: ";
        cin >> valore;
        albero.inserisci(valore);
    }

    cout << "Valori in ordine: ";
    albero.stampaInOrdine();

    cout << "Inserisci un numero da cercare: ";
    cin >> valore;
    if (albero.cerca(valore)) {
        cout << valore << " trovato nell'albero.\n";
    } else {
        cout << valore << " non trovato.\n";
    }

    return 0;
}
