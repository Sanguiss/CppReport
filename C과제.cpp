#include<iostream>
#include<ctime>
#include<cstdlib>
#include <windows.h>
using namespace std;

int range = 45;
int num = 6;
int money = 5000; 
int rotation = 100;

int numbers[50] = {};
void Initialize(){
	srand(time(0));
	for(int i = 0; i<50; i++){
		numbers[i] = i+1;
	}
	
}


void bubble(int target[]){
	for(int i = num; i>0; i--){
		for(int j = 1; j<i; j++){
			if(target[j]<target[j-1]){
				int temp = target[j];
				target[j] = target[j-1];
				target[j-1] = temp;
			}
		}
	}
	
}

void MyShuffle(int target[]){
	
	for(int i = 0; i<num; i++){
		target[i] = 0;
	}
	
	
	int temp = 0;
	while(temp!=num+1){
		int randnum = rand()%range+1;
		int i;
		for(i = 0; i < temp; ++i){
			if(randnum==target[i])break;
			
		}
		if(i!=temp) continue;
		else target[temp] = randnum;
		temp++;
	}
	bubble(target);
}

void Shuffle(int count){
	srand(time(0));
	
	for(int i = 0; i < count; i++){
		int n0 = rand()%range+1;
		int n1 = rand()%range+1;
		
		int temp = numbers[n0];
		numbers[n0] = numbers[n1];
		numbers[n1] = temp;
		
	}
}


void MyPrint(int target[], string text){
	cout << text;
	for(int i = 0; i<num; i++){
		cout << target[i] << " ";
	}
	cout << endl;
	
}


bool Answer(string text){
	cout << text;
	char answer;
	cin >> answer;
	
	return (answer == 'y' || answer == 'Y');
}

int Compare(int target[], int goal[]){
	int count=0;
	for(int i = 0; i<num; i++){
		for(int j = 0; j<num; j++){
			if(target[j]>goal[i]) break;
			else if(target[j]==goal[i]){
				count++;
				break;
			}
		}
	}
	return count;
}

void Configure(){
	cout << "�ζǹ�ȣ�� ����:";
	cin >> range;
	cout << "�ζǹ�ȣ�� ��:";
	cin >> num;
	cout << "�ζ� �Ǵ� �ݾ�:";
	cin >> money;
	cout << "�ݺ� Ƚ��:";
	cin >> rotation;
}





int main(){
	clock_t start, end;
	if(Answer("�ζ� �⺻ ������ �ٲٽðڽ��ϱ�?(Y/N)")){
		Configure();
	} 
	
	
	int mynumbers[num] = {};
	int mygoal[num] = {};
	int prize[num+1] = {0,};
	MyShuffle(mygoal);
	int totaltry = 0;
	while(Answer("�ζǹ�ȣ�� �����ðڽ��ϱ�?(Y/N)")){
		start = clock();
		for(int i = 0; i<100; i++){
			MyShuffle(mynumbers);
			MyPrint(mynumbers, "�ζ� ��ȣ:");
			int prizetemp = Compare(mynumbers, mygoal);
			if(prizetemp==0) prizetemp = num;
			else prizetemp--;
			prize[prizetemp]++;
			totaltry++;
			if(totaltry%1000==0) system("cls");
		}
		end = clock();
		double result = (double)(end - start);
		MyPrint(mygoal, "��÷ ��ȣ:");
		MyPrint(prize, "��÷ ���:");
		cout << "�ش��ȣ ����:"<<prize[num]<<endl;
		cout << "�� Ƚ��:"<<totaltry<<endl;
		cout << "��� �ݾ�:"<<totaltry*money<<endl;
		cout << "����ð�:"<<result<<"ms"<<endl;
	}
}
