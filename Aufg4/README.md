# Aufgabe 4 - Konstruktoren / Destruktoren

## Inhalte
- Container-Klassen
- statische Klassenvariablen und -methoden
- Konstruktoren & Destruktoren

## Aufgabe
Erstellen Sie ein Programm, dass ihnen Straßen mit Häusern erzeugt.
Die Straßen erhalten beim Konstruktor-Aufruf eine Initialisierungsliste/set/andereContainerklasse mit Hausnummern, für die Häuser erzeugt werden und speichern sie in einem Vektor. Weiter erhalten die Straßen beim Konstruktor aufruf einen Namen. Die Häuser haben Hausnummer. Straßen können mit schreibe() direkt auf cout ihren Namen und deren Häuser ausgeben.

Erzeugen Sie >=3 Straßen, mit jeweils meherern Häusern.
Geben Sie die Straßen und Häuser nach Erzeugung aus.


Verwenden Sie in dieser Aufgaben einen Logger, um Konstruktor und Destruktor aufrufe auszugeben.

Der Logger soll als Singleton realisiert sein, das heißt, es ist sichergestellt, dass nur eine Instanz dieser Klasse existieren kann!

In der Regel verwendet man eine static-Funktion(getLogger), welche die Instanz(m_logger) mittels privatem Konstruktor erzeugt, wenn noch keine Instanz existiert.
Dieses Objekt gibt mit der schreibe-Funktion den übergebenen Text auf cout aus, mit vorgestelltem "Logger: ".

Die Klassen schreiben im Konstruktor/Destruktor auf den Logger ihre Signatur/Namen. (compiler-macors __func__ oder __PRETTY_FUNCTION__ ?)

[Hier können Sie die Lebensdaurern der Objekte bei unterschiedlichen "Speichermethoden"(Zeiger/Objekte/Referenzen) im Container vergleichen. Ggf auf den copyconstructor auf logger schreiben lassen.] 

### mögliche main
```c++
int main()
{
    Strasse hauptstrasse{"Hauptstrasse", {1,2,3,5,6} };
    Strasse nebenstrasse{"Nebenstrasse", {10,12,53,45,26} };
    Strasse drittestrasse{"Drittestrasse", {38,93,2,834,120} };
    hauptstrasse.write();
    nebenstrasse.write();
    drittestrasse.write();
    return 0;
}
```

### zugehörige Ausgabe
```c
Logger::Logger()
Logger: Strasse::Strasse(std::__cxx11::string, std::initializer_list<int>)
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Strasse::Strasse(std::__cxx11::string, std::initializer_list<int>)
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Strasse::Strasse(std::__cxx11::string, std::initializer_list<int>)
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::Haus(std::__cxx11::string, int)
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Strasse: Hauptstrasse hat die Haeuser:
        Haus: Hauptstrasse 1
        Haus: Hauptstrasse 2
        Haus: Hauptstrasse 3
        Haus: Hauptstrasse 5
        Haus: Hauptstrasse 6
Strasse: Nebenstrasse hat die Haeuser:
        Haus: Nebenstrasse 10
        Haus: Nebenstrasse 12
        Haus: Nebenstrasse 53
        Haus: Nebenstrasse 45
        Haus: Nebenstrasse 26
Strasse: Drittestrasse hat die Haeuser:
        Haus: Drittestrasse 38
        Haus: Drittestrasse 93
        Haus: Drittestrasse 2
        Haus: Drittestrasse 834
        Haus: Drittestrasse 120
Logger: Strasse::~Strasse()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Strasse::~Strasse()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Strasse::~Strasse()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
```
