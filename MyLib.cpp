#include "MyLib.h"

Studentas::Studentas() {
    vardas = "Testas";
    pavarde = "TestasTestas";
    paz = { 1,5,8,7,7,4,8,9 };
    egzaminas = 10;
    rez();
}
Studentas::Studentas(string A, string B, vector<int> C, int D) {
    vardas = A;
    pavarde = B;
    paz = C;
    egzaminas = D;
    rez();
}
Studentas::Studentas(const Studentas& other) {
    vardas = other.vardas;
    pavarde = other.pavarde;
    paz = other.paz;
    egzaminas = other.egzaminas;
    rezultatas = other.rezultatas;
}
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        paz = other.paz;
        egzaminas = other.egzaminas;
        rezultatas = other.rezultatas;
    }
    return *this;
}

Studentas::~Studentas() {
    vardas.clear();
    pavarde.clear();
    paz.clear();
    egzaminas = 0;
    rezultatas = 0;
}

void Studentas::setVardas(const std::string& v) { vardas = v; }
void Studentas::setPavarde(const std::string& p) { pavarde = p; }
void Studentas::setEgzaminas(int e) { egzaminas = e; }
void Studentas::addPazymys(int p) { paz.push_back(p); }

double Studentas::skaiciuotiMediana() const {
    if (paz.empty()) return 0.0;

    std::vector<int> sortedPaz = paz;
    std::sort(sortedPaz.begin(), sortedPaz.end());

    size_t size = sortedPaz.size();
    if (size % 2 == 0) {
        return (sortedPaz[size / 2 - 1] + sortedPaz[size / 2]) / 2.0;
    } else {
        return sortedPaz[size / 2];
    }
}

void Studentas::rez(bool useMedian) {
    double namuDarbuVidurkis;

    if (useMedian) {
        namuDarbuVidurkis = skaiciuotiMediana();
    }
    else {
        if (paz.empty()) {
            namuDarbuVidurkis = 0.0;
        }
        else {
            namuDarbuVidurkis = accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
        }
    }

    rezultatas = namuDarbuVidurkis * 0.4 + egzaminas * 0.6;
}
void Studentas::generuotiAtsitiktiniusPazymius(int ndKiekis) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    paz.clear();
    for (int i = 0; i < ndKiekis; ++i) {
        paz.push_back(dis(gen));
    }
    egzaminas = dis(gen);
    rez();
}
std::ostream& operator<<(std::ostream& os, const Studentas& obj) {
    double vidurkis = obj.paz.empty() ? 0.0 : accumulate(obj.paz.begin(), obj.paz.end(), 0.0) / obj.paz.size();
    double mediana = obj.skaiciuotiMediana();
    double galutinisVid = vidurkis * 0.4 + obj.egzaminas * 0.6;
    double galutinisMed = mediana * 0.4 + obj.egzaminas * 0.6;

    os << std::setw(15) << std::left << obj.pavarde
        << std::setw(15) << obj.vardas
        << std::fixed << std::setprecision(2)
        << std::setw(20) << galutinisVid
        << std::setw(20) << galutinisMed;
    return os;
}
std::istream& operator>>(std::istream& is, Studentas& obj) {
    std::cout << "Vardas Pavarde: ";
    is >> obj.vardas >> obj.pavarde;

    obj.paz.clear();
    std::cout << "Iveskite pazymius: ";
    int n;
    while (is >> n) {
        if (n == -1) break;
        if (n < 1 || n > 10) {
            std::cout << "Pazymys turi buti nuo 1 iki 10";
            continue;
        }
        obj.paz.push_back(n);
    }

    std::cout << "Egzamino pazymys: ";
    is >> obj.egzaminas;

    if (obj.egzaminas < 1 || obj.egzaminas > 10) {
        throw std::runtime_error("Egzamino pazymys turi buti nuo 1 iki 10");
    }

    obj.rez();
    return is;
}
void spausdintiLentele(const vector<Studentas>& grupe, bool showBoth) {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << std::left << std::setw(15) << "Pavarde"
        << std::setw(15) << "Vardas";

    if (showBoth) {
        std::cout << std::setw(20) << "Galutinis (Vid.)"
            << std::setw(20) << "Galutinis (Med.)";
    }
    else {
        std::cout << std::setw(20) << "Galutinis (Vid.)";
    }

    std::cout << "\n" << std::string(70, '-') << "\n";

    for (const auto& studentas : grupe) {
        std::cout << studentas << std::endl;
    }
    std::cout << std::string(70, '=') << "\n";
}

void rikiuotiStudentus(vector<Studentas>& grupe) {
    std::sort(grupe.begin(), grupe.end(),
        [](const Studentas& a, const Studentas& b) {
            if (a.getPavarde() != b.getPavarde()) {
                return a.getPavarde() < b.getPavarde();
            }
            return a.getVardas() < b.getVardas();
        });
}
vector<Studentas> ivestiStudentusRankiniuBudu() {
    vector<Studentas> grupe;
    int kiekis;

    std::cout << "Kiek studentu? ";
    std::cin >> kiekis;

    for (int i = 0; i < kiekis; i++) {
        Studentas studentas;
        std::cin >> studentas;
        grupe.push_back(studentas);
    }

    return grupe;
}
 
vector<Studentas> generuotiAtsitiktiniusStudentus() {
    vector<Studentas> grupe;
    int studentuKiekis, ndKiekis;

    std::cout << "Studentu kiekis: ";
    std::cin >> studentuKiekis;
    std::cout << "Namu darbu kiekis: ";
    std::cin >> ndKiekis;

    for (int i = 0; i < studentuKiekis; i++) {
        Studentas studentas;
        studentas.generuotiAtsitiktiniusPazymius(ndKiekis);
        studentas.setVardas("Studentas" + std::to_string(i + 1));
        studentas.setPavarde("Pavarde" + std::to_string(i + 1));
        grupe.push_back(studentas);
    }

    return grupe;
}