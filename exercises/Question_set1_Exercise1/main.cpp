/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: djarv
 *
 * Created on the 5 july 2017, 16:46
 */

#include <cstdlib>
#include "AudFile.h"
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

/*
 *
 */
void usage(char* prg){
    printf("Usage: %s <aud16.dat>\n",prg);
}

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc<2){
        usage(*argv);
        return 0;
    }
    printf("%s\n",argv[1]);
    AudFile *file = new AudFile(string(argv[1]));
    file->print();
    delete file;
    return 0;
}

