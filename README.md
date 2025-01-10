# 🔍 Kelime Arama Motoru

Bu proje, metin dosyaları içinde kelime araması yapabilen gelişmiş bir arama motorudur. Hem Windows hem de MacOS işletim sistemlerinde çalışabilir.

## ✨ Özellikler

- 📝 Tam eşleşme araması
- 🎯 Yakın eşleşme bulma
- 🌟 Büyük/küçük harf duyarsız arama
- 🖥️ Çoklu işletim sistemi desteği (Windows & MacOS)
- 🎨 Windows'ta renkli konsol arayüzü
- 🔤 Türkçe karakter desteği
- 📚 Çoklu dosya formatı desteği (TXT, DOCX, PDF, HTML)
- 🧹 Akıllı metin temizleme ve normalizasyon
- 🔄 Binary dosya okuma desteği

## 🚀 Nasıl Çalışır?

Program üç farklı eşleşme türü sunar:

1. **Tam Eşleşme**: Aranan kelime ile birebir aynı olan sonuçları gösterir
2. **Yakın Eşleşme**: Aranan kelimeye çok benzeyen kelimeleri bulur
3. **Uzak Eşleşme**: Aranan kelime ile benzerlik gösteren diğer kelimeleri listeler

## 💻 Kurulum

### Gereksinimler
- C++ derleyici (GCC veya MSVC)
- C++11 desteği
- Metin editörü
- Git

### Projeyi Bilgisayarınıza İndirme
```bash
# Projeyi klonlayın
git clone https://github.com/kerimayvaz77/Arama-Motoru.git

# Proje dizinine gidin
cd Arama-Motoru

# Örnek metin dosyalarını oluşturun (veya kendi dosyalarınızı ekleyin)
touch kelimeler1.txt kelimeler2.docx kelimeler3.pdf kelimeler4.html
```

### Derleme
Windows için:
```bash
g++ -std=c++11 "ARAMA MOTORU.cpp" -o arama_motoru
```

MacOS için:
```bash
g++ -std=c++11 "ARAMA MOTORU.cpp" -o arama_motoru
```

## 🎮 Kullanım

1. Programı derledikten sonra çalıştırın:
   ```bash
   # Windows için
   .\arama_motoru.exe

   # MacOS/Linux için
   ./arama_motoru
   ```

2. Aranacak kelimeyi girin
3. Program otomatik olarak sonuçları `SONUC.txt` dosyasında gösterecektir
4. Sonuçları görüntülemek için:
   ```bash
   # Windows için
   type SONUC.txt

   # MacOS/Linux için
   cat SONUC.txt
   ```

### 📝 Örnek Kullanım

```bash
# Projeyi klonlayın
git clone https://github.com/kerimayvaz77/Arama-Motoru.git

# Proje dizinine gidin
cd Arama-Motoru

# Programı derleyin
g++ -std=c++11 "ARAMA MOTORU.cpp" -o arama_motoru

# Programı çalıştırın
./arama_motoru

# Bir kelime arayın (örneğin: "kitap")
# Sonuçları görüntüleyin
cat SONUC.txt
```

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
- ✅ Çoklu dosya formatı desteği eklendi
- ✅ Binary dosya okuma desteği eklendi
- ✅ Akıllı metin temizleme sistemi geliştirildi
- ✅ Bellek yönetimi iyileştirildi

## 🛠️ Teknik Detaylar

- Rabin-Karp algoritması tabanlı arama
- Dosya işlemleri için standart C++ kütüphaneleri
- Platform bağımsız kod yapısı
- Akıllı bellek yönetimi
- Binary dosya işleme özellikleri:
  - Karakter temizleme ve normalizasyon
  - Akıllı metin çıkarma
  - Hata toleranslı okuma
- İşletim sistemi özel optimizasyonları:
  - Windows için özel konsol renklendirme
  - MacOS için native dosya açma desteği
  - Her platform için özel Türkçe karakter desteği

## 📦 Desteklenen Dosya Formatları

1. **TXT Dosyaları**
   - Tam metin desteği
   - UTF-8 kodlama
   - Satır satır okuma

2. **DOCX Dosyaları**
   - Binary okuma modu
   - Metin çıkarma
   - Karakter normalizasyonu

3. **PDF Dosyaları**
   - Binary okuma modu
   - Temel metin çıkarma
   - Karakter temizleme

4. **HTML Dosyaları**
   - Binary okuma modu
   - Tag temizleme
   - Metin normalizasyonu

## ⚠️ Notlar

- Her dosya formatı için optimize edilmiş okuma rutinleri
- Binary dosyalarda (PDF, DOCX, HTML) bazı karakterler düzgün okunamayabilir
- Sonuçlar her zaman `SONUC.txt` dosyasına yazılır
- Daha iyi sonuçlar için özel format kütüphaneleri eklenebilir

## 🤝 Katkıda Bulunma

1. Bu depoyu fork edin
2. Yeni bir branch oluşturun (`git checkout -b yeni-ozellik`)
3. Değişikliklerinizi commit edin (`git commit -am 'Yeni özellik eklendi'`)
4. Branch'inizi push edin (`git push origin yeni-ozellik`)
5. Pull Request oluşturun

## 🔜 Gelecek Özellikler

- [ ] DOCX için özel parser kütüphanesi entegrasyonu
- [ ] PDF için gelişmiş metin çıkarma
- [ ] HTML için tag analizi
- [ ] Daha fazla dosya formatı desteği
- [ ] Gelişmiş karakter kodlama desteği

## 📬 İletişim

Sorularınız, önerileriniz veya geri bildirimleriniz için:

- 📧 E-posta: kerimayva7@gmail.com
- 💻 GitHub: [kerimayvaz77](https://github.com/kerimayvaz77)

Projeyle ilgili her türlü görüş ve önerilerinizi bekliyorum!
