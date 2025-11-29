#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // toupper fonksiyonu için

int main() {
    // Rastgele sayı üretimi için seed (zaman tabanlı)
    srand(time(NULL));

    // Durum Değişkenleri [cite: 22]
    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0; // 0: Yok, 1: Var
    int i;
    char komut;

    printf("=== HAYATTA KALMA SIMULATORU ===\n");
    printf("Komutlar: [A]vlan, [S]iginak, [E]nvanter, [R]Dinlen, [F]Tehlike, [P]Sifre, [X]Cikis\n");

    // OYUN DONGUSU (Do-While) [cite: 7]
    do {
        printf("\nNe yapmak istiyorsun? > ");
        scanf(" %c", &komut);
        komut = toupper(komut); // Küçük harf girilirse büyüt

        // KOMUT SISTEMI (Switch-Case) 
        switch (komut) {
            case 'A': // Avlanma
                if (enerji >= 10) {
                    enerji -= 10; // Enerji maliyeti 
                    printf("Avlanmaya ciktin... (Enerji -10)\n");
                    
                    // Mantıksal operatörlerle şans hesabı 
                    int sans = rand() % 100;
                    if (sans < 40) { // %40 ihtimalle yemek bul
                        yemek++;
                        printf("Basarili! Bir tavsan yakaladin. (Yemek +1)\n");
                    } else if (sans > 80) { // %20 ihtimalle yaralan
                        saglik -= 15;
                        printf("Dikkat! Vahsi bir hayvan saldirdi. (Saglik -15)\n");
                    } else {
                        printf("Maalesef elin bos dondun.\n");
                    }
                } else {
                    printf("Avlanmak icin yeterli enerjin yok! Dinlenmelisin.\n");
                }
                break;

            case 'S': // Sığınak Arama
                if (siginak == 1) {
                    printf("Zaten bir siginagin var.\n");
                } else {
                    enerji -= 15;
                    // If-Else ile başarı kontrolü [cite: 14]
                    if ((rand() % 100) < 30) { 
                        siginak = 1;
                        printf("Guvenli bir magara buldun! Artik siginagin var.\n");
                    } else {
                        printf("Uygun bir yer bulamadim. Aramaya devam et.\n");
                    }
                }
                break;

            case 'E': // Envanter Görüntüle [cite: 11]
                printf("\n--- DURUM RAPORU ---\n");
                printf("Saglik: %d | Enerji: %d\n", saglik, enerji);
                printf("Yemek: %d  | Siginak: %s\n", yemek, (siginak ? "VAR" : "YOK"));
                break;

            case 'R': // Dinlen
                if (siginak == 1) {
                    enerji += 20;
                    saglik += 10; // Sığınak varsa daha çok iyileş
                    printf("Siginakta guzelce uyudun. (Enerji +20, Saglik +10)\n");
                } else {
                    enerji += 10;
                    printf("Disarida titreyerek dinlendin. (Enerji +10)\n");
                }
                // Sınır kontrolü (100'ü geçmesin)
                if (enerji > 100) enerji = 100;
                if (saglik > 100) saglik = 100;
                break;
            
            case 'F': // Tehlike Dalgası (FOR Döngüsü)
                printf("\n!!! TEHLIKE DALGASI BASLIYOR (3 Tur) !!!\n");
                
                int i; 
                for (i = 1; i <= 3; i++) {
                    printf("--- Dalga %d ---\n", i);
                    
                    // 1. DURUM: SIĞINAK KONTROLÜ
                    // Sığınağın varsa %90 ihtimalle hiç hasar almazsın.
                    if (siginak == 1) {
                        if (rand() % 100 < 90) {
                            printf(">> Siginagin sayesinde firtinadan korundun.\n");
                            continue; // Döngünün başına dön, diğer kontrollere girme
                        } else {
                            printf(">> Siginagin kapisi kirildi! Hasar alacaksin.\n");
                        }
                    }

                    // 2. DURUM: ENERJİ KONTROLÜ (KAÇMA İHTİMALİ)
                    // Enerjin 40'tan fazlaysa kaçma şansın yüksek olur.
                    if (enerji >= 40) {
                        printf(">> Enerjin yerinde, tehlikeden kacmayi deniyorsun...\n");
                        // %70 ihtimalle başarılı kaçış
                        if (rand() % 100 < 70) {
                            int harcananEnerji = rand() % 10 + 5;
                            enerji -= harcananEnerji;
                            printf(">> BASARILI! Hizlica kactin. (Hasar Yok, -%d Enerji)\n", harcananEnerji);
                        } else {
                            // Kaçamazsa hasar alır
                            int hasar = rand() % 15 + 5;
                            saglik -= hasar;
                            printf(">> Kacamadin! Ayagin takildi. (-%d Saglik)\n", hasar);
                        }
                    } 
                    // 3. DURUM: DÜŞÜK ENERJİ (SAVUNMASIZLIK)
                    else {
                        printf(">> Cok yorgunsun, kacamiyorsun!\n");
                        int hasar = rand() % 20 + 10; // Daha çok hasar yer
                        saglik -= hasar;
                        printf(">> Savunmasiz yakalandin! (-%d Saglik)\n", hasar);
                    }

                    // Ölüm kontrolü
                    if (saglik <= 0) {
                        printf("\nTehlike sirasinda hayatini kaybettin...\n");
                        break;
                    }
                }
                break;

            case 'P': // Şifreli İlerleme (DO-WHILE) 
                {
                    int girilenSifre;
                    int dogruSifre = 1234;
                    printf("Kilitli bir sandik buldun. Sifreyi cozmen lazim.\n");
                    
                    // Kullanıcı doğru girene kadar dönen döngü
                    do {
                        printf("Sifreyi giriniz (4 hane): ");
                        scanf("%d", &girilenSifre);
                        if(girilenSifre != dogruSifre) {
                            printf("Hatali sifre! Tekrar dene.\n");
                        }
                    } while (girilenSifre != dogruSifre);
                    
                    printf("Sifre dogru! Sandiktan ekstra yemek cikti. (Yemek +2)\n");
                    yemek += 2;
                }
                break;

            case 'X': // Çıkış
                printf("Simulasyondan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz komut! A, S, R, E, F, P veya X kullanin.\n");
        }

        // Oyun Bitti Kontrolü
        if (saglik <= 0) {
            printf("\nSagligin tukendi. OYUN BITTI.\n");
            komut = 'X'; // Döngüyü kırmak için
        }

    } while (komut != 'X');

    return 0;
}


