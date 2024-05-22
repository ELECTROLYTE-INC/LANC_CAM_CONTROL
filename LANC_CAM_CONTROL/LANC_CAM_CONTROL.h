//Based on code of KOCH Martin - Created by DANEL Mario

#ifndef LANC_CAM_CONTROL_H
#define LANC_CAM_CONTROL_H

#include <Arduino.h>

class LANC_CAM_CONTROL {
public:
    LANC_CAM_CONTROL(int commandPin, int lancPin);

    void startStopRecording();
    void zoomIn(int speed);
    void zoomOut(int speed);
    void focusNear();
    void focusFar();
    void focusAuto();
    void powerOff();
    void powerOn();
    void powerRestart();
    void powerSleep();
    void menu();
    void up();
    void down();
    void left();
    void right();
    void execute();

private:
    int _commandPin;
    int _lancPin;
    void sendCommand(const boolean command[]);

    static const boolean REC[16];
    static const boolean ZOOM_IN[8][16];
    static const boolean ZOOM_OUT[8][16];
    static const boolean FOCUS_NEAR[16];
    static const boolean FOCUS_FAR[16];
    static const boolean FOCUS_AUTO[16];
    static const boolean POWER_OFF[16];
    static const boolean POWER_ON[16];
    static const boolean POWER_RESTART[16];
    static const boolean POWER_SLEEP[16];
    static const boolean MENU[16];
    static const boolean UP[16];
    static const boolean DOWN[16];
    static const boolean LEFT[16];
    static const boolean RIGHT[16];
    static const boolean EXECUTE[16];
};

#endif 
