# Refine Scroll Renewal & Blacksmith Shop

Yükseltme kâğıdı kuralları ve iki sekmeli Demirci mağazası (NPC 20016).

![Önizleme](preview.png)

---

## Ne var?

- Ritüel Taşı, Onur, Ejderha, Yükseliş kâğıtlarının kuralları (seviye / başarı / düşürme)
- Demirci: Demirhane ve Gelişmiş Demirhane (106+) sekmeleri, yang + 3 ek eşya fiyatı
- Yeni eşya satırları: `03. Server/proto/`

## Paket yapısı

```
01. Svn/          → Client & Game source (Ara / Altına ekle / Bul / Değiştir patch dosyaları + yeni dosyalar)
02. Client/       → root, uiscript, locale, d_/ymir work assetleri
03. Server/       → MySQL tabloları, quest ve sunucu verileri
Added/            → Değişikliklerin uygulanmış hali (tam dosyalar, karşılaştırma için)
```

## Flagler

**Game** (`service.h`):
- `ENABLE_REFINE_SCROLL_RENEWAL`

## Kurulum (kısaca)

1. `01. Svn` altındaki patch dosyalarını kendi source ağacına uygula. Her blokta `// Ara:` satırlarını bul, `// Altına ekle:` kısmını altına ekle; `// Bul:` / `// Degistir:` bloklarında bulduğun satırları verilen blokla değiştir.
2. `02. Client/root` ve `02. Client/uiscript` içindeki tam dosyaları pack'e kopyala, patch dosyalarını (`# Ara:` / `# Altına ekle:`) kendi dosyalarına uygula.
3. `02. Client/locale/<dil>/` satırlarını kendi locale dosyalarının sonuna ekle.
4. `03. Server` içindeki SQL ve verileri sunucuya uygula.
5. Client + game + db rebuild, pack güncelle.

## Bağımlılıklar

- Tabbed NPC Shops (ShopEx) & Alchemist paketi (sekmeli mağaza altyapısı, 3 ek fiyat)

## Notlar

- Locale dosyalarında yalnızca bu sisteme ait anahtarlar var; `new_locale_*` kendi eklediğimiz, `locale_game` / `locale_interface` resmi istemcide olmayan anahtarlar. Türkçe dosyalar cp1254.
- Patch'lerde başka sistemlere ait satırlar görürsen (farklı `#ifdef`), o sistem sende yoksa yok say.
- Fork farklıysa paket header / struct sıralamasını kontrol et.

---

## İletişim

Sorular için Discord'dan yazabilirsin.

| | |
|---|---|
| GitHub | [github.com/ybeststudio](https://github.com/ybeststudio) |
| Discord | [discord.gg/NXmc6JrwYr](https://discord.gg/NXmc6JrwYr) |
| Discord ID | `beststudio` |
| Web | [beststudio.dev](https://www.beststudio.dev/) |
| TurkMMO | [Best Studio](https://forum.turkmmo.com/uye/2104546-best-studio/) |
| YouTube | [@ybeststudio](https://www.youtube.com/@ybeststudiotr) |
| Instagram | [@ybeststudio](https://www.instagram.com/ybeststudio) |
| Facebook | [ybeststudio](https://www.facebook.com/ybeststudio/) |
| Twitter | [@ybeststudio](https://twitter.com/ybeststudio) |
| TikTok | [@ybeststudio](https://tiktok.com/@ybeststudio) |

---

**Best Studio** — Metin2 private server çözümleri
