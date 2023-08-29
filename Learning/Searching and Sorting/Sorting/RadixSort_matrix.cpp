///Matrix method to store element . See rema

#include<iostream>

using namespace std;

int arr[100];
int bucket_size[10];   ///in each pass it tracks like - how many element have 1 in units place . Store that count in bucket_count[i]
int bucketmatrix[10][100];   ///row represent digit. 0-9

void radixSort(int n)
{
    int maxs = 0;
    for(int i=0;i<n;i++)
        maxs = max(maxs ,arr[i]);

    for(int place=1;maxs/place>1;place*=10)
    {
        for(int i=0;i<=9;i++)
            bucket_size[i] =0;
        for(int i=0;i<n;i++)
        {
            int num = arr[i];
            bucketmatrix[(num/place)%10][bucket_size[(num/place)%10]] = num;  ///for digit 0 if there is no number with digit zero store it in column 1
            bucket_size[(num/place)%10]++; ///now there is 1 element with digit zero
        }
        int itr = 0;
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<bucket_size[i];j++)  ///number of elements with digit 1 . put them in array one by one.
            {
                arr[itr++] = bucketmatrix[i][j];
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    radixSort(n);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" " ;
    return 0;
}
