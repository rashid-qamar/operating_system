#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    string name[100];
    int AT[100], BT[100];
    int CT[100], TAT[100], WT[100];
    int quantum;

    cout << "Enter Quantum: ";
    cin >> quantum;

    for(int i=0; i<n; i++) {
        cout << "\nEnter " << (i+1) << " name: ";
        cin >> name[i];

        cout << "Enter AT: ";
        cin >> AT[i];

        cout << "Enter BT: ";
        cin >> BT[i];
    }

    for(int i=0; i<n; i++) {           //Gantt chart (Arranging)
		for(int j=i; j<n; j++) {
			if(AT[i] > AT[j]) {
				swap(AT[i], AT[j]);
				swap(name[i], name[j]);
				swap(BT[i], BT[j]);
			}
		}
	}

    int CT_count=0;
    int BT1[100];                   //Copying BT 
    for(int i = 0; i < n; i++) {
        BT1[i] = BT[i];
    }

    bool done;
    while(true) {
        done = true;

        for(int i = 0; i < n; i++) {
            if(BT1[i] > 0) {
                done = false;

                if(BT1[i] > quantum) {
                    CT_count += quantum;
                    BT1[i] -= quantum;
                } 
                else {
                    CT_count += BT1[i];
                    CT[i] = CT_count;  
                    BT1[i] = 0;
                }
            }
        }

        if(done)
            break;
    }

    int total_TAT=0;
	for(int i=0; i<n; i++) {		   //For TAT
		TAT[i] = CT[i];
		total_TAT += TAT[i];
	}
	float avg_TAT = (float)total_TAT/n;

	int total_waiting=0;
	for(int i=0; i<n; i++) {		   //For WT
		WT[i] = TAT[i] - BT[i];
		total_waiting += WT[i];
	}
	float avg_waiting = (float)total_waiting/n;

    cout << "\nFinal Table \n";  				//Final Table
	cout << "Pro \tBT \tCT \tTAT \tWT\n";
	for(int i=0; i<n; i++) {
		cout << name[i] << "\t";
		cout << BT[i] << "\t";
		cout << CT[i] << "\t";
		cout << TAT[i] << "\t";
		cout << WT[i] << "\t";
		cout << "\n";
	}
	cout << "\nAvg waiting time (RR): " << avg_waiting;
	cout << "\nAvg TAT (RR): " << avg_TAT;

}