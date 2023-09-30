#include<bits/stdc++.h>

using namespace std;

void adjust(int &milis,int &seconds, int &minutes, int &hours){
	if(milis >= 1000){
		seconds += (milis/1000);
		milis = milis%1000;
	}
	if(seconds >= 60){
		minutes += seconds/60;
		seconds = seconds%60;
	}
	if(minutes >= 60){
		hours += minutes/60;
		minutes = minutes%60;
	}
	return;
}

int main(){
	int n,sec,milis; scanf("%d %d.%d", &n, &sec, &milis);
 	while(n--){
		int id; cin >> id;
		//cout << "id=" << id << "\n";
		int hoursStart,minutesStart,secondsStart,milisStart;
		int hoursEnd,minutesEnd,secondsEnd,milisEnd;
		scanf("%d:%d:%d,%d --> %d:%d:%d,%d\n", &hoursStart, &minutesStart, &secondsStart, &milisStart, 
			&hoursEnd,&minutesEnd, &secondsEnd, &milisEnd);
		//cout << hoursStart << " " << minutesStart << " " << secondsStart << " " << milisStart << "\n";
		string line1="", line2="";
		getline(cin, line1);
		getline(cin, line2);
		//cout << "line1=" << line1 << "\n";
		//cout << "line2=" << line2 << "\n";
		milisStart += milis;
		secondsStart += sec;
		milisEnd += milis;
		secondsEnd += sec;
		adjust(milisStart, secondsStart, minutesStart, hoursStart);
		adjust(milisEnd, secondsEnd, minutesEnd, hoursEnd);

		cout << id << "\n";
		printf("%02d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d\n",hoursStart,minutesStart,secondsStart,milisStart,hoursEnd,minutesEnd,secondsEnd,milisEnd);
		cout << line1 << "\n";
		if(!line2.empty()) cout << line2 << "\n";
		cout << "\n";
	}

    return 0;
}
