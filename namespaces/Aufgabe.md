
# namespaces and constructors/destructors

Erstellen Sie nach folgendem Klassendiagramm einen Zoo mit jew. zwei Gehegen und <5 Tieren.
Nach dem Sie die Tiere ein mal gefüttert haben (Ausgabe durch die Fütter-Funktion des Zoos) müssen Sie den Zoo schließen.

Wird ein Gehege geschlossen, werden die Tiere freigelassen und verabschieden sich.

## UML
![Class Diagram](zoo.png)

## main.cpp
```c
int main()
{
    Zoo myZoo;

    myZoo.feed();


    return 0;
}
```

## mögliche Ausgabe
```
Zoo wird angelegt:
        Ente-Voiliere wird angegelegt:
                neuer Ente
                neuer Ente
                neuer Ente
        Adler-Voiliere wird angegelegt:
                neuer Adler
                neuer Adler
        Elefant-Gehege wird angegelegt:
                neuer Elefant
                neuer Elefant
        Giraffe-Gehege wird angegelegt:
                neuer Giraffe
                neuer Giraffe
                neuer Giraffe
                neuer Giraffe
        Pinguin-Becken wird angegelegt:
                neuer Pinguin
                neuer Pinguin
                neuer Pinguin
        Delfin-Becken wird angegelegt:
                neuer Delfin
                neuer Delfin
                neuer Delfin
                neuer Delfin
Fuetterungszeit:
        in Ente-Voiliere wird gef³ttert
                Ente isst
                Ente isst
                Ente isst
        in Adler-Voiliere wird gef³ttert
                Adler isst
                Adler isst
        in Elefant-Gehege wird gef³ttert
                Elefant isst
                Elefant isst
        in Giraffe-Gehege wird gef³ttert
                Giraffe isst
                Giraffe isst
                Giraffe isst
                Giraffe isst
        Pinguin-Becken wird gef³ttert
                Pinguin isst
                Pinguin isst
                Pinguin isst
        Delfin-Becken wird gef³ttert
                Delfin isst
                Delfin isst
                Delfin isst
                Delfin isst
Zoo wird aufgel÷st:
        Adler-Voiliere wird aufgeloest:
                Adler in Freiheit entlassen
                Adler in Freiheit entlassen
        Ente-Voiliere wird aufgeloest:
                Ente in Freiheit entlassen
                Ente in Freiheit entlassen
                Ente in Freiheit entlassen
        Giraffe-Gehege wird aufgeloest:
                Giraffe in Freiheit entlassen
                Giraffe in Freiheit entlassen
                Giraffe in Freiheit entlassen
                Giraffe in Freiheit entlassen
        Elefant-Gehege wird aufgeloest:
                Elefant in Freiheit entlassen
                Elefant in Freiheit entlassen
        Delfin-Becken wird aufgeloest:
                Delfin in Freiheit entlassen
                Delfin in Freiheit entlassen
                Delfin in Freiheit entlassen
                Delfin in Freiheit entlassen
        Pinguin-Becken wird aufgeloest:
                Pinguin in Freiheit entlassen
                Pinguin in Freiheit entlassen
                Pinguin in Freiheit entlassen
```