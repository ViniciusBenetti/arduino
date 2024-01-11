
#define BLYNK_TEMPLATE_ID "TMPL2XwXeDFSl"
#define BLYNK_TEMPLATE_NAME "MinhaPlanta"
#define BLYNK_AUTH_TOKEN "fHXqODOatDDc717b1HILWMg-K6TIioZ7"
#define BYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "FAMILIABENETTI_2G";
char pass[] = "Gabi120500";

const int pino = 35;
const int limiteSuperior = 3500;
const int tempoEspera = 2000;
int contador = 0;

String estadoAnterior = "";
String Estado = "";

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(pino, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void enviarNotificacao(String evento, String mensagem) {
  Estado = mensagem;
  if (Estado != "" && Estado != estadoAnterior) {
    Blynk.logEvent(evento, Estado);
    estadoAnterior = Estado;
  }
}

void loop() {
  int leitura = analogRead(pino);

  if (leitura > limiteSuperior) {
    enviarNotificacao("precisa_agua", "Rapaz, preciso de água");
  } else {
    enviarNotificacao("muita_agua", "Acabei de receber a água que preciso, Obrigada!");
  }

  Serial.println(leitura);
  if(contador >= 7200 || contador == 0){
    Blynk.logEvent("contador","umidade atual "+String(leitura));
    contador = 1;
  }
  delay(tempoEspera);
  contador+=2;
  Blynk.run();


}
