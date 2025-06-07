# 🚀 Task Manager Queue (C++)

Aplikasi manajemen tugas berbasis **antrian** yang dibangun dengan bahasa **C++**, memanfaatkan struktur data _linked list_ untuk mengelola tugas berdasarkan ID, prioritas, dan waktu masuk (_FIFO_).

---

## 🔧 Fitur Lengkap

- 🆕 Tambah tugas baru dengan informasi lengkap
- 📋 Tampilkan seluruh tugas secara terurut berdasarkan **prioritas**: tinggi → sedang → rendah
- 🔍 Cari tugas berdasarkan **ID**
- 📝 Perbarui data tugas dengan mudah
- ❌ Hapus tugas berdasarkan ID atau metode FIFO (dequeue)
- 🎯 Filter tugas berdasarkan prioritas tertentu
- ♻️ Memori dikelola otomatis menggunakan destructor

---

## 🧠 Struktur Kode

- `Task`: Kelas utama untuk merepresentasikan informasi tugas
- `Node`: Struktur node untuk membangun _linked list_
- `TaskManager`: Kelas pengelola antrian tugas, termasuk operasi tambah, hapus, cari, tampilkan, dan perbarui

---

## 🖥️ Cara Menjalankan

### 1. Clone repositori
```bash
git clone https://github.com/username/namarepo.git
cd namarepo
```
### 2. Kompilasi program
```
g++ -o task_manager main.cpp
```
### 3. Jalankan program
```
./task_manager
```
## 📌 Menu Program
```
=== MENU MANAJEMEN TUGAS ===
1. Tambah Tugas
2. Tampilkan Semua Tugas
3. Perbarui Tugas
4. Hapus Tugas (berdasarkan ID)
5. Cari Tugas
6. Tampilkan Tugas Berdasarkan Prioritas
7. Dequeue (Hapus Tugas Pertama)
8. Keluar
```

## 📝 Catatan
✅ Prioritas hanya digunakan saat display, bukan untuk urutan di antrian.

✅ dequeue() selalu menghapus tugas terdepan (sesuai metode FIFO).

✅ Program akan meminta konfirmasi sebelum keluar setelah setiap aksi.

## 👨‍💻 Author
- Lutfi
- Akbar
- Evan
- Ozza
- Samuel

### 🛠 Mahasiswa / Developer pemula yang belajar struktur data & algoritma

## 📄 Lisensi
Bebas digunakan untuk keperluan edukasi, modifikasi, atau pengembangan lanjutan. Tidak diperkenankan untuk dijual tanpa izin.

## ⭐ Tips
Jika kamu suka proyek ini, beri bintang ⭐ di GitHub dan bagikan ke temanmu yang sedang belajar C++!
```
> Pastikan Anda mengganti `https://github.com/username/namarepo.git` dengan URL repo Anda sendiri.
```
# *DAN YANG TERAKHIR TERIMA KASIH BANG LAKS DAN BANG KHAI ATAS SEMUA PELAJARAN NYA*
![Gambar WhatsApp 2025-06-07 pukul 13 29 17_a362b520](https://github.com/user-attachments/assets/683ccf6d-6bce-4add-ba87-6c999820c8b3)
