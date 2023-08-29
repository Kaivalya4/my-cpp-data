/*
mehod1 -
    we shift one elements at a time 
    time  - O(n*d) , space - O(1)
    void oneTimeRotate(int arr1[] , int d , int size)
    {
        int temp;
        for(int i=0 ; i<d ; i++)
        {
            temp = arr1[0];
            for(int j=0 ; j<size-1 ; j++)
            {
                arr1[j] = arr1[j+1];
            }
            arr1[size-1] = temp;
        }
    }

method2 - 
    //we use temp array to store elements till d 
    //time - O(n) , space - O(d)
    void temp_method(int arr[] , int d , int size)
    {
        int temp[1000];
        for(int i=0 ; i<d; i++)
        {
            temp[i] = arr[i];
        }
        for(int i=d ; i<size ; i++)
        {
            arr[i-d] = arr[i];
        }
        int j=size -d;
        for(int i=0 ; i<d ; i++)
        {
            arr[j] = temp[i];
            j++;
        }
    }

method3 -
    rotate first d element , then rotate remaining element , rotate full array-
    reverse(int arr[] , int beg , int end)
    {
        for(int i=beg ,j=end ; i<j ; i++,j--)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    rotate(int arr[] , int d)
    {
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);

    }
*/