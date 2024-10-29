int ultrason = 0; // Déclaration de la variable 'ultrason' qui stockera la distance mesurée par le capteur ultrasonique

// Fonction pour lire la distance mesurée par le capteur ultrasonique
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Configure le pin trigger en mode sortie
  digitalWrite(triggerPin, LOW); // Initialise le trigger à l'état bas
  delayMicroseconds(2); // Attend 2 microsecondes pour stabiliser le signal
  
  // Active le pin trigger à l'état haut pendant 10 microsecondes pour déclencher le capteur
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); // Maintient l'état haut pendant 10 microsecondes
  digitalWrite(triggerPin, LOW); // Remet le trigger à l'état bas
  
  pinMode(echoPin, INPUT); // Configure le pin echo en mode entrée pour lire la durée du signal renvoyé
  
  // Lit la durée pendant laquelle le pin echo est à l'état haut et retourne cette durée en microsecondes
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600); // Initialise la communication série à 9600 bps pour afficher la distance
  pinMode(13, OUTPUT); // Configure le pin 13 en mode sortie (pour activer un signal sonore si nécessaire)
}

void loop()
{
  // Multiplie la durée du trajet de l'onde sonore par 0.01723 pour obtenir la distance en centimètres
  ultrason = 0.01723 * readUltrasonicDistance(2, 3);
  
  Serial.println(ultrason); // Affiche la distance mesurée dans le moniteur série
  
  // Vérifie si la distance est inférieure ou égale à 10 cm
  if (ultrason <= 10) {
    tone(13, 523, 1000); // Joue un son de 523 Hz (note C5) pendant 1 seconde sur le pin 13
  } else {
    noTone(13); // Arrête le son sur le pin 13 si la distance est supérieure à 10 cm
  }
  
  delay(10); // Petite pause pour améliorer les performances de la simulation
}
