# Aufgabe 10 - Radar

Erstellen Sie ein Programm, das die Luftraumüberwachung simuliert. Verwenden Sie das folgende Klassen-Diagram - ergänzen Sie const! 
Air werden Überwacher - wie ein Radar - hinzugefügt und unterschiedliche Luftfahrzeuge. In jeder Runde (gesteuert von der main) lässt Air die Flugobjekte fliegen und übergibt die Luftfahrzeuge an die Überwachung. Das Radar gibt die ID der Fluggeräte und deren Höhe aus. 
Die IAircraft und Aircraft_Impl Klassen sind analog zu dem Standardvorgehen von Prof. Mahr und hoffentlich selbsterklärend.

Flugzeuge werden mit einer Flugdauer gestartet. Nach einem Steigflug von 4000m / fly()-Aufruf, plus eine Zufallszahl zwischen 0 und 100, fliegen diese `duration`x fly()-Aufrufe. Danach Sinken die Flugzeuge mit 4000m / fly()-Aufruf. 
Vernachlässigen Sie zunächst die Ufos, aber diese fliegen immer auf 12000m.

*Die Funktionen sind hauptsächlich Einzeiler.*

Da Ihnen auffällt, dass sich in diesem Modell Flugzeuge mehrere Kilometer in den Boden rammen möchten Sie diesen Fall ausschließen - werfen Sie für alle Luftfahrzeuge eine `out_of_range`-exception die in den Implementierungen von fly()-abgehandelt wird. Das Flugzeug legt dann eine Notlandung ein, Ufos wieder auf 12000m Flughöhe gesetzt.

Jetzt die UFOs:
Hier liefert getID() keine gültige ID sondern eine exception. Vergleichen Sie was passiert wenn Sie "!!!!!UFO!!!!!" werfen und wenn sie eine `ExtraTerestrial_Exception` von `std::logic_error` ableiten und eine Instanz davon werfen.

![alt text](https://github.com/JankMi/opr/tree/master/Aufgabe10/Radar.png "Class diagram 'radar'")


