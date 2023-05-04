#include <iostream>
#include <string>

using namespace std;

int main() {

    string a = "$?Wie initialisiert man ein int-Array richtig?$3";  // Varieble, welche die aktuell geladene Zeile beinhaltet
    int zeile = 0;
    string frage;
    int antworten = 0;

    if (a[0] == '$') {          // Mit $ wird ein Befehl signalisiert
        if (a[1] == '?') {      // Mit ? nach dem $ wird eine frage deklariert
            for (int x = 2; x < 900; x++) {
                if (a[x] != '$') {             // Das nächste $ signalisiert das Ende der Frage
                    frage = frage + a[x];      // frage wird ausgelesen und in string frage geladen
                }
                else {
                    antworten = int(a[x+1]) - 48;  // Die Zahl nach dem $ steht für die Anzahl der möglichen Antworten, diese werden vorher aus ascii in dezimal gerechnet
                    break;
                }

            }
           string antwort[antworten];  // String Array für die Fragen wird generiert
           bool aw[antworten]; // Bool Array über die richtigkeit der Frage wird generiert

            for (int x = 0; x < antworten; x++) {             // Stütze um die Zeilen laden zu können
                zeile++;
                switch (zeile){
                case 1: a = "$1+Mit int arr[3]1;$"; break;
                case 2: a = "$2-Mit int arr[3]2;$"; break;
                case 3: a = "$3+Mit int arr[3]3;$"; break;
                }                                            //


                // Neue Zeile in string a laden (^^^ Stütze ersetzt dies hierbei)


                if (a[0] == '$') {         // $ Signalisiert auch hier wieder ein "Befehl, hierbei, da eine Frage bereits erstellt wurde eine Antwort"
                    if (a[2] == '+') {     // Wenn nach dem $ ein + steht, so ist die Antwort richtig
                        aw[x] = true;
                    }
                    else if (a[2] == '-') {  // Wenn nach dem $ ein - steht, so ist die Antwort falsch
                        aw[x] = false;
                    } else {
                        cout << "Error 1"; // error
                    }
                    for (int y = 3; y < 900; y++) {  // Frage wird in string antwort geladen, bis diese durch ein erneutes $ beendet wird
                        if (a[y] != '$') {
                            antwort[x] = antwort[x] + a[y];
                        } else{
                        break;  
                        }
                        
                    }
                }
            }

                                               // Zum ausgeben der Werte, temporär zum debuggen
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

}
