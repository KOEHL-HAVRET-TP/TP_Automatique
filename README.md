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

#### Calcul du Dead Time  
On veut DT = 2 us et on doit entrer 8 bits dans le registre du temps mort. 
D'après les fréquences du timer et de l'horloge, le calcul donne 340, ce qui est codé sur plus de 8 bits (max 255) en binaire.  
Les 2 MBS du registre du temps mort sont réservés. On calcule cette fois la valeur sur 6 bits et cette fois encore la valeur du registre dépasse le macimum sur 6 bits.  
On réserve les 3 MBS puis par le calcul, on obtient le nombre 10 qui tient sur 4 bits en binaire (1010). Ainsi, on place dans le registre du temps mort une valeur de 202 au minimum (1100 1010).  

Le timer a été configuré avec :  
- Fréquence de la PWM : 16kHz
- Temps mort minimum : 2us
- Résolution minimum : 10bits
- Rapport cyclique à 60%

#### Observation à l'oscilloscope
Observation à l'oscilloscope des signaux PWM complémentaires décalés générés avec un dead time supérieur à 2 us :
  
![alt text](https://github.com/KOEHL-HAVRET-TP/TP_Automatique/blob/main/Images/PWM_comp_decal.png)

#### Mesures des temps morts  
Le DeadTime final rentré dans Cube IDE est de 203, pour une valeur "réelle" de 2.024 us (observée sur l'oscilloscope).  

### Prise en main du hacheur
A l'aide de la datasheet on repère les pins à connecter sur le hacheur.  
Nous utiliserons :
- les pins 12 et 30 pour faire la connection de la phase Jaune 
- les pins 13 et 31 pour faire la connection de la phase Rouge
- La pin 33 pour ISO_Reset (permettant le démarrage)

Les pins 12,13,30 et 31 seront réliés aux PWM. CH1 et CH1N correspondent à la phase rouge et CH2 et CH2N à la phase jaune.  
On adopte ce schéma de branchement du hacheur à partir des observations faites à l'oscilloscope :  

![alt text](https://github.com/KOEHL-HAVRET-TP/TP_Automatique/blob/main/Images/Hacheur.JPG)

### Commande Start
On configure l'allumage de la pin ISO_Reset à l'aide la commande start, la pin devra s'allumer et s'éteindre quelques secondes après.  
L'appel de la commande "start" se fera par le biais de la console UART, le "shell" crée précédemment. 
Pour effectuer les tests de fonctionnement de la commande "start" et le bon allumage du GPIO, nous faisons les tests avec une diode présente sur la carte Nucléo. 

Observation à l'oscilloscope du passage à l'état haut de la pin ISO_Reset sur la voie 4 avant de repasser à 0 :  
  
![alt text](https://github.com/KOEHL-HAVRET-TP/TP_Automatique/blob/main/Images/Start.png)

### Commande de vitesse
On configure la lecture de speed=xxxx sur le shell. Dans un premier temps on vérifie que les 6 premiers caractères entrés dans la console sont "speed=". Par la suite on relève la valeur de la vitesse que l'on convertit en valeur numérique. 

La valeur de la vitesse est ensuite utilisée pour modifier, dans le code, les valeurs dans les 2 PWM afin de modifier la vitesse du moteur (modification du rapport cyclique).

### Premier test

Une fois l'ensemble des branchements effectués (Carte - Hacheur - MCC), on met en route le moteur avec le shell. La comande "start" permet le premier démarrage et par la suite on modifie la vitesse avec "speed=xxxx" pour lancer le moteur. On configure au préalable dans le code un rapport cyclique de 50%.  
Il faut augmenter le rapport cyclique de manière progressive de sorte à ce que le hacheur ne se mette pas en défaut. 

## TP2  : Mesure de Vitesse et de courant
