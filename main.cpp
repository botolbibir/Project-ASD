#include <iostream>
#include <string>
using namespace std;

// ===================================================================
// ================ BAGIAN 1: Kelas Task dan Struct Node =============
// ===================================================================


// kelas untuk menyimpan informasi tugas
class Task {
public:
    string task_id;
    string name;
    string course_name;
    string description;
    string date_assigned;
    string deadline;
    string priority;

    // konstruktor default
    Task(){}

    // konstruktor dengan parameter
    
    Task(string id, string nm, string course, string desc, string assigned, string dl, string prio)
        : task_id(id), name(nm), course_name(course), description(desc),
          date_assigned(assigned), deadline(dl), priority(prio) {}

    // output display penugasan
    void display() const {
        cout << "==============================" << endl;
        cout << "ID           : " << task_id << endl;
        cout << "Nama         : " << name << endl;
        cout << "Mata Kuliah  : " << course_name << endl;
        cout << "Deskripsi    : " << description << endl;
        cout << "Diberikan    : " << date_assigned << endl;
        cout << "Deadline     : " << deadline << endl;
        cout << "Prioritas    : " << priority << endl;
    }
};

// struktur Node 
struct Node {
    Task task;         // untuk simpan tugas
    Node* next;        // pointer ke node berikutnya

    // konstruktor node
    Node(Task t) : task(t), next(nullptr) {}
};

// ===================================================================
// =========== BAGIAN 2: TaskManager (Constructor, Add, Delete) ======
// ===================================================================


// kelas untuk mengelola antrian tugas
class TaskManager {
private:
    Node* front;   // pointer ke depan antrian
    Node* rear;    // pointer ke belakang antrian

public:
    //konstruktor 
    TaskManager() : front(nullptr), rear(nullptr) {}

    // destructor untuk hapus semua node dalam antrian
    ~TaskManager() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // tambah tugas ke antrian 
    void addTask(const Task& task) {
        Node* newNode = new Node(task);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Tugas berhasil ditambahkan.\n";
    }

    // hapus tugas berdasarkan ID (untuk menghapus tugas jika ingin mendelete tugas tidak berdasarkan priority tertinggi/ dengan dequeue, tapi berdasarkan id)
    bool deleteTask(const string& task_id) {
        if (front == nullptr) 
        return false;

        Node* temp = front;
        Node* prev = nullptr;

        // cari tugas berdasarkan id
        while (temp != nullptr && temp->task.task_id != task_id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) 
        return false;

        // update pointer jika node dihapus
        if (temp == front) front = front->next;
        else prev->next = temp->next;

        if (temp == rear) rear = prev;

        delete temp;
        return true;
    }

    // hapus tugas pertama dalam antrian (FIFO)( ini yang menggunakan dequeue jadi langsung menghapus atrian pertama atau tugas dengan prioritas tinggi)
    bool dequeue() {
        if (front == nullptr) {
            cout << "Antrian kosong. Tidak ada tugas yang bisa dihapus.\n";
            return false;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) 
        rear = nullptr;

        cout << "Tugas dengan ID \"" << temp->task.task_id << "\" berhasil dikeluarkan dari antrian.\n";
        delete temp;
        return true;
    }

// ===================================================================
// ========== BAGIAN 3: Display, Search, Prioritas ===================
// ===================================================================


    // output tugas berdasarkan urutan prioritas
    void displayAll() const {
        if (front == nullptr) {
            cout << "Tidak ada tugas untuk ditampilkan.\n";
            return;
        }

        cout << "--- Daftar Tugas Berdasarkan Prioritas ---\n";

        //  output untuk prioritas tinggi terlebih dahulu
        Node* temp = front;
        while (temp != nullptr) {
            if (temp->task.priority == "tinggi")
                temp->task.display();
            temp = temp->next;
        }

        // baru prioritas sedang
        temp = front;
        while (temp != nullptr) {
            if (temp->task.priority == "sedang")
                temp->task.display();
            temp = temp->next;
        }

        // terakhir prioritas rendah
        temp = front;
        while (temp != nullptr) {
            if (temp->task.priority == "rendah")
                temp->task.display();
            temp = temp->next;
        }
    }

    // cari tugas berdasarkan id
    Task* search(const string& task_id) {
        Node* temp = front;
        while (temp != nullptr) {
            if (temp->task.task_id == task_id) 
            return &(temp->task);
            
            temp = temp->next;
        }
        return nullptr;
    }

    // output tugas berdasarkan prioritas tertentu
    void displayByPriority(const string& level) const {
        Node* temp = front;
        bool found = false;
        while (temp != nullptr) {
            if (temp->task.priority == level) {
                temp->task.display();
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "Tidak ditemukan tugas dengan prioritas itu.\n";
    }

// ===================================================================
// =========== BAGIAN 4: Fungsi Menu dan Konfirmasi ==================
// ===================================================================


    // mengupdate tugas yang ditemukan dengan tugas baru
    bool update(const string& task_id, const Task& updated_task) {
        Node* temp = front;
        while (temp != nullptr) {
            if (temp->task.task_id == task_id) {
                temp->task = updated_task;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    
};

// output menu untuk UI pengguna
void displayMenu() {
    cout << "\n=== MENU MANAJEMEN TUGAS ===" << endl;
    cout << "1. Tambah Tugas" << endl;
    cout << "2. Tampilkan Semua Tugas" << endl;
    cout << "3. Perbarui Tugas" << endl;
    cout << "4. Hapus Tugas (berdasarkan ID)" << endl;
    cout << "5. Cari Tugas" << endl;
    cout << "6. Tampilkan Tugas Berdasarkan Prioritas" << endl;
    cout << "7. Dequeue (Hapus Tugas Pertama)" << endl;
    cout << "8. Keluar" << endl;
    cout << "============================" << endl;
}

// output untuk melanjutkan program atau tidak
bool confirm() {
    string jawab;
    cout << "\nApakah Anda ingin melanjutkan? (y/n): ";
    getline(cin, jawab);
    return (jawab == "y" || jawab == "Y");
}

// ===================================================================
// =========== BAGIAN 5: Fungsi main dan Operasi Tugas ==============
// ===================================================================


// Fungsi main
int main() {
    TaskManager tskmng; 
    int choice;

    while (true) {
        displayMenu(); // output fungsi menu
        cout << "Pilih menu: ";
        cin >> choice;
        cout << "\n\n";
        cin.ignore(); // Hapus newline di buffer

        if (choice == 8) {
            cout << "Program selesai." << endl;
            break;
        }

        string task_id, name, course_name, description, date_assigned, deadline, priority;

        switch (choice) {
            case 1:
                // input data tugas
                cout << "ID Tugas: "; getline(cin, task_id);
                cout << "Nama Tugas: "; getline(cin, name);
                cout << "Nama Mata Kuliah: "; getline(cin, course_name);
                cout << "Deskripsi: "; getline(cin, description);
                cout << "Tanggal Diberikan: "; getline(cin, date_assigned);
                cout << "Deadline: "; getline(cin, deadline);
                cout << "Prioritas (tinggi/sedang/rendah): "; getline(cin, priority);

                while (priority != "tinggi" && priority != "sedang" && priority != "rendah") {
                    cout << "Prioritas tidak valid. Masukkan (tinggi/sedang/rendah): ";
                    getline(cin, priority);
                }

                // memasukkan data menjadi satu node dan dijadikan linklist
                tskmng.addTask(Task(task_id, name, course_name, description, date_assigned, deadline, priority));
                cout << "\n\n";
                if (!confirm()) return 0;
                break;

            case 2:
                tskmng.displayAll(); // output semua tugas
                cout << "\n\n";
                if (!confirm()) return 0;
                break;

            case 3:
                cout << "ID Tugas yang ingin diperbarui: "; getline(cin, task_id);
                if (tskmng.search(task_id)) {
                    // input data baru
                    cout << "Nama Baru: "; getline(cin, name);
                    cout << "Mata Kuliah Baru: "; getline(cin, course_name);
                    cout << "Deskripsi Baru: "; getline(cin, description);
                    cout << "Tanggal Diberikan Baru: "; getline(cin, date_assigned);
                    cout << "Deadline Baru: "; getline(cin, deadline);
                    cout << "Prioritas Baru (tinggi/sedang/rendah): "; getline(cin, priority);

                     while (priority != "tinggi" && priority != "sedang" && priority != "rendah") {
                        cout << "Prioritas tidak valid. Masukkan (tinggi/sedang/rendah): ";
                        getline(cin, priority);
                    }
                    
                    tskmng.update(task_id, Task(task_id, name, course_name, description, date_assigned, deadline, priority));
                    cout << "Tugas berhasil diperbarui.\n";
                } else {
                    cout << "Tugas tidak ditemukan.\n";
                }
                cout << "\n\n";
                if (!confirm()) return 0;
                break;

            case 4:
            // menghapus data berdasarkan id (tidak menggunakan dequeue), ini untuk mendelete tugas secara spesifik bukan berdasarkan priority tertinggi
                cout << "ID Tugas yang ingin dihapus: "; 
                getline(cin, task_id);

                if (tskmng.deleteTask(task_id))
                    cout << "Tugas berhasil dihapus.\n";
                else
                    cout << "Tugas tidak ditemukan.\n";
                cout << "\n\n";
               
                if (!confirm()) return 0;
                break;

            case 5:
                cout << "ID Tugas yang dicari: "; 
                getline(cin, task_id);

                if (Task* t = tskmng.search(task_id)) {
                    cout << "Tugas ditemukan:\n";
                    t->display();
                } else {
                    cout << "Tugas tidak ditemukan.\n";
                }
                cout << "\n\n";
                
                if (!confirm()) return 0;
                break;

            case 6:
                cout << "Masukkan prioritas (tinggi/sedang/rendah): "; 
                getline(cin, priority);
                
                tskmng.displayByPriority(priority);
                cout << "\n\n";
                if (!confirm()) return 0;
                break;

            case 7:
                 // hapus tugas priority tinggi dahulu (FIFO), ini baru menggunakan dequeue
                tskmng.dequeue(); 
                cout << "\n\n";
                if (!confirm()) return 0;
                break;

            default:
                cout << "Pilihan tidak valid!\n\n";
                if (!confirm()) return 0;
        }
    }

    return 0;
}