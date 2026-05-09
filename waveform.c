//
// Created by 24029135 on 08/04/2026.
//
// Requirement 5/6/7/8 - RMS, P2P, DC offset, detect clipping

#include <stdio.h>
#include <math.h>
#include "waveform.h"

// RMS calculation
 double calculateRMS(double *values, int n) {
     int i;
     double sum = 0;
     for (i = 0; i < n; i++)
         sum += values[i] * values[i];
     return sqrt(sum / n);
 }

// DC offset or mean calculation
double calculateMean(double *values, int n) {
     int i;
     double sum = 0;
     for (i = 0; i < n; i++)
         sum += values[i];
     return sum / n;
 }

// Peak to Peak Calculation
double calculatePeak2Peak(double *values, int n) {
    double min = 0, max = 0;
     for (int i = 0; i < n; i++) {
         if (values[i] > max) max = values[i];
         if (values[i] < min) min = values[i];
     }
     return max - min;
 }

// Clipping detection
int clippingDetection(double *values, int n) {

     for (int i = 0; i < n; i++) {
         if (values[i] >= 324.9 || values[i] < -329.9) {
             return 1;
         }
     }

    return 0;
}

int toleranceCompliance(double rms) {
     if (rms <= 253 && rms >= 207)
         return 0;//within tolerance
     else {
         return 1;//out of tolerance
     }
 }