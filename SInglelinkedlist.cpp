#include <iostream>
using namespace std;

struct film {
    string judul;
    int durasi;
    int harga;
    film *next;
};

film *head, *tail, *cur, *newNode, *del;

void createdsinglelinkedlist(string judul, int durasi, int harga) {
    head = new film();
    head->judul = judul;
    head->durasi = durasi;
    head->harga = harga;
    head->next = NULL;
    tail = head;
}

void addfirst(string judul, int durasi, int harga) {
    newNode = new film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->next = head;
    head = newNode;
}

void addlast(string judul, int durasi, int harga) {
    newNode = new film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void removefirst() {
    del = head;
    head = head->next;
    delete del;
}

void removelast() {
    del = tail;
    cur = head;
    while (cur->next != tail) {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void changefirst(string judul, int durasi, int harga) {
    head->judul = judul;
    head->durasi = durasi;
    head->harga = harga;
}

void changelast(string judul, int durasi, int harga) {
    tail->judul = judul;
    tail->durasi = durasi;
    tail->harga = harga;
}

void printsinglelinkedlist() {
    cur = head;
    while (cur != NULL) {
        cout << "Judul: " << cur->judul << endl;
        cout << "Durasi: " << cur->durasi << " menit" << endl;
        cout << "Harga: " << cur->harga << endl;
        cur = cur->next;
    }
    cout << "\n\n";
}

int main() {
    createdsinglelinkedlist("Ultraman Tiga", 120, 50000);
    printsinglelinkedlist();

    addfirst("Raja Terakhir", 60, 30000);
    printsinglelinkedlist();

    addlast("Power Rangers", 100, 45000);
    printsinglelinkedlist();

    removefirst();
    printsinglelinkedlist();

    removelast();
    printsinglelinkedlist();

    changefirst("Train To Busan", 90, 40000);
    printsinglelinkedlist();

    changelast("Cinta Satu Malam", 90, 40000);
    printsinglelinkedlist();

    return 0;
}