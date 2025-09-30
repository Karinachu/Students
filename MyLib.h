#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>

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
    void rez();
    void output();
    friend std::ostream& operator<<(std::ostream& os, const Studentas& obj);
    friend std::istream& operator>>(std::istream& is, Studentas& obj);

private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egzaminas;
    double rezultatas;
};