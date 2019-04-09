# Aufgabe 4 - Konstruktoren / Destruktoren

## Inhalte
- Container-Klassen
- statische Klassenvariablen und -methoden
- Konstruktoren & Destruktoren

## Aufgabe
Verwenden Sie in dieser Aufgaben einen Logger, der als Singleton-Realisiert ist, für die Ausgaben.
Das heißt, es ist sichergestellt, dass nur eine Instanz dieser Klasse existieren kann!
In der Regel verwendet man eine static-Funktion, welche die Instanz mittels privatem Konstruktor erzeugt, wenn noch keine Instanz existiert.
Dieses Objekt gibt mit der schreibe-Funktion den übergebenen Text auf cout aus, mit vorgestelltem "Logger: ".

Die folgenden Klassen schreiben im Konstruktor/Destruktor auf den Logger ihre Signatur. (compiler-macors \_\_func\_\_ oder \_\_PRETTY_FUNCTION\_\_ ?)

Erstellen Sie ein Programm, dass ihnen Straßen mit Häusern erzeugt.
Die Straßen erhalten beim Konstruktor-Aufruf eine Initialisierungsliste mit Hausnummern, für die Häuser erzeugt werden und speichern sie in einem Vektor. Weiter erhalten die Straßen beim Konstruktor aufruf einen Namen. Die Häuser haben Straßennamen und Hausnummer. Straßen und Häuser haben Funktionen um direkt auf cout ihre Werte auszugeben.

Erzeugen Sie >=3 Straßen, mit jeweils meherern Häusern.
Geben Sie die Straßen und Häuser nach Erzeugung aus.

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
Logger: Haus::~Haus()
        Haus: Hauptstrasse 2
Logger: Haus::~Haus()
        Haus: Hauptstrasse 3
Logger: Haus::~Haus()
        Haus: Hauptstrasse 5
Logger: Haus::~Haus()
        Haus: Hauptstrasse 6
Logger: Haus::~Haus()
Strasse: Nebenstrasse hat die Haeuser:
        Haus: Nebenstrasse 10
Logger: Haus::~Haus()
        Haus: Nebenstrasse 12
Logger: Haus::~Haus()
        Haus: Nebenstrasse 53
Logger: Haus::~Haus()
        Haus: Nebenstrasse 45
Logger: Haus::~Haus()
        Haus: Nebenstrasse 26
Logger: Haus::~Haus()
Strasse: Drittestrasse hat die Haeuser:
        Haus: Drittestrasse 38
Logger: Haus::~Haus()
        Haus: Drittestrasse 93
Logger: Haus::~Haus()
        Haus: Drittestrasse 2
Logger: Haus::~Haus()
        Haus: Drittestrasse 834
Logger: Haus::~Haus()
        Haus: Drittestrasse 120
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
Logger: Strasse::~Strasse()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
Logger: Haus::~Haus()
```