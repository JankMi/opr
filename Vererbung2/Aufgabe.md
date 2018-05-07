# Vererbung2 (protected)
(lösbar in unter 70 Zeilen)
## Themen
+ Vererbung mit protected
+ graphische Ausgabe mit opencv
+ pseudo-code

## Aufgabe
1. Erstellen Sie ein Programm zur Darstellung und zum Speichern von (einfarbigen) Bildern.
    - Dazu erzeugen Sie eine Klasse ``Drawable``, die
        - ein Array für die Farbwerte der Pixel bereitstellt (``unsigned char``, ``CV_8UC1``)
        - eine ``draw`` und eine ``save`` bietet, die das Bild anzeigt bzw speichert
    - Zum Test leiten Sie von ``Drawable`` die Klassen ``HorizontalLine`` und ``VerticalLine`` ab, zum Zeichnen einer horizontalen bzw vertikalen Linie
2. Darstellen einer Julia-Menge <br>grob gesagt sind Julia-Mengen Stabilitätsbetrachtungen, von Funktionen(f(z) = z^2+c) in der Komplexen Ebene, die immer wieder auf ihre Ergebnisse angewendet werden. Ein Beispiel ist der Einheitskreis (c=0) Punkte auf dem Kreis werden immer auf sich selbst abgebildet, andere divergieren.<br>Mit folgendem Pseudo-Code kann die Stabilität von Funktionen betractet werden:
```
// 'c'
Realteil c = -0.8, Imaginärteil c = 0.2
für jeden Pixel an [x][y]
    // initialer Wert
    Realteil neuePosition = 1.5 * (2 x - Bildbreite)/Bildbreite
    imag-teil neuePosition = (2 y - Bildhöhe)/Bildhöhe
    i Schritte, max 255 mal
        altePostion = neuePosition
        neuePosition = altePosition ^2 + c
        Abbruch falls abs(neuePosition)^2 > 4 // schneller als abs(neuePosition) > 2
    Farbwert des Pixels = i
```
-0.8 + 0.2i liefert
![](m0k8p0k2.png)

-0.7 + 0.27015i
![](test.png)

## OpenCV 2.4
OpenCV ist eine freie Programmbibliothek mit Algorithmen für die Bildverarbeitung und maschinelles Sehen. Sie ist für die Programmiersprachen C, C++, Python und Java geschrieben und steht als freie Software unter den Bedingungen der BSD-Lizenz. [Wikipedia](https://de.wikipedia.org/wiki/OpenCV)
### prebuilt/build
- Visual Studio https://opencv.org/releases.html
- Linux packagemanager
- MinGW (CodeBlocks) muss compiliert werden ([Ausführlich](https://www.kevinhughes.ca/tutorials/opencv-install-on-windows-with-codeblocks-and-mingw) )
    - [sourcen opencv 2.4.9](http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/2.4.9/opencv-2.4.9.zip/download) laden und entpacken
    - [Cmake](https://cmake.org/download/) installieren
    - cmake-gui starten
    - where is the source code -> entpakter Ordner
    - where to build the binaries -> beliebiger Ordner [1]
    - Confiure klicken 
        - MinGW Makefiles
        - default compiler
    - unter BUILD
        - PERF_TESTS und TESTS deaktivieren
        - von BUILD_opencv_* werden nur core, highgui und imgproc benötigt
        - CMAKE_INSTALL_PREFIX[2] festlegen, hier werden die header und libraries abgelegt
    - nochmals Configure klicken, anschließend Generate
    - command prompt öffnen und in den Ordner [1] navigieren
        - build mit ``(pfad)(mingw32-)make -jX`` starten, die -j[Anzahl] option compiliert parallel in X jobs
        - ``(pfad)(mingw32-)make install`` kopiert header und libraries in [2]

### Verwendung
- [Bilder speichern](https://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html)
- [Bilder anzeigen](https://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html?highlight=imshow#imshow)


