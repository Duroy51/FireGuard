
Voici le fichier README traduit en français pour votre projet de capteur de flamme :

---

# Projet Capteur de Flamme

Ce projet utilise un Arduino et un capteur de flamme pour détecter des niveaux de température et activer des LED en fonction de plages de température spécifiques. Le système est conçu pour surveiller l’intensité de la flamme et fournir des alertes selon différents seuils de température.

**Simulation :** Accédez à la [simulation Tinkercad ici](https://www.tinkercad.com/things/128zTTY3Y8c-detecteur-de-flamme/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard). 

## Table des Matières
- [Aperçu](#aperçu)
- [Matériel Requis](#matériel-requis)
- [Montage du Circuit](#montage-du-circuit)
- [Explication du Code](#explication-du-code)
- [Utilisation](#utilisation)
- [Améliorations Futures](#améliorations-futures)

---

## Aperçu
Ce projet utilise un capteur de flamme connecté à un Arduino pour lire les niveaux de température, lesquels sont ensuite mappés à des seuils de température spécifiques. Le système active différentes LED en fonction de la température détectée, ce qui permet d’indiquer l'intensité faible, moyenne ou élevée de la flamme.

## Matériel Requis
- 1 x Arduino Uno
- 1 x Capteur de flamme (connecté à l’entrée analogique A0)
- 3 x LED (Rouge, Jaune, Verte)
- 3 x Résistances de 220Ω
- Fils de connexion

## Montage du Circuit
1. **Capteur de Flamme** : Connectez la sortie analogique du capteur de flamme à la broche A0 de l’Arduino.
2. **LED** :
   - LED verte connectée à la broche numérique 4 (indique une basse température).
   - LED jaune connectée à la broche numérique 3 (indique une température moyenne).
   - LED rouge connectée à la broche numérique 2 (indique une température élevée).
3. **Alimentation** : Assurez-vous de bien connecter les pins 5V et GND de l’Arduino.

## Explication du Code

Le code suivant lit la température depuis le capteur de flamme et allume une LED en fonction de la plage de température :

```cpp
int temp = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT); // LED verte
  pinMode(3, OUTPUT); // LED jaune
  pinMode(2, OUTPUT); // LED rouge
}

void loop()
{
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(temp);

  if (temp < 25) {
    digitalWrite(4, HIGH);   // Basse température - LED verte allumée
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  else if (temp >= 25 && temp < 50) {
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);   // Température moyenne - LED jaune allumée
    digitalWrite(2, LOW);
  }
  else if (temp >= 50) {
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);   // Haute température - LED rouge allumée
  }
  delay(10);
}
```

### Détails du Code
- **Calcul de la Température** : La température est calculée en utilisant la fonction `map()`, où la valeur analogique est convertie en une plage de -40°C à 125°C.
- **Indicateurs LED** : 
  - **LED Verte** : S’allume lorsque la température est inférieure à 25°C.
  - **LED Jaune** : S’allume lorsque la température est entre 25°C et 50°C.
  - **LED Rouge** : S’allume lorsque la température est supérieure à 50°C.
  
## Utilisation
1. **Montez le circuit** comme décrit ci-dessus.
2. **Chargez le code** sur votre carte Arduino à l’aide de l’IDE Arduino.
3. **Surveillez la Sortie Série** : Ouvrez le Moniteur Série pour voir les relevés de température.
4. **Observez les LED** : En fonction de la température détectée, différentes LED s’allument pour indiquer des températures basses, moyennes et élevées.

## Améliorations Futures
- Ajouter un buzzer pour fournir une alerte sonore lorsque des températures élevées sont détectées.
- Ajouter un écran pour afficher les relevés de température en temps réel.
- Calibrer le capteur de flamme pour des cas d'utilisation spécifiques ou des environnements particuliers.
