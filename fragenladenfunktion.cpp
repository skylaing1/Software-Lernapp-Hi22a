#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Frage {

public:
string frage;
vector <string> antwort;
vector <bool> aw;

};

vector <Frage> fragen;



using namespace std;

void read_question_file(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Konnte " << filename << " nicht öffnen." << endl;
        return;
    }
   fragen.push_back();
    string a;  // Varieble, welche die aktuell geladene Zeile beinhaltet
    getline(infile, a);
    /*int zeile = 0;
    string frage;*/
    int antworten = 0;

    if (a[0] == '$') {          // Mit $ wird ein Befehl signalisiert
        if (a[1] == '?') {      // Mit ? nach dem $ wird eine frage deklariert
            for (int x = 2; x < 900; x++) {
                if (a[x] != '$') {             // Das nächste $ signalisiert das Ende der Frage
                    fragen.frage = fragen.frage + a[x];      // frage wird ausgelesen und in string frage geladen
                }
                else {
                    antworten = int(a[x+1]) - 48;  // Die Zahl nach dem $ steht für die Anzahl der möglichen Antworten, diese werden vorher aus ascii in dezimal gerechnet
                    break;
                }

            }
          //  string antwort[antworten];  // String Array für die Fragen wird generiert
           // bool aw[antworten]; // Bool Array über die richtigkeit der Frage wird generiert

            for (int x = 0; x < antworten; x++) {             // Stütze um die Zeilen laden zu können
                
                getline(infile, a);

                if (a[0] == '$') {         // $ Signalisiert auch hier wieder ein "Befehl, hierbei, da eine Frage bereits erstellt wurde eine Antwort"
                    if (a[2] == '+') {     // Wenn nach dem $ ein + steht, so ist die Antwort richtig
                        fragen.aw[x] = true;
                        fragen.aw.push_back();
                    }
                    else if (a[2] == '-') {  // Wenn nach dem $ ein - steht, so ist die Antwort falsch
                        fragen.aw[x] = false;
                        fragen.aw.push_back();
                    } else {
                        cout << "Error 1"; // error
                    }
                    for (int y = 3; y < 900; y++) {  // Frage wird in string antwort geladen, bis diese durch ein erneutes $ beendet wird
                        if (a[y] != '$') {
                            fragen.antwort[x] = fragen.antwort[x] + a[y];






                        } else{
                            fragen.antwort.push_back();
                            break;  
                        }

                    }
                }
            }
            fragen.aw.erase(fragen.aw.size()-1);
            fragen.antwort.erase(fragen.antwort.size()-1);

            // Zum ausgeben der Werte, temporär zum debuggen
            cout << "Frage: " << fragen.frage << endl;
            cout << "Anzahl der Antworten: " << antworten << endl;
            for (int i = 0; i < antworten; i++) {
                cout << "Antwort " << i+1 << ": " << fragen.antwort[i] << " - Richtig: " << fragen.aw[i] << endl; 
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
int main (){
    read_question_file("Arrays/Bonus/1.txt");
    read_question_file("Fragen/Bonus/1.txt");
}