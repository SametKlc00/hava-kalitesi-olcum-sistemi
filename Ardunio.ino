#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

/* OLED AYARLARI */
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/* DHT22 */
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

/* MQ-2 */
#define MQ2_PIN A0

/* KART & ZAMAN */
int kart = 0;
unsigned long oncekiZaman = 0;
int anim = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 25);
  display.println("Sistem Basladi");
  display.display();
  delay(2000);
}

void loop() {
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();
  int gaz = analogRead(MQ2_PIN);

  /* Kart degistirme */
  if (millis() - oncekiZaman > 3000) {
    oncekiZaman = millis();
    kart++;
    anim = 0;
    if (kart > 3) kart = 0;
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  /* KART 1 - SICAKLIK */
  if (kart == 0) {
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("Sicaklik");
    display.setCursor(0, 30);
    display.print(sicaklik);
    display.print(" C");

    // animasyon
    display.drawCircle(110, 32, 5 + anim % 4, WHITE);
  }

  /* KART 2 - NEM */
  if (kart == 1) {
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("Nem");
    display.setCursor(0, 30);
    display.print(nem);
    display.print(" %");

    // damla animasyonu
    display.fillCircle(110, 25 + anim % 6, 4, WHITE);
  }

  /* KART 3 - GAZ */
  if (kart == 2) {
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("Gaz");
    display.setCursor(0, 30);
    display.print(gaz);

    // bar animasyonu
    display.fillRect(0, 55, map(gaz, 0, 1023, 0, 128), 6, WHITE);
  }

  /* KART 4 - SAGLIK BILGI */
  if (kart == 3) {
    display.setTextSize(1);
    display.setCursor(0, 0);

    if (gaz <= 300) {
      display.println("TEMIZ HAVA");
      display.println("Normal solunum");
      display.println("Saglik riski yok");
      display.println();
      display.println("Guvenli ortam");

      // gülümseme
      display.drawCircle(110, 20, 8, WHITE);
      display.drawPixel(107,18,WHITE);
      display.drawPixel(113,18,WHITE);
      display.drawLine(107,23,113,23,WHITE);
    }
    else if (gaz <= 700) {
      display.println("ORTA SEVIYE");
      display.println("Alerjik rinit");
      display.println("Hafif astim");
      display.println("Bogaz tahrisi");

      // uyarı animasyonu
      display.drawTriangle(105,35,120,35,112,20,WHITE);
      display.fillCircle(112,30,1,WHITE);
    }
    else {
      display.println("KIRLI HAVA");
      display.println("Astim krizi");
      display.println("Bronşit");
      display.println("KOAH riski");
      display.println("Maske onerilir");

      // çarpı animasyonu
      display.drawLine(104,18,120,34,WHITE);
      display.drawLine(120,18,104,34,WHITE);
    }
  }

  display.display();
  anim++;
  delay(150);
}
