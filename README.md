# Karakter Tabanlı Hayatta Kalma Simülasyonu (C Language)

Bu proje, Algoritma ve Programlama dersi kapsamında C dili ile geliştirilmiş, komut satırı üzerinden çalışan metin tabanlı bir hayatta kalma oyunudur.

## 🎯 Proje Amacı
Kullanıcının sağlık, enerji ve yemek durumunu yöneterek hayatta kalmaya çalıştığı bu simülasyon; C programlama dilindeki döngüler, karar yapıları ve operatörlerin pratik kullanımını göstermek amacıyla geliştirilmiştir.

## 🚀 Özellikler
* **Dinamik Durum Takibi:** Sağlık, enerji ve envanter (yemek, sığınak) değişkenleri her komutta güncellenir.
* **Şans Faktörü:** Avlanma ve sığınak arama eylemleri rastgele sonuçlar üretir (örn. yemek bulma veya yaralanma).
* **Tehlike Dalgası (`For` Döngüsü):** Oyuncu 'F' komutuyla belirli sayıda saldırı dalgasına maruz kalır.
* **Şifreli Kilit Sistemi (`Do-While`):** Oyuncu, kilitli bir sandığı açmak için doğru şifreyi bulana kadar döngüde tutulur.

## 🎮 Komut Listesi

| Komut | İşlev | Açıklama |
| :---: | :--- | :--- |
| **A** | Avlan | Enerji harcar. Şansa bağlı yemek kazandırır veya sağlık kaybettirir. |
| **S** | Sığınak Ara | Enerji harcar. Başarılı olursa dinlenirken daha çok can yenilenir. |
| **R** | Dinlen | Enerji ve sağlık yeniler. Sığınak varsa etkisi artar. |
| **E** | Envanter | Mevcut sağlık, enerji ve yemek durumunu gösterir. |
| **F** | Tehlike Dalgası | 3 aşamalı bir fırtına/saldırı simülasyonu başlatır. |
| **P** | Şifre Çöz | Kilitli sandığı açmak için şifre doğrulama ekranına girer. |
| **X** | Çıkış | Simülasyonu sonlandırır. |

## 🛠️ Kurulum ve Çalıştırma

Bu projeyi bilgisayarınızda çalıştırmak için bir C derleyicisine (GCC gibi) ihtiyacınız vardır.

1.  Projeyi klonlayın veya indirin.
2.  Terminali açın ve dosyanın bulunduğu dizine gidin.
3.  Aşağıdaki komutla derleyin:
    ```bash
    gcc main.c -o survival
    ```
4.  Çalıştırın:
    * **Linux/Mac:** `./survival`
    * **Windows:** `survival.exe`

## 📝 Teknik Detaylar
Kod içerisinde `Switch-Case` yapısı menü yönetimi için, `Do-While` oyunun ana döngüsü ve şifre kontrolü için, `For` döngüsü ise sıralı olaylar (tehlike dalgası) için kullanılmıştır.

---
**Geliştirici:** Samet Artan

**Ders:** Algoritma ve Programlama
