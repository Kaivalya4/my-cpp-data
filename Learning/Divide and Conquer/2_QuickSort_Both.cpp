#include<iostream>
#include<fstream>
#include<chrono>
#include<time.h>
#include<iomanip>

using namespace std;

int counts = 0;

void CreateFile()
{
    fstream file("Kaivalya1.txt",ios::out);
    for(int i=0;i<10000;i++)
    {
        file << i<< " ";
    }
    file.close();

    fstream file2("Kaivalya2.txt",ios::out);
    for(int i=0;i<10000;i++)
    {
        file2 << rand() << " ";
    }
    file2.close();
}

int Kaivalyapartitions(int arr[]  ,int low , int high)
{
    int pivot = arr[high];
    int i = low;
    for(int j = low ;j<high;j++)
    {
        if(pivot>=arr[j])
        {
            counts++;
            swap(arr[i],arr[j]);
            i++;
        }
    }

    swap(arr[i],arr[high]);
    return i;
}

void LamutoSort(int arr[] , int low , int high)
{
    if(low<high)
    {
        int pi = Kaivalyapartitions(arr , low, high);  ///find partition
        LamutoSort(arr , low , pi-1);  ///left subarray
        LamutoSort(arr , pi+1 , high);  ///right subarray
    }
}

int Tripathipartitions(int arr[] , int low ,int high)
{
    int pi = arr[low];
    int i=low-1;
    int j = high+1;
    while(true)
    {
        do{
            i++;
        }while(arr[i]<pi);
        do{
            j--;
        }while(arr[j]>pi);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
        counts++;
    }
}

void HoareSort(int arr[] , int low , int high)
{
    if(low < high)
    {
        int pi = Tripathipartitions(arr , low, high);
        HoareSort(arr, low , pi);
        HoareSort(arr,pi+1,high);
    }
}

void File1()
{
//using namespace std::chrono;
    int arr[10000];
    int arr1[10000];
    fstream file1("Kaivalya1.txt",ios::in);
    int num;
    int n=0;
    while(file1 >> num)
    {
        arr[n] = num;
        arr1[n] = num;
        n++;
    }
    /*auto start = high_resolution_clock::now();
    LamutoSort(arr , 0 , n-1);
    auto stop  = high_resolution_clock::now();
    auto ans = duration_cast<milliseconds>(stop - start);*/
    clock_t start,ends;
    start = clock();
    LamutoSort(arr , 0 , n-1);
    ends= clock();
    double ans = (double)(ends - start)/(double) (CLOCKS_PER_SEC);
    cout << "Time taken in execution of file Kaivalya" << 1 << " By Lamuto Partition : " << ans << setprecision(5)  << "sec" << endl;
    cout << "Number of swaps done on file Kaivalya" << 1 << " By Lamuto Partition : " << counts << endl;

    counts = 0;
    /*start = high_resolution_clock::now();
    HoareSort(arr1 , 0 , n-1);
    stop  = high_resolution_clock::now();
    ans = duration_cast<milliseconds>(stop - start);*/
    start = clock();
    HoareSort(arr , 0 , n-1);
    ends= clock();
    ans = (double)(ends - start)/(double) (CLOCKS_PER_SEC);
    cout << "Time taken in execution of file Kaivalya" << 1 << " By Hoare Partition : " << ans << setprecision(5)  << "sec" << endl;
    cout << "Number of swaps done on file Kaivalya" << 1 << " By Hoare Partition : " << counts << endl;
    file1.close();
}

void File2()
{
//using namespace std::chrono;
    counts = 0;
    int arr[10000];
    int arr1[10000];
    fstream file1("Kaivalya2.txt",ios::in);
    int num;
    int n=0;
    while(file1 >> num)
    {
        arr[n] = num;
        arr1[n] = num;
        n++;
    }
    /*auto start = high_resolution_clock::now();
    LamutoSort(arr , 0 , n-1);
    auto stop  = high_resolution_clock::now();
    auto ans = duration_cast<milliseconds>(stop - start);
    cout << "Time taken in execution of file Kaivalya" << 2 << " By Lamuto Partition : " << ans.count()  << "ms" << endl;
    cout << "Number of swaps done on file Kaivalya" << 2 << " By Lamuto Partition : " << counts << endl;
*/
    clock_t start,ends;
    start = clock();
    LamutoSort(arr , 0 , n-1);
    ends= clock();
    double ans = (double)(ends - start)/(double) (CLOCKS_PER_SEC);
    cout << "Time taken in execution of file Kaivalya" << 2 << " By Lamuto Partition : " << ans << setprecision(5)  << "sec" << endl;
    cout << "Number of swaps done on file Kaivalya" << 2 << " By Lamuto Partition : " << counts << endl;

    counts = 0;
    /*start = high_resolution_clock::now();
    HoareSort(arr1 , 0 , n-1);
    stop  = high_resolution_clock::now();
    ans = duration_cast<milliseconds>(stop - start);*/
    start = clock();
    HoareSort(arr , 0 , n-1);
    ends= clock();
    ans = (double)(ends - start)/(double) (CLOCKS_PER_SEC);
    cout << "Time taken in execution of file Kaivalya" << 2 << " By Hoare Partition : " << ans << setprecision(5)  << "sec" << endl;
    cout << "Number of swaps done on file Kaivalya" << 2 << " By Hoare Partition : " << counts << endl;
    file1.close();
}


int main()
{
    CreateFile();
    File1();
    File2();
    return 0;
}

/*
partition( ..........)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(true)
    {
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }
}
*/
