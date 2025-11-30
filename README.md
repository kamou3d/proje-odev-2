# Karakter Tabanlı Hayatta Kalma Simülatörü (C Language)

Bu proje, Algoritma ve Programlama dersi kapsamında C dili ile geliştirilmiş, komut satırı üzerinden çalışan metin tabanlı bir hayatta kalma oyunudur.

## 🎥 Proje Oynanış Videosu
Aşağıdaki videoda projenin teknik çalışma mantığı, komutların işleyişi (A, S, F, P vb.) ve durum yönetimi simülasyonu detaylıca gösterilmektedir.

[Videoyu indirmek veya izlemek için tıklayınız](kucuk_video.mp4)

> **Not:** Video yüklenemezse veya açılmazsa lütfen dosyalar arasındaki `.mp4` uzantılı dosyayı indirip izleyiniz.

---

## 🎯 Proje Amacı
Kullanıcının sağlık, enerji ve yemek durumunu yöneterek hayatta kalmaya çalıştığı bu simülasyon; C programlama dilindeki döngüler, karar yapıları ve operatörlerin pratik kullanımını göstermek amacıyla geliştirilmiştir.

## 🚀 Özellikler
* **Dinamik Durum Takibi:** Sağlık, enerji ve envanter (yemek, sığınak) değişkenleri her komutta güncellenir.
* **Şans Faktörü:** Avlanma ve sığınak arama eylemleri rastgele sonuçlar üretir.
* **Tehlike Dalgası (`For` Döngüsü):** Oyuncu 'F' komutuyla belirli sayıda saldırı dalgasına maruz kalır; sığınak ve enerji durumuna göre hasar alır veya kaçar.
* **Şifreli Kilit Sistemi (`Do-While`):** Oyuncu, kilitli bir sandığı açmak için doğru şifreyi bulana kadar döngüde tutulur (Input Validation).

## 🎮 Komut Listesi

| Komut | İşlev | Açıklama |
| :---: | :--- | :--- |
| **A** | Avlan | Enerji harcar. Şansa bağlı yemek kazandırır veya sağlık kaybettirir. |
| **S** | Sığınak Ara | Enerji harcar (Min 15). Başarılı olursa sığınak koruması sağlar. |
| **R** | Dinlen | Enerji ve sağlık yeniler. Sığınak varsa etkisi artar. |
| **E** | Envanter | Mevcut sağlık, enerji ve yemek durumunu gösterir. |
| **F** | Tehlike Dalgası | 3 aşamalı bir fırtına/saldırı simülasyonu başlatır (For Döngüsü). |
| **P** | Şifre Çöz | Kilitli sandığı açmak için şifre doğrulama ekranına girer (Do-While). |
| **X** | Çıkış | Simülasyonu sonlandırır. |

## 🛠️ Kurulum ve Çalıştırma

Bu projeyi bilgisayarınızda çalıştırmak için bir C derleyicisine (GCC gibi) ihtiyacınız vardır.

1.  Terminali açın ve dosyanın bulunduğu dizine gidin.
2.  Aşağıdaki komutla derleyin:
    ```bash
    gcc main.c -o survival
    ```
3.  Çalıştırın:
    * **Linux/Mac:** `./survival`
    * **Windows:** `survival.exe`

## 📝 Teknik Detaylar
Kod içerisinde `Switch-Case` yapısı menü yönetimi için, `Do-While` oyunun ana döngüsü ve şifre kontrolü için, `For` döngüsü ise sıralı olaylar (tehlike dalgası) için kullanılmıştır. Ayrıca oyuncunun durumuna göre sonuç üretmek için mantıksal operatörlerden faydalanılmıştır.

---
**Geliştirici:** Samet Artan

**Ders:** Algoritma ve Programlama
