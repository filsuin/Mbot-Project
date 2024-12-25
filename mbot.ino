#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

// Configuration réseau
const char* ssid = "ESP-Robot"; // Nom du réseau Wi-Fi
const char* password = "";      // Pas de mot de passe (réseau ouvert)

// Définition des broches
#define IN1 D1 // GPIO5
#define IN2 D2 // GPIO4
#define IN3 D5 // GPIO14
#define IN4 D6 // GPIO12

// Serveur Web Asynchrone
AsyncWebServer server(80);

void setup() {
  // Configuration des broches
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Arrêter les moteurs au démarrage
  stopMotors();

  // Démarrer le Wi-Fi en mode point d'accès
  WiFi.softAP(ssid, password);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Point d'accès Wi-Fi créé");
  Serial.println("Adresse IP : " + WiFi.softAPIP().toString());

  // Page Web principale
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", getHTMLPage());
  });

  // Commandes pour les moteurs
  server.on("/forward", HTTP_GET, [](AsyncWebServerRequest *request) {
    moveForward();
    request->send(200, "text/plain", "Avancer");
  });
  server.on("/backward", HTTP_GET, [](AsyncWebServerRequest *request) {
    moveBackward();
    request->send(200, "text/plain", "Reculer");
  });
  server.on("/left", HTTP_GET, [](AsyncWebServerRequest *request) {
    turnLeft();
    request->send(200, "text/plain", "Tourner à gauche");
  });
  server.on("/right", HTTP_GET, [](AsyncWebServerRequest *request) {
    turnRight();
    request->send(200, "text/plain", "Tourner à droite");
  });
  server.on("/stop", HTTP_GET, [](AsyncWebServerRequest *request) {
    stopMotors();
    request->send(200, "text/plain", "Arrêt");
  });

  // Démarrer le serveur
  server.begin();
}

// Fonctions pour contrôler les moteurs
void moveForward() {
    Serial.println("Moteurs : Avancer");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}


void moveBackward() {
  Serial.println("Moteurs : Reculer");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  Serial.println("Moteurs : Gauche");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  Serial.println("Moteurs : Droite");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  Serial.println("Moteurs : Stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Fonction pour générer la page HTML
String getHTMLPage() {
  return R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Robot Control</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background: linear-gradient(to bottom, #0d47a1, #1976d2);
      color: white;
      text-align: center;
      margin: 0;
      padding: 0;
    }

    h1 {
      margin-top: 20px;
      font-size: 2.5em;
    }

    .control-panel {
      display: grid;
      grid-template-columns: 1fr 1fr 1fr;
      gap: 15px;
      max-width: 400px;
      margin: 50px auto;
    }

    .control-button {
      padding: 15px;
      border: none;
      border-radius: 8px;
      background: #29b6f6;
      color: white;
      font-size: 1.2em;
      font-weight: bold;
      cursor: pointer;
      box-shadow: 0 4px 6px rgba(0, 0, 0, 0.3);
      transition: background 0.3s, transform 0.2s;
    }

    .control-button:active {
      transform: scale(0.95);
    }

    .control-button:hover {
      background: #0288d1;
    }

    .control-panel .blank {
      visibility: hidden;
    }

    footer {
      margin-top: 50px;
      font-size: 0.9em;
      color: #bbdefb;
    }

    footer a {
      color: #ffffff;
      text-decoration: none;
      font-weight: bold;
    }

    footer a:hover {
      text-decoration: underline;
    }
  </style>
</head>
<body>
  <h1>Contrôle du Robot ESP8266</h1>
  <div class="control-panel">
    <button class="control-button blank"></button>
    <button class="control-button" onclick="sendCommand('forward')">Avancer</button>
    <button class="control-button blank"></button>
    <button class="control-button" onclick="sendCommand('left')">Gauche</button>
    <button class="control-button" onclick="sendCommand('stop')">Stop</button>
    <button class="control-button" onclick="sendCommand('right')">Droite</button>
    <button class="control-button blank"></button>
    <button class="control-button" onclick="sendCommand('backward')">Reculer</button>
    <button class="control-button blank"></button>
  </div>
   <script>
    function sendCommand(command) {
      fetch(`/${command}`)
        .then(response => {
          if (!response.ok) {
            alert("Erreur : commande non envoyée !");
          }
        })
        .catch(() => alert("Erreur de connexion au robot."));
    }
  </script>
</body>
</html>
)rawliteral";
}

void loop() {
  // Rien à faire ici, tout est géré par le serveur web.
}
