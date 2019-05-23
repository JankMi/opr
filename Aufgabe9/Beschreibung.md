# Temmplates und Operatoren

Erstellen Sie eine parametrierbare/template Klasse VektorSumme, die Vektoren summieren kann. Zum Test erstellen Sie die Klassen Vektor2D und Vektor3D. Die Klassen und Operatoren sind unfreundlich.

Die Vektoren(2D&3D)
- besitzen ihre Koordinaten x,y[,z]
- get-Funktionen für die Koordinaten und die Vektorlänge
- können auf ostream geschrieben werden
- können mit den + und += operatoren Addiert werden

Die VektorSumme
- speichert nur den Summenvektor
- kann den Summenvektor bzw. dessen Länge zurückgeben
- kann mit += eine andere Vektorsumme hinzu addieren

Kurz die folgende Main muss erfüllt werden.
```c++
int main()
{
    VektorSumme<Vektor2D> vektorZug_2d;
    vektorZug_2d += (Vektor2D(1,1)+Vektor2D(1,1));
    cout << "Laenge: "<< vektorZug_2d.getLaenge() << " Vektor: " <<vektorZug_2d.getVektorSumme() <<endl;

    cout<<endl;

    VektorSumme<Vektor2D> vektorZug_2d_toAdd(Vektor2D(1,1));
    auto result2D = vektorZug_2d + vektorZug_2d_toAdd;
    cout << "Laenge: "<< result2D.getLaenge() << " Vektor: " <<result2D.getVektorSumme() <<endl<<endl<<endl;


    VektorSumme<Vektor3D> vektorZug_3d;
    vektorZug_3d += (Vektor3D(1,1,1)+Vektor3D(1,1,1));
    cout << "Laenge: "<< vektorZug_3d.getLaenge() << " Vektor: " <<vektorZug_3d.getVektorSumme() <<endl;

    cout<<endl;

    VektorSumme<Vektor3D> vektorZug_3d_toAdd(Vektor3D(1,1,1));
    auto result3D = vektorZug_3d + vektorZug_3d_toAdd;
    cout << "Laenge: "<< result3D.getLaenge() << " Vektor: " <<result3D.getVektorSumme() <<endl<<endl<<endl;

    return 0;
}
```

Ausgabe
```
Laenge: 2.82843 Vektor: Vektor(2/2)

Laenge: 4.24264 Vektor: Vektor(3/3)


Laenge: 3.4641 Vektor: Vektor(2/2/2)

Laenge: 4.89898 Vektor: Vektor(3/3/3)
```
