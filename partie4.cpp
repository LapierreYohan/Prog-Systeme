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
    cout << getpid() << endl;
    cout << getppid() << endl;

    signal (SIGUSR1, handler);
    signal (SIGUSR2, handler);


    pid_t pid = fork();

     switch (pid)
    {

    case -1:

        perror("Erreur de creation du processus : ");
        exit(EXIT_FAILURE);
        break;
    
    case 0:
        cout << "---------------------" << endl;
        cout << "Processus fils" << endl;
        cout << "PID :" << getpid() << endl;
        cout << "PPID :" << getppid() << endl;
        cout << "---------------------" << endl;
        sleep(1);
        cout << "je vais kill mon pere ok ca te vas yo56han"<< endl;
        kill(getppid(), SIGUSR1);
        cout << "j'ai kill mon pere ok ca te vas yo56han"<< endl;
        break;

    default:
        cout << "---------------------" << endl;
        cout << "Processus : Pere" << endl;
        cout << "PID : " << getpid() << endl;
        cout << "PPID : " << getppid() << endl;
        cout << "---------------------" << endl;
        cout << "le daron est mis en attente au bout du fil veulliez patienter (*musique d'assenseur*)"<< endl;
        pause();
        cout << "le darons à fini sa pause"<< endl;
        cout << "mise en wait" << endl;
        wait(NULL);
        cout << "fin de wait" << endl;
        break;
    }

    return EXIT_SUCCESS;
}

void handler(int sig) {
    cout << "Recu signal " << sig << " " << sys_siglist[sig] << endl;
    if (sig == SIGUSR1) { // Signal 10
        cout << "Bonjour" << endl;
    } else if ( sig == SIGUSR2) { // Signal 12
        cout << "Bonsoir" << endl;
    }
    return;
}

