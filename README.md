# TP_Automatique  

__Matériels à disposition__  
- Carte Nucleo-STM32G474RE
- Hacheur 
- MCC

## Github et Doxygen
Sur __la master__ se trouve le projet CubeIDE.  
Le dossier __html__ dans Cube IDE contient la documentation Doxygen  

### Prise en main de la Nucléo
Découverte du matériel, du PCB et de la Nucléo à notre disposition. Analyse du PCB et des différentes connexions établis entre la nucléo, le PCB et les divers composants.  

### Configuration des pins sur CubeIDE 
Configuration du projet CubeIDE avec l'ensemble des connexions necessaire au TP.  

![alt text](https://github.com/KOEHL-HAVRET-TP/TP_Automatique/blob/fcc6e490f1d8087805aa1f0a3249d28175753caa/Images/image_pin_cubeIDE.JPG)

### Console UART - Création du Shell
Reprise du code de Mr Papazoglou pour la création du Shell et rajout des fonctions const uint8_t powerOn[] et const uint8_t powerOff[] qui ne contiennent pour le moment qu'un message.  
Le Shell s'ouvre correctement et envoie les bons message à l'appel de "cmdNotFound", "help", "pinout", "powerOn" et "powerOff".  
LE shell a été configuré à l'aide de liason UART. (USART2_RX et USART2_TX sur le .ioc de CubeIDE).  

## TP1  : Commande MCC Basique
### PWM  
#### Configuration Timer
Configuration de 2 channel complémentaires de TIM1. TIM1CH1 et TIM1CH1N ainsi que TIM1CH2 et TIM1CH2N. (TIM1 sur le registre APB2) 
Calcul des valeurs de PSC (10) et ARR(1062). 
Le timer a été configuré avec :  
- Fréquence de la PWM : 16kHz
- Temps mort minimum : 2us
- Résolution minimum : 10bits
- Rapport cyclique à 60%

#### Observation à l'oscilloscope
Observation à l'oscilloscope des signaux PWM générés: 
  
![alt text](https://github.com/KOEHL-HAVRET-TP/TP_Automatique/blob/main/Images/deadTime_v2.png)

#### Mesures des temps morts  
Le DeadTime final rentré dans Cube IDE est de 23, pour une valeur "réelle" de 2.024 us (observée sur l'oscilloscope).  

### Prise en main du hacheur
A l'aide de la datasheet on repère les pins à connecter sur le hacheur.  
Nous utiliserons :
- les pins 12 et 30 pour faire la connection de la phase Jaune 
- les pins 13 et 31 pour faire la connection de la phase Rouge
- La pin 33 pour ISO_Reset (permettant le démarrage)

Les pins 12,13,30 et 31 seront réliés aux PWM.

### Commande Start
On configure l'allumage de la pin ISO_Reset à l'aide la commande start, la pin devra s'allumer et s'éteindre quelques secondes après.  

### Commande de vitesse

### Premier test

## TP2  : Mesure de Vitesse et de courant