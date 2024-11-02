# Simulation Capteur Ultrason

## Description
Ce dossier contient les fichiers et instructions pour la simulation du capteur ultrasonique (HC-SR04) utilisé dans le projet FIREGUARD. Le capteur ultrasonique est employé pour la détection d'obstacles et la navigation autonome du robot de secours incendie.

## Schéma de Montage
Le montage du capteur ultrasonique inclut les connexions suivantes :
- **VCC** : Connecté à l'alimentation 5V.
- **GND** : Connecté à la terre (GND).
- **Trig** : Connecté à la broche numérique D9 du microcontrôleur.
- **Echo** : Connecté à la broche numérique D10 du microcontrôleur.
- **Buzzer** :
  - Terminal positif -> Broche numérique 8 de l'Arduino.
  - Terminal négatif -> GND de l'Arduino.

## Fichiers Inclus
- **lien_tinkercad_capteur_ultrason** : Lien vers la simulation Tinkercad pour visualiser le montage.
- **.gitkeep** : Fichier pour maintenir la structure du dossier.
- **readme.md** : Ce fichier expliquant le fonctionnement du montage.
- **Rendu final.png** : Image du rendu final du montage.
- **Schéma de montage complet.png** : Schéma détaillé du montage du capteur ultrason.

## Fonctionnement
1. **Activation du Capteur** : Le capteur envoie une impulsion ultrasonique via la broche `Trig`.
2. **Réception de l'Écho** : La broche `Echo` reçoit l'impulsion réfléchie par un obstacle.
3. **Calcul de la Distance** : Le microcontrôleur mesure le temps entre l'émission et la réception de l'impulsion pour calculer la distance de l'obstacle.
4. **Alerte Sonore** : Le buzzer émet un signal sonore en fonction de la distance mesurée.( ici lorsque l'osbtacle est à 10 cm )   

## Simulation Tinkercad

Pour virsualiser et tester le monatge du capteur ultrasonique

[Accéder à la simulation Tinkercad](https://www.tinkercad.com/things/6G6PAu9rwcS/editel?lessonid=EFU6PEHIXGFUR1J&projectid=OGK4Q7VL20FZRV9&collectionid=undefined&title=Editing%20Components&sharecode=xIN4BPeDCIxUulXke1eNfRdvjO6b3aZkX0cRPFSjgQo
)

---