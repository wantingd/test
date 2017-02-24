#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int partitionIn(int num[], int left, int right);

int main(){
	int type, n;
	cin >> type;
	cin >> n;
	int num[n];
	int piv=0;
	int abc;
	int i,j;
	for(i=0; i<n; i++) { cin >> num[i];}
	if(type == 5) piv = partitionIn(num, 0, n-1);
	if(type == 4) abc = partitionIn(num, 0, n-1);
	for(i=0; i<n; i++) { cout << num[i] << endl; }
	cout << piv << abc << endl;
	return 0;
}

int partitionIn(int num[], int left, int right){
	int piv=left;
	int i, j, temp;
	i = left+1;
	j = right;
	while(1){
		while(num[piv] > num[i]) i++;
		while(num[piv] <= num[j]) j--;
		if( i < j ){
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
		}
		else{
			temp = num[piv];
			num[piv] = num[j];
			num[j] = temp;
			break;
		}
	}
	return j;
}

