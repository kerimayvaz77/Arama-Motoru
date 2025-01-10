# 🔍 Kelime Arama Motoru

Bu proje, metin dosyaları içinde kelime araması yapabilen gelişmiş bir arama motorudur. Hem Windows hem de MacOS işletim sistemlerinde çalışabilir.

## ✨ Özellikler

- 📝 Tam eşleşme araması
- 🎯 Yakın eşleşme bulma
- 🌟 Büyük/küçük harf duyarsız arama
- 🖥️ Çoklu işletim sistemi desteği (Windows & MacOS)
- 🎨 Windows'ta renkli konsol arayüzü
- 🔤 Türkçe karakter desteği

## 🚀 Nasıl Çalışır?

Program üç farklı eşleşme türü sunar:

1. **Tam Eşleşme**: Aranan kelime ile birebir aynı olan sonuçları gösterir
2. **Yakın Eşleşme**: Aranan kelimeye çok benzeyen kelimeleri bulur
3. **Uzak Eşleşme**: Aranan kelime ile benzerlik gösteren diğer kelimeleri listeler

## 💻 Kurulum

### Gereksinimler
- C++ derleyici (GCC veya MSVC)
- Metin editörü

### Derleme
Windows için:
```bash
g++ "ARAMA MOTORU.cpp" -o arama_motoru
```

MacOS için:
```bash
g++ "ARAMA MOTORU.cpp" -o arama_motoru
```

## 🎮 Kullanım

1. Programı çalıştırın
2. Aranacak kelimeyi girin
3. Program otomatik olarak sonuçları `SONUC.txt` dosyasında gösterecektir

## 📋 Örnek Çıktılar

### Tam Eşleşme Bulunduğunda:
```
|************----Tam Eslesme----************|
-----------------book-----------------
```

### Benzer Kelimeler Bulunduğunda:
```
(---- BUNU'MU DEMEK ISTEDINIZ? ----)
---- books ----
---- booking ----
```

## 🔄 Son Güncellemeler

- ✅ MacOS desteği eklendi
- ✅ Türkçe karakter sorunları giderildi
- ✅ Dosya okuma işlemleri iyileştirildi
- ✅ Arama algoritması optimize edildi

## 🛠️ Teknik Detaylar

- Rabin-Karp algoritması tabanlı arama
- Dosya işlemleri için standart C++ kütüphaneleri
- Platform bağımsız kod yapısı
- Akıllı bellek yönetimi

## ⚠️ Notlar

- Program şu anda sadece `kelimeler1.txt` dosyasında arama yapar
- Binary dosyalarda (PDF, DOCX, HTML) arama desteği kaldırıldı
- Sonuçlar her zaman `SONUC.txt` dosyasına yazılır

## 🤝 Katkıda Bulunma

1. Bu depoyu fork edin
2. Yeni bir branch oluşturun (`git checkout -b yeni-ozellik`)
3. Değişikliklerinizi commit edin (`git commit -am 'Yeni özellik eklendi'`)
4. Branch'inizi push edin (`git push origin yeni-ozellik`)
5. Pull Request oluşturun
