#ifndef LAHENDAJA_H
#define LAHENDAJA_H

#include <stdexcept>
#include "sudokuväli.h"
using namespace std;

template <int N>
bool lahendaRekursiivselt(sudokuväli<N>& sudoku) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Kui väli on täidetud, siis jäta vahele
            if (sudoku.väli[i][j] != 0) continue;

            // Leiame ühisosa, kui ühisosa on tühi, siis oleme valesti lahendanud ning tagastame false
            set<int> sobivad = sudoku.reaVeeruKastiÜhisosa(i,j);
            if (sobivad.empty()) return false;

            // Abi muutuja et näha kas oli lahendatav
            bool oliMuutus = false;
            for (int x : sobivad) {
                // Võtame ühisosast väärtuses ning täidame välja sellega
                sudoku.väli[i][j] = x;
                // Kutsume rekursiivselt sama funktsiooni ning kui ühisosa oli tühi
                // või kui ükski ühisosadest ei sobinud järgnevatel rekursiivsetel väljakutsetel
                // (Tegime eelnevalt vale valiku), siis
                // muudame välja uuesti 0ks
                if (!lahendaRekursiivselt(sudoku)) {
                    sudoku.väli[i][j] = 0;
                } else {
                    // Kui ühisosa sobis muudame oliMuutus väärtuse tõeseks ning lõpetame tsükli
                    oliMuutus = true;
                    break;
                }
            }
            // Kui muutust ei toimunud (sudoku pole lahendatav) tagastame false
            // Kui muutus toimus (leidsime sobiva ühisosa) tagastame true
            return oliMuutus;
        }
    }
    return true;
}

template <int N>
void lahendaSudoku(sudokuväli<N>& sudoku) {

    // Kõigepealt proovime täita kõik lahtrid kuhu sobib ainult 1 arv
    // Kasutame abimuutujat, et näha kas tsükli jooksul sai vähemalt üks väli muudetud (ei jää lõpmatusse tsüklisse)
    bool oliMuutus = true;
    while (oliMuutus) {
        oliMuutus = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Kui väli on juba täidetud siis jätkame järgmise lahtriga
                if (sudoku.väli[i][j] != 0) continue;
                // Leiame lahtrisse sobivad arvud, mis ei riku reegleid
                set<int> sobivad = sudoku.reaVeeruKastiÜhisosa(i,j);
                // Kui lahtrisse ei sobi ükski arv pole sudoku lahendatav
                if (sobivad.empty()) throw runtime_error("sudoku pole lahendatav");
                // Kui lahtrisse sobib ainult 1 arv, siis täidame lahtri sellega
                if (sobivad.size() == 1) {
                    sudoku.väli[i][j] = *sobivad.begin();
                    // Täitsime vähemalt ühe lahtri äkki sobib kuhugi mujale ka nüüd ainult 1 arv
                    // muutus toimus ehk jätkame tsükkliga
                    oliMuutus = true;
                }
            }
        }
    }

    // Kutsume välja rekursiivse lahendaja
    // Kui kõik väljad on juba täidetud, siis jookseb algoritm tühjalt läbi ning tagastab true
    // Kui esimes algoritmiga jäid täitmata väljad, kuhu igasse lahtrisse sobib rohkem kui 1 arv ...
    // siis lahendatakase ülejäänud sudoku rekursiivselt.
    if (!lahendaRekursiivselt(sudoku)) {
        throw runtime_error("sudoku pole lahendatav");
    }
}


#endif
#endif