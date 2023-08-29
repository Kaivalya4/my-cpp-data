#include<iostream>
#include<cmath>

using namespace std;

int heap[100];
int n;
int sizes = -1;

void Push()
{
    cout << "Enter the value to be pushed( enter -1 to exit) : ";
    int val ;
    cin >> val;
    while(val != -1)
    {
        if(sizes == n-1)
        {
            cout << "Overflow!! " << val << "can't be pushed." << endl;
            break;
        }
        heap[++sizes] = val;
        int i = sizes;
        ///Percolate up Algorithm- moving small value up
        /// value inserted is less than its parent or grandparent......
        ///see we just comparison sign
        while(i >0 && (heap[i] < heap[(int)ceil((double)i/(double)2)-1]))  ///ceil returns double
        {
            swap(heap[i], heap[(int)ceil((double)i/(double)2)-1]);
            i = ceil(((double)i/(double)2)) -1;
        }
        cout << "Enter the another value to pushed : " ;
        cin >> val;
    }
}

void MinHeapify(int i)
{
    int smallest ;
    int leftChild = 2*i+1;
    int rightChild = 2*i +2;
    ///we just reversed comparison sign
    if(leftChild<=sizes && heap[i]>heap[leftChild])
        smallest = leftChild;
    else
        smallest = i;
    if(rightChild<=sizes && heap[smallest]>heap[rightChild])
        smallest  = rightChild;
    ///Percolate Down Algorithm - moving large value down
    if(smallest != i){
        swap(heap[i],heap[smallest]);
        MinHeapify(smallest);
    }


}

void Pop()
{
    if(sizes <0 )
    {
        cout << "UnderFlow !!";
        return ;
    }
    int mins = heap[0];
    heap[0] = heap[sizes]; ///Obviously , here also we put last value.
    sizes--;
    ///Mix Heapify
    MinHeapify(0);
    cout << "Min Value is : " << mins << endl;
}

void Increase()
{
    cout <<  "Enter the index where value to be changed : " ;
    int index;
    cin >> index;
    if(index > sizes)
    {
        cout << "Invalid index!!";
        return;
    }
    int val;
    cout << "Enter the new value to be entered : ";
    cin >> val;
    if(val < heap[index])
    {
        cout << "Wrong Operation!!";
        return;
    }
    heap[index] = val;
    ///Percolate Down algorithm - moving large value downward
    MinHeapify(index);
}

void Decrease()
{
    cout <<  "Enter the index where value to be changed : " ;
    int index;
    cin >> index;
    if(index > sizes)
    {
        cout << "Invalid index!!";
        return;
    }
    int val;
    cout << "Enter the new value to be entered : ";
    cin >> val;
    if(val > heap[index])
    {
        cout << "Wrong Operation!!";
        return;
    }
    heap[index] = val;
    ///Percolate Down Algorithm-
    while(index >0 && (heap[index] < heap[(int)ceil((double)index/(double)2)-1]))  ///ceil returns double
    {
        swap(heap[index], heap[(int)ceil((double)index/(double)2)-1]);
        index = ceil(((double)index/(double)2)) -1;
    }
}

/*void check()
{
    for(int i=0;i<=sizes ;i++)
        cout << heap[i] << " ";
    cout << endl;
}*/
int main()
{
    int flag = 0;
    cout << "Enter size of heap : ";
    cin >> n;
    do{
        cout << endl << "1.Insert(or push)" <<endl;
        cout << "2.Delete(or pop or Extract Max)" << endl;
        cout << "3.Increase Key" << endl;
        cout << "4.Decrease Key" << endl;
        cout << "5.Exit" << endl;
        cout << "\tEnter your choice : " ;
        int ch;
        cin >> ch;
        switch(ch)
        {
            case 1 :
                Push();
                break;
            case 2 :
                Pop();
                break;
            case 3 :
                Increase();
                break;
            case 4 :
                Decrease();
                break;
            case 5 :
                flag = 1;
                break;
            /*case 6 :
                check();
                break;*/
            default :
                cout << "Enter the valid Choice !!!" << endl;
                break;
        }
    }while(flag !=1);
    return 0;
}

