#include <bits/stdc++.h>
using namespace std;

class edges {
    public:
    int source, dest, weight;
};

bool comp (edges a, edges b) { return a.weight < b.weight;}

int findPar(int v, vector<int>& parent) { 
    if(v == parent[v]) return v;
    return parent[v] = findPar(parent[v], parent);
}

void kruskals(vector<edges>& input, int n, int e) {
    sort(input.begin(), input.end(), comp);
    vector<edges> output(n-1);

    vector<int> parent(n);
    for(int i = 0; i < n; i++) parent[i] = i;

    int count = 0;
    for(int i = 0; count != n - 1; i++) {
        edges currEdge = input[i];

        int parSource = findPar(currEdge.source, parent);
        int parDest = findPar(currEdge.dest, parent);

        if(parSource != parDest) {
            output[count] = currEdge;
            parent[parSource] = parDest;
            count++;
        }
    }

    //printing minimum wt
    for(int i = 0; i < n-1; i++) {
        if (output[i].source < output[i].dest) {
			cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
		}
		else {
			cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
		}
    }
}

int main()
{
    
    int n, e;
    cin >> n >> e;
    vector<edges> input(e);

    for(int i = 0; i < e; i++) {
        int s, d, wt;
        cin >> s >> d >> wt;

        input[i].source = s;
        input[i].dest = d;
        input[i].weight = wt;
    }
    
    kruskals(input, n, e);
    
    return 0;
}
