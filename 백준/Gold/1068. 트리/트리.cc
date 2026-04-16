#include <iostream>
#include <vector>

using namespace std;

vector <int> tree;

int n = 0;
int deleteNum = 0;
int leafCnt = 0;

void DeleteCnt(int node)
{   
    //printf("[%d] ",node);
    if(tree[node] == -2)
        return;

    tree[node] = -2;    
    for(int i = 0; i <n; i++)
    {
        if(tree[i] == node)
        {
            DeleteCnt(i);
        }    
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0; i < n; i++)        
    {
        int parent = 0;

        cin >> parent;

        tree.push_back(parent);
    }



    cin >> deleteNum;

    DeleteCnt(deleteNum);

    //cout << "\n";

    for(int i=0; i < n; i++)        
    {
        int flag = 0;
        if(tree[i] == -2)
            continue;
        
        for(int j = 0; j < n; j++)
        {
            if(i == tree[j])
                flag = 1;
        }

        if(flag == 0)
            leafCnt++;
    }

    cout << leafCnt <<"\n";

    return 0;
}