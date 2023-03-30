#include <iostream> 
#include <string>
#include <algorithm> 

using namespace std;

struct Siswa {
    string nama;
    string password;
    int nilai[5];
    float rataRata;
    int nilaiMax;
    int nilaiMin;
};

bool sortByRataRataAsc(const Siswa& a, const Siswa& b) {
    return a.rataRata < b.rataRata;
}

bool sortByRataRataDesc(const Siswa& a, const Siswa& b) {
    return a.rataRata > b.rataRata;
}

int main() {
    Siswa siswa[3] = {
        {"Andi", "andi12345", {70, 83, 80, 92, 82}},
        {"Fina", "fina12345", {70, 82, 91, 95, 88}},
        {"Budi", "budi12345", {70, 73, 90, 79, 78}}
    };

    bool isLoginValid = false;
    do{
        string username, password;
        cout << "----- LOGIN -----\n";
        cout << "Username  : ";
        cin >> username;
        cout << "Password  : ";
        cin >> password;
        cout << "---------------------" << endl;

        if (username == "walas" && password == "12345") {
            isLoginValid = true;
            for (int i = 0; i < 3; i++) {
                float total = 0;
                for (int j = 0; j < 5; j++) {
                    total += siswa[i].nilai[j];
                }
                siswa[i].rataRata = total / 5;

            cout << "\nData nilai " << siswa[i].nama << endl;
            cout << "  | Matematika       Nilai = " << siswa[i].nilai[0] <<"   |"<< endl;
            cout << "  | Fisika           Nilai = " << siswa[i].nilai[1] <<"   |"<< endl;
            cout << "  | Bahasa Indonesia Nilai = " << siswa[i].nilai[2] <<"   |"<< endl;
            cout << "  | English          Nilai = " << siswa[i].nilai[3] <<"   |"<< endl;
            cout << "  | OOP              Nilai = " << siswa[i].nilai[4] <<"   |"<< endl;
            cout << "Rata-rata nilai: " << siswa[i].rataRata<< endl;            
            }
            
			int k;
			for(k=0; k<5;k++){
				if (k <=5){
            int filter;
            cout << " " << endl;
            cout << "=================================================" << endl;
            cout << "\nSorting nilai murid berdasarkan rata-rata:\n";
            cout << "   1.Ascending\n";
            cout << "   2.Descending\n";
            cout << "   3.Logout\n";
            cout << "Masukan pilihan anda: ";
            cin >> filter;

            if (filter == 1) {
                sort(siswa, siswa+3, sortByRataRataAsc);
            } else if (filter == 2) {
                sort(siswa, siswa+3, sortByRataRataDesc);
            } else if (filter == 3) {
            	cout <<"\n\nAnda Telah Keluar Program"<<endl;
            	return 0;
			}

            cout << "\nData siswa setelah difilter:\n";
            for (int i = 0; i < 3; i++) {
                cout <<"   " <<siswa[i].nama<< " dengan rata-rata nilai: " << siswa[i].rataRata << endl;
            }
            }
        }
        } else {
        	 isLoginValid = true;
            for (int i = 0; i < 3; i++) {
			if(username == siswa[i].nama && password == siswa[i].password){
                float total = 0;
                for (int j = 0; j < 5; j++) {
                    total += siswa[i].nilai[j];
                }
                siswa[i].rataRata = total / 5;
                
                
            int maxNilai = siswa[i].nilai[0];
            int minNilai = siswa[i].nilai[0];
            for (int j = 1; j < 5; j++) {
                if (siswa[i].nilai[j] > maxNilai) {
                    maxNilai = siswa[i].nilai[j];
                }
                if (siswa[i].nilai[j] < minNilai) {
                    minNilai = siswa[i].nilai[j];
                }
            }
            siswa[i].nilaiMax = maxNilai;
            siswa[i].nilaiMin = minNilai;


            cout << "\nWelcome " << siswa[i].nama << "!" << endl;
            cout << "Berikut adalah nilai kamu: " << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "  | Matematika       Nilai = " << siswa[i].nilai[0] <<"   |"<< endl;
            cout << "  | Fisika           Nilai = " << siswa[i].nilai[1] <<"   |"<< endl;
            cout << "  | Bahasa Indonesia Nilai = " << siswa[i].nilai[2] <<"   |"<< endl;
            cout << "  | English          Nilai = " << siswa[i].nilai[3] <<"   |"<< endl;
            cout << "  | OOP              Nilai = " << siswa[i].nilai[4] <<"   |"<< endl;
            cout << " " <<endl;
            cout << "  | Rata-rata nilai        = " << siswa[i].rataRata<<"    |" << endl;    
            cout << "  | Nilai maksimum         = " << siswa[i].nilaiMax<<"    |" << endl;
            cout << "  | Nilai minimum          = " << siswa[i].nilaiMin<<"    |" << endl;
			break;        
            }
		}
}
        if (!isLoginValid) {
        cout << "Login gagal, username atau password salah\n" << endl;
    }
}while(!isLoginValid);
	return 0;
}

