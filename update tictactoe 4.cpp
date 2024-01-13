#include <iostream>
#include <iomanip>
using namespace std;

void drawBoard(char board[3][3]) {
	cout << endl;
    cout << "======================= "<< endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "||  " << board[0][0] << "  ||  " << board[0][1] << "  ||  " << board[0][2] << "  ||" << endl;
    cout << "||     ||     ||     ||" << endl;
	cout << "||=====||=====||=====||" << endl;
	cout << "||     ||     ||     ||" << endl;
    cout << "||  " << board[1][0] << "  ||  " << board[1][1] << "  ||  " << board[1][2] << "  ||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "||=====||=====||=====||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "||  " << board[2][0] << "  ||  " << board[2][1] << "  ||  " << board[2][2] << "  ||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "======================= "<< endl;
    cout << endl;
}

bool isValidMove(char board[3][3], int choice) {
    if (choice < 1 || choice > 9) {
        cout << "Pilihan tidak valid. Silakan pilih angka antara 1 hingga 9." << endl;
        return false;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '0' + choice) {
                return true;
            }
        }
    }

    cout << "Kotak sudah terisi. Silakan pilih kotak lain." << endl;
    return false;
}

void placeMark(char board[3][3], int choice, char mark) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '0' + choice) {
                board[i][j] = mark;
                return;
            }
        }
    }
}

int main() {
    int k;
    string nama, kls;
    long long nim;
    
    cout << "NAMA : " ;
    getline(cin,nama);
    cout << "NIM  : " ;
    cin>>nim;
    cout << "KELAS: " ;	
	cin>>kls;
	system("cls");
	
    cout << "====================================================" << endl;
    cout << "||       SELAMAT DATANG DI GAME TIC TAC TOE       ||" << endl;
    cout << "====================================================" << endl;
    cout<<endl;
    
	cout<<"NAMA  : "<<nama<<endl;
	cout<<"NIM   : "<<nim<<endl;
	cout<<"KELAS : "<<kls<<endl;
		
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player = 1;
    int choice;
    char mark;
    bool draw = false;

    do {
        // Menampilkan papan permainan
        drawBoard(board);

        // Meminta pemain untuk memilih nomor kotak
        cout << "Player " << player << ", Pilih nomor kotak: ";
        cin >> choice;

        // Validasi input pemain
        if (!isValidMove(board, choice)) {
            continue;
        }

        // Menentukan simbol pemain
        mark = (player == 1) ? 'X' : 'O';

        // Menempatkan simbol pada kotak yang dipilih
        placeMark(board, choice, mark);

        // Menentukan pemenang
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
                cout << "Player " << player << " menang! SELAMAT!!!" << endl;
                return 0;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
                cout << "Player " << player << " menang! SELAMAT!!!" << endl;
                return 0;
            }
        }

        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
            (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
            cout << "Player " << player << " menang! SELAMAT!!!" << endl;
            return 0;
        }

        // Memeriksa jika permainan seri
        draw = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    draw = false;
                    break;
                }
            }
            if (!draw) break;
        }

        // Ganti giliran pemain
        player = (player == 1) ? 2 : 1;

// untuk permainan seri 
    } while (!draw);

    if (draw) {
        cout << "Permainan seri!" << endl;
    }

    return 0;
}

