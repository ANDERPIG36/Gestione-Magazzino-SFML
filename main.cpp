#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const double IVA = 0.22;

struct Prodotto {
    string nome;
    double prezzoAcquisto;
    double prezzoVendita;
    int quantita;

    double getIVA() const { return prezzoVendita * IVA; }
    double getPrezzoConIVA() const { return prezzoVendita * (1 + IVA); }
    double getMargineUnitario() const { return prezzoVendita - prezzoAcquisto; }
    double getValoreTotaleStock() const { return prezzoAcquisto * quantita; }
    bool daRiordinare() const { return quantita < 5; }
};

int main() {
    vector<Prodotto> magazzino;
    int n;
    cout << "Quanti prodotti vuoi inserire? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Prodotto p;
        cout << "\nProdotto " << i + 1 << "/" << n << endl;
        cout << "Nome: ";
        getline(cin, p.nome);
        cout << "Prezzo acquisto: ";
        cin >> p.prezzoAcquisto;
        cout << "Prezzo vendita: ";
        cin >> p.prezzoVendita;
        cout << "Quantita: ";
        cin >> p.quantita;
        cin.ignore();
        magazzino.push_back(p);
    }

    cout << fixed << setprecision(2);

    double valoreTot = 0;
    int riordinoTot = 0;

    for (auto &p : magazzino) {
        cout << "\n--- " << p.nome << " ---" << endl;
        cout << "IVA (22%): EUR " << p.getIVA() << endl;
        cout << "Prezzo con IVA: EUR " << p.getPrezzoConIVA() << endl;
        cout << "Margine unitario: EUR " << p.getMargineUnitario() << endl;
        cout << "Valore totale magazzino: EUR " << p.getValoreTotaleStock() << endl;

        valoreTot += p.getValoreTotaleStock();
        if (p.daRiordinare()) {
            riordinoTot++;
            cout << "*** RIORDINO ***" << endl;
        }
    }

    cout << "\n=== RIASSUNTO ===" << endl;
    cout << "Prodotti totali inseriti: " << n << endl;
    cout << "Valore totale magazzino: EUR " << valoreTot << endl;
    cout << "Prodotti da riordinare: " << riordinoTot << endl;

    cout << "\nPremi Invio per uscire...";
    cin.get();
}
