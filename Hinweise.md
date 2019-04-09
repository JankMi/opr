# Hinweise zur C++-Programmierung
## Namenskonventionen
- Variablen/Instanzen sollten immer mit einem Kleinbuchstaben beginnen,
- Defines, Makros Ausschließlich aus Großbuchstaben bestehen und
- Klassen und Strukturen mit einem Großbuchstaben gefolgt von Kleinbuchstaben

Selbstverständlich sind "sprechende" Namen zu bevorzugen.

Häufig werden Variablen einer Klasse mit voran gestelltem "m_" gekennzeichnet. Viele IDEs enthalten Tools zur automatischen Code-Vervollständigung, hier bekommt man, nach Eingabe von "m_", direkt alle Klassenvariablen zur Auswahl. 
```c 
int m_identifier
```

Die CamelCase-Notation ist auch weit verbreitet und wird zum Teil in Kombination angewendet.
```c
class ObjectContainer
{
private:  
    int m_objectCounter;
}
```


## Header - Source Trennung
Die Trennung von code in Header- und Sourcedateien bringt nicht nur den Vorteil der Übersichtlichkeit mit sich, sondern ist in ein paar Fällen unbedingt nötig. Diese werden ich am Ende anschneiden, Sie werden diese im Verlauf der Vorlesung kennenlernen.  
In vielen Fällen ist es nur interessant, den Aufbau und die Fähigkeiten einer Klasse zu kennen. Beispielsweise arbeiten Sie in einem Projekt mit mehreren Personen und erhalten Klassen oder Komponenten von Teammitgliedern, oder Sie verwenden eine Bibliothek, fügen ein neues Feature in eine existierendes Program ein, ... . In diesen Fällen liegt die Funktionalität der Klassen nicht bei Ihnen und vermutlich wollen Sie die Implementierung z.B. von std::stringstream auch nicht wissen. Mit einem Blick in den Header sollte man diese Informationen schnell und übersichtlich finden.  
Als Faustformel sollte nur die Klassendeklaration und deren Dokumentation im Header stehen. Allerdings werden in der Regel noch weitere Einträge erforderlich oder hilfreich sein. Wie z.B.:
- Include-Guards / pragma once
- Inculdes verwendeter Klassen header
- namespaces
- Forward declarations (Vorwärtsdeklarationen)
- inline-Funktionen
- ggf. mehr

zu inline-Funktionen:  
Funktionen, die innerhalb der Klassendeklaration definiert werden sind automatisch inline Funktionen, mit dem `ìnline` Schlüsselwort können inline Funktionen auch außerhalb der Klassen-Deklaration definiert werden. Die [google-c++ Programmierrichtlinien](https://google.github.io/styleguide/cppguide.html#Header_Files) schlagen eine Obergrenze für inline-Funktionen von Zeilen vor - Keine Schleifen! Keine Rekursionen! - Allerdings ist inline nur eine Empfehlung.

### Fälle in denen Header source Trennung unbedingt nötig ist
Unter anderem bei Vorwärtsdeklarationen, diese sind nötig wenn in der Architektur ein Henne-Ei-Problem auftritt. Würde `Henne.h`  `Ei.h` inkludieren und umgekehrt `Ei.h` `Henne.h` inkludieren würden dies die include-guards verhinder, bzw. ohne eine Endlosschleife entstehen. In der folgenden Lösung wird in beiden Headern per Vorwärtsdeklaration bekannt gegben, dass eine Klasse mit dem jeweiligen Namen existiert und beim Kompilieren der source-Datei zur Verfügung steht (include in cpp-Datei)
Vorwärtsdeklarationen werden auch bei Freund-Klassen und Funktionen eingesetzt
```c henne.h
#ifndef HENNE_H
#define HENNE_H

class Ei;       // forawrd declaration

class Henne
{
public:
    Henne();
    Ei* legeEi()const;
};

#endif // HENNE_H
```

```c ei.h
#ifndef EI_H
#define EI_H

class Henne;     // forawrd declaration

class Ei
{
public:
    Ei();
    Henne* schluepfe()const;
};

#endif // EI_H
```

Weiter müssen statische Klassenvariablen außerhalb der Klasse definiert werden. Werden diese im Header definiert und ist dieser mehrfach inkludiert, wird die Variable auch mehrfach definiert -> Linker-Fehler