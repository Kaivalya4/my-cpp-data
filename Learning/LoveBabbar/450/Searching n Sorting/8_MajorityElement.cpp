/**
->Brute
->Mapping
->Sorting
->Moore Algorithm -
    See loop in code for algorithm

    Main intuition is that : if a majority element exist then its count will always be atleast
    one greater than total count of all other elements.

    Suppose majority element exist ,  so count  of majority element > n/2 i.e. count of
    majority element will always be atleast one extra than count of other elements. This
    algortihm assure that the element we are getting at last has count zero. So if
    Majority element exist then candidate will store that.

    Suppose majority element not exist
    2 3 4 5 3 4
    Finally candidate  = 4
    count = 1
    So 4 is the candidate , we are not sure wether its Majority or not . So we run one more loop to verify.

    Consider 4 4 4 2 3 . We can see as count of 4 is greater than count of all other elements. So
    finally
    Candidate = 4
    Count = 1
    One more  loop to just verify.

    hence main intuition :
    Count of Majority element > count of all other elements . So candidate will store majority element(if it exists)

int majorityElement(int a[], int n)
{

    // your code here
    int candidate = -1;
    int counts = 0;
    for(int i=0;i<n;i++)
    {
        if(counts == 0)
            candidate = a[i];
        if(a[i] == candidate)
            counts ++;
        else
            counts --;
    }
    int verify =0;
    for(int i=0;i<n;i++)
        if(a[i] == candidate)
         verify ++;
    if(verify > n/2)
        return candidate;
    return -1;
}
*/
