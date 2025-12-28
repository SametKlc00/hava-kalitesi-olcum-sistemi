# Hava Kalitesi Ölçüm Sistemi (Arduino Tabanlı)

Bu proje, düşük maliyetli sensörler kullanılarak ortamın **sıcaklık**, **nem** ve **hava kalitesi (gaz seviyesi)** değerlerini ölçen ve bu verileri **OLED ekran** üzerinde kullanıcıya sunan bir hava kalitesi izleme sistemidir.  
Ayrıca ölçülen hava kalitesine göre **sağlık bilgilendirme kartları** gösterilmektedir.

## Proje Amacı
- Ortam sıcaklık ve nem değerlerini gerçek zamanlı ölçmek  
- Gaz sensörü ile hava kalitesini izlemek  
- Ölçümleri OLED ekran üzerinde görselleştirmek  
- Hava kalitesine bağlı olası solunum yolu riskleri hakkında kullanıcıyı bilgilendirmek  
- Düşük maliyetli ve taşınabilir bir sistem geliştirmek  

## Kullanılan Donanımlar
- Arduino Uno  
- DHT22 Sıcaklık ve Nem Sensörü  
- MQ-2 Gaz Sensörü (Modül)  
- 0.96” OLED Ekran (SSD1306, I2C)  
- Breadboard  
- Jumper kablolar  

## Kullanılan Kütüphaneler
- `Wire.h`  
- `Adafruit_GFX.h`  
- `Adafruit_SSD1306.h`  
- `DHT.h`  

## Sistem Özellikleri
- Sıcaklık ölçümü (°C)  
- Nem ölçümü (%)  
- Gaz seviyesi ölçümü (analog değer)  
- OLED ekranda kart sistemi ile bilgi gösterimi  
- Sağlık bilgilendirme kartları:
  - **Temiz Hava**
  - **Orta Seviye**
  - **Kirli Hava**
- Basit animasyonlar ve görsel göstergeler  

## Sağlık Bilgilendirme Seviyeleri
- **Temiz Hava:** Normal solunum, sağlık riski yok  
- **Orta Seviye:** Alerjik rinit, hafif astım tetiklenmesi, boğaz tahrişi  
- **Kirli Hava:** Astım krizi, bronşit, KOAH riski, maske önerisi  

## Çalışma Prensibi
Sistem belirli aralıklarla sensörlerden veri okur.  
OLED ekranda:
1. Sıcaklık  
2. Nem  
3. Gaz seviyesi  
4. Sağlık bilgilendirme kartı  

olacak şekilde döngüsel olarak gösterim yapılır.

## Kurulum
1. Arduino IDE’yi kurun  
2. Gerekli kütüphaneleri Arduino IDE üzerinden yükleyin  
3. Donanım bağlantılarını yapın  
4. Kodu Arduino’ya yükleyin  

## Geliştirme Önerileri
- Bluetooth veya WiFi modülü eklenerek mobil/web arayüz desteği  
- Gaz sensörü kalibrasyonu  
- Uzun süreli veri kaydı  
- Ortalama gaz değeri ve grafiksel gösterim  

## Proje Sahibi
**Samet Kılıç**

Bu proje TÜBİTAK 2209-A kapsamındaki proje önerisi doğrultusunda geliştirilmiştir.
