#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLabel>
#include <QMessageBox>
#include <QHeaderView>
#include <vector>
#include <string>
using namespace std;

struct Kontak { string nama, nomor, email; };
vector<Kontak> db;

class ContactBook : public QMainWindow {
    Q_OBJECT
public:
    QTableWidget* tabel;
    QLineEdit* inputNama;
    QLineEdit* inputNomor;
    QLineEdit* inputEmail;
    QLineEdit* inputCari;

    ContactBook(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Buku Kontak");
        setMinimumSize(700, 500);

        QWidget* central = new QWidget(this);
        setCentralWidget(central);
        QVBoxLayout* mainLayout = new QVBoxLayout(central);

        // Input form
        QHBoxLayout* formLayout = new QHBoxLayout();
        inputNama  = new QLineEdit(); inputNama->setPlaceholderText("Nama");
        inputNomor = new QLineEdit(); inputNomor->setPlaceholderText("Nomor");
        inputEmail = new QLineEdit(); inputEmail->setPlaceholderText("Email");
        formLayout->addWidget(inputNama);
        formLayout->addWidget(inputNomor);
        formLayout->addWidget(inputEmail);
        mainLayout->addLayout(formLayout);

        // Tombol
        QHBoxLayout* btnLayout = new QHBoxLayout();
        QPushButton* btnTambah = new QPushButton("Tambah");
        QPushButton* btnEdit   = new QPushButton("Edit");
        QPushButton* btnHapus  = new QPushButton("Hapus");
        btnLayout->addWidget(btnTambah);
        btnLayout->addWidget(btnEdit);
        btnLayout->addWidget(btnHapus);
        mainLayout->addLayout(btnLayout);

        // Search
        QHBoxLayout* cariLayout = new QHBoxLayout();
        inputCari = new QLineEdit(); inputCari->setPlaceholderText("Cari nama...");
        QPushButton* btnCari = new QPushButton("Cari");
        QPushButton* btnReset = new QPushButton("Reset");
        cariLayout->addWidget(inputCari);
        cariLayout->addWidget(btnCari);
        cariLayout->addWidget(btnReset);
        mainLayout->addLayout(cariLayout);

        // Tabel
        tabel = new QTableWidget(0, 3);
        tabel->setHorizontalHeaderLabels({"Nama", "Nomor", "Email"});
        tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tabel->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabel->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mainLayout->addWidget(tabel);

        // Koneksi sinyal
        connect(btnTambah, &QPushButton::clicked, this, &ContactBook::tambah);
        connect(btnEdit,   &QPushButton::clicked, this, &ContactBook::edit);
        connect(btnHapus,  &QPushButton::clicked, this, &ContactBook::hapus);
        connect(btnCari,   &QPushButton::clicked, this, &ContactBook::cari);
        connect(btnReset,  &QPushButton::clicked, this, &ContactBook::refreshTabel);
    }

    void refreshTabel(const vector<Kontak>& data) {
        tabel->setRowCount(0);
        for (auto& k : data) {
            int row = tabel->rowCount();
            tabel->insertRow(row);
            tabel->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(k.nama)));
            tabel->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(k.nomor)));
            tabel->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(k.email)));
        }
    }

public slots:
    void refreshTabel() { refreshTabel(db); }

    void tambah() {
        QString nama  = inputNama->text().trimmed();
        QString nomor = inputNomor->text().trimmed();
        QString email = inputEmail->text().trimmed();
        if (nama.isEmpty()) { QMessageBox::warning(this, "Error", "Nama tidak boleh kosong!"); return; }
        db.push_back({nama.toStdString(), nomor.toStdString(), email.toStdString()});
        inputNama->clear(); inputNomor->clear(); inputEmail->clear();
        refreshTabel();
    }

    void hapus() {
        int row = tabel->currentRow();
        if (row < 0) { QMessageBox::warning(this, "Error", "Pilih kontak dulu!"); return; }
        db.erase(db.begin() + row);
        refreshTabel();
    }

    void edit() {
        int row = tabel->currentRow();
        if (row < 0) { QMessageBox::warning(this, "Error", "Pilih kontak dulu!"); return; }
        Kontak& k = db[row];
        inputNama->setText(QString::fromStdString(k.nama));
        inputNomor->setText(QString::fromStdString(k.nomor));
        inputEmail->setText(QString::fromStdString(k.email));
        db.erase(db.begin() + row);
        refreshTabel();
    }

    void cari() {
        QString q = inputCari->text().trimmed().toLower();
        if (q.isEmpty()) { refreshTabel(); return; }
        vector<Kontak> hasil;
        for (auto& k : db) {
            if (QString::fromStdString(k.nama).toLower().contains(q))
                hasil.push_back(k);
        }
        refreshTabel(hasil);
    }
};

#include "main.moc"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    ContactBook window;
    window.show();
    return app.exec();
}