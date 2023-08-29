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
        ///Percolate up Algorithm-
        while(i >0 && (heap[i] > heap[(int)ceil((double)i/(double)2)-1]))  ///ceil returns double
        {
            swap(heap[i], heap[(int)ceil((double)i/(double)2)-1]);
            i = ceil(((double)i/(double)2)) -1;
        }
        cout << "Enter the another value to pushed : " ;
        cin >> val;
    }
}

void MaxHeapify(int i)
{
    int largest ;
    int leftChild = 2*i+1;
    int rightChild = 2*i +2;
    if(leftChild<=sizes && heap[largest]<heap[leftChild])
        largest = leftChild;
    else
        largest = i;
    if(rightChild<=sizes && heap[largest]<heap[rightChild])
        largest  = rightChild;
    ///Percolate Down Algorithm
    if(largest != i){
        swap(heap[i],heap[largest]);
        MaxHeapify(largest);
    }


}

void Pop()
{
    if(sizes <0 )
    {
        cout << "UnderFlow !!";
        return ;
    }
    int maxi = heap[0];
    heap[0] = heap[sizes];
    sizes--;
    ///Max Heapify
    MaxHeapify(0);
    cout << "Max Value is : " << maxi << endl;
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
    ///Percolate up algorithm -
    while(index >0 && (heap[index] > heap[(int)ceil((double)index/(double)2)-1]))  ///ceil returns double
    {
        swap(heap[index], heap[(int)ceil((double)index/(double)2)-1]);
        index = ceil(((double)index/(double)2)) -1;
    }
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
    MaxHeapify(index);
}

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
            default :
                cout << "Enter the valid Choice !!!" << endl;
                break;
        }
    }while(flag !=1);
    return 0;
}
