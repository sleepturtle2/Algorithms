#include<iostream> //cout
#include<numeric> //iota
#include<vector> //vector
#include<cstring> //memset

using namespace std; 
int main()
{
    //use of iota in array and vectors 
    int arr[10]; 
    iota(arr, arr+10, 0); 

    for(int i=0; i<10; i++)
    cout<<arr[i]<<" "; 
    cout<<endl; 
    //vector
    vector<int>v(10); 
    iota(v.begin(), v.end(), 10); //start from 10
    for(int el : v)
    cout<<el<<" "; 
    cout<<endl; 

    //fill array and vector
    vector<int>v2(10); 
    fill(v2.begin()+2, v2.end()-1, 2); //range is inclusive of start, exclusive of end
    for(int i : v2)
    cout<<i<<" "; 
    cout<<endl; 
    //array 
    int arr2[10]; 
    //format of memset = (pointer, initializer value 0 / -1 , sizeof(pointer var))
    memset(arr2, 0, sizeof(arr2)); //initialize 
    fill(arr2+1, arr2+7, 9); //start inclusive, end exclusive
    for(int i=0; i<10; i++)
    cout<<arr2[i]<<" "; 
    cout<<endl; 
}