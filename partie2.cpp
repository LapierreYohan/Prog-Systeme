#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

using namespace std;
//g++ -o index.exe index.cpp

void handler(int sig);

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

    pid_t pid = 1;
    int seconde = rand() % 21;
    int id = 0;

    for (int i = 0; i < nb; i++) {
        if (pid > 0) {
            pid = fork();
            seconde = rand() % 21;
            id = i + 1;
        }
    }

    switch (pid)
    {

    case -1:

        perror("Erreur de creation du processus : ");
        exit(EXIT_FAILURE);
        break;
    
    case 0:
        //Fils
        sleep(seconde);
        cout << "---------------------" << endl;
        cout << "Processus : " << id << endl;
        cout << "PID : " << getpid() << endl;
        cout << "PPID : " << getppid() << endl;
        cout << "Secondes : " << seconde << endl;
        cout << "---------------------" << endl;
        
        break; 

    default:
        //Pere
        sleep(seconde);
        cout << "---------------------" << endl;
        cout << "Processus : " << id << endl;
        cout << "PID : " << getpid() << endl;
        cout << "PPID : " << getppid() << endl;
        cout << "Secondes : " << seconde << endl;
        cout << "---------------------" << endl;
        for (int i = 0; i<nb; i++) {
            wait(NULL);
        }
        break;
    }

    /**
     * Partie 3 du tp01
    */

    int i ;
    for ( i =1; i < NSIG ; i ++)
        if (i!= 9 | i !=19) {
            signal (i, handler);
        }
    for ( i =1; i < NSIG ; i ++)
        if (i!= 9 || i !=19) {
            raise ( i );
        }
    return EXIT_SUCCESS;
}

void handler(int sig) {
    cout << "Recu signal " << sig << " " << sys_siglist[sig] << endl;
    if (sig == SIGUSR1) {
        cout << "Bonjour" << endl;
    } else if ( sig == SIGUSR2) {
        cout << "Bonsoir" << endl;
    }
    return;
}