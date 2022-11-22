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
    
    while (true);

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