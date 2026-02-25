#include<iostream> 
using namespace std;

int main() {
	int n;
	cout << "Enter size: ";
	cin >> n;
	
	string name[100];
	int BT[100];   							//For input
	int CT[100], TAT[100], WT[100];   		// For Output
	
	for(int i=0; i<n; i++) {
		cout << "Enter " << (i+1) << " name: ";
		cin >> name[i];
		
		cout << "Enter Burst time: ";
		cin >> BT[i];
		
		cout << "\n";
	}
	
	for(int i=0; i<n-1; i++) {           //Gantt chart (Arranging)
		for(int j=i+1; j<n; j++) {
			if(BT[i] > BT[j]) {
				swap(BT[i], BT[j]);
				swap(name[i], name[j]);
			}
		}
	}
	
	CT[0] = BT[0];				//For Completetion time
    for(int i=1; i<n; i++) {
        CT[i] = CT[i-1] + BT[i];
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
	
	cout << "Final Table \n";  				//Final Table
	cout << "Pro \tBT \tCT \tTAT \tWT\n";
	for(int i=0; i<n; i++) {
		cout << name[i] << "\t";
		cout << BT[i] << "\t";
		cout << CT[i] << "\t";
		cout << TAT[i] << "\t";
		cout << WT[i] << "\t";
		cout << "\n";
	}
	cout << "\nAvg waiting time (SJF): " << avg_waiting;
	cout << "\nAvg TAT (SJF): " << avg_TAT;
}