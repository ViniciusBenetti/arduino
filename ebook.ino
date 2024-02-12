#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <time.h>

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

char ssid[] = "secret";
char password[] = "secret";

void setup() {
  lcd.init();
  lcd.backlight();
  WiFi.begin(ssid, password);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Configuração do tempo usando NTP
  configTime(0, 0, "pool.ntp.org");
}


void loop() {
  frase_do_dia();
  delay(30);
}



void frase_do_dia() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Falha ao obter a hora");
    return;
  }

  // Formata a data de acordo com o padrão esperado na URL
  char formattedDate[20];
  strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", &timeinfo);

  // Constrói a URL usando a data formatada
  String url = "https://www.ihbristol.com/english-phrases/" + String(formattedDate);

  // Fazer uma solicitação HTTP
  HTTPClient http;
  http.begin(url);

  int httpCode = http.GET();

  // Verificar se a solicitação foi bem-sucedida
  if (httpCode > 0) {
    String html = http.getString();
    // Encontrar a posição inicial e final da frase desejada
    int startPos = html.indexOf("<div class=\"field-item even\" property=\"dc:title\"><h2>") + 48;
    int endPos = html.indexOf("</h2></div>", startPos + 5);

    // Extrair a frase
    String frase = html.substring(startPos + 5, endPos);

    lcd.setCursor(0, 0);

    if (frase.length() <= 16) {
      lcd.print(frase);
    } else if (frase.length() <= 32) {
      lcd.print(frase.substring(0, 16));
      lcd.setCursor(0, 1);
      lcd.print(frase.substring(16));
    } else {
      lcd.print("Bom dia");
      delay(2000);
      lcd.clear();
    }
    delay(2000);

    Serial.println(frase);
  } else {
    Serial.println("erro http");
  }

  http.end();
}
