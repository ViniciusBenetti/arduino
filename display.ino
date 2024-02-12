#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <time.h>
#include <TimeLib.h>


int lcdColumns = 16;
int numeros = 0;
int lcdRows = 2;
int estadoBotaoAnterior = HIGH;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
const int botaoPin = 18;
char ssid[] = "secret";
char password[] = "secret";
String GOOGLE_SCRIPT_ID =
"secret";
const String frasesDoDia[] = {
  "Ame a vida.",
  "Seja gentil.",
  "Persista!",
  "Aprenda sempre.",
  "Espalhe amor.",
  "Sorria muito.",
  "Faca o bem.",
  "Seja grato.",
  "Viva feliz.",
  "Aja com fe.",
  "Sonhe alto.",
  "Celebre hoje.",
  "Desperte alegria.",
  "Viva intensamente.",
  "Supere desafios.",
  "Cultive otimismo.",
  "Brilhe como o sol.",
  "Acredite em você.",
  "Enfrente medos.",
  "Inspire confiança.",
  "Mantenha a calma.",
  "Semeie bondade.",
  "Colha gratidao.",
  "Seja luz.",
  "Voe alto.",
  "Escolha a paz.",
  "Abrace a felicidade.",
  "Valorize cada instante.",
  "Pratique a gratidao.",
  "Conquiste seus sonhos.",
  "Viva com propósito.",
  "Seja resiliente.",
  "Crie oportunidades.",
  "Cultive amizades.",
  "Aprenda com a vida.",
  "Agradeça sempre.",
  "Abrace o novo.",
  "Respire fundo.",
  "Aprecie a jornada.",
  "Cultive a serenidade.",
  "Abrace desafios.",
  "Ame incondicionalmente.",
  "Faça a diferença.",
  "Dance na chuva.",
  "Valorize o presente.",
  "Busque o equilíbrio.",
  "Acredite em seus sonhos.",
  "Cultive a alegria.",
  "Desperte seu potencial.",
  "Viva com autenticidade.",
  "Transforme desafios em oportunidades.",
  "Abra seu coracao.",
  "Aprecie as pequenas coisas.",
  "Seja a mudanca.",
  "Construa pontes.",
  "Respeite a natureza.",
  "Mantenha a mente aberta.",
  "Comemore conquistas.",
  "Pratique o desapego.",
  "Abra as asas.",
  "Abrace a simplicidade.",
  "Explore o desconhecido.",
  "Celebre a vida.",
  "Cultive a compaixao.",
  "Seja humilde.",
  "Inspire-se na natureza.",
  "Viva com amor.",
  "Valorize sua jornada.",
  "Aprenda com os erros.",
  "Cultive boas energias.",
  "Ame sem medidas.",
  "Desperte seu potencial.",
  "Abrace o aprendizado.",
  "Celebre suas conquistas.",
  "Acredite na magia.",
  "Deixe sua luz brilhar.",
  "Cultive a paciencia.",
  "Viva com coragem.",
  "Descubra sua forca.",
  "Seja autentico.",
  "Ame a si mesmo.",
  "Dedique tempo ao descanso.",
  "Mantenha a fe.",
  "Pratique a generosidade.",
  "Aprenda com a sabedoria.",
  "Valorize sua essencia.",
  "Desperte sua criatividade.",
  "Abrace a positividade.",
  "Crie momentos especiais.",
  "Siga seu coracao.",
  "Celebre cada dia.",
  "Viva em harmonia.",
  "Ame sem reservas.",
  "Cultive a gratidao.",
  "Desperte sua paixao.",
  "Acredite em seus talentos.",
  "Sorria para a vida.",
  "Abra portas.",
  "Valorize suas escolhas.",
  "Viva com plenitude.",
  "Cultive relacionamentos saudaveis.",
  "Seja a melhor versao de si mesmo.",
  "Abrace a jornada.",
  "Dance ao ritmo da vida.",
  "Viva o presente.",
  "Inspire confianca.",
  "Aprenda com a adversidade.",
  "Seja flexivel.",
  "Abrace a liberdade.",
  "Celebre sua autenticidade.",
  "Desperte seu entusiasmo.",
  "Viva com compaixao.",
  "Ame intensamente.",
  "Cultive a paz interior.",
  "Seja grato por tudo.",
  "Sorria para o mundo.",
  "Acredite em seu potencial.",
  "Viva com propósito.",
  "Abrace o amor.",
  "Celebre a diversidade.",
  "Cultive a honestidade.",
  "Ame a si mesmo.",
  "Desperte sua criatividade.",
  "Abrace a serenidade.",
  "Viva com paixao.",
  "Inspire o mundo.",
  "Aprenda com a experiencia.",
  "Seja resiliente.",
  "Cultive a gratidao.",
  "Ame a natureza.",
  "Desperte sua intuicao.",
  "Celebre a vida.",
  "Viva com leveza.",
  "Acredite em si mesmo.",
  "Sorria para a vida.",
  "Abrace a felicidade.",
  "Cultive a humildade.",
  "Seja grato por cada dia.",
  "Ame sem medidas.",
  "Desperte sua coragem.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
  "Abrace a felicidade.",
  "Cultive a gratidao.",
  "Desperte a criatividade.",
  "Celebre suas conquistas.",
  "Viva com autenticidade.",
  "Acredite em seus sonhos.",
  "Sorria para o futuro.",
  "Ame o presente.",
  "Desperte a alegria.",
  "Celebre o amor.",
  "Cultive a esperanca.",
  "Viva com compaixao.",
  "Abrace a generosidade.",
  "Ame a si mesmo.",
  "Desperte sua paixao.",
  "Celebre a vida.",
  "Viva com plenitude.",
  "Acredite em seu potencial.",
  "Sorria para o mundo.",
};
void setup() {
lcd.init();
lcd.backlight();
pinMode(botaoPin, INPUT_PULLUP);
lcd.print("conectando wifi...");
WiFi.begin(ssid, password);
int wifi_ctr = 0;
delay(5000);
lcd.clear();
while (WiFi.status() != WL_CONNECTED)
{
lcd.setCursor(0,0);
lcd.print("erro wifi");
lcd.setCursor(0,1);
lcd.print("reconectando...");
delay(5000);
lcd.clear();
}
lcd.setCursor(0,0);
lcd.print("ajustando tempo");
configTime(0, 0, "pool.ntp.org");
delay(2000);
lcd.clear();
lcd.print("mude com botao");
}
void loop() {
    int estadoBotao = digitalRead(botaoPin);

    if (estadoBotao == LOW && estadoBotaoAnterior == HIGH) {
        lcd.clear();
        delay(500);
        numeros++;
        if (numeros == 5) {
            numeros = 1;
        }
    }

    estadoBotaoAnterior = estadoBotao;

    if(numeros == 1){
      frase_do_dia();
    }
    if(numeros == 2){
      rotina();
    }
    if(numeros == 3){
      spreadsheet_comm();
    }
    if(numeros == 4){
      meteorologia();
    }
   
    delay(23);

}

void spreadsheet_comm() {
    HTTPClient https;

    String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?read";
    https.begin(url.c_str());
    https.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    
    int httpCode = https.GET();

    if (httpCode > 0) {
        String payload = https.getString();
        Serial.println(payload);

        String payload1 = payload.substring(0, 15);
        String payload2 = payload.substring(16, 24);

        String meses[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        String mesString = payload.substring(4, 7);
        int mesInt = 0;
        
        for (int i = 0; i < 12; i++) {
            if (mesString == meses[i]) {
                mesInt = i + 1;
                break;
            }
        }

        String formatted = payload1.substring(8, 10) + '/' + String(mesInt) + '/' + payload1.substring(11, 15);

        lcd.setCursor(0, 0);
        lcd.print(formatted);
        lcd.setCursor(0, 1);
        lcd.print(payload2 + " Venda");
        delay(23);
    } else {
        lcd.setCursor(0, 0);
        lcd.print("erro HTTP");
        lcd.clear();
        delay(23);
    }

    https.end();
}

void frase_do_dia() {
  time_t now = time(nullptr);
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);

  int dias = (timeinfo.tm_mon + 1) * 30 + timeinfo.tm_mday;

  int indice = dias % (sizeof(frasesDoDia) / sizeof(frasesDoDia[0]));
  lcd.setCursor(0, 0);

  String frase = frasesDoDia[indice];
    if (frase.length() <= 16) {
      lcd.print(frase);
    } else if (frase.length() <= 32) {
      lcd.print(frase.substring(0, 16));
      lcd.setCursor(0, 1);
      lcd.print(frase.substring(16));
    } else {
      lcd.print("bom dia");
    }
    
    delay(23);
  } 
void rotina() {
    time_t now = time(nullptr);
    struct tm timeinfo;
    gmtime_r(&now, &timeinfo);

    if (timeinfo.tm_hour >= 3) {
        timeinfo.tm_hour -= 3;
    } else {
        timeinfo.tm_hour = 24 + timeinfo.tm_hour - 3;
    }

    char data[11];
    strftime(data, sizeof(data), "%d/%m/%Y", &timeinfo);

    char horario[9];
    strftime(horario, sizeof(horario), "%H:%M:%S", &timeinfo);

    lcd.setCursor(0,0);
    lcd.print("Meta diária:");

    int hora = timeinfo.tm_hour;
    int minuto = timeinfo.tm_min;

    lcd.setCursor(0, 1);

    if (hora >= 6 && hora < 8) {
        lcd.print("Tomar café");
    } else if (hora >= 8 && hora < 9) {
        lcd.print("Ir à academia");
    } else if (hora >= 9 && hora < 12) {
        lcd.print("Programar");
    } else if (hora >= 12 && hora < 14) {
        lcd.print("Descanso");
    } else if (hora >= 14 && hora < 17) {
        lcd.print("Faculdade");
    } else if (hora >= 17 && hora < 23) {
        lcd.print("Livre");
    } else {
        lcd.print("Fora do horário");
    }

    delay(23);
}


void meteorologia(){

  String url = "https://www.climatempo.com.br/previsao-do-tempo/agora/cidade/384/aracaju-se";

  HTTPClient http;
  http.begin(url);

  int httpCode = http.GET();
  if (httpCode > 0) {
    String html = http.getString();
    int startPos = html.indexOf("<span class=\"-bold -gray-dark-2 -font-55 _margin-l-20 _center\">");
    int endPos = html.indexOf("</span>", startPos);

if (startPos != -1 && endPos != -1) {
    startPos += strlen("<span class=\"-bold -gray-dark-2 -font-55 _margin-l-20 _center\">") + 1;
    endPos = startPos + 2; 

    String frase = html.substring(startPos, endPos);

    lcd.setCursor(0, 0);
    lcd.print(frase);
    lcd.write(223);
    lcd.print('C');
  

} else {
    lcd.setCursor(0,0);
    lcd.print("erro tag");
    lcd.clear();
    delay(23);
}
    
  }else{
    lcd.setCursor(0,0);
    lcd.print("erro em req");
    lcd.clear();
    delay(23);

  }
  http.end();
}
