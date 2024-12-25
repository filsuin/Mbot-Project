# Projet Mbot

Ce projet permet de contrôler un robot ESP8266 via une interface web. Le robot peut avancer, reculer, tourner à gauche, tourner à droite et s'arrêter.

## Matériel requis

- ESP8266
- Moteurs connectés aux broches GPIO de l'ESP8266

## Configuration des broches

Les broches GPIO utilisées pour contrôler les moteurs sont définies comme suit :

- IN1 : D1 (GPIO5)
- IN2 : D2 (GPIO4)
- IN3 : D5 (GPIO14)
- IN4 : D6 (GPIO12)

## Installation

1. Clonez ce dépôt ou téléchargez les fichiers.
2. Ouvrez le fichier `mbot.ino` dans l'IDE Arduino.
3. Assurez-vous d'avoir les bibliothèques suivantes installées :
   - ESP8266WiFi
   - ESPAsyncWebServer
4. Connectez votre ESP8266 à votre ordinateur.
5. Téléversez le code sur votre ESP8266.

## Utilisation

1. Une fois le code téléversé, l'ESP8266 créera un point d'accès Wi-Fi avec le SSID `ESP-Robot`.
2. Connectez-vous à ce réseau Wi-Fi (aucun mot de passe requis).
3. Ouvrez un navigateur web et accédez à l'adresse IP affichée dans le moniteur série (généralement `192.168.4.1`).
4. Utilisez l'interface web pour contrôler le robot.

## Commandes disponibles

- **Avancer** : Le robot avance.
- **Reculer** : Le robot recule.
- **Gauche** : Le robot tourne à gauche.
- **Droite** : Le robot tourne à droite.
- **Stop** : Le robot s'arrête.
