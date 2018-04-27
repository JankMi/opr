# Vererbung
Nach dem Sie Ihren Zoo schließen mussten, weil die artgerechte Haltung nicht gegeben war, planen Sie einen neuen Versuch.
Die Anforderungen an den Zoo aufgrund der [Richtlinien zur Säugetierhaltung](https://www.bmel.de/SharedDocs/Downloads/Tier/Tierschutz/GutachtenLeitlinien/HaltungSaeugetiere.pdf?__blob=publicationFile) wollen Sie sich erzeugen lassen.
## Aufgabenstellung
Analog zur Verkehrsmittelaufgabe von Prof. Mahr
### Beschreigung
1. Der Zoo besitzt meherere Gehege, und eine Gesamtfläche
2. Gehege besitzen eine minimale Grundfläche, die Grundfläche für die Anzahl an Tieren, geplante Anzahl an Tieren, und einen Namen ('Tier'-Gehege) und eine Funktion zum liefern der Gehegfläche.
3. Die Anzahl der Tiere kann geändert werden
4. Es gibt spezielle Gehege: Gehege mit Becken und Volieren
5. Eine Voliere besitzt eine Höhe
6. Ein Gehege mit Becken eine Beckenfläche (zusätzlich zur "Trockenfläche")

### Architektur
Erläutern Sie Ihre Architektur anhand eines UML-Klassendiagramms. Verwenden Sie hierfür
* PlantUML (z.B. als VisualStudio Code Plugin, Beschreibung: http://plantuml.com/)
* das UML-Modellierungswerkzeug Enterprise Architect
  * Enterprise Architect ist auf den PCs im WB201,WB212 (C201 und C212 ???) installiert.
  * Eine kostenlose 30-Tage-Testversion kann auch von www.sparxsystems.com heruntergeladen werden. Das Windows-Programm kann man unter Linux oder Mac OSX in einer virtuellen Maschine ausführen, z.B. mit www.virtualbox.org.
* ein beliebiges anderes UML-Modellierungswerkzeug
  * Eine Liste von freien und kommerziellen Werkzeugen finden Sie unter http://de.wikipedia.org/wiki/UML_tool
  * Für das Klassendiagramm reicht das kompakte ArgoUML http://argouml.tigris.org.
  * Ein interessantes Open-Source-Werkzeug ist das von Airbus unterstützte Topcased http://www.topcased.org
  * Qt-Creator, ...
* oder notfalls, als vermeintliche Abkürzung, ein Zeichenprogramm oder eine handschriftlich erstellte, eingescannte Skizze.
Legen Sie Ihre Architektur als PDF-Dokument Ihrem Quellcode bei.

### Umsetzung in C++
1. Finden Sie anhand der vorangegangenen Beschreibung geeignete Klassen und deren Datenelemente und Elementfunktionen.
2. Nutzen Sie Vererbung bei allen Klassen, die Gehege darstellen.
3. Programmieren Sie alle Klassen in C++.
4. Bieten Sie für alle Datenelemente Lesefunktionen.
5. Jede Klasse muss in einer eigenen Datei definiert sein.
6. Alle Klassen müssen über eine Funktion ``string text()`` zur Darstellung des Objekts in Textform verfügen.
    * Eine Kindklasse überschreibt hierbei die Funktion ``string text()`` der Elternklasse.
    * Das Überschreiben von Funktionen der Elternklasse haben wir noch nicht im Unterricht besprochen. Bei Bedarf sollten Sie sich die Hintergründe im Skript oder einer anderen Quelle ansehen.
    * Falls Sie sich etwas Programmieraufwand sparen möchten, können Sie innerhalb der ``text()``-Funktion der Kindklasse auf die ``text()``-Funktion der Elternklasse ``E`` über die Notation ``E::text()`` zugreifen.
7. Die Zoo Klasse berechnet die nötige Gesamtfläche und gibt diese in ```text()``` mit aus
8. Schreiben Sie ein Testprogramm ``main()``, in dem Sie
    * von jeder Klasse, die ein Gehege darstellt, ein Objekt anlegen,
    * die Funktion string ``text()`` für diese Objekte aufrufen,
    * die Objekte an eine neue Anzahl setzen und
    * die Funktion string ``text()`` für diese Objekte nochmal aufrufen.

### Beispiele für Gehegerichtlinien
* Gleitbeutler 
    * minimal 6 m<sup>2</sup>
    * pro Tier 1 m<sup>2</sup>
    * Höhe 2m
*  Kängurus (kleine Arten)
    *  minimal 10 m<sup>2</sup>
    *  pro Tier 2 m<sup>2</sup>
    *  Badebecken mit 5 m<sup>2</sup>
* Gürteltiere
    * 10 m<sup>2</sup>
    * pro Tier 2 m<sup>2</sup>
* Seekühe
    * Becken mit 150 m<sup>2</sup>