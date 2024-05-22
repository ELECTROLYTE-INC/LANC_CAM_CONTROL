//Based on code of KOCH Martin - Created by DANEL Mario

#include "LANC_CAM_CONTROL.h"

LANC_CAM_CONTROL::LANC_CAM_CONTROL(int commandPin, int lancPin) : _commandPin(commandPin), _lancPin(lancPin) {
    pinMode(_lancPin, INPUT);
    pinMode(_commandPin, OUTPUT);
}

void LANC_CAM_CONTROL::sendCommand(const boolean command[]) {
    noInterrupts();
    int cmdRepeatCount = 0;
    unsigned long bitDuration = 104; // Adjust this duration as needed
    while (cmdRepeatCount < 5) {
        while (pulseIn(_lancPin, HIGH) < 5000);
        delayMicroseconds(bitDuration);
        for (int i = 7; i >= 0; i--) {
            digitalWrite(_commandPin, command[i]);
            delayMicroseconds(bitDuration);
        }
        digitalWrite(_commandPin, LOW);
        delayMicroseconds(10);
        while (digitalRead(_lancPin));
        delayMicroseconds(bitDuration);
        for (int i = 15; i >= 8; i--) {
            digitalWrite(_commandPin, command[i]);
            delayMicroseconds(bitDuration);
        }
        digitalWrite(_commandPin, LOW);
        cmdRepeatCount++;
    }
    interrupts();
}

void LANC_CAM_CONTROL::startStopRecording() { sendCommand(REC); }
void LANC_CAM_CONTROL::zoomIn(int speed) { if (speed >= 0 && speed < 8) sendCommand(ZOOM_IN[speed]); }
void LANC_CAM_CONTROL::zoomOut(int speed) { if (speed >= 0 && speed < 8) sendCommand(ZOOM_OUT[speed]); }
void LANC_CAM_CONTROL::focusNear() { sendCommand(FOCUS_NEAR); }
void LANC_CAM_CONTROL::focusFar() { sendCommand(FOCUS_FAR); }
void LANC_CAM_CONTROL::focusAuto() { sendCommand(FOCUS_AUTO); }
void LANC_CAM_CONTROL::powerOff() { sendCommand(POWER_OFF); }
void LANC_CAM_CONTROL::powerOn() { sendCommand(POWER_ON); }
void LANC_CAM_CONTROL::powerRestart() { sendCommand(POWER_RESTART); }
void LANC_CAM_CONTROL::powerSleep() { sendCommand(POWER_SLEEP); }
void LANC_CAM_CONTROL::menu() { sendCommand(MENU); }
void LANC_CAM_CONTROL::up() { sendCommand(UP); }
void LANC_CAM_CONTROL::down() { sendCommand(DOWN); }
void LANC_CAM_CONTROL::left() { sendCommand(LEFT); }
void LANC_CAM_CONTROL::right() { sendCommand(RIGHT); }
void LANC_CAM_CONTROL::execute() { sendCommand(EXECUTE); }

const boolean LANC_CAM_CONTROL::REC[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH};
const boolean LANC_CAM_CONTROL::ZOOM_IN[8][16] = {
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}, // 0
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW}, // 1
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW}, // 2
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW}, // 3
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW}, // 4
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, HIGH, LOW}, // 5
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW}, // 6
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW}  // 7
};
const boolean LANC_CAM_CONTROL::ZOOM_OUT[8][16] = {
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW}, // 0
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW, HIGH, LOW}, // 1
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, HIGH, LOW, LOW}, // 2
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, HIGH, HIGH, LOW}, // 3
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW}, // 4
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH, LOW}, // 5
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, LOW}, // 6
    {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW}  // 7
};
const boolean LANC_CAM_CONTROL::FOCUS_NEAR[16] = {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH};
const boolean LANC_CAM_CONTROL::FOCUS_FAR[16] = {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW, HIGH, LOW, HIGH};
const boolean LANC_CAM_CONTROL::FOCUS_AUTO[16] = {LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH};
const boolean LANC_CAM_CONTROL::POWER_OFF[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW};
const boolean LANC_CAM_CONTROL::POWER_ON[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH, LOW, LOW, LOW};
const boolean LANC_CAM_CONTROL::POWER_RESTART[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW};
const boolean LANC_CAM_CONTROL::POWER_SLEEP[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, LOW};
const boolean LANC_CAM_CONTROL::MENU[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH, LOW, LOW, HIGH, HIGH, LOW, HIGH, LOW};
const boolean LANC_CAM_CONTROL::UP[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW, HIGH, LOW, LOW};
const boolean LANC_CAM_CONTROL::DOWN[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW};
const boolean LANC_CAM_CONTROL::LEFT[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH, LOW, LOW};
const boolean LANC_CAM_CONTROL::RIGHT[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH, LOW};
const boolean LANC_CAM_CONTROL::EXECUTE[16] = {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW, HIGH, LOW};
