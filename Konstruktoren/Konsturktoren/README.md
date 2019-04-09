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

Die folgenden Klassen schreiben im Konstruktor/Destruktor auf den Logger ihre Signatur. (compiler-macors __func__ oder __PRETTY_FUNCTION__ ?)

Erstellen Sie ein Programm, dass ihnen Straßen mit Häusern erzeugt.
Die Straßen erhalten beim Konstruktor-Aufruf eine Initialisierungsliste mit Hausnummern, für die Häuser erzeugt werden und speichern sie in einem Vektor. Weiter erhalten die Straßen beim Konstruktor aufruf einen Namen. Die Häuser haben Straßennamen und Hausnummer. Straßen und Häuser haben Funktionen um direkt auf cout ihre Werte auszugeben.

Erzeugen Sie >=3 Straßen, mit jeweils meherern Häusern.
Geben Sie die Straßen und Häuser nach Erzeugung aus.