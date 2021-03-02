#include <Arduino.h>
#include "header/UltraSonic.h"
#include "header/Presence.h"
#include "header/InfraRed.h"
#include "header/Communication.h"
#include "header/IntervalManager.h"

UltraSonic sonic1 = UltraSonic();
UltraSonic sonic2 = UltraSonic();
UltraSonic sonic3 = UltraSonic();

Presence detectPresence = Presence();

InfraRed wasteDetector1 = InfraRed();
InfraRed wasteDetector2 = InfraRed();
InfraRed wasteDetector3 = InfraRed();

Communication com = Communication();
IntervalManager timer = IntervalManager();

void setup()
{
  /* Initialise le port série */
  com.init(9600);
  sonic1.init(13, 12);
  sonic2.init(11,10);
  sonic3.init(9,8);

  detectPresence.init(1);

  wasteDetector1.init(2);
  wasteDetector2.init(3);
  wasteDetector3.init(4);

}

void loop()
{
  Serial.print(F("Distance détecteur 1 : "));
  Serial.println(sonic1.getDistance());

  Serial.print(F("Distance détecteur 2 : "));
  Serial.println(sonic2.getDistance());

  if(detectPresence.getIsDetect() == PresenceState::startDetecting) {
    Serial.println("Motion detected");
  }


  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(timer.getInterval());
}

