#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iterator>    

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
    const std::vector<int>& getPaz() const { return paz; } 
    int getEgzaminas() const { return egzaminas; }
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
vector<Studentas> nuskaitytiStudentusIsFailo(const std::string& filename);
void generuotiStudentuFaila(int numStudents, int numHomeworks, const std::string& filename);
void irasytiStudentusIFaila(const vector<Studentas>& students, const std::string& filename, int numHomeworks);
void padalintiStudentus(const vector<Studentas>& grupe, vector<Studentas>& vargs, vector<Studentas>& kiet);

void padalintiStudentus1(const std::vector<Studentas>& grupe, std::vector<Studentas>& vargs, std::vector<Studentas>& kiet);
void padalintiStudentus2(std::vector<Studentas>& grupe, std::vector<Studentas>& vargs);
void padalintiStudentus3(std::vector<Studentas>& grupe, std::vector<Studentas>& vargs);