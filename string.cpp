#include <iostream>
#include <string>

using namespace std;

int main() {
    string antwort[3];  // string array für die fragen
    bool aw[3];

    string a = "$?Wie initialisiert man ein int-Array richtig?$3";
    string b[6];
    b[1] = "$1+Mit int arr[3];$";
    b[2] = "$2-Mit int arr[3];$";
    b[3] = "$3+Mit int arr[3];$!";
    int zeile = 0;
    string frage;
    int antworten = 0;

    if (a[0] == '$') {
        if (a[1] == '?') {
            for (int x = 2; x < 900; x++) {
                if (a[x] != '$') {
                    frage = frage + a[x];      // frage wird in string frage geladen
                }
                else {
                    antworten = int(a[x+1]) - 48;
                    x = 900; // alternativ x = 900
                }

            }
                     // bool array, welche fragen richtig sind, 
            for (int x = 0; x < antworten; x++) {
                zeile++;                                    //Ersatz, um neue Zeilen zu laden
                switch (zeile){                              
                case 1: a = "$1+Mit int arr[3];$"; break;
                case 2: a = "$2-Mit int arr[3];$"; break;
                case 3: a = "$3+Mit int arr[3];$!";    break;
                }                                          //bis hier ggf. löschen


                // Neue Zeile in string a laden
                if (a[0] == '$') {
                    if (a[2] == '+') {
                        aw[x] = true;
                    }
                    else if (a[2] == '-') {
                        aw[x] = false;
                    } else {
                        cout << "Error 1"; // error
                    }
                    for (int y = 3; y < 900; y++) {
                        if (a[y] != '$') {
                            antwort[x] = antwort[x] + a[y];
                        }
                        else {
                            if (a[y+1] == '!') {
                                x = 900;      // alternativ x = 900
                            }
                            else {
                                y = 900;
                            }
                        }
                    }
                }
            }
            cout << "Frage: " << frage << endl;
            cout << "Anzahl der Antworten: " << antworten << endl;
            for (int i = 0; i < antworten; i++) {
                cout << "Antwort " << i+1 << ": " << antwort[i] << " - Richtig: " << aw[i] << endl; 
            }
        }
        else {
            cout << "Error 2"; // error
        }
    }
    else {
       cout << "Error 3"; //error
    }

    return 0;
}