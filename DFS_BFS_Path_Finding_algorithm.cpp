#include <iostream>
#include <array>
#include <stack>
#include <queue>
using namespace std;

int database[8][8] = {{0,3,4,0,0,0,0,0},{3,0,5,4,5,4,2,0},{4,5,0,0,3,0,3,0},{0,4,0,0,4,0,0,4},{0,5,3,4,0,5,4,0},{0,4,0,0,5,0,0,0},{0,2,3,0,4,0,0,1},{0,0,0,4,0,0,1,0}};
array<int,8> parent = {0,0,0,0,0,0,0,0};
array<int,8> cost = {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX}; //it gives the maximum possible number to the int.
stack <int> stack1;
queue <int> queue1;
int i =0;
int reply=0;

int main() {
    int source;
    int target;
    int curr;

    cout<<"   0 1 2 3 4 5 6 7 "<<endl;
    cout<<"0 {0,3,4,0,0,0,0,0}"<<endl;
    cout<<"1 {3,0,5,4,5,4,2,0}"<<endl;
    cout<<"2 {4,5,0,0,3,0,3,0}"<<endl;
    cout<<"3 {0,4,0,0,4,0,0,4}"<<endl;
    cout<<"4 {0,5,3,4,0,5,4,0}"<<endl;
    cout<<"5 {0,4,0,0,5,0,0,0}"<<endl;
    cout<<"6 {0,2,3,0,4,0,0,1}"<<endl;
    cout<<"7 {0,0,0,4,0,0,1,0}"<<endl;


    cout<<"input the source "<<endl;
    cin>>source;
    cout<<"input the target "<<endl;
    cin>>target;

    cout<<endl<<" CHOOSE YOUR PATH FINDING ALGORITHM "<<endl;
    cout<<" 1. Depth first search   2. Breadth first search "<<endl;
    cin>>reply;
    if(reply=1){
        cost[source] =0;
        stack1.push(source);
        while(!stack1.empty()){
            curr = stack1.top(); stack1.pop();
            if(curr != target)
                for(int neigh = 0; neigh < 8; neigh++){
                    if(database[curr][i] != 0){
                        if (cost[neigh] > (cost[curr] + database[curr][neigh])){
                            cost[neigh] = cost[curr] + database[curr][neigh];
                            parent[neigh] = curr;
                            stack1.push(neigh);
                        }
                    }
                    ++i;
                }
        }
        curr = target;
    }
    else{
        cost[source] =0;
        queue1.push(source);
        while(!queue1.empty()){
            curr = queue1.front(); queue1.pop();
            if(curr != target)
                for(int neigh = 0; neigh < 8; neigh++){
                    if(database[curr][i] != 0){
                        if (cost[neigh] > (cost[curr] + database[curr][neigh])){
                            cost[neigh] = cost[curr] + database[curr][neigh];
                            parent[neigh] = curr;
                            queue1.push(neigh);
                        }
                    }
                    ++i;
                }
        }
        curr = target;
    }

    cout<<"-------------------------------------"<<endl;
    std::cout << curr << " ";
    while (curr != source) {
        curr = parent[curr];
        std::cout << curr << " ";
    }
    std::cout << "TOTAL COST IS : "<< cost[target] <<endl;
    return 0;
}
