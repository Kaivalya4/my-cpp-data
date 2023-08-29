/**
TOPIC OF OS -
->Shortest Job First (SJF) CPU scheduling algorithm is a CPU scheduling algorithm which is based on
 the principles of Greedy Algorithms. The key idea is to allocate the CPU to the process with the
 smallest burst time so that the CPU seems to be more responsive.
 Burst time is the amount of time required by a process for its execution on the CPU.

->It is practically infeasible as Operating System may not know burst time and therefore may not sort them.

This algorithm can be improved at many instances but we are not going to see them.

TERMINOLOGIES -
 -Arrival time
 -Burst time :  Burst time is the amount of time required by a process for its execution on the CPU.
 -Completion Time: Time at which process completes its execution.
 -Turn Around Time: Time Difference between completion time and arrival time.
        Turn Around Time = Completion Time – Arrival Time
 -Waiting Time(W.T): Time Difference between turn around time and burst time.
        Waiting Time = Turn Around Time – Burst Time

ALGORITHM -
->Sort all the process according to the arrival time.
->Then select that process which has minimum arrival time and minimum Burst time
->After completion of the process, select from the ready queue the process which has the minimum burst time.
->Repeat above processes untill all processes have finished their execution.
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct storage{
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

bool comp(struct storage a , struct storage b)
{
    if(a.arrival > b.arrival)
        return false;
    return true;
}

int main()
{
    storage arr[100];
    int n;
    cout << "Enter the number of processes : ";
    cin >> n;
    cout << "Enter the arrival time of processes : " << endl;
    for(int i=0;i<n;i++)
    {
        arr[i].id = i+1;
        cin >> arr[i].arrival;
    }
    cout << "Enter the burst time of the processes  : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].burst;
    }

    cout << "Before the Arrange...." << endl;
    cout << "Process id \t Arrival Time \t Burst Time" << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i].id << " \t " << arr[i].arrival << " \t " << arr[i].burst << endl;
    }

    sort(arr , arr+n , comp);

    return 0;
}
