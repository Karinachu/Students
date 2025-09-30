
#include "MyLib.h"
int main() {
    vector<Studentas> grupe;
    int pasirinkimas;

    std::cout << "Pasirinkite buda:\n";
    std::cout << "1 - Ivesti rankiniu budu\n";
    std::cout << "2 - Generuoti atsitiktinai\n";
    std::cout << "Pasirinkimas: ";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        grupe = ivestiStudentusRankiniuBudu();
    }
    else if (pasirinkimas == 2) {
        grupe = generuotiAtsitiktiniusStudentus();
    }

    rikiuotiStudentus(grupe);
    spausdintiLentele(grupe, true);

    return 0;
}