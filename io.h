//
// Created by 24029135 on 08/04/2026.
//Requirements
#ifndef IO_H
#define IO_H
#include "waveform.h"
//Functions
int countRows(char *fileName);
waveformSample *loadData(char *fileName, int totalCount);

#endif //IO_H
