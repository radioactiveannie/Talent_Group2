/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudFile.h
 * Author: djarv
 *
 * Created on den 5 juli 2017, 17:13
 */

#ifndef AUDFILE_H
#define AUDFILE_H
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

struct row{
    int iz, ia, in;
    double bindEner, error; 
};  

class AudFile {
public:
    AudFile(string filename);
    AudFile(const AudFile& orig);
    ~AudFile();
    void print();
private:
    
    vector<row> rows;
};

#endif /* AUDFILE_H */

