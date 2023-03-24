#include<bits/stdc++.h>
using namespace std;

// Function to perform left shift
void leftShift(int *key,int times,int l,int r)
{
    for(int i=0;i<times;i++)
    {
        int t=key[0];
        for(int j=l;j<r-1;j++)
        {
            key[j]=key[j+1];
        }
        key[r-1]=t;
    }
}

void keyGenerator(int *key,int *P10,int *P8,vector<vector<int>> & subkeys)
{
    // Since array index start from 0 wo subtract 1 from every value of P10
    for(int i=0;i<10;i++)
    {
        P10[i]=P10[i]-1;
    }

    // Since array index start from 0 wo subtract 1 from every value of P8
    for(int i=0;i<8;i++)
    {
        P8[i]=P8[i]-1;
    }

    // Copying key content to temporary array
    int temp[10];
    for(int i=0;i<10;i++)
    {
        temp[i]=key[i];
    }

    // Performing P10 permutation on key
    for(int i=0;i<10;i++)
    {
        key[i]=temp[P10[i]];
    }

    // Dividing key into 5 bits each
    int left[5],right[5];
    for(int i=0;i<5;i++)
    {
        left[i]=key[i];
    }
    for(int i=5,j=0;i<10;i++)
    {
        right[j]=key[i];
        j++;
    }

    //  Performing left shift (LS1) on first and last 5 bits of key
    leftShift(left,1,0,5);
    leftShift(right,1,0,5);

    //Combining left and right key bits together
    for(int i=0,j=5;i<5;i++,j++)
    {
        key[i]=left[i];
        key[j]=right[i];
    }

    //  Declaring vectors for storing subkeys
    vector<int> K1(8);
    vector<int> K2(8);

    // Using P8 permutation generating K1 key
    
    for(int i=0;i<8;i++)
    {
        K1[i]=key[P8[i]];
    }

    //  Performing left shift (LS2) on first and last 5 bits of key
    leftShift(left,2,0,5);
    leftShift(right,2,0,5);

    //Combining left and right key bits together
    for(int i=0,j=5;i<5;i++,j++)
    {
        key[i]=left[i];
        key[j]=right[i];
    }

    // Using P8 permutation generating K2 key
    for(int i=0;i<8;i++)
    {
        K2[i]=key[P8[i]];
    }

    //Storing k1 and k2 in subkeys vector
    subkeys.push_back(K1);
    subkeys.push_back(K2);
}

int main()
{
    int key[10];
    cout<<"Enter key "<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"Enter "<<(i+1)<<" bit (0/1) "<<"from left side: ";
        cin>>key[i];
        if(key[i]<0 || key[i]>1)
        {
            cout<<"You have entered wrong input please enter 1 or 0 :\n";
            i=-1;
            continue;
        }
    }
    int P10[] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
    int P8[] = { 6, 3, 7, 4, 8, 5, 10, 9 };
    vector<vector<int>> subkeys(2);
    keyGenerator(key,P10,P8,subkeys);
    for(auto i:subkeys)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}