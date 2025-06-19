# type42-berlin

Ein Terminal-basiertes Lernwerkzeug für 42-Studenten, um libft, get_next_line und ft_printf Funktionen durch Tippen auswendig zu lernen.

## Funktionen

- **Kopiermodus**: Der Benutzer tippt die angezeigte Funktion ab, um die Syntax und Struktur einzuprägen.
- **Erinnerungsmodus**: Nur der Funktionsname und die Beschreibung werden angezeigt – der Benutzer tippt die Implementierung aus dem Gedächtnis.
- **Punkte-System**: Richtige und falsche Antworten werden gezählt und am Ende als Score angezeigt.
- **Konfigurierbare Varianten**: Wähle z.B. zwischen index- und pointer-basierten Varianten von Funktionen.
- **GNL- und ft_printf-Unterstützung**: Funktionen aus diesen Projekten sind zur Übung integriert.
- **Mehrsprachige Benutzeroberfläche**: Standardmäßig auf Englisch, aber übersetzbar (z.B. ins Deutsche).

## Installation

```bash
make install
./type42
```

## Struktur

Die Funktionen sind in strukturierten Kategorien organisiert:

- libft
- get_next_line
- ft_printf (in drei Teilen: Hilfsfunktionen, Format-Handler, Dispatcher)

## Beispiel

```
Funktionsname: ft_strlen
Beschreibung: Berechnet die Länge eines Strings.
Erwartete Rückgabe: Länge als size_t
```

## Ziel

Diese App soll dir helfen, durch aktives Tippen und Wiederholen das Verständnis und die Sicherheit in grundlegenden Funktionen zu vertiefen – ideal zur Vorbereitung auf Prüfungen und zum Aufbau von Muscle Memory.
