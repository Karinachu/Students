# Students
Project
Programa dalija studentus i vargsiukus ir kietiakius. Matuoja laika ir atminti.

v0.1 
2025-09-30
Funkcijos:
- Klasė `Studentas` su **Rule of Three**
- Įvedimas per `cin`, išvedimas per `cout`
- Vidurkis 
- Atsitiktinis generavimas
- `std::vector` saugojimui
Rezultatai:
Programa veikia su mazais duomenimis. Isvedimas formatuotas.

v0.2
2025-10-08
Funkcijos:
- Skaitymas is failo
- Generavimas failu
- Dalijimas i `vargsiukai.txt` ir `kietiakiai.txt`
- Laiko matavimas (`chrono`)
Rezultatai (1000 studentų):
| Veiksmas | Laikas |
|---------|--------|
| Generavimas | 0.012s |
| Skaitymas | 0.008s |
| Dalijimas | 0.002s |
| Rašymas | 0.015s |


v1.0
2025-10-29Funkcijos:
- 3 dalijimo strategijos
- `std::partition` + `std::move`
- Atminties ir laiko matavimas
Rezultatai (1000 studentų):
| Strategija | Laikas | Atmintis |
|-----------|--------|----------|
| 1 (2 vektoriai) | 0.0021s | ~90 KB |
| 2 (erase) | 0.0045s | ~60 KB |
| **3 (partition)** | **0.0012s** | ~60 KB |
Isvada: `std::partition` – greiviausias ir taupiausias budas.
