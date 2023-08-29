//                                                                                                                                  KaivalyaMani Tripathi.
#include<iostream>
#include<fstream>
#include<chrono>
#include<random>

using namespace std;
using namespace std::chrono;

int temp[10000];
int counts =0;

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

void KAIVALYAmerges(int arr[] , int low , int mid , int high)
{
    int i=low , j = mid+1 , k=0;
    while(i<=mid && j<=high)
    {
        counts+=2;
        if(arr[i] >= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    counts++;
    while(i<=mid){
            counts++;
        temp[k++] = arr[i++];
    }
    counts++;
    while(j<=high){
        counts++;
        temp[k++] = arr[j++];
    }
    counts++;
    int aitr = low;
    counts += k;
    for(int itr=0;itr<k;itr++)
        arr[aitr++] = temp[itr];
}

void mergeSort(int arr[] , int low , int high)
{
    counts ++ ;
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(arr , low , mid);
        mergeSort(arr,mid+1,high);
        KAIVALYAmerges(arr,low,mid,high);
    }
}

void TRIPATHIFourWaymerges(int arr[] , int low , int mid1 , int mid2  ,int mid3 , int high)
{
    int i=low , j = mid1+1 , t = mid2+1 , r = mid3+1;
    int kt = 0;
    /// For first 2 subarray                                                                                    -by Kaivalya
    while(i<=mid1 && j<=mid2)
    {
        counts +=2 ;
        if(arr[i]<=arr[j])
        {
            temp[kt++] = arr[i++];
        }
        else{
            temp[kt++] = arr[j++];
        }
    }
    counts++;
    while(i<=mid1)
    {
        counts ++;
        temp[kt++] = arr[i++];
    }
    counts++;
    while(j<=mid2)
    {
        counts++;
        temp[kt++] = arr[j++];
    }
    counts++;
    int marker = low;
    counts += kt;
    for(int itr = 0; itr<kt ;itr++)
        arr[marker++] = temp[itr];

    kt = 0;
    while(t<=mid3 && r<=high)
    {
        counts +=2;
        if(arr[t]<=arr[r])
        {
            temp[kt++] = arr[t++];
        }
        else{
            temp[kt++] = arr[r++];
        }
    }
    counts++;
    while(t<=mid3)
    {
        counts++;
        temp[kt++] = arr[t++];
    }
    counts++;
    while(r<=high)
    {
        counts++;
        temp[kt++] = arr[r++];
    }
    counts++;

    marker = mid2+1;
    counts += kt;
    for(int itr = 0 ;itr<kt;itr++)
        arr[marker++] = temp[itr];

    i = low , j = mid2 +1;
    kt = 0;
    while(i<=mid2 && j<=high)
    {
        counts +=2;
        if(arr[i]<=arr[j])
        {
            temp[kt++] = arr[i++];
        }
        else{
            temp[kt++] = arr[j++];
        }
    }
    counts++;
    while(i<=mid2){
        counts ++;
        temp[kt++] = arr[i++];
    }
    counts ++;
    while(j<=high){
        counts ++;
        temp[kt++] = arr[j++];
    }
    counts ++;
    marker = low;
    counts += kt;
    for(int itr = 0; itr<kt; itr++)
        arr[marker++] = temp[itr];
}

void FourWayMS(int arr[] , int low  , int high)
{
    counts ++ ;
    if(low <high){
        int mid1 = ((3*low) + (1*high))/4;
        int mid2 = (low+ high)/2;
        int mid3 = ((1*low) + (3*high))/4;
        FourWayMS(arr ,low , mid1);
        FourWayMS(arr,mid1+1 , mid2);
        FourWayMS(arr , mid2+1, mid3);
        FourWayMS(arr , mid3+1 , high);
        TRIPATHIFourWaymerges(arr , low , mid1 , mid2 , mid3 ,high);
    }
}

void Kaivalya1()
{
    int arr[10000];
    int arr1[10000];
    int n = 0;
    fstream file("Kaivalya1.txt",ios::in);
    int num;
    while(file >> num)
    {
        arr[n++] = num;
        arr1[--n] = num;
        n++;
    }
    auto start = high_resolution_clock::now();
    mergeSort(arr , 0 , n-1);
    auto stop  = high_resolution_clock::now();
    auto ans = duration_cast<milliseconds>(stop - start);
    cout << "Time taken in execution of file Kaivalya" << 1 << " By MergeSort : " << ans.count()  << "ms" << endl;
    cout << "Number of comparison done on file Kaivalya" << 1 << " By MergeSort : " << counts << endl;

    counts = 0;
    start = high_resolution_clock::now();
    FourWayMS(arr1 , 0 , n-1);
    stop  = high_resolution_clock::now(); /*-----All program by KT   */
    ans = duration_cast<milliseconds>(stop - start);
    cout << "Time taken in execution of file Kaivalya" << 1 << " By 4Way MergeSort : " << ans.count()  << "ms" << endl;
    cout << "Number of comparison done on file Kaivalya" << 1 << " By 4Way MergeSort : " << counts << endl;
    cout << endl;
}

void Kaivalya2()
{
    counts = 0;
    int arr[10000];
    int arr1[10000];
    int n = 0;
    fstream file("Kaivalya2.txt",ios::in);
    int num;
    while(file >> num)
    {
        arr[n++] = num;
        arr1[--n] = num;
        n++;
    }

    auto start = high_resolution_clock::now();
    mergeSort(arr , 0 , n-1);
    auto stop  = high_resolution_clock::now();
    auto ans = duration_cast<milliseconds>(stop - start);
    cout << "Time taken in execution of file Kaivalya" << 2 << " By MergeSort : " << ans.count()  << "ms" << endl;
    cout << "Number of comparison done on file Kaivalya" << 2 << " By MergeSort : " << counts << endl;

    counts = 0;
    auto start1 = high_resolution_clock::now();
    FourWayMS(arr1 , 0 , n-1);
    auto stop1  = high_resolution_clock::now(); /*-----All program by KT   */
    auto ans1 = duration_cast<milliseconds>(stop - start);
    cout << "Time taken in execution of file Kaivalya" << 2 << " By 4Way MergeSort : " << ans1.count()  << "ms" << endl;
    cout << "Number of comparison done on file Kaivalya" << 2 << " By 4Way MergeSort : " << counts << endl;

    cout << endl  << endl << endl << "Thank You !!!! Program by KT";
}

int main()
{
    CreateFile();
    Kaivalya1();
    Kaivalya2();
    return 0;
}
