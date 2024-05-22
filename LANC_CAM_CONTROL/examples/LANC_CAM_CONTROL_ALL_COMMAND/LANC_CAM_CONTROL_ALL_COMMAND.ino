//Based on code of KOCH Martin - Created by DANEL Mario

#include "LANC_CAM_CONTROL.h"

// Définir les pins de commande et LANC
#define COMMAND_PIN 6
#define LANC_PIN 7

LANC_CAM_CONTROL cameraControl(COMMAND_PIN, LANC_PIN);

void setup() {
    // Initialisation, si nécessaire
}

void loop() {
    // Démarrer ou arrêter l'enregistrement vidéo
    cameraControl.startStopRecording();
    delay(1000);
    
    // Zoomer de la vitesse la plus lente à la plus rapide
    for (int i = 0; i < 8; i++) {
        cameraControl.zoomIn(i);
        delay(500);  // Ajustez le délai si nécessaire pour observer les différents niveaux de zoom
    }
    
    // Dézoomer de la vitesse la plus lente à la plus rapide
    for (int i = 0; i < 8; i++) {
        cameraControl.zoomOut(i);
        delay(500);  // Ajustez le délai si nécessaire pour observer les différents niveaux de zoom
    }
    
    // Contrôle de la mise au point
    cameraControl.focusNear();
    delay(1000);
    cameraControl.focusFar();
    delay(1000);
    cameraControl.focusAuto();
    delay(1000);  
    // Commandes de menu
    cameraControl.menu();
    delay(1000);
    cameraControl.up();
    delay(1000);
    cameraControl.down();
    delay(1000);
    cameraControl.left();
    delay(1000);
    cameraControl.right();
    delay(1000);
    cameraControl.execute();
    delay(1000);
/*    
    // Commandes d'alimentation
    cameraControl.powerOff();
    delay(1000);
    cameraControl.powerOn();
    delay(1000);
    cameraControl.powerRestart();
    delay(1000);
    cameraControl.powerSleep();
    delay(1000);
*/      
}
