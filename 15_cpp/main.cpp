#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
    srand((unsigned)time(NULL)); // seed rand → Zufallsgenerator mit den
    const int maxIndex = 250000; // Feldgroesse
    int array[maxIndex]; // Feld
    for (int i = 0; i < maxIndex; i++){
        array[i] = rand(); // Fülle Feld mit Zufallswerten
    }

    time_t vorher = time(NULL); // Startzeit in Sekunden

    double gap = maxIndex;
        bool swaps = true;

        while (gap > 1 || swaps)
        {
            gap /= 1.247330950103979;

            if (gap < 1)
                gap = 1;

            int i = 0;
            swaps = false;

            while (i + gap < maxIndex)
            {
                int igap = i + (int)gap;

                if (array[i] > array[igap])
                {
                    int temp = array[i];
                    array[i] = array[igap];
                    array[igap] = temp;
                    swaps = true;
                }

                ++i;
            }
        }

    time_t nachher = time(NULL); // Endezeit in Sekunden
    cout << "Gnome Sort brauchte " << nachher-vorher << " Sekunden" << endl;


    return 0;
}
