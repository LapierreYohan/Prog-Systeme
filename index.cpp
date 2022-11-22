#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;
//g++ -o index.exe index.cpp

int main(int argc, char const *argv[])
{
    /**
     * Partie 1 du TP01
    */
    cout << getpid() << endl;
    cout << getppid() << endl;

    /**
     * Partie 2 du TP01
    */

    int nb = 0;
    cout << "Entrez un nombre de processus entre 0 et 10 : ";
    cin >> nb;
    cout << endl;

    if (nb < 0 || nb > 10) {
        cout << "Tu sais pas lire ou quoi ??" << endl;
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    int seconde = 0;
    int id = 0;

    for (int i = 0; i < nb; i++) {
        if (pid > 0) {
            pid = fork();
            seconde = rand() * 21;
            id = i + 1;
        }
    }

    switch (pid)
    {

    case -1:

        perror("Erreur de creation du processus : ");
        exit(EXIT_FAILURE);
        break;
    /*
    case 0:

        cout << "---------------------" << endl;
        cout << "Processus fils" << endl;
        cout << "PID :" << getpid() << endl;
        cout << "PPID :" << getppid() << endl;
        cout << "---------------------" << endl;
        break; */

    default:
        sleep(seconde);
        cout << "---------------------" << endl;
        cout << "Processus : " << id << endl;
        cout << "PID : " << getpid() << endl;
        cout << "PPID : " << getppid() << endl;
        cout << "Secondes : " << seconde << endl;
        cout << "---------------------" << endl;
        wait(NULL);
        break;
    }

    return EXIT_SUCCESS;
}