# AlberoBin_Ricerca: Implementazione di un Albero Binario di Ricerca (BST)

#### Obiettivi:
1. Estendere la classe fornita `AlberoBin` per implementare un albero binario di ricerca (BST).
2. Implementare le operazioni base:
   - **Inserimento** di elementi rispettando la proprietà dell'albero binario di ricerca.
   - **Ricerca** di un elemento nell'albero.
   - **Stampa in ordine crescente** (visita in-order).
   - **Rimozione** di un elemento specifico dall'albero.
   - **Ricerca del massimo** e **del minimo** valore nell'albero.

---

#### Firma della Classe:
```cpp
template <typename T>
class AlberoBinarioRicerca : public AlberoBin<T> {
public:
    void inserisci(const T& valore);
    bool cerca(const T& valore) const;
    void rimuovi(const T& valore);
    T massimo() const;
    T minimo() const;
    void stampaInOrdine() const;
};
```

---

### Dettagli:

1. **Inserimento (`inserisci`)**:
   - Se l'albero è vuoto, crea la radice.
   - Altrimenti, inserisci l'elemento nel sottoalbero sinistro o destro, rispettando la proprietà del BST.

   Passi dell'Algoritmo di Inserimento:
      - Inizio dalla radice: Iniziamo l'inserimento dal nodo radice.
      - Confronto: Se il valore da inserire è uguale al valore del nodo corrente, l'inserimento non viene effettuato poiché i valori duplicati non sono consentiti. Se il valore da inserire è minore del valore del nodo corrente, ci si sposta verso il figlio sinistro. Se il valore da inserire è maggiore del valore del nodo corrente, ci si sposta verso il figlio destro.
      - Posizionamento: Quando si raggiunge un nodo foglia (cioè un nodo senza figli), il nuovo valore viene inserito come nuovo nodo figlia (sinistra se é minore del nodo, destra altrimenti).

3. **Ricerca (`cerca`)**:
   - Verifica ricorsivamente se un valore è presente nell'albero, partendo dalla radice.
  	
    Passi dell'algoritmo di ricerca:
       - Partenza dalla radice: iniziamo la ricerca dal nodo radice dell'albero.
       - Confronto: se il valore del nodo corrente è uguale al valore che cerchiamo, abbiamo trovato il nodo. Se il valore del nodo corrente è maggiore del valore cercato, procediamo verso il figlio sinistro. Se il valore del nodo corrente è minore del valore cercato, procediamo verso il figlio destro.
       - Ripetizione: Continuiamo a scendere nell'albero, ripetendo il confronto, fino a: 
            • Trovare il valore (successo).
            • Raggiungere un nodo foglia (non c'è un nodo con il valore cercato, quindi il valore non è presente nell'albero).

4. **Rimozione (`rimuovi`)**: facoltativo
   - Rimuove un nodo specifico, gestendo i tre casi:
     1. Nodo senza figli.
     2. Nodo con un solo figlio.
     3. Nodo con due figli (utilizzando il successore in-order per sostituire il nodo da rimuovere).

   Passi dell'algoritmo di ricerca:
       - Casi di RimozioneNodo senza figli (nodo foglia): Se il nodo da rimuovere è una foglia (cioè non ha figli), è sufficiente rimuoverlo direttamente.
       - Nodo con un solo figlio: Se il nodo ha solo un figlio, si sostituisce il nodo da rimuovere con il suo unico figlio. In questo modo, la struttura dell'albero rimane valida.
       - Nodo con due figli: Se il nodo ha due figli, ci sono due approcci comuni per gestire la rimozione:
           ▪ Sostituzione con il successore in-ordine: Si trova il nodo con il valore più piccolo nel sottoalbero destro del nodo da rimuovere (il successore) e viene spostato nel nodo da rimuovere.
           ▪ Sostituzione con il predecessore in-ordine: Si trova il nodo con il valore più grande nel sottoalbero sinistro (il predecessore) e viene spostato nel nodo da rimuovere.

5. **Massimo (`massimo`) e Minimo (`minimo`)**:
   - Trova ricorsivamente il nodo più a destra o più a sinistra.
     -  Il valore massimo in un BST si trova sempre nel nodo più a destra dell'albero. Per trovare il valore massimo, si segue il percorso dei nodi a destra fino a raggiungere un nodo senza figli a destra.
     -  Il valore minimo in un BST si trova sempre nel nodo più a sinistra dell'albero. Per trovare il valore minimo, si segue il percorso dei nodi a sinistra fino a raggiungere un nodo senza figli a sinistra

6. **Stampa In-Order (`stampaInOrdine`)**:
   - Stampa i nodi in ordine crescente visitando il sottoalbero sinistro, il nodo corrente, e il sottoalbero destro.
     Osservare il seguente pseudocodice:
    ![image](https://github.com/user-attachments/assets/53fc273b-b485-4acd-a909-9fa520cb2bd8)

---

### Programma Principale:
1. Creare un albero binario di ricerca.
2. Far inserire dall'utente i valori dei nodi (chiedi prima quanti nodi inserire, e poi richiederli uno ad uno. Ricorda che la posizione nell'albero non puó essere scelta dall'utente in quanto é calcolata in automatico dal programma)
3. Cercare due valori, stampando un messaggio di successo o fallimento.
4. Stampare i valori in ordine crescente.
5. Rimuovere un valore e ristampare l'albero. facoltativo
6. Trovare e stampare il massimo e il minimo.
```

---

Questa traccia richiede agli studenti di implementare tutte le operazioni essenziali per un BST, estendendo la classe base. Se hai bisogno di ulteriori dettagli o modifiche, fammi sapere!
