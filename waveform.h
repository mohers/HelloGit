//
// Created by 24029135 on 08/04/2026.
// Requirement 1 - define a waveform sample struct

#ifndef WAVEFORM_H
#define WAVEFORM_H

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformTemplate;

#endif //WAVEFORM_H
