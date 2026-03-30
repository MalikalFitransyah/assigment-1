### Malikal Fitransyah Alwan | 5024251005
## tujuan

Program C++ ini digunakan untuk menghitung:

* Umur dalam **tahun**
* Umur dalam **bulan**
* **Hari dalam minggu** dari tanggal lahir

Input diberikan dalam format **dd/mm/yyyy**, lalu program memprosesnya menggunakan library waktu (`ctime`).

## Cara Kerja Program

* Program mengambil **tanggal saat ini** menggunakan `localtime()`
* Input diparsing menggunakan `stringstream`
* Data tanggal disimpan dalam struktur `tm`
* Perhitungan dilakukan melalui 3 fungsi utama

## Fungsi Utama

* **yearsOld()**
  Menghitung umur dalam tahun, dengan pengecekan apakah ulang tahun sudah lewat atau belum.

* **monthsOld()**
  Menghitung total bulan dari selisih tahun dan bulan, serta menyesuaikan jika hari belum lewat.

* **dayOfDate()**
  Menentukan hari menggunakan `mktime()` lalu mencocokkan dengan array hari.

## Contoh

Input:

```id="f0tkpm"
23/10/2008
```

Output:

```id="pr3cfd"
17 209 kamis
```

---

## Kesimpulan

Program ini mampu menghitung umur dan hari lahir secara otomatis dengan memanfaatkan struktur waktu di C++, serta penggunaan fungsi yang terpisah agar lebih terstruktur.
