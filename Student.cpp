#include "MyLib.h"

int main() {
    vector<Studentas> grupe;
    int pasirinkimas;

    std::cout << "Pasirinkite buda:\n";
    std::cout << "1 - Ivesti rankiniu budu\n";
    std::cout << "2 - Generuoti atsitiktinai\n";
    std::cout << "3 - Didelis failas\n";
    std::cout << "Pasirinkimas: ";
    std::cin >> pasirinkimas;

    try {
        if (pasirinkimas == 1) {
            grupe = ivestiStudentusRankiniuBudu();
            std::cout << "Rikiuojami studentai\n";
            auto start = std::chrono::high_resolution_clock::now();
            vector<Studentas> vargsiukai, kietiakiai;
            rikiuotiStudentus(grupe);
            padalintiStudentus(grupe, vargsiukai, kietiakiai);
            rikiuotiStudentus(vargsiukai);
            rikiuotiStudentus(kietiakiai);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            std::cout << "Studentai surikiuoti ir padalinti per " << diff.count() << " sekundziu\n";
            std::cout << "\nVargsiukai:\n";
            spausdintiLentele(vargsiukai, true);
            std::cout << "\nKietiakiai:\n";
            spausdintiLentele(kietiakiai, true);
        }
        else if (pasirinkimas == 2) {
            grupe = generuotiAtsitiktiniusStudentus();
            std::cout << "Rikiuojami studentai\n";
            auto start = std::chrono::high_resolution_clock::now();
            vector<Studentas> vargsiukai, kietiakiai;
            rikiuotiStudentus(grupe);
            padalintiStudentus(grupe, vargsiukai, kietiakiai);
            rikiuotiStudentus(vargsiukai);
            rikiuotiStudentus(kietiakiai);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            std::cout << "Studentai surikiuoti ir padalinti per " << diff.count() << " sekundziu\n";
            std::cout << "\nVargsiukai:\n";
            spausdintiLentele(vargsiukai, true);
            std::cout << "\nKietiakiai:\n";
            spausdintiLentele(kietiakiai, true);
        }
        else if (pasirinkimas == 3) {
            string inputFile = "studentai_1000.txt";
            string vargsiukaiFile = "vargsiukai_1000.txt";
            string kietiakiaiFile = "kietiakiai_1000.txt";
            int numHomeworks = 5;
            std::cout << "Generuojamas failas\n";
            auto start = std::chrono::high_resolution_clock::now();
            generuotiStudentuFaila(1000, numHomeworks, inputFile);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            std::cout << "Failas sugeneruotas per " << diff.count() << " sekundziu\n";
            std::cout << "Nuskaitomi studentai is failo\n";
            start = std::chrono::high_resolution_clock::now();
            grupe = nuskaitytiStudentusIsFailo(inputFile);
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            std::cout << "Studentai nuskaityti per " << diff.count() << " sekundziu\n";
            std::cout << "Rikiuojami studentai\n";
            start = std::chrono::high_resolution_clock::now();
            vector<Studentas> vargsiukai, kietiakiai;
            rikiuotiStudentus(grupe);
            padalintiStudentus(grupe, vargsiukai, kietiakiai);
            rikiuotiStudentus(vargsiukai);
            rikiuotiStudentus(kietiakiai);
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            std::cout << "Studentai surikiuoti ir padalinti per " << diff.count() << " sekundziu\n";
            std::cout << "irašomi failai...\n";
            start = std::chrono::high_resolution_clock::now();
            irasytiStudentusIFaila(vargsiukai, vargsiukaiFile, numHomeworks);
            irasytiStudentusIFaila(kietiakiai, kietiakiaiFile, numHomeworks);
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            std::cout << "Failu iradymo laikas: " << diff.count() << " sekundziu\n";
            std::cout << "\nVargsiukai:\n";
            spausdintiLentele(vargsiukai, true);
            std::cout << "\nKietiakiai:\n";
            spausdintiLentele(kietiakiai, true);
        }
        else {
            std::cout << "Neteisingas pasirinkimas\n";
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Klaida " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
