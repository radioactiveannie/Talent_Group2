/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudFile.cpp
 * Author: djarv
 * 
 * Created on den 5 juli 2017, 17:13
 */
#include <errno.h>
#include <cstdlib>
#include <string.h>
#include "AudFile.h"

AudFile::AudFile(string filename) {
    cout<<filename<<endl;
    FILE* infile = fopen(filename.c_str(),"r");
    if (infile == NULL){
        fprintf(stderr,"Error could not open file %s, %s",
                filename.c_str(),strerror(errno));
        exit(1);
    }
    char* r = NULL;
    size_t n = 0;
    // Removing the two first lines, since they do not help us
    getline(&r,&n,infile);
    getline(&r,&n,infile);
    while (!feof(infile)){
        row r_;
        // Read each row in the file and then construct a vector
        getline(&r,&n,infile);
        // The star means that it should expect an integer, but not assign the 
        // value to an argument
        if (sscanf(r,"%d %d %lf %lf %*d %d",
                &r_.iz,&r_.ia,&r_.bindEner,&r_.error,&r_.in)<5){
            break;
        }
        rows.push_back(r_);
    }
    fclose(infile);
    free(r);
}

AudFile::AudFile(const AudFile& orig) {
}

AudFile::~AudFile() {
}

void AudFile::print() {
    for (row r_ : rows){
        printf("%d %d %lf %lf %d\n",
               r_.iz,r_.ia,r_.bindEner,r_.error,r_.in);
    }
}