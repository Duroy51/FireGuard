# Moteur à courant continu

## Schéma de Montage
Le montage comporte les éléments suivants :

- **Alimentation des drivers moteur** : Connectée à une source de 12V (ou adaptée aux spécifications des moteurs).
- **Drivers moteur L298N** :
  
  - **Premier driver** (contrôle des moteurs gauche) :
    - **ENA** : Broche `3` (PWM pour contrôler la vitesse).
    - **IN1** : Broche `2`.
    - **IN2** : Broche `4`.
    - **ENB** : Broche `6` (PWM pour contrôler la vitesse).
    - **IN3** : Broche `7`.
    - **IN4** : Broche `8`.
  
  - **Deuxième driver** (contrôle des moteurs droit) :
    - **ENA** : Broche `5` (PWM pour contrôler la vitesse).
    - **IN1** : Broche `12`.
    - **IN2** : Broche `13`.
    - **ENB** : Broche `9` (PWM pour contrôler la vitesse).
    - **IN3** : Broche `10`.
    - **IN4** : Broche `11`.

## Fonctionnement
Les quatre moteurs sont contrôlés via deux drivers L298N, chacun contrôlant les moteurs de chaque côté du robot (gauche et droit).

## Simulation Tinkercad
Pour visualiser et tester le montage complet du robot avec capteur ultrason et drivers moteurs :

[Accéder à la simulation Tinkercad](https://www.tinkercad.com/things/6G6PAu9rwcS/editel?lessonid=EFU6PEHIXGFUR1J&projectid=OGK4Q7VL20FZRV9&collectionid=undefined&title=Editing%20Components&sharecode=xIN4BPeDCIxUulXke1eNfRdvjO6b3aZkX0cRPFSjgQo)

---

