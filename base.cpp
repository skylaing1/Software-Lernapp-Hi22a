#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;


int main()
{
	srand(time(NULL));

	
	string fragea[6] = { "Frage: 1.2.01", "Die Teilnahme am Stra\341enverkehr erfordert st\204ndige Vorsicht und gegenseitige R\201cksicht.Was bedeutet das f\201r Sie ? ", "A- Vorausschauend fahren", "B- In jedem Fall auf Ihrem Vorfahrtrecht bestehen", "C- Mit Fehlverhalten anderer rechnen", "A,C"};

	string frageb[6] = { "Frage: 1.2.19-003", "Sie n\204hern sich einem Bahn\201bergang mit Blinklichtanlage und Halbschranke. Das rote Blinklicht leuchtet auf; die Halbschranke ist noch ge\224ffnet. Wie verhalten Sie sich?", "A- Vor dem Andreaskreuz warten", "B- Weiterfahren, solange die Halbschranke noch geoeffnet ist", "C- Den Bahnuebergang ueberqueren, wenn kein Schienenfahrzeug in Sicht ist", "A"};

	string fragec[6] = { "Frage: 1.2.12 - 103", "Wo ist das Halten verboten?", "A- An Taxenst\204nden", "B- Auf der Fahrbahn, wenn rechts ein geeigneter Seitenstreifen vorhanden ist", "C- Auf markierten Fahrstreifen mit Richtungspfeilen", "A,B,C"};


	struct frage {
		string ueber;
		string frage;
		string a;
		string b;
		string c;
		string antwort;
	} frage1, frage2, frage3;
	
	frage1.ueber = fragea[0];
	frage1.frage = fragea[1];
	frage1.a = fragea[2];
	frage1.b = fragea[3];
	frage1.c = fragea[4];
	frage1.antwort = fragea[5];

	frage2.ueber = frageb[0];
	frage2.frage = frageb[1];
	frage2.a = frageb[2];
	frage2.b = frageb[3];
	frage2.c = frageb[4];
	frage2.antwort = frageb[5];

	frage3.ueber = fragec[0];
	frage3.frage = fragec[1];
	frage3.a = fragec[2];
	frage3.b = fragec[3];
	frage3.c = fragec[4];
	frage3.antwort = fragec[5];

	string start;
	int Fertig = 0;
	bool frage1_dran = false;
	bool frage2_dran = false;
	bool frage3_dran = false;
	string antwort;
	int punkte = 0;
	string wiederholen;

	cout << "F\201hrerschein-Test" << endl << endl << "Geben Sie die Antworten in dem Format A,B,C an" << endl << endl << "Um fortzufahren, schreiben Sie 'Start' und dr\201cken Sie die Enter-Taste" << endl << endl;
	cin >> start;

	do {
		Fertig = 0;
		punkte = 0;
		frage1_dran = false;
		frage2_dran = false;
		frage3_dran = false;
		while (Fertig < 3) {
			int frageauswahl = rand() % 3;

			if (frageauswahl == 0 && frage1_dran == false) {
				cout << endl << endl << endl << frage1.ueber << endl << endl << frage1.frage << endl << endl << frage1.a << endl << frage1.b << endl << frage1.c << endl << endl << endl << "Antwort: ";
				cin >> antwort;

				if (antwort == frage1.antwort)
				{
					cout << endl << endl << "Ihre Antwort ist korrekt!" << endl << endl << endl;
					punkte += 1;
				}
				else {
					cout << endl << endl << "Ihre Antwort ist falsch!" << endl << endl << endl;
				}

				Fertig += 1;
				frage1_dran = true;
			}

			if (frageauswahl == 1 && frage2_dran == false) {
				cout << endl << endl << endl << frage2.ueber << endl << endl << frage2.frage << endl << endl << frage2.a << endl << frage2.b << endl << frage2.c << endl << endl << endl << "Antwort: ";
				cin >> antwort;

				if (antwort == frage2.antwort)
				{
					cout << endl << endl << "Ihre Antwort ist korrekt!" << endl << endl << endl;
					punkte += 1;
				}
				else {
					cout << endl << endl << "Ihre Antwort ist falsch!" << endl << endl << endl;
				}

				Fertig += 1;
				frage2_dran = true;
			}

			if (frageauswahl == 2 && frage3_dran == false) {
				cout << endl << endl << endl << frage3.ueber << endl << endl << frage3.frage << endl << endl << frage3.a << endl << frage3.b << endl << frage3.c << endl << endl << endl << "Antwort: ";
				cin >> antwort;

				if (antwort == frage3.antwort)
				{
					cout << endl << endl << "Ihre Antwort ist korrekt!" << endl << endl << endl;
					punkte += 1;
				}
				else {
					cout << endl << endl << "Ihre Antwort ist falsch!" << endl << endl << endl;
				}

				Fertig += 1;
				frage3_dran = true;
			}
			if (Fertig == 3) {
				cout << endl << endl << endl << endl << "Sie haben " << punkte << " von 3 Fragen richtig beantwortet" << endl << endl << endl << endl << endl;
				cout << "Test Wiederholen? (Ja/Nein) ";
				cin >> wiederholen;
			
			}
		}
		
	} while (wiederholen == "Ja"||"JA"||"ja"||"jA");
	
