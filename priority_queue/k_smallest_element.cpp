#include<queue>
#include<vector>
#include<iostream>



using namespace std;




vector<int> kSmallest(int *input, int n, int k){

    priority_queue<int> pq;
    vector<int> output;

    int i =0;
    for(i=0;i<k;i++)
        pq.push(input[i]);

    for(; int i<n; i++)
    {
        if(input[i] < pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }

    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }

    return output;
}


int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> output = kSmallest(input, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
}
