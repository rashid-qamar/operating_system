#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    string name[100];
    int AT[100], BT[100], RT[100];
    int CT[100], TAT[100], WT[100];

    for(int i = 0; i < n; i++) {
        cout << "\nEnter " << (i+1) << " name: ";
        cin >> name[i];

        cout << "Enter AT: ";
        cin >> AT[i];

        cout << "Enter BT: ";
        cin >> BT[i];

        RT[i] = BT[i];   // Remaining Time
    }

    int completed = 0, time = 0;
    int minRT, idx;
    bool found;

    while(completed != n) {
        minRT = INT_MAX;
        found = false;

        for(int i = 0; i < n; i++) {
            if(AT[i] <= time && RT[i] > 0 && RT[i] < minRT) {
                minRT = RT[i];
                idx = i;
                found = true;
            }
        }

        if(!found) {
            time++;   // CPU idle
            continue;
        }

        // Execute process for 1 unit
        RT[idx]--;
        time++;

        // If process finished
        if(RT[idx] == 0) {
            CT[idx] = time;
            completed++;
        }
    }

    int total_TAT = 0, total_WT = 0;

    for(int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        total_TAT += TAT[i];
        total_WT += WT[i];
    }

    cout << "\nFinal Table\n";
    cout << "Pro \tAT \tBT \tCT \tTAT \tWT\n";
    for(int i = 0; i < n; i++) {
        cout << name[i] << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << CT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << "\n";
    }

    cout << "\nAvg WT (SRTF): " << (float)total_WT / n;
    cout << "\nAvg TAT (SRTF): " << (float)total_TAT / n;
}
