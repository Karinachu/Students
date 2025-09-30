#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::accumulate;

class Studentas {
public:
    Studentas();
    Studentas(std::string A, std::string B, std::vector<int> C, int D);
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    ~Studentas();
    void rez(bool useMedian = false);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& obj);
    friend std::istream& operator>>(std::istream& is, Studentas& obj);

    double skaiciuotiMediana() const;
    void generuotiAtsitiktiniusPazymius(int ndKiekis);
    void setVardas(const std::string& v);
    void setPavarde(const std::string& p);
    void setEgzaminas(int e);
    void addPazymys(int p);
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    double getRezultatas() const { return rezultatas; }
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egzaminas;
    double rezultatas;
};
void spausdintiLentele(const vector<Studentas>& grupe, bool showBoth = false);
void rikiuotiStudentus(vector<Studentas>& grupe);
vector<Studentas> ivestiStudentusRankiniuBudu();
vector<Studentas> generuotiAtsitiktiniusStudentus();