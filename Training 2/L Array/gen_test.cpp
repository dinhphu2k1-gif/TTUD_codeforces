#include <bits/stdc++.h>

using namespace std;

int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}

int main(){
    freopen("input.txt", "w", stdout);
    int n = rand() % 100 + 1;
    int arr[105];
    cout << n << endl;

    for (int i = 0; i < n; i++){
        arr[i] = random(-1000, 1000);
    }
    int index;  
    for (int i = 0; i < n/10; i++){
        index = rand() % 100 + 1;
        arr[index] = 0;
    }
    for (int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }

    fclose(stdout);
    return 0;
}