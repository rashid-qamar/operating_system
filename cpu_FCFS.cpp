#include<iostream> 
#include<algorithm>
using namespace std;

int main() {
	int n;
	cout << "Enter size: ";
	cin >> n;
	
	string name[100];
	int BT[n], AT[n];   				//For input
	int CT[n], TAT[n], WT[n];   		// For Output
	
	for(int i=0; i<n; i++) {
		cout << "Enter " << (i+1) << " name: ";
		cin >> name[i];
		
		cout << "Enter Burst time: ";
		cin >> BT[i];
		
		cout << "Enter Arrival time: ";
		cin >> AT[i];
		
		cout << "\n";
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
	
	CT[0] = AT[0] + BT[0];				//For Completetion time
    for(int i=1; i<n; i++) {
        CT[i] = max(CT[i-1], AT[i]) + BT[i];
    }
	
	int total_TAT=0;
	for(int i=0; i<n; i++) {		   //For TAT
		TAT[i] = CT[i] - AT[i];
		total_TAT += TAT[i];
	}
	float avg_TAT = (float)total_TAT/n;

	int total_waiting=0;
	for(int i=0; i<n; i++) {		   //For WT
		WT[i] = TAT[i] - BT[i];
		total_waiting += WT[i];
	}
	float avg_waiting = (float)total_waiting/n;
	
	cout << "Final Table \n";  				//Final Table
	cout << "Pro \tBT \tAT \tCT \tTAT \tWT\n";
	for(int i=0; i<n; i++) {
		cout << name[i] << "\t";
		cout << BT[i] << "\t";
		cout << AT[i] << "\t";
		cout << CT[i] << "\t";
		cout << TAT[i] << "\t";
		cout << WT[i] << "\t";
		cout << "\n";
	}
	cout << "\nAvg waiting time (FCFS): " << avg_waiting;
	cout << "\nAvg TAT (FCFS): " << avg_TAT;
}